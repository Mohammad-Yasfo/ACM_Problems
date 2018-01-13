#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct nod
{
	int fl;
	int fr;
	int n;
};
#define MAX 1000009
string a;
nod sgt[4*MAX];
void build (int node,int l,int r)
{
	if (l==r)
	{
		if (a[l]=='(')
		{
			sgt[node].fl=0;
			sgt[node].fr=1;
		}
		else
		{
			sgt[node].fl=1;
			sgt[node].fr=0;
		}
		sgt[node].n=0;
		return;
	}
	build (node*2,l,(l+r)/2);
	build(node*2+1,(l+r)/2+1,r);
	sgt[node].fl=sgt[node*2].fl+max(sgt[node*2+1].fl-sgt[node*2].fr,0);
	sgt[node].fr=sgt[node*2+1].fr+max(sgt[node*2].fr-sgt[node*2+1].fl,0);
	sgt[node].n=sgt[node*2].n+sgt[node*2+1].n+min(sgt[node*2].fr,sgt[node*2+1].fl);
}
nod query(int node,int l,int r,int s,int e)
{
	if (s<=l && e>=r)
		return sgt[node];
	if (l>e || (r+l)/2<s)
		return query(node*2+1,(l+r)/2+1,r,s,e);
	if ((l+r)/2+1>e || r<s)
		return query(node*2,l,(l+r)/2,s,e);
	nod a=query(node*2,l,(l+r)/2,s,e);
	nod b=query(node*2+1,(l+r)/2+1,r,s,e);
	nod c;
	c.fl=a.fl+max(b.fl-a.fr,0);
	c.fr=b.fr+max(a.fr-b.fl,0);
	c.n=a.n+b.n+min(a.fr,b.fl);
	return c;
}
int main()
{
	cin>>a;
	int n=a.length();
	build(1,0,n-1);
	int m,f,l;
	cin>>m;
	for (int i=0;i<m;++i)
	{
		cin>>f>>l;
		cout<<query(1,0,n-1,f-1,l-1).n*2<<endl;
	}
	return 0;
}
