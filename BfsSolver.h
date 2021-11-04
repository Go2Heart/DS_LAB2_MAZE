struct BfsSolver
{
	BfsSolver(int N,int M) : N(N), M(M), Map(N, M, 0), Vis(N, M, 0), Pre(N, M, 0), Q(N * M), AnsStack(N * M), AnsQ(5) { }
	Queue<BfsNode> Q;
	Queue<BfsNode> AnsQ;
	Stack<BfsNode> AnsStack;
	Array<bool> Map;
	Array<bool> Vis;
	Array<int> Pre; 
	int N, M;
	int Sx, Sy, Tx, Ty;
	const int dx[4] = {0, 0, 1, -1};
	const int dy[4] = {1, -1, 0, 0};
	const char Dir[4][10] = {"East", "West", "South", "North"};
	bool Available(int x, int y);
	bool Solve(FILE* fin, FILE* fout, FILE* fout2/*, FILE* Debug*/);
};