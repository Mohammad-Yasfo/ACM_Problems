/*
الأعداد المجنونة
*/
#include <fstream>
using namespace std;
int main()
{	
	int N,sum=0,w;
	long long number=0;
	ifstream fin ("inequality.in");
	ofstream fout("inequality.out");
	fin>>N;
	for (int i=0;i<N-1;++i)
	{
		fin>>w;
		number+=w*w;
		sum+=w;
	}
	N=0;
	for (;number+N*N<=pow((long double)sum+N,2);--N);
	fout <<N<<endl;
	return 0;
}
