#include <iostream>
#include<vector>
using namespace std;
#define inf 10009
#define qq 99999999
int sgt[4 * inf] = { 0 };
int dis[inf];
bool vis[inf];
vector<pair<int, int> >adj[inf];
void build(int node, int l, int r)
{
	if (l == r)
	{
		sgt[node] = l;
		return;
	}
	build(node * 2, l, (l + r) / 2);
	build(node * 2 + 1, (l + r) / 2 + 1, r);
	if (dis[sgt[node * 2]] < dis[sgt[node * 2 + 1]])
		sgt[node] = sgt[node * 2];
	else
		sgt[node] = sgt[node * 2 + 1];
}
void update(int node, int l, int r, int t)
{
	if (r<t || l>t)return;
	if (l == r)
	{
		return;
	}
	update(node * 2, l, (l + r) / 2, t);
	update(node * 2 + 1, (l + r) / 2 + 1, r, t);
	if (dis[sgt[node * 2]] < dis[sgt[node * 2 + 1]])
		sgt[node] = sgt[node * 2];
	else
		sgt[node] = sgt[node * 2 + 1];
}
int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int t, n = 0, m, st, end, nv;
	int  a, b, c;
	cin >> t;
	for (int w = 0; w < t; ++w)
	{
		for (int i = 0; i < n; ++i)
		{
			adj[i].clear();
			vis[i] = false;
		}
		nv = 1;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			dis[i] = qq;
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b >> c;
			--a, --b;
			adj[a].push_back(make_pair(b, c));
		}
		build(1, 0, n - 1);
		cin >> st >> end;
		--st, --end;
		dis[st] = 0;
		while (nv < n && st != end){
			vis[st] = true;
			for (int i = 0; i < adj[st].size(); ++i)
			{
				if (!vis[adj[st][i].first] && dis[st] + adj[st][i].second < dis[adj[st][i].first])
				{
					dis[adj[st][i].first] = dis[st] + adj[st][i].second;
					update(1, 0, n - 1, adj[st][i].first);
				}
			}
			dis[st] = qq;
			update(1, 0, n - 1, st);
			st = sgt[1];
			++nv;
		}
		if (st == end && dis[st] != qq)
			cout << dis[st] << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}