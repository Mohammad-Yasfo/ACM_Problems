/*
الجمعة الواقعة في 13
*/
#include <iostream>
using namespace std;
int num[7]={0};

bool isloop_day(int year)
{
	return year%100==0 &&year%400==0||year%100!=0&& year%4==0;
}
int main()
{
	int num_days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int N;
	cin>>N;
	int lastindex=0;
	++num[lastindex];
	for (int Y=1900;Y<1900+N;++Y)
	{
		for (int m=0;m<12-(Y==1900+N-1);++m)
		{
			int index=num_days[m]+(m==1&&isloop_day(Y));
			lastindex=(lastindex+index)%7;
			++num[lastindex];			
		}
	}
	for (int i=0;i<7;++i)
		cout<<num[i]<<" ";
	return 0;
}
