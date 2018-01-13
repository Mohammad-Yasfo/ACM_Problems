#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct edge
{
	int f,t,cost;
};
bool operator<(edge m1,edge m2)
{
	return m1.cost<m2.cost;
}
vector <edge> edges;
vector <int> adj[100009];
int intree[100009];
int n,m;
bool trans(int a,int b)
{
	int c;
	if (adj[a].size()<adj[b].size())
	{
		while (!adj [a].empty())
		{
			c=adj[a].back();
			intree[c]=b;
			adj[b].push_back(c);
			adj[a].pop_back();
		}
		if (adj[b].size()==n)
			return true;
	}
	else
	{
		while (!adj [b].empty())
		{
			c=adj[b].back();
			intree[c]=a;
			adj[a].push_back(c);
			adj[b].pop_back();
		}
		if (adj[a].size()==n)
			return true;
	}
	return false;
}
int main()
{

	cin>>n>>m;
	int a,b,v;
	for (int i=0;i<n;++i)
	{
		intree[i]=i;
		adj[i].push_back(i);
	}
	for (int i=0;i<m;++i)
	{
		cin>>a>>b>>v;
		--a,--b;
		edge e;
		e.f=a;
		e.t=b;
		e.cost=v;
		edges.push_back(e);
	}
	sort(edges.begin(),edges.begin()+edges.size());
	int sum=0;
	for (int i=0;i<m;++i)
	{
		if (intree[edges[i].f]!=intree[edges[i].t])
		{
			sum+=edges[i].cost;
			trans(intree[edges[i].f],intree[edges[i].t]);
		}
	}
	cout<<sum<<endl;
	return 0;
}
