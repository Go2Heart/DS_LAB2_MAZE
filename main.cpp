#include<cstdio>
#include<cstdlib>
#include "DfsSolver.h"
#include "BfsSolver.h"
using namespace std;
int main()
{
	FILE* fin = fopen("Maze.in", "w");
	int InitN, InitM, sx, sy, tx, ty, x;
	scanf("%d %d", InitN, InitM);
	fprintf(fin, "%d %d\n", InitN, InitM);
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	fprintf(fin, "%d %d\n%d %d\n", sx, sy, tx, ty);
	for(int i = 1; i <= InitN; i++)
	{
		for(int j = 1; j <= InitM; j++)
		{
			scanf("%d",&x);
			fprintf(fin, "%d%c", x, j == InitM ? '\n' : ' ');
		}
	}
	fclose(fin);
	DfsSolver SolByDfs;
	BfsSolver SolByBfs;
	if(!SolByDfs.Solve(fopen("Maze.in", "r"), fopen("SolByDfs.out", "w")))
		fprintf(stderr, "Solve By DFS Error!\n");
	if(!SolByBfs.Solve(fopen("Maze.in", "r"), fopen("SolByBfs.out", "w"), fopen("AllPath.out", "w")))
		fprintf(stderr, "Solve By BFS Error!\n");
}