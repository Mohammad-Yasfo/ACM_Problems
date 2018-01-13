#include <iostream>
using namespace std;
int main()
{
	int num3=0;
	int number;
	cin>>number;
	while (number%5>0)
	{
		++num3;
		number-=3;
	}
	cout<<number/5<<" "<<num3<<endl;
	return 0;
}
