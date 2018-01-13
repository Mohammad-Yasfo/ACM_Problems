#include <iostream>
#include <vector>
using namespace std;
#define MAX 100009
bool vis[MAX];
vector<pair<long long, long long>> adj[MAX];
long long dis[MAX];
#define for(a) for(int i=0;i<a;++i)
#define inf 9999999999
#define min(a,b) (a)<(b)?(a):(b)
int main()
{
	long long n, m, a, b, c, sum = 0;
	cin >> n >> m;
	for (m)
	{
		cin >> a >> b >> c;
		--a, --b;
		adj[a].push_back(make_pair(b, c));
	}
	int n_v = 1;
	int s = 0;
	long long max = inf;
	for (n)
		dis[i] = inf;
	dis[s] = 0;
	while (n_v < n)
	{
		vis[s] = true;
		for (adj[s].size())
		{
			if (!vis[adj[s][i].first])
				dis[adj[s][i].first] = min(dis[adj[s][i].first], dis[s] + adj[s][i].second);
		}
		max = inf;
		for (n)
		{
			if (!vis[i]&&max > dis[i])
				s = i, max = dis[i];
		}
		sum += dis[s];
		++n_v;
	}
	cout << dis[s] << endl;
	return 0;
}