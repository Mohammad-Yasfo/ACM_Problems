#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define mx 100009
#define inf 9999999
vector<pair<int, int> >adj[inf];
long long dis[inf];
bool vis[inf];
#define des adj[st][i].first
#define descost adj[st][i].second
int main()
{
	int n, m, a, b, c;
	set<pair<int, int> >low;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		--a, --b;
		adj[a].push_back(make_pair(b, c));
		//adj[b].push_back(make_pair(a, c)); put it if the road is undirected
	}
	int nv = 1, st = 0, cost;
	long long sum = 0;
	pair<int, int>q;
	low.insert(make_pair(st, 0));
	while (nv < n)
	{
		q = *low.begin();
		st = q.first;
		cost = q.second;
		low.erase(low.begin());
		for (int i = 0; i < adj[st].size(); ++i)
		{
			if (dis[des]> descost)
				if (dis[des] != inf)
					low.erase(low.find(make_pair(des, dis[des])));
			low.insert(make_pair(st, descost));
		}
		sum += (*low.begin()).second;
		++nv;
	}
	cout << sum << endl;
	return 0;
}