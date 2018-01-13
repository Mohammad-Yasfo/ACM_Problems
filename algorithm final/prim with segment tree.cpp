#include <iostream>
#include <vector>
using namespace std;
#define MAX 100009
struct nod
{
	int v;
	int cost;
};
vector<nod> adj [MAX];
int n;
bool vis[MAX];
int dis[MAX];
int sgt[4*MAX];
void build (int node,int l,int r)
{
	if (l==r)
	{
		sgt[node]=dis[l];
		return;
	}
	build (node*2,l,(r+l)/2);
	build (node*2+1,(r+l)/2+1,r);
	sgt[node]=min(sgt[node*2],sgt[node*2+1]);
}
int query()
{
	return sgt[1];
}
void update(int node,int l,int r,int s,int val)
{
	if (r<s || l>s)return;
	if (l==r && r==s)
	{
		sgt[node]=val;
		return;
	}
	update(node*2,l,(r+l)/2+1,s,val);
	update(node*2+1,(r+l)/2+1,r,s,val);
	sgt[node]=min(sgt[node*2],sgt[node*2+1]);
}
int main()
{
	int sum=0,m,a,c;
	cin>>n;
	int s,e;
	cin>>s>>e;
	for (int i=0;i<n;++i){
		dis[i]=99999999;
		cin>>m;
		for (int j=0;j<m;++j)
		{
			cin>>a>>c;
			nod q;
			q.v=a-1;
			q.cost=c;
			adj[i].push_back(q);
		}
	}

	dis[0]=0;
	while (s!=e)
	{
		vis[s]=true;
		for (int i=0;i<adj[s].size();++i)
		{
			if (!vis[adj[s][i].v]&& adj[s][i].cost<dis[adj[s][i].v]){
				dis[adj[s][i].v]=adj[s][i].cost;
				update(1,0,n-1,i,dis[i]);
			}
		}
		s=query();
		update(1,0,n-1,s,99999999);
		sum+=dis[s];
	}
	cout<<sum<<endl;
}

