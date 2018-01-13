#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	ifstream fin("slowdown.in");
	ofstream fout("slowdown.out");
	int n;
	double a;
	char c;
	fin>>n;
	vector<double>Ti;
	vector<double>Di;
	for (int i=0;i<n;++i)
	{
		fin>>c>>a;
		if (c=='D')
			Di.push_back(a);
		else
			Ti.push_back(a);
	}
	sort(Di.begin(),Di.begin()+Di.size());
	sort(Ti.begin(),Ti.begin()+Ti.size());
	int ti=0,di=0;
	double dis=0,time=0,speed=1,cost=0;
	while (ti<Ti.size()||di<Di.size())
	{
		if (di==Di.size())
		{
			cost+=Ti[ti]-time;
			dis+=double((Ti[ti]-time)*double(1/speed));
			time=Ti[ti++];
		}
		else if (ti==Ti.size())
		{
			cost+=double((Di [di]-dis)/double(1/speed));
			time+=double((Di [di]-dis)/double(1/speed));
			dis=Di[di++];
		}
		else if ((Di [di]-dis)/double(1/speed)<Ti[ti]-time)
		{
			cost+=double((Di [di]-dis)/double(1/speed));
			time+=double((Di [di]-dis)/double(1/speed));
			dis=Di[di++];
		}
		else if(Ti.empty()||(Di [di]-dis)/double(1/speed)>Ti[ti]-time)
		{
			cost+=Ti[ti]-time;
			dis+=double((Ti[ti]-time)*double(1/speed));
			time=Ti[ti++];
		}
		else
		{
			dis=Di[di++];
			time=Ti[ti++];
		}
		++speed;
	}
	time+=double((1000-dis)/double(1/speed));
	fout<<time<<endl;
	return 0;
}
