#include <iostream>
#include <queue>
using namespace std;
int H, W;
char map[53][53];
int vis[53][53];
int length[53][53] = { 0 };
#define max(a,b) (a)>(b)?(a):(b)
int bfs(int i, int j)
{
	queue < pair<int, int> >r;
	r.push(make_pair(i, j));
	length[i][j] = 1;
	int s = 0;
	while (!r.empty())
	{
		i = r.front().first, j = r.front().second;
		r.pop();
		++vis[i][j];
		if (i + 1 < H &&  vis[i + 1][j] < 8 && map[i][j] == map[i + 1][j] - 1)
		{
			r.push(make_pair(i + 1, j));
			length[i + 1][j] = max(length[i + 1][j], length[i][j] + 1);
		}
		if (j + 1 < W &&  vis[i][j + 1] < 8 && map[i][j] == map[i][j + 1] - 1)
		{
			r.push(make_pair(i, j + 1));
			length[i][j + 1] = max(length[i][j + 1], length[i][j] + 1);
		}
		if (i>0 && vis[i - 1][j] < 8 && map[i][j] == map[i - 1][j] - 1)
		{
			r.push(make_pair(i - 1, j));
			length[i - 1][j] = max(length[i - 1][j], length[i][j] + 1);
		}
		if (j>0 && vis[i][j - 1] < 8 && map[i][j] == map[i][j - 1] - 1)
		{
			r.push(make_pair(i, j - 1));
			length[i][j - 1] = max(length[i][j - 1], length[i][j] + 1);

		}
		if (i + 1 < H && j + 1 < W &&  vis[i + 1][j + 1] < 8 && map[i][j] == map[i + 1][j + 1] - 1)
		{
			r.push(make_pair(i + 1, j + 1));
			length[i + 1][j + 1] = max(length[i + 1][j + 1], length[i][j] + 1);

		}
		if (i + 1 < H && j > 0 && vis[i + 1][j - 1] < 8 && map[i][j] == map[i + 1][j - 1] - 1)
		{
			r.push(make_pair(i + 1, j - 1));
			length[i + 1][j - 1] = max(length[i + 1][j - 1], length[i][j] + 1);

		}
		if (j + 1 < W && i > 0 && vis[i - 1][j + 1] < 8 && map[i][j] == map[i - 1][j + 1] - 1)
		{
			r.push(make_pair(i - 1, j + 1));
			length[i - 1][j + 1] = max(length[i - 1][j + 1], length[i][j] + 1);

		}
		if (j>0 && i > 0 && vis[i - 1][j - 1] < 8 && map[i][j] == map[i - 1][j - 1] - 1)
		{
			r.push(make_pair(i - 1, j - 1));
			length[i - 1][j - 1] = max(length[i - 1][j - 1], length[i][j] + 1);

		}
	}
	return length[i][j];
}
int main()
{
	int sel, maxs = 0;
	int C = 1;
	while (true)
	{
		scanf_s("%d%d", &H, &W);
		if (H == 0 && W == 0)
			break;
		for (int i = 0; i < H; ++i)
			for (int j = 0; j < W; ++j)
			{
				length[i][j] = 0;
				vis[i][j] = 0;
			}
		for (int i = 0; i < H; ++i)
			for (int j = 0; j < W; ++j)
				cin >> map[i][j];
		for (int i = 0; i < H; ++i)
		{
			for (int j = 0; j < W; ++j)
			{
				if (map[i][j] == 'A')
				{
					sel = bfs(i, j);
					if (sel>maxs)
						maxs = sel;
				}
			}
		}
		printf("Case %d: ", C);
		printf("%d\n", maxs);
		++C;
	}
	return 0;
}