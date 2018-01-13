/*
الكلمات المتقاطعة
*/
#include <fstream>
#include <vector>
using namespace std;
void get_words(vector<vector<int>> &black,int &sum,int num)
{
		for (int i=0;i<black.size();++i)
	{
		int select_index=0;
		for (int j=0;j<black[i].size();++j)
		{
			if (black[i][j]-select_index>=2)
			{
				++sum;
			}
			select_index=black[i][j]+1;
		}
		if (num-select_index>=2)
			++sum;
	}
}
int main()
{
	ifstream fin("puzzle2.in");
	ofstream fout("puzzle2.out");
	vector<vector<int>>black;
	vector<vector<int>>black_N;
	int N,M;
	int sum_i=0,sum_j=0;
	fin>>N>>M;
	int a,f,w;
	for (int i=0;i<M;++i)
	{
		fin>>a;
		vector <int>index;
		for (int j=0;j<a;++j)
		{
			fin>>f;
			--f;
			for (w=0;w<index.size() &&f>index[w];++w);
			index.insert(index.begin()+w,f);
		}
		black.push_back(index);
	}
	for (int i=0;i<N;++i)
	{
		vector<int>index;
		black_N.push_back(index);
	}
	for (int i=0;i<black.size();++i)
	{
		for (int j=0;j<black[i].size();++j)
		{
			for (w=0;w<black_N[black[i][j]].size()&&i>black_N[black[i][j]][w];++w);
			black_N[black[i][j]].insert(black_N[black[i][j]].begin()+w,i);
		}
	}
	get_words(black,sum_i,N);
	get_words(black_N,sum_j,M);
	fout<<sum_i<<" "<<sum_j<<endl;
	return 0;
}
طريقة ثانية
#include <fstream>
using namespace std;
int main()
{
	ifstream fin("puzzle2.in");
	ofstream fout("puzzle2.out");
	int N,M,numofH=0,numofV=0;
	fin>>N>>M;
	char **map=new char *[M];
	for (int i=0;i<M;++i)
		map [i]=new char [N];
	for (int i=0;i<M;++i)
		for (int j=0;j<N;++j)
			map [i][j]='-';
	int n,l;
	for (int i=0;i<M;++i)
	{
		fin>>n;
		for (int j=0;j<n;++j)
		{
				fin>>l;
				map [i][l-1]='#';
		}
	}
	for (int i=0;i<M;++i)
	{
		int H=0;
		for (int j=0;j<N;++j)
		{
			if (map [i][j]!='#')
				++H;
			else {
				if (H>1)
					++numofH;
				H=0;
			}
		}
		if (H>1)
			++numofH;
	}
		for (int i=0;i<N;++i)
	{
		int V=0;
		for (int j=0;j<M;++j)
		{
			if (map [j][i]!='#')
				++V;
			else {
				if (V>1)
					++numofV;
				V=0;
			}
		}
		if (V>1)
			++numofV;
	}
		fout<<numofH<<" "<<numofV<<endl;
	return 0;
}
