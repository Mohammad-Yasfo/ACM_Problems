#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<bool> ith;
vector<int>solution;
int chess[50][50];
int solutions=0;
void set_queen(int i,int j,int in_un)
{
	for (int a=0;a<N;++a)
		chess[i][a]+=in_un;
	for (int a=0;a<N;++a)
		chess[a][j]+=in_un;
	for (int a=1;i-a>=0;++a)
	{
		if (j-a>=0)
			chess[i-a][j-a]+=in_un;
		if (j+a<N)
			chess[i-a][j+a]+=in_un;
	}
	for (int a=1;i+a<N;++a)
	{
		if (j-a>=0)
			chess[i+a][j-a]+=in_un;
		if (j+a<N)
			chess[i+a][j+a]+=in_un;
	}
	chess[i][j]+=(in_un*-1);
}
void backtrack(int i)
{
	for (int a=0;a<N;++a)
	{
		if (ith[a] && chess[i][a]==0)
		{
			solution.push_back(a);
			ith[a]=false;
			if (i+1==N)
			{
				++solutions;
				
			}
			else{
			set_queen(i,a,1);
			backtrack (i+1);
			set_queen(i,a,-1);
			}
			
			solution.pop_back();
			ith[a]=true;
		}
	}
}

int main()
{
	cin>>N;
	vector<int>f;
	for (int i=0;i<N;++i){
		ith.push_back(true);
		for (int j=0;j<N;++j)
			chess[i][j]=0;
	}
	backtrack(0);
	cout<<solutions<<" ";
	cin>>N;
	return 0;
}
