#include <fstream>
#include <set>
using namespace std;
struct nod
{
	char c;
	int t;
	bool vis;
	int dis;
};
#define inf 999999
int nis = 0;
nod map[53][53];
int R, C;
set<pair<int, pair<int, int> > > low;
#define le map[i][j-1]
#define ri map[i][j+1]
#define up map[i-1][j]
#define dn map[i+1][j]
#define sel map[i][j]
#define jlast last.second
#define ilast last.first
#define lelast map [ilast][jlast-1]
#define rilast map[ilast][jlast+1]
#define uplast map[ilast-1][jlast]
#define dnlast map[ilast+1][jlast]
void dfs(int i, int j)
{
	sel.vis = true;
	sel.t = nis;
	if (j > 0 && !le.vis&& le.c == 'X')
		dfs(i, j - 1);
	if (i > 0 && !up.vis&&up.c == 'X')
		dfs(i - 1, j);
	if (i < R - 1 && !dn.vis &&dn.c == 'X')
		dfs(i + 1, j);
	if (j < C - 1 && !ri.vis&&ri.c == 'X')
		dfs(i, j + 1);
}
void change_dis(int i, int j, int cost)
{
	if (sel.dis>cost)
	{
		if (sel.dis != inf)
			low.erase(low.find(make_pair(sel.dis, make_pair(i, j))));
		low.insert(make_pair(cost, make_pair(i, j)));
		sel.dis = cost;
	}
}
void reset()
{
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			sel.vis = false, sel.dis = inf;
}
int main()
{
	ifstream fin("island.in");
	ofstream fout("island.out");
	fin >> R >> C;
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
		{
			fin >> map[i][j].c;
			sel.vis = false;
			sel.dis = inf;
		}
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
		{
			if (sel.vis || sel.c != 'X')
				continue;
			dfs(i, j);
			++nis;
		}
	bool visis[16] = { false };
	int	num[15][15];
	for (int i = 0; i < 15; ++i)
		for (int j = 0; j < 15; ++j)
			num[i][j] = inf;

	pair<int, int>last;
	int cost, selis;
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j){
			reset();
			if (sel.vis || sel.c != 'X' || visis[sel.t])continue;
			visis[sel.t] = true;
			num[sel.t][sel.t] = 0;
			selis = sel.t;
			low.clear();
			low.insert(make_pair(0, make_pair(i, j)));
			while (!low.empty())
			{
				cost = (*low.begin()).first;
				last = (*low.begin()).second;
				low.erase(low.begin());
				map[ilast][jlast].vis = true;
				if (jlast > 0 && !lelast.vis&& lelast.c == 'X')
					change_dis(ilast, jlast - 1, cost);
				if (jlast > 0 && !lelast.vis&& lelast.c == 'S')
					change_dis(ilast, jlast - 1, cost + 1);
				if (ilast > 0 && !uplast.vis&&uplast.c == 'X')
					change_dis(ilast - 1, jlast, cost);
				if (ilast > 0 && !uplast.vis&&uplast.c == 'S')
					change_dis(ilast - 1, jlast, cost + 1);
				if (ilast < R - 1 && !dnlast.vis &&dnlast.c == 'X')
					change_dis(ilast + 1, jlast, cost);
				if (ilast < R - 1 && !dnlast.vis &&dnlast.c == 'S')
					change_dis(ilast + 1, jlast, cost + 1);
				if (jlast < C - 1 && !rilast.vis&&rilast.c == 'X')
					change_dis(ilast, jlast + 1, cost);
				if (jlast < C - 1 && !rilast.vis&&rilast.c == 'S')
					change_dis(ilast, jlast + 1, cost + 1);
			}
			for (int i = 0; i < R; ++i)
				for (int j = 0; j < C; ++j)
				{
					if (sel.c == 'X'&& sel.dis < num[selis][sel.t])
						num[selis][sel.t] = sel.dis;
				}
		}
	int mx = 1 << nis;
	int t, q, r;
	int dp[(1 << 15) + 4][15];
	for (int i = 0; i < nis; ++i)
		dp[0][i] = 0;
	for (int i = 1; i < mx; ++i)
	{
		t = i;
		q = 1;
		r = 0;
		for (int j = 0; j < nis; ++j)
			dp[i][j] = inf;
		while (t)
		{
			if (t % 2)
			{
				for (int j = 0; j < nis; ++j)
					dp[i][r] = min(dp[i][r], dp[i - q][j] + num[j][r]);
			}
			++r;
			q *= 2;
			t /= 2;
		}
	}
	int sol = inf;
	for (int i = 0; i < nis; ++i)
		sol = min(sol, dp[mx - 1][i]);
	fout << sol << endl;
	return 0;
}