#include <iostream>
#include <vector>
using namespace std;
#define MAX 1009
int adj [MAX][MAX];
int n,nv;
bool vis[MAX];
int dis[MAX];
int main()
{
	int sum=0;
	cin>>n;
	for (int i=0;i<n;++i){
		dis[i]=99999999;
		for (int j=0;j<n;++j)
		{
			cin>>adj[i][j];
		}
	}
          nv=0;
         int s=0;
	dis[s]=0;
	while (nv<n)
	{
		vis[s]=true;
		for (int i=0;i<n;++i)
		{
			if (!vis[i]&& adj[s][i]<dis[i])
				dis[i]=adj[s][i];
		}
		s=-1;
		for (int i=0;i<n;++i)
			if (!vis[i] && (s==-1||dis[i]<dis[s]))
				s=i;
		sum+=dis[s];
                   ++nv;
	}
	cout<<sum<<endl;
}

