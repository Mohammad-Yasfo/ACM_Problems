#include <iostream>
#include <string>
using namespace std;
string sum(string max,string min)
{
	bool carry=false;
	int n;
	int min_l=min.length();
	int max_l=max.length();
	for (int i=0;i<max_l;++i)
	{
		
		n=(min_l-1-i>=0? min[min_l-1-i]-48:0)+max[max_l-1-i]-48+carry;
		carry=n>=10;
		max[max_l-1-i]=(n%10)+48;
	}
	if (carry && min_l==max_l&&carry)
		max.insert(max.begin(),'1');
	return max;
}
int main()
{
	string a="2",b="3",c;
	int num=2,N;
	cin>>N;
	if (N==1){cout<<a<<"0"<<endl;return 0;}
	if (N==2){cout<<b<<"0"<<endl;return 0;}
	while (num<N)
	{
		if (a.length()>b.length())
			c=sum(a,b);
		else
			c=sum(b,a);
		a=b;
		b=c;
		++num;
	}
	cout <<c<<"0"<<endl;
	cin>>c;
	return 0;
}
