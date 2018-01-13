/*
 هي: الدخل شجرة rooted و ال root هو العقدة 1 المطلوب من اجل كل عقدة بالشجرة توجد كم عقدة يوجد بال subtree لهي العقدة
N<=100000
يعني كل العقد الي هية ابناء او احفاد او احفاد احفاد الخ
*/
#include <iostream>
#include <vector>
using namespace std;
struct point
{
	int n;
	int n_child;
	point **child;
	point()
	{
		n_child=0;
		child=new point*[100000];
	}
};
point p[100000];
int dfs(int node,int par)
{
	int sum=1;
	for (int i=0;i<p[node].n_child;++i)
		if (p[node].child[i]->n!=par)
			sum+=dfs(p[node].child[i]->n,node);
	p[node].n_child=sum;
	return sum;
}
int main()
{
	int n,a,b;

	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>a>>b;
		p[a].n=a;
		p[b].n=b;
		p[a].child[p[a].n_child++]=&p[b];
		p[b].child[p[b].n_child++]=&p[a];
	}
	dfs(0,-1);

	return 0;
}
