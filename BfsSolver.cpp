#include<cstdio>
#include<cstdlib>
#include "Queue.h"
#include "BfsNode.h"
#include "Array.h"
#include "BfsSolver.h"
bool BfsSolver::Init(int InitN, int InitM)
{
	Q = Queue<BfsNode> (N * M);
	Map = Array<bool> (N, M);
	Vis = Array<bool> (N, M);
	N = InitN, M = InitM;
}
bool BfsSolver::Solve(FILE* fin, FILE* fout, FILE* Debug = NULL)
{
	int InitN, InitM, x;
	fscanf(fin, "%d %d", &InitN, &InitM);
	Init(InitN, InitM);
	fscanf(fin, "%d %d", &Sx, &Sy);
	fscanf(fin, "%d %d", &Tx, &Ty);
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++) 
		{
			fscanf(fin, "%d", &x);
			Map.Assign(i, j, x);
		}
	Q.InQueue(BfsNode(Sx, Sy, -1));
	while(!Q.IsEmpty())
	{
		BfsNode Cur;
		Q.DeQueue(&Cur);
		Vis.Assign(Cur.x, Cur.y, true);
		for(int k = 0; k < 4; k++)
		{
			int nx = Cur.x + dx[k];
			int ny = Cur.y + dy[k];
			bool f1, f2;
			if(Vis.Value(nx, ny, &f1) && !f1 && Map.Value(nx, ny, &f2) && !f2)
				Q.InQueue(BfsNode(nx, ny, k));
		}
	}
	fclose(fin);
}