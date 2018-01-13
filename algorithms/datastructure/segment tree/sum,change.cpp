#include <iostream>
using namespace std;
#define max 100006
int sgt[max*4];
int a[max];
int lzy[max*4];
void build(int node,int l,int r)
{
	lzy[node]=0;
	if (l==r)
	{
		sgt[node]=a[l];
		return;
	}
	build(2*node,l,(r+l)/2);
	build(2*node+1,(l+r)/2+1,r);
	sgt[node]=sgt[node*2]+sgt[2*node+1];
}
void lazy_update(int node,int l,int r)
{
	if (l==r)
	{
		sgt[node]+=lzy[node];
		return;
	}
	sgt[node]+=(r-l+1)*lzy[node];
	lzy[2*node]+=lzy[node];
	lzy[2*node+1]+=lzy[node];
	lzy[node]=0;
}
void update(int node,int l,int r,int s,int e,int val)
{
	lazy_update(node,l,r);	
	if (r<s || e<l)return;
	if (s<=l && e>=r)
	{
		lzy[node]+=val;
		lazy_update(node,l,r);
		return;
	}
	update(2*node,l,(r+l)/2,s,e,val);
	update(2*node+1,(l+r)/2+1,r,s,e,val);
	sgt[node]=sgt[2*node]+sgt[2*node+1];
}
int query(int node,int l,int r,int s,int e)
{
	lazy_update(node,l,r);
	if (r<s || e<l)return 0;
	if (s<=l && e>=r)
	{
		return sgt[node];
	}
	int a=query(2*node,l,(r+l)/2,s,e);
	int b=query(2*node+1,(l+r)/2+1,r,s,e);
	return a+b;
}
int main()
{
	int a_,b,q,v,n,m;
	cin>>n>>m;
	for (int i=0;i<n;++i)
		cin>>a[i];
	build(1,0,n-1);
	for (int i=0;i<m;++i)
	{
		cin>>q;
		if (q==0)
		{
			cin>>a_>>b;
			cout<<query(1,0,n-1,a_-1,b-1)<<endl;
		}
		else
		{
			cin>>a_>>b>>v;
			update(1,0,n-1,a_-1,b-1,v);
		}
	}
	return 0;
}