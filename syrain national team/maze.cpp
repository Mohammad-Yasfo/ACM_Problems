#include <iostream>
using namespace std;
int n,m,k;
char map[504][504];
bool vis[504][504];
bool backtrack(int i,int j)
{
	vis[i][j]=true;
	bool f=true;
	if (j+1<m &&!vis[i][j+1])
		backtrack(i,j+1);
	if (i+1<n &&!vis[i+1][j])
		backtrack(i+1,j);
	if (j>0 && !vis[i][j-1])
		backtrack(i,j-1);
	if (i>0 && !vis[i-1][j])
		backtrack(i-1,j);
	if (k==0)
		return false;
	map[i][j]='X';--k;
	return f;
}

int main()
{
	cin>>n>>m>>k;
	for (int i=0;i<n;++i)
		for (int j=0;j<m;++j)
		{
			cin>>map[i][j];
			if (map [i][j]=='#')
				vis[i][j]=true;
		}
	for (int i=0;i<n;++i)
		for (int j=0;j<m;++j)
			if (map [i][j]=='.')
			{
				backtrack(i,j);
				break;
			}
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j)
			cout<<map[i][j];
		cout<<endl;
	}
	return 0;
}