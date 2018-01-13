/*
العطلة
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int>adj[50009];
bool vis[50009] = { false };
int sol = 0;
void dfs(int node, int p)
{
	for (int i = 0; i < adj[node].size(); ++i)
		if (adj[node][i] != p)
		{
			dfs(adj[node][i], node);
		}
	if (!vis[node])
	{
		++sol;
		vis[p] = true;
	}
}
int main()
{
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		scanf_s("%d%d", &a, &b);
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, 0);
	printf("%d\n", sol);
	return 0;
}