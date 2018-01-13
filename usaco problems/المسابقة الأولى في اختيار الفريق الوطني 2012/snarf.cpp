/*
المنزل المفقود
(الخوارزمية الأسرع)
*/
#include <fstream>
using namespace std;
int main()
{
	ifstream fin("snarf.in");
	ofstream fout("snarf.out");
	int B;
	fin>>B;
	fout<<1<<endl;
	long long before=1,after=0;
	int last_index=2;
	for (int i=2;i<B;++i)
	{
		for (int j=last_index+1;j<B&&after<before;++j)
		{
			after+=j;
			last_index=j;
		}
		if (after==before)
			fout<<i<<endl;
		before+=i;
		after-=(i+1);
	}
	return 0;
}
