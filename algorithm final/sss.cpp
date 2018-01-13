#include <iostream>
using namespace std;
#define MAX 100009
struct nod
{
	int n;
	int pn;
};
int a[MAX];
nod sgt[MAX*4];
int lzy[MAX*4];
void build (int node,int l,int r)
{
	lzy[node]=0;
	if (l==r)
	{
		sgt[node].n=a[l];
		sgt[node].pn=a[l]*a[l];
		return;
	}
	build(2*node,l,(r+l)/2);
	build(2*node+1,(l+r)/2+1,r);
	sgt[node].n=sgt[node*2].n+sgt[node*2+1].n;
	sgt[node].pn=sgt[node*2].pn+sgt[node*2+1].pn;
}
void lazy_update(int node,int l,int r)
{
	int n=r-l+1;
	sgt[node].pn+=n*lzy[node]*lzy[node]+2*sgt[node].n*lzy[node];
	sgt[node].n+=n*lzy[node];
	if (l!=r)
	{
		lzy[node*2]+=lzy[node];
		lzy[node*2+1]+=lzy[node];
	}
	lzy[node]=0;
}
void update(int node,int l,int r,int s,int e,int val)
{
	if (r<s || l>e)return;
	lazy_update(node,l,r);
	if (s<=l && e>=r)
	{
		lzy[node]+=val;
		lazy_update(node,l,r);
		return;
	}
	update(2*node,l,(r+l)/2,s,e,val);
	update(2*node+1,(l+r)/2+1,r,s,e,val);
	sgt[node].n=sgt[node*2].n+sgt[node*2+1].n;
	sgt[node].pn=sgt[node*2].pn+sgt[node*2+1].pn;
}
int query(int node,int l,int r,int s,int e)
{
	if (r<s || l>e)return 0;
	lazy_update(node,l,r);
	if (s<=l && e>=r)
		return sgt[node].pn;
	int a=query(2*node,l,(r+l)/2,s,e);
	int b=query(2*node+1,(l+r)/2+1,r,s,e);
	return a+b;
}
int main()
{
	int n,m,f,l,v,q;
	cin>>n>>m;
	for (int i=0;i<n;++i)
		cin>>a[i];
	build(1,0,n-1);
	for (int i=0;i<m;++i)
	{
		cin>>q;
		cin>>f>>l;
		if (q==0)
		{
			cout<<query(1,0,n-1,f-1,l-1)<<endl;
		}
		else
		{
			cin>>v;
			update(1,0,n-1,f-1,l-1,v);
		}
			
	}

	return 0;
}
