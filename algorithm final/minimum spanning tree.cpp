#include <iostream>
#include <vector>
using namespace std;
#define MAX 100009
struct nod
{
	long long v;
	long long cost;
};
struct nodes
{
	int m;
	int index;
};
vector<nod> adj [MAX];
int n;
bool vis[MAX];
int dis[MAX];
nodes sgt[4*MAX];
void build (int node,int l,int r)
{
	if (l==r)
	{
		sgt[node].m=dis[l];
		sgt[node].index=l;
		return;
	}
	build (node*2,l,(r+l)/2);
	build (node*2+1,(r+l)/2+1,r);
	sgt[node]= sgt[node*2].m<sgt[node*2+1].m?sgt[node*2]:sgt[node*2+1];
}
int query()
{
	return sgt[1].index;
}
void update(int node,int l,int r,int s,int val)
{
	if (r<s || l>s)return;
	if (l==r && r==s)
	{
		sgt[node].m=val;
		return;
	}
	update(node*2,l,(r+l)/2,s,val);
	update(node*2+1,(r+l)/2+1,r,s,val);
	sgt[node]= sgt[node*2].m<sgt[node*2+1].m?sgt[node*2]:sgt[node*2+1];
}
int main()
{
	long long sum=0,m,a,b,c;
	cin>>n>>m;
	int nv=0;
	for (int i=0;i<n;++i)
		dis[i]=99999999;
	for (int j=0;j<m;++j)
	{
		cin>>a>>b>>c;
		--a,--b;
		nod q1,q2;
		q1.v=b;
		q1.cost=c;
		q2.v=a;
		q2.cost=c;
		adj[a].push_back(q1);
		adj[b].push_back(q2);
	}
	build(1,0,n-1);
	int s=0;
	dis[s]=0;
	update(1,0,n-1,0,99999999);
	while (nv<n)
	{
		vis[s]=true;
		for (int i=0;i<adj[s].size();++i)
		{
			if (!vis[adj[s][i].v]&& adj[s][i].cost<dis[adj[s][i].v]){
				dis[adj[s][i].v]=adj[s][i].cost;
				update(1,0,n-1,i,dis[adj[s][i].cost]);
			}
		}
		s=query();
		update(1,0,n-1,s,99999999);
		sum+=dis[s];
		++nv;
	}
	cout<<sum<<endl;
	return 0;
}

