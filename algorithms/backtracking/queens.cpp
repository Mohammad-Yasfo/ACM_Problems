#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> ith;
int chess[50][50];
vector<vector<int>>no_case;
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
	chess[i][j]+=in_un*-1;
}
int selected_ith;
bool is_here(int i,int val)
{
	int length=no_case[i].size();
	for (int a=0;a<length;++a)
		if (no_case[i][a]==val)
			return true;
	return false;
}
bool backtrack(int i,int i_ith)
{
	st:if (!is_here(i,ith[i_ith])&& chess[i][ith[i_ith]]==0)
	{
		swap(ith[i],ith[i_ith]);
		i_ith=i;
		set_queen(i,ith[i],1);
		selected_ith=ith[i_ith];
		if (i+1==N)
			return true;
		
		if (backtrack(i+1,i+1))
			return true;
		else
		{
			set_queen(i,ith[i_ith],-1);
			no_case[i].push_back(ith[i_ith]);
		}
	}
	++i_ith;
	if (i_ith>=N){
		no_case[i].clear();
		return false;
	}
	goto st;
}

int main()
{
	cin>>N;
	vector<int>f;
	for (int i=0;i<N;++i){
		ith.push_back(i);
		no_case.push_back(f);
		for (int j=0;j<N;++j)
			chess[i][j]=0;
	}
	if (backtrack(0,0))
	{
		for (int i=0;i<N;++i)
			cout<<ith[i]<<" ";
	}
	else
	{
		cout<<"no solution"<<endl;
	}
	cin>>N;
	return 0;
}
