#include<cstdio>
#include<cstdlib>
#include "Stack.h"
#include "DfsNode.h"
#include "Array.h"
#include "DfsSolver.h"

bool DfsSolver::Available(int x, int y)
{
	return x >= 1 && x <= N && y >= 1 && y <= M; 
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
	bool f0;
	if(!Available(Sx, Sy) || (Map.Value(Sx, Sy, &f0) && f0))
	{
		fprintf(fout, "Start Point Unreachable!\n");
		fclose(fout);
		return false;
	}
	if(!Available(Tx, Ty) || (Map.Value(Tx, Ty, &f0) && f0))
	{
		fprintf(fout, "End Point Unreachable!\n");
		fclose(fout);
		return false;
	}
	S.Push(DfsNode(Sx, Sy, 0));
	bool Arrive = 0;
	while(!S.IsEmpty())
	{
		DfsNode Cur;
		S.Pop(&Cur);
		Vis.Assign(Cur.x, Cur.y, 1);
		if(Cur.x == Tx && Cur.y == Ty)
		{
			Arrive = 1;
			break;
		}
			
		if(Cur.k >= 4) continue;
		int nx = Cur.x + dx[Cur.k];
		int ny = Cur.y + dy[Cur.k];
		Cur.k++;
		S.Push(Cur);
		bool ch, ch2;
		if(Vis.Value(nx, ny, &ch2) && ch2 == 0 && Map.Value(nx, ny, &ch) && ch == 0)
			S.Push(DfsNode(nx, ny, 0));
	}
	if(!Arrive)
	{
		fprintf(fout, "No Available Path\n");
		fclose(fout);
		return false;
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
