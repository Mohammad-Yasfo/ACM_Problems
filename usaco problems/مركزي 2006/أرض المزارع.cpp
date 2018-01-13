#include <algorithm>
#include <fstream>
using namespace std;
int main() {
int h,w,max_all=0,max_num,mt,e;
int map[205][205];
ifstream fin("box.in");
ofstream fout("box.out");
fin>>w>>h;
for (int i=0;i<h;++i)
{
	for (int j=0;j<w;++j)
	{
		fin>>map[i][j];
		if (i>0)
			map [i][j]+=map [i-1][j];
	}
}
for (int i=0;i<h;++i)
{
	for(int j=i;j<h;++j)
	{
		max_num=0;
		mt=0;
		for (int a=0;a<w;++a)
		{
			e=map[j][a]-(i>0?map [i-1][a]:0);
			mt=max(e,mt+e);
			max_num=max(max_num,mt);
		}
		max_all=max(max_all,max_num);
	}
}
fout<<max_all<<endl;
}
