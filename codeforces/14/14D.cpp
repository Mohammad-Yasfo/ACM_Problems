#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[209];
#define max(a,b) (a)>(b)?(a):(b)
int maxs = 0, ind;
void dfs(int t, int pa, int lev)
{
	if (maxs < lev)
	{
		maxs = lev;
		ind = t;
	}
	for (int i = 0; i < adj[t].size(); ++i)
	if (adj[t][i] != pa)
		dfs(adj[t][i], t, lev + 1);
}
int main()
{
	int n, a, b;
	pair<int, int> edges[209];
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> a >> b;
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		edges[i] = make_pair(a, b);
	}
	int maxpru = 0, f, l, m1, m2;
	for (int i = 0; i < n - 1; ++i)
	{
		m1 = edges[i].first;
		m2 = edges[i].second;
		for (int j = 0; j < adj[m1].size(); ++j)
		if (adj[m1][j] == m2)
		{
			adj[m1].erase(adj[m1].begin() + j);
			break;
		}
		for (int j = 0; j < adj[m2].size(); ++j)
		if (adj[m2][j] == m1)
		{
			adj[m2].erase(adj[m2].begin() + j);
			break;
		}
		maxs = 0;
		dfs(m1, -1, 0);
		if (maxs != 0)
		{

			maxs = 0;
			dfs(ind, -1, 0);
		}
		f = maxs;
		maxs = 0;
		dfs(m2, -1, 0);
		if (maxs != 0){
			maxs = 0;
			dfs(ind, -1, 0);
		}
		l = maxs;
		if (maxpru < f*l)
			maxpru = f*l;
		adj[m1].push_back(m2);
		adj[m2].push_back(m1);
	}
	cout << maxpru << endl;
	return 0;
}