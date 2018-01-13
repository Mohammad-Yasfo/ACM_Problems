#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<bool> ith;
vector<int>solution;
int chess[50][50];
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
bool backtrack(int i)
{
	for (int a=0;a<N;++a)
	{
		if (ith[a] && chess[i][a]==0)
		{
			solution.push_back(a);
			ith[a]=false;
			if (i+1==N)
			{
				return true;
			}
			set_queen(i,a,1);
			if (backtrack (i+1))
				return true;
			set_queen(i,a,-1);
			solution.pop_back();
			ith[a]=true;
		}
	}
	return false;
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
	if (backtrack(0))
	{
		for (int i=0;i<N;++i)
			cout<<solution[i]<<" ";
	}
	else
	{
		cout<<"no solution"<<endl;
	}
	cin>>N;
	return 0;
}
