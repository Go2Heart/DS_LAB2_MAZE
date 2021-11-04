#include<bits/stdc++.h>
#define MN 1005
using namespace std;
struct node
{
	int x, y, v;
	friend bool operator<(node x, node y)
	{
		if(x.v == y.v)
		{
			if(x.x == y.x)
				return x.y < y.y;
			return x.x < y.x;
		}
		return x.v < y.v;
	}
}que[MN * MN];
set<node> s;
int val[MN][MN], n, m;
const int dx[]={-1, 1, 0, 0};
const int dy[]={0, 0, -1, 1};
bool inq[MN][MN], vis[MN][MN];
int len[MN][MN];
bool in(int x, int y){
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
int main()
{
	srand(time(NULL));
	n = 1000/*rand() % 1000 + 1*/, m = 1000/*rand() % 1000 + 1*/;
	int sx = rand() % n + 1, sy = rand() % m + 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) val[i][j] = rand();
	for(int i = 0; i < 4; i++)
	{
		int nx = sx + dx[i], ny = sy + dy[i];
		if(in(nx, ny))
			s.insert((node){nx, ny, val[nx][ny]});
	}
	inq[sx][sy] = vis[sx][sy] = 1;
	int tt = 0;
	while(!s.empty())
	{
		node tmp = (*s.begin());
		s.erase(tmp);
		vis[tmp.x][tmp.y] = 1;
		int con = 0;
		int findx, findy; 
		for(int i = 0; i < 4; i++)if(in(tmp.x + dx[i],tmp.y + dy[i]))
			con += inq[tmp.x + dx[i]][tmp.y + dy[i]], findx = tmp.x + dx[i], findy = tmp.y + dy[i];
		if(con != 1)continue;
		len[tmp.x][tmp.y] = len[findx][findy] + 1;
	//	printf("%d %d\n",tmp.x, tmp.y);
		inq[tmp.x][tmp.y] = 1;
		que[++tt] = (node){tmp.x, tmp.y};
		for(int i = 0; i < 4; i++)
		{
			int nx = tmp.x + dx[i];
			int ny = tmp.y + dy[i];
			if(in(nx, ny) && !vis[nx][ny])
				s.insert((node){nx, ny, val[nx][ny]});
		}
	}
	sort(que + 1, que + tt + 1);
	int now = tt / 10 * 9 + rand() % (tt / 10 + 1) + 1;
	if(now > tt) now = tt;
	int tx = que[now].x, ty = que[now].y;
	FILE* fin = fopen("test.in", "w");
	fprintf(fin, "%d %d\n", n, m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			fprintf(fin, "%d%c", inq[i][j] ^ 1, j == m ? '\n': ' ');
	fprintf(fin, "%d %d\n%d %d\n", sx, sy, tx, ty);
}
