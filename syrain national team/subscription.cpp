#include <iostream>
using namespace std;
long long gcd(long long a, long long b)
{
	if (b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	int n;
	long long a,b,sum,temp;
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>a>>b;
		sum=0;
		if (a<b)
		{
			temp=a;
			a=b;
			b=temp;
		}
		while (b!=0)
		{
			sum+=a/b;
			temp=b;
			b=a%b;
			a=temp;
		}
		cout<<sum<<endl;
	}
	return 0;
}
