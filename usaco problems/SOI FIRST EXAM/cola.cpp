/*
هرم الكولا
*/
#include <fstream>
#include <string>
using namespace std;
int get_length(int num)
{
	return (num*(num+1))/2;
}
int main()
{
	ifstream fin("cola.in");
	ofstream fout("cola.out");
	int number,n,sum;
	while (true)
	{
	fin>>number;
	if (number==0)
		return 0;
	sum=0;
	for (int i=1;number>0;++i)
	{
		n=get_length(i);
		if (number>=n)
		{
			number-=n;
			++sum;
		}
		else
			break;
	}
	fout<<sum<<endl;
	}
	return 0;
}
