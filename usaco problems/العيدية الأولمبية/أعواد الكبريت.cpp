/*
أعواد الكبريت
*/
#include <iostream>
#include <string>
using namespace std;
string get_max(long long num)
{
	string m="";
	if (num%2==1)
	{
		num-=3;
		m+="7";
	}
	while (num>2)
	{
		num-=2;
		m+="1";
	}
	return m;
}
string get_min(long long num)
{
	string m;
	int sum[10]={6,2,5,5,4,5,6,3,7,6};
	bool s=true;
	int index,mod;
	while (num>0)
	{
		index=0;
		mod=num%7;
		if (mod==0)mod=7;
		if (s)
		{
			++index;
			s=false;
		}
		while (sum[index]<mod)
			++index;
		m+=index+48;
		num-=sum[index];
	}
	return m;
}
int main()
{
	long long N;
	cin>>N;
	if (N==1)
	{
		cout <<"error";
		return 0;
	}
	cout<<"min number : "<<get_min(N)<<endl;
	cout<<"max number : "<<get_max(N)<<endl;
	cin>>N;
	return 0;
}
