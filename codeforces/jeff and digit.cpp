#include <iostream>
using namespace std;
int main()
{
	int n,num5=0,num0=0,a;
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>a;
		if (a==0)
			++num0;
		else
			++num5;
	}
	if (num0==0)
	{
		cout<<-1<<endl;
		return 0;
	}
	while (num5*5%9>0 && num5>0)
		--num5;
	if (num5==0)
	{
		cout<<0<<endl;
		return 0;
	}
	else{
	for (int i=0;i<num5;++i)
		cout<<5;
	for (int i=0;i<num0;++i)
		cout<<0;
	cout<<endl;
	}
	return 0;
}

