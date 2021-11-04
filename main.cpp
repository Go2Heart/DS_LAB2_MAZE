#include<cstdio>
#include<cstdlib>
#include "Array.h"
#include "Stack.h"
#include "Queue.h"
#include "DfsNode.h"
#include "BfsNode.h"
#include "DfsSolver.h"
#include "BfsSolver.h"
using namespace std;
int main()
{
	FILE* fin = fopen("Maze.in", "w");
	int InitN, InitM, sx, sy, tx, ty, x;
	
	#ifdef TEST
		FILE* nowfin = fopen("test.in", "r");
		fscanf(nowfin, "%d%d", &InitN, &InitM);
		fprintf(fin, "%d %d\n", InitN, InitM);
		for(int i = 1; i <= InitN; i++)
		{
			for(int j = 1; j <= InitM; j++)
			{
				fscanf(nowfin, "%d", &x);
				fprintf(fin, "%d%c", x, j == InitM ? '\n' : ' ');
			}
		}
		fscanf(nowfin, "%d%d%d%d", &sx, &sy, &tx, &ty);
		fprintf(fin, "%d %d\n%d %d\n", sx, sy, tx, ty);
		fclose(fin);
		fclose(nowfin);	
	#else 
		scanf("%d %d", &InitN, &InitM);
		fprintf(fin, "%d %d\n", InitN, InitM);
		for(int i = 1; i <= InitN; i++)
		{
			for(int j = 1; j <= InitM; j++)
			{
				scanf("%d", &x);
				fprintf(fin, "%d%c", x, j == InitM ? '\n' : ' ');
			}
		}
		scanf("%d%d%d%d",&sx, &sy, &tx, &ty);
		fprintf(fin, "%d %d\n%d %d\n", sx, sy, tx, ty);
		fclose(fin);
	#endif
	DfsSolver SolByDfs(InitN, InitM);
	BfsSolver SolByBfs(InitN, InitM);
	if(!SolByDfs.Solve(fopen("Maze.in", "r"), fopen("SolByDfs.out", "w")))
		fprintf(stderr, "Solve By DFS Error!\n");
	if(!SolByBfs.Solve(fopen("Maze.in", "r"), fopen("SolByBfs.out", "w"), fopen("AllPath.out", "w")))
		fprintf(stderr, "Solve By BFS Error!\n");
}
