#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define inf 10009
#define sel adj[st][i].first
#define selcst adj[st][i].second
int main()
{
	int n, m, a, b, c, st, end,T;
	vector<pair<int, int > > adj[inf];
	set<pair<int, int > > low;
	bool vis[inf] = { false };
	int dis[inf];
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			adj[i].clear();
			vis[i] = false;
			dis[i] = inf;
		}
		low.clear();
		for (int i = 0; i < m; ++i)
		{
			scanf("%d%d%d", &a, &b, &c);
			--a, --b;
			adj[a].push_back(make_pair(b, c));
		}
		int nv = 1;
		cin >> st >> end;
		--st, --end;
		dis[st] = 0;
		low.insert(make_pair(0, st));
		while (!low.empty())
		{
			st = (*low.begin()).second;
                             vis[st] = true;
			low.erase(low.begin());
			if (st == end)
				break;
			for (int i = 0; i < adj[st].size(); ++i)
			{
				if (!vis[sel] && selcst + dis[st] < dis[sel])
				{
					if (dis[sel] != inf)
						low.erase(low.find(make_pair(dis[sel], sel)));
					low.insert(make_pair(selcst + dis[st], sel));
					dis[sel] = dis[st] + selcst;

				}
			}
		}
		if (st == end && dis[st] != inf)
			printf("%d\n", dis[st]);
		else
			printf("NO\n");
	}
	return 0;
}