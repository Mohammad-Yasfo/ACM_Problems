#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	long long w,m,e,k,sum=0,maxdigit;
	cin>>w>>m>>k;
	e=m;
	int begin_pow=0;
	maxdigit=w/k;
	while (e>0)
	{
		++begin_pow;
		e/=10;
	}
	while (maxdigit>0){
	e=(pow(10.0,begin_pow)-m)*begin_pow;
	e=min(e,maxdigit);
	sum+=e/begin_pow;
	maxdigit-=e;
	maxdigit/=begin_pow;
	maxdigit*=begin_pow;
	m=pow(10.0,begin_pow);
	++begin_pow;
	}
	cout<<sum<<endl;
	return 0;
}
