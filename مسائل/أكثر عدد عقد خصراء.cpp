#include <iostream>
#include <vector>
using namespace std;
int n;
#define inf 10009
vector<int> adj[inf];
bool vis[inf] = { false };
int sum = 0;
void dfs(int node, int p)
{
	for (int i = 0; i < adj[node].size(); ++i)
		if (adj[node][i] != p)
			dfs(adj[node][i], node);
	if (!vis[node] && !vis[p]){
		++sum;
		vis[p] = true;
	}
}
int main()
{

	cin >> n;
	int a, b;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> a >> b;
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, 0);
	cout << sum << endl;
	return 0;
}