#include <iostream>
#include <vector>
using namespace std;
#define MAX 1009
int adj [MAX][MAX];
int n;
bool vis[MAX];
int dis[MAX];
int main()
{
	int sum=0;
	cin>>n;
	int s,e;
	cin>>s>>e;
	for (int i=0;i<n;++i){
		dis[i]=99999999;
		for (int j=0;j<n;++j)
		{
			cin>>adj[i][j];
		}
	}

	dis[s]=0;
	while (s!=e)
	{
		vis[s]=true;
		for (int i=0;i<n;++i)
		{
			if (!vis[i]&& dis[s]+adj[s][i]<dis[i])
				dis[i]=dis[s]+adj[s][i];
		}
		s=-1;
		for (int i=0;i<n;++i)
			if (!vis[i] && (s==-1||dis[i]<dis[s]))
				s=i;
	}
	cout<<dis[s]<<endl;
}

