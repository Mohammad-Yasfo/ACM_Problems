/*
بطاقات الألعاب الالكترونية
*/
#include <fstream>
#include <string>
using namespace std;
int main()
{
	int N,N_lines,number,time;
	string command;
	int times[145]={0};
	ifstream fin("timecard.in");
	ofstream fout("timecard.out");
	fin>>N>>N_lines;
	for (int i=0;i<N_lines;++i)
	{
		fin>>number>>command>>time;
		if (command=="START")
			times[number-1]-=time*60;
		else
			times[number-1]+=time*60;
		fin>>time;
		if (command=="START")
			times[number-1]-=time;
		else
			times[number-1]+=time;
	}
	for (int i=0;i<N;++i)
		fout<<times[i]/60<<" "<<times[i]%60<<endl;
	return 0;
}
