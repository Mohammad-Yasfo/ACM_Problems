#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

FILE *fout = fopen("island.out", "w");
FILE *fin = fopen("island.in", "r");

const int INF = 1000000000;
const int dr[] = { -1, 0, 0, 1 };
const int dc[] = { 0, -1, 1, 0 };

const int MAXN = 16;
const int MAXG = 55;
const int MAXS = 70000;

struct loc
{
	int row, col, dis;

	loc(int r, int c, int d)
	{
		row = r, col = c, dis = d;
	}
};

int N, R, C;

char grid[MAXG][MAXG];
int group[MAXG][MAXG];

int tdist[MAXG][MAXG];
int dist[MAXN][MAXN];
queue <loc> q;

int best[MAXN][MAXS];
int masks[MAXS];
int msize;

int ans;

inline bool comp(int a, int b)
{
	return __builtin_popcount(a) < __builtin_popcount(b);
}

void floodfill(int r, int c)
{
	group[r][c] = N;

	for (int k = 0; k < 4; k++)
	{
		int nr = r + dr[k];
		int nc = c + dc[k];

		if (grid[nr][nc] == 'X' && group[nr][nc] == -1)

			floodfill(nr, nc);
	}
}

void solveislands()
{
	memset(group, -1, sizeof (group));

	N = 0;

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			if (grid[i][j] == 'X' && group[i][j] == -1)
			{
				floodfill(i, j);
				N++;
			}
}

void solvedist()
{
	memset(dist, 63, sizeof (dist));

	for (int i = 0; i < N; i++)
	{
		int ir = -1, ic = -1;
		bool found = false;

		for (int r = 1; r <= R && !found; r++)
			for (int c = 1; c <= C && !found; c++)
				if (group[r][c] == i)
				{
					ir = r, ic = c;
					found = true;
				}


		memset(tdist, 63, sizeof (tdist));

		q.push(loc(ir, ic, 0));
		tdist[ir][ic] = 0;


		while (!q.empty())
		{
			loc top = q.front();
			q.pop();


			if (group[top.row][top.col] != -1)
			{
				if (top.dis < dist[i][group[top.row][top.col]])
					dist[i][group[top.row][top.col]] = top.dis;
			}

			for (int k = 0; k < 4; k++)
			{
				int nr = top.row + dr[k];
				int nc = top.col + dc[k];

				if (grid[nr][nc] == 'X')
				{
					if (top.dis < tdist[nr][nc])
					{
						tdist[nr][nc] = top.dis;
						q.push(loc(nr, nc, top.dis));
					}
				}
				else if (grid[nr][nc] == 'S')
				{
					if (top.dis + 1 < tdist[nr][nc])
					{
						tdist[nr][nc] = top.dis + 1;
						q.push(loc(nr, nc, top.dis + 1));
					}
				}
			}
		}
	}
}

void solvetsp()
{
	memset(best, 63, sizeof (best));

	for (int i = 0; i < N; i++)
		best[i][1 << i] = 0;


	msize = 0;

	for (int m = 1; m < (1 << N); m++)
		masks[msize++] = m;

	sort(masks, masks + msize, comp);


	for (int ind = 0; ind < msize; ind++)
	{
		int m = masks[ind];

		for (int i = 0; i < N; i++)
			if (best[i][m] < INF)
			{
				for (int j = 0; j < N; j++)
					if (best[i][m] + dist[i][j] < best[j][m | (1 << j)])
						best[j][m | (1 << j)] = best[i][m] + dist[i][j];
			}
	}


	ans = INF;

	for (int i = 0; i < N; i++)
		if (best[i][(1 << N) - 1] < ans)
			ans = best[i][(1 << N) - 1];
}

int main()
{
	memset(grid, '.', sizeof (grid));

	fscanf(fin, "%d %d", &R, &C);

	for (int i = 1; i <= R; i++)
		fscanf(fin, "%s", &grid[i][1]);


	solveislands();

	solvedist();

	solvetsp();


	fprintf(fout, "%d\n", (ans < INF) ? ans : -1);

	return 0;
}