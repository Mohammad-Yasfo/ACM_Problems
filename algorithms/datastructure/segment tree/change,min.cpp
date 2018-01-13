#include <fstream>
#include <random>
using namespace std;
int main()
{
	ofstream fout ("file.in");
	const int MAX=100000;
	for (int i=0;i<MAX;++i)
		fout<<rand()*5+i<<endl;
	for (int i=0;i<MAX;++i)
	{
		int g=rand()%2;
		fout<<g<<" ";
		if (g==0)
		{
			fout<<rand()%MAX<<" "<<(((rand()+5)*2)%MAX)/2+rand()<<endl;
		}
		else
			fout<<rand()%MAX<<" "<<((rand()*7)/3+2)%MAX<<" "<<rand()*3/4<<endl;
	}
	return 0;
}
/*int a[100003];
int sgt[400003];
int lzy[400003];
//pair<int,int> b[100004];
void build(int node,int l,int r){
	lzy[node]=0;
	if(l==r){
		sgt[node]=a[l];
		return;
	}
	build(2*node,l,(r+l)/2);
	build(2*node+1,(r+l)/2+1,r);
	sgt[node]=min(sgt[2*node],sgt[2*node+1]);
}
void lazy_update(int node,int l,int r){
	sgt[node]+=lzy[node];
	if(l!=r){
		lzy[2*node]+=lzy[node];
		lzy[2*node+1]+=lzy[node];
	}
	lzy[node]=0;
}
int query(int node,int l,int r,int s,int e){
	lazy_update(node,l,r);
	if(l>e || r<s)return 1000000000;
	if(s<=l && r<=e){
		return sgt[node];
	}
	int a=query(2*node,l,(r+l)/2,s,e);
	int b=query(2*node+1,(r+l)/2+1,r,s,e);
	return min(a,b);
}
void update(int node,int l,int r,int s,int e,int val){
	lazy_update(node,l,r);
	if(l>e || r<s)return;
	if(s<=l && r<=e){
		lzy[node]+=val;
		lazy_update(node,l,r);
		return;
	}
	update(2*node,l,(r+l)/2,s,e,val);
	update(2*node+1,(r+l)/2+1,r,s,e,val);
	sgt[node]=min(sgt[2*node],sgt[2*node+1]);
}
int n,m;
int main(){
	/*cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i].first>>b[i].second;
		b[i].first--;
		b[i].second--;
	}
	sort(b,b+m);*
	ifstream fin("file.in");
	ofstream fout("file.out");
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>a[i];
	}
	build(1,0,n-1);
	fin>>m;
	int a,b,c,d;
	for(int u=0;u<m;u++){
		fin>>a;
		if(a==0){
			fin>>b>>c;
			fout<<query(1,0,n-1,b-1,c-1)<<endl;
		} else {
			fin>>b>>c>>d;
			update(1,0,n-1,b-1,c-1,d);
		}
	}
}*/