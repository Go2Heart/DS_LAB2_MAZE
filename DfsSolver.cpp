#include<cstdio>
#include<cstdlib>
#include "Stack.h"
#include "DfsNode.h"
#include "Array.h"
#include "DfsSolver.h"

bool DfsSolver::Init(int InitN, int InitM)
{
	N = InitN, M = InitM;
	Stack<DfsNode> S(N * M);
	Array<bool> Map(N, M, 0);
	Array<bool> Vis(N, M, 0);
	return true;
}

bool DfsSolver::Solve(FILE* fin, FILE* fout/*, FILE* Debug = NULL*/)
{
	int InitN, InitM, x;
	fscanf(fin, "%d %d", &InitN, &InitM);
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++) 
		{
			fscanf(fin, "%d", &x);
			Map.Assign(i, j, x);
		}
	
	fscanf(fin, "%d %d", &Sx, &Sy);
	fscanf(fin, "%d %d", &Tx, &Ty);
	S.Push(DfsNode(Sx, Sy, 0));
	while(!S.IsEmpty())
	{
		DfsNode Cur;
		S.Pop(&Cur);
		Vis.Assign(Cur.x, Cur.y, 1);
		if(Cur.x == Tx && Cur.y == Ty)
			break;
		if(Cur.k >= 4) continue;
		int nx = Cur.x + dx[Cur.k];
		int ny = Cur.y + dy[Cur.k];
		Cur.k++;
		S.Push(Cur);
		bool ch, ch2;
		if(Vis.Value(nx, ny, &ch2) && ch2 == 0 && Map.Value(nx, ny, &ch) && ch == 0)
			S.Push(DfsNode(nx, ny, 0));
	}
	Stack<DfsNode> S2(N * M);
	while(!S.IsEmpty())
	{
		DfsNode Cur;
		S.Pop(&Cur);
		S2.Push(Cur);
	}
	fprintf(fout, "The path is as below:\n");
	while(!S2.IsEmpty())
	{
		DfsNode Cur;
		S2.Pop(&Cur);
		Cur.k--;
		fprintf(fout, "from (%d,%d), move to the %s ,arrive at (%d,%d)\n", Cur.x, Cur.y, Dir[Cur.k], Cur.x + dx[Cur.k], Cur.y + dy[Cur.k]);
	}
	fclose(fin);
	fclose(fout);
	return true;
}
