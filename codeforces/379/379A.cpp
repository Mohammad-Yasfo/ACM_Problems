#include <iostream>
using namespace std;
int main() {
	int a,b,c=0,sum=0;
	cin>>a>>b;
	sum+=a;
	st:while (a>0)
	{
		sum+=a/b;
		c+=a%b;
		a/=b;
	}
	a=c;
	c=0;
	if (a>=b)
	goto st;
	cout<<sum<<endl;
	return 0;
}
