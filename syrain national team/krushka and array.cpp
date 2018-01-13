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
	int n,a,c,sgcd;
	bool is=true;
	cin>>n;
	cin>>a;
	sgcd=a;
	c=a;
	for (int i=1;i<n;++i)
	{
		sgcd=c;
		cin>>a;
		c=gcd(max(sgcd,a),min(a,sgcd));
		if (c!=sgcd)
			is=false;
		if (a==c)
			is=true;
	}
	if (is)
		cout<<c<<endl;
	else
		cout<<-1<<endl;
	return 0;
}
