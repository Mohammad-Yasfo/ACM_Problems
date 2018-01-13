#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 100006
#define selmod 3
struct point
{
	int *num_mod_by_num;
};
int a[MAX];
int lzy [4*MAX];
point sgt [4*MAX];
void build(int node,int l,int r)
{
	sgt[node].num_mod_by_num=new int [selmod];
	for (int i=0;i<selmod;++i)
		sgt[node].num_mod_by_num[i]=0;
	if (l==r)
	{
		sgt[node].num_mod_by_num[a[l]%selmod]++;
		return;
	}
	build(2*node,l,(r+l)/2);
	build(2*node+1,(r+l)/2+1,r);
	for (int i=0;i<selmod;++i)
		sgt[node].num_mod_by_num[i]=sgt[2*node].num_mod_by_num[i]+sgt[node*2+1].num_mod_by_num[i];
}
void lzy_update(int node,int l,int r)
{
	if (lzy[node]==0)
		return;
	lzy[node]%=3;
	int selected_index=(0+lzy[node]+selmod)%selmod;
	int selected=sgt[node].num_mod_by_num[selected_index];
	for (int i=0;i<selmod;++i)
	{
		if (i==selected_index)
			sgt[node].num_mod_by_num[(i+lzy[node]+selmod)%selmod]=selected;
		else
			sgt[node].num_mod_by_num[(i+lzy[node]+selmod)%selmod]=sgt[node].num_mod_by_num[i];
	}
	if (l!=r)
	{
		lzy[2*node]+=lzy[node];
		lzy[2*node+1]+=lzy[node];
	}
	lzy[node]=0;
}
void update(int node,int l,int r,int s,int e,int val)
{
	lzy_update(node,l,r);
	if (s>r || e<l)return;
	if (l>=s && r<=e)
	{
		lzy[node]+=val;
		lzy_update(node,l,r);
		return;
	}
	update(node*2,l,(l+r)/2,s,e,val);
	update(node*2+1,(r+l)/2+1,r,s,e,val);
	for (int i=0;i<selmod;++i)
		sgt[node].num_mod_by_num[i]=sgt[2*node].num_mod_by_num[i]+sgt[node*2+1].num_mod_by_num[i];
}
int query(int node,int l,int r,int s,int e)
{
	lzy_update(node,l,r);
	if (s>r || e<l)return 0;
	if (l>=s && r<=e)
		return sgt[node].num_mod_by_num[0];
	int a=query(node*2,l,(l+r)/2,s,e);
	int b=query(node*2+1,(l+r)/2+1,r,s,e);
	return a+b;
}
int main() {
int n,m,l1,l2,val,q;
cin>>n>>m;
for (int i=0;i<n;++i)
	cin>>a[i];
build(1,0,n-1);
for (int i=0;i<m;++i)
{
	cin>>q;
	if (q==0)
	{
		cin>>l1>>l2;
		cout<<query(1,0,n-1,l1-1,l2-1)<<endl;
	}
	else
	{
		cin>>l1>>l2>>val;
		update(1,0,n-1,l1-1,l2-1,val);
	}
}
}
