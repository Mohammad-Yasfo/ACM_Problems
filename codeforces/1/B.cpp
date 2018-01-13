#include <iostream>
#include <string>
using namespace std;
//#define gcd(a,b) a!=b?gcd(b,a%b):a
string to_string (int number)
{
	string c="";
	while (number)
	{
		if (number%26)
			c+=number%26 +64;
		else
		{c+='Z';number-=26;}
		number/=26;
	}
	char temp;
	number=c.length();
	for (int i=0;i<number/2;++i)
	{
		temp=c[i];
		c[i]=c[number-1-i];
		c[number-1-i]=temp;
	}
	return c;
}
int to_int(string n)
{
	int num=0;
	int q=n.length();
	for (int i=0;i<q;++i)
	{
		num+=pow(26.0,q-1-i)*(n[i]-64);
	}
	return num;
}
bool contain(string n,char c)
{
	for (int i=0;i<n.length();++i)
		if (n[i]==c)
			return true;
	return false;
}

int main()
{
	int n,r,j,c;
	string co,e;
	int ns;
	cin>>n;
	for (int i=0;i<n;++i){
		cin>>co;
		ns=co.length();
		if (co [0]=='R' && co[1]>=48 && co [1]<=57 && contain(co,'C'))
		{
			r=0;
			for (j=1;j<ns && co [j]>=48 && co[j]<=57;++j)
			{
				r*=10;
				r+=co[j]-48;
			}
			++j;
			c=0;
			for (j;j<ns;++j)
			{
				c*=10;
				c+=co[j]-48;
			}
			cout << to_string(c)<<r<<endl;
		}
		else
		{
			e="";
			for (j=0;j<ns && co[j]>=65 && co[j]<=90;++j)
				e+=co[j];
			r=0;
			for (j;j<ns;++j)
			{
				r*=10;
				r+=co[j]-48;
			}
			cout<<'R'<<r<<'C'<<to_int(e)<<endl;
		}
	}
return 0;
}
