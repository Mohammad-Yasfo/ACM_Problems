#include <iostream>
using namespace  std;
int main()
{
	int a,b,x,y;
	int n1=0,n2=0,n3=0;
	cin>>a>>b;
	for (int i=1;i<=6;++i)
	{
		x=abs(a-i),y=abs(b-i);
		if (x<y)
			++n1;
		else if (x>y)
			++n3;
		else
			++n2;
	}
	cout<<n1<<" " <<n2<<" "<<n3<<endl;
	return 0;
}
