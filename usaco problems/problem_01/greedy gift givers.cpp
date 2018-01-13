/*
تبادل الهدايا
*/
#include <fstream>
#include <string>
using namespace std;
	string names[10];
	int finallmoney[10]={0};
	int N;
	int get_index(string name)
	{
		for (int index=0;index<N;++index)
			if (names[index]==name)
				return index; 
		return 0;
	}
int main()
{
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");

	fin>>N;
	for (int i=0;i<N;++i)
	{
		fin>>names[i];
	}
	string name="";
	int money=0,nop=0,index;
	while (!fin.eof())
	{
		fin>>name>>money>>nop;
		index=(get_index(name));

		finallmoney[index]-=money;
		if (nop==0)continue;
		finallmoney[index]+=money%nop;
		for (int i=0;i<nop;++i)
		{
			fin>>name;
			finallmoney[get_index(name)]+=money/nop;
		}
	}
	for (int i=0;i<N;++i)
	{
		fout<<names[i]<<" "<<finallmoney[i]<<endl;
	}
	return 0;
}
