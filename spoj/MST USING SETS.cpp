#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define inf 100009
#define qq 99999999
#define sel adj[st][i].first
#define selcst adj[st][i].second
int main()
{
	int n, m, a, b, c, st;
	long long sol = 0;
	vector<pair<int, int > > adj[inf];
	set<pair<int, int > > low;
	bool vis[inf] = { false };
	int dis[inf];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		adj[i].clear();
		vis[i] = false;
		dis[i] = qq;
	}
	low.clear();
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d", &a, &b, &c);
		--a, --b;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}		
	st = 0;
	dis[st] = 0;
	low.insert(make_pair(0, st));
	while (!low.empty())
	{
		st = (*low.begin()).second;
		vis[st] = true;
		low.erase(low.begin());
		sol += dis[st];
		for (int i = 0; i < adj[st].size(); ++i)
		{
			if (!vis[sel] && selcst < dis[sel])
			{
				if (dis[sel] != qq)
					low.erase(low.find(make_pair(dis[sel], sel)));
				low.insert(make_pair(selcst, sel));
				dis[sel] =selcst;
 
			}
		}
	}
	cout << sol << endl;
	return 0;
}