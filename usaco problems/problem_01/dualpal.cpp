/*
dualpal
*/
#include <fstream>
using namespace std;
	int N,S;
	bool isdualpal(string text)
	{
		for (int i=0;i<text.length()/2;++i)
			if (text[i]!=text[text.length()-1-i])
				return false;
		return true;
	}
	string convert(int number,int base)
	{
		string num="";
		while (number>0)
		{
			num+=(number%base+48);
			number/=base;
		}
		return num;
	}
int main()
{
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	fin>>N>>S;

	for (++S;N>0&&S<1000;++S)
	{
		int sum=0;
		for (int j=2;j<=10&&sum<2;++j)
		{
			if (isdualpal(convert(S,j)))
				++sum;
		}
		if (sum==2)
		{
			fout<<S<<endl;
			--N;
		}
	}
	return 0;
}
