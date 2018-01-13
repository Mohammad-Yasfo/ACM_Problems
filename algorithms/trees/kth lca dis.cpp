#include <iostream>
#include <vector>
using namespace std;
struct node
{
	int n;
	int cost;
};
vector < node >adj[100009];
int level[100009];
int costs [100009];
int dp[100009][20];
int n;
void dfs(int n, int p,int l,int cost)
{
	dp[n][0] = p;
	level[n]=l;
	costs[n]=cost;
	for (int i = 0; i < adj[n].size(); ++i)
		if (adj[n][i].n!=p)
			dfs(adj[n][i].n, n,l+1,cost+adj[n][i].cost);
}

void build()
{
	for (int j = 1; j < 20; ++j)
		for (int i = 0; i <= n; ++i)
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
}
int get_p(int i,int k)
{
int num=0;
while(k>0)
{
if(k%2)
i=dp[i][num];
num++;
k/=2;
}
return i;
}
int lca(int a,int b)
{
	if (level[a]!=level[b])
	{
		if (level[a]>level [b])
			a=get_p(a,level[a]-level[b]);
		else
			b=get_p(b,level[b]-level[a]);
	}
	if (a==b)
		return a;
	int p=20,s,e;
	while (p--)
	{
		if (dp[a][p]!=dp[b][p])
			a=dp[a][p],b=dp[b][p];
	}
	if (a!=b)
		return dp[a][0];
}
int get_dis(int a,int b)
{
	int c=lca(a,b);
	return costs[a]+costs[b]-2*costs[c];
}
int main()
{
	int a, b,c, r,m;
	cin >> n >>m>> r;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b >> c;
		a--, b--;
		node n1,n2;
		n1.n=a;
		n1.cost=c;
		n2.n=b;
		n2.cost=c;
		adj[a].push_back(n2);
		adj[b].push_back(n1);
	}
	dfs(0, 0,1,0);
	build();
	for(int i=0;i<m;++i)
	{
	cin>>a>>b;
	cout<<get_dis(a-1,b-1)<<endl;
	}
}
