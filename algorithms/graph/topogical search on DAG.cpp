#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10005
#define infinite 99999999
struct edge
{
	int to;
	int dis;
};
int main()
{
	ifstream fin("dag.in");
	ofstream fout("dag.out");
	vector<edge> adj [MAX];
	int	num_node [MAX]={0};
	int sum[MAX];
	queue<int>zero_indgree;
	int n,m,a,b,c,start,end;
	fin>>n>>m;
	for (int i=0;i<m;++i)
	{
		fin>>a>>b>>c;
		edge e;
		e.to=b-1;
		e.dis=c;
		adj[a-1].push_back(e);
		++num_node[b-1];
	}
	for (int i=0;i<n;++i)
	{
		sum [i]=infinite;
		if (num_node [i]==0)
			zero_indgree.push(i);
	}
	fin>>start>>end;
	sum [--start]=0;
	--end;
	while (!zero_indgree.empty())
	{
		a=zero_indgree.front();
		b=adj[a].size();
		for (int i=0;i<b;++i)
		{
			c=adj[a][i].to;
			if (sum[c]>sum[a]+adj[a][i].dis)
				sum[c]=sum[a]+adj[a][i].dis;
			num_node[c]--;
			if (num_node[c]==0){
				if (c==end)
				{
					fout<<sum[c]<<endl;
					return 0;
				}
				zero_indgree.push(c);
			}
		}
		zero_indgree.pop();
	}
	return 0;
}
