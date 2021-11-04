#include<cstdio>
#include<cstdlib>
#include "Queue.h"
#include "Stack.h"
#include "BfsNode.h"
#include "Array.h"
#include "BfsSolver.h"
bool BfsSolver::Init(int InitN, int InitM)
{
	N = InitN, M = InitM;
	Queue<BfsNode> Q(N * M);
	Stack<BfsNode> AnsStack(N * M);
	Array<bool> Map(N, M, 0);
	Array<bool> Vis(N, M, 0);
	Array<int> Pre(N, M, 0);
	Queue<BfsNode> AnsQ(4);
	return true;
}
bool BfsSolver::Available(int x, int y)
{
	return x >= 1 && x <= N && y >= 1 && y <= M; 
}
bool BfsSolver::Solve(FILE* fin, FILE* fout, FILE* fout2/*, FILE* Debug = NULL*/)
{
	int InitN, InitM, x;
	fscanf(fin, "%d %d", &InitN, &InitM);
	//Init(InitN, InitM);
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++) 
		{
			fscanf(fin, "%d", &x);
			Map.Assign(i, j, x);
		}
	fscanf(fin, "%d %d", &Sx, &Sy);
	fscanf(fin, "%d %d", &Tx, &Ty);
	Q.InQueue(BfsNode(Sx, Sy, -1));
	while(!Q.IsEmpty())
	{
		BfsNode Cur;
		Q.DeQueue(&Cur);
		Vis.Assign(Cur.x, Cur.y, true);
		if(Cur.x == Tx && Cur.y == Ty) continue;
		for(int k = 0; k < 4; k++)
		{
			int nx = Cur.x + dx[k];
			int ny = Cur.y + dy[k];
			if (!Available(nx, ny)) continue;
			bool f1, f2;
			if(nx == Tx && ny == Ty)
			{
				AnsQ.InQueue(BfsNode(Cur.x, Cur.y, k));
			}
			if(Vis.Value(nx, ny, &f1) && !f1 && Map.Value(nx, ny, &f2) && !f2)
			{
				Q.InQueue(BfsNode(nx, ny, k));
				Pre.Assign(nx, ny, k ^ 1);
			}
		}
	}
	fprintf(fout, "The shortest path is as below:\n");
	bool Arrive = 0;
	int PathCnt = 0;
	while(!AnsQ.IsEmpty())
	{
		++PathCnt;
		fprintf(fout2, "Path %d:\n", PathCnt);
		BfsNode Cur, Tmp;
		AnsQ.DeQueue(&Cur);
		if(!Arrive)
		{
			Arrive = 1;
			AnsStack.Push(Cur);
			Tmp = Cur;
			int TmpPre;
			while(!(Tmp.x == Sx && Tmp.y == Sy))
			{
				if(Pre.Value(Tmp.x, Tmp.y, &TmpPre))
				{
					Tmp = BfsNode(Tmp.x + dx[TmpPre], Tmp.y + dy[TmpPre], TmpPre ^ 1);
				}
				else fprintf(stderr, "out of range!\n");
				AnsStack.Push(Tmp);
			}
			while(!AnsStack.IsEmpty())
			{
				AnsStack.Pop(&Tmp);
				fprintf(fout, "from (%d,%d), move to the %s ,arrive at (%d,%d)\n", Tmp.x, Tmp.y, Dir[Tmp.d], Tmp.x + dx[Tmp.d], Tmp.y + dy[Tmp.d]);
			}
		}
		AnsStack.Push(Cur);
		Tmp = Cur;
		int TmpPre;
		while(!(Tmp.x == Sx && Tmp.y == Sy))
		{
			if(Pre.Value(Tmp.x, Tmp.y, &TmpPre))
			{
				Tmp = BfsNode(Tmp.x + dx[TmpPre], Tmp.y + dy[TmpPre], TmpPre ^ 1);
			}
			else fprintf(stderr, "out of range!\n");
			AnsStack.Push(Tmp);
		}
		while(!AnsStack.IsEmpty())
		{
			AnsStack.Pop(&Tmp);
			fprintf(fout2, "from (%d,%d), move to the %s ,arrive at (%d,%d)\n", Tmp.x, Tmp.y, Dir[Tmp.d], Tmp.x + dx[Tmp.d], Tmp.y + dy[Tmp.d]);
		}
	}
	fclose(fin);
	fclose(fout);
	fclose(fout2);
	return true;
}
