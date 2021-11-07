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
		fprintf(stderr, "Maze Solving: please input the width and the height of the maze.(divided by space such as\"5 7\"):");
		scanf("%d %d", &InitN, &InitM);
		fprintf(fin, "%d %d\n", InitN, InitM);
		fprintf(stderr, "Please input n * m 0/1 to set up the maze, as 0 for roads and 1 for walls:\n");
		for(int i = 1; i <= InitN; i++)
		{
			for(int j = 1; j <= InitM; j++)
			{
				scanf("%d", &x);
				fprintf(fin, "%d%c", x, j == InitM ? '\n' : ' ');
			}
		}
		fprintf(stderr, "Please input two integers to set up the start point:");
		scanf("%d%d", &sx, &sy);
		fprintf(stderr, "Please input two integers to set up the end point:");
		scanf("%d%d", &tx, &ty);
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
