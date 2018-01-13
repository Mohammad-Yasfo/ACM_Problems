#include <iostream>
using namespace std;
int main()
{
	long long  maxs=-1,mins=9999999999;
	long long sol=-1;
	int n;
	long long a,b;
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>a>>b;
		if (a<mins)
		{
			sol=-1;
			mins=a;
		}
		if (b>maxs)
		{
			sol=-1;
			maxs=b;
		}
		if (maxs==b && mins == a)
			sol=i+1;
	}
	cout<<sol<<endl;
	return 0;
}

