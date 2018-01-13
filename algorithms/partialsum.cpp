#include <fstream>
using namespace std;
int main()
{
	ifstream fin("file.in");
	ofstream fout("file.out");
	int N,Q;
	fin>>N;
	int *nums=new int [N];
	fin>>nums[0];
	for (int i=1;i<N;++i)
	{
		fin>>nums[i];
		nums[i]+=nums[i-1];
	}
	fin>>Q;
	int a,b;
	for (int i=0;i<Q;++i)
	{
		fin>>a>>b;
		if (b>a)
			fout<<nums[b-1]-(a>1?nums[a-2]:0)<<endl;
		else
			fout<<nums[a-1]-(b>1?nums[b-2]:0)<<endl;
	}
	return 0;
}

