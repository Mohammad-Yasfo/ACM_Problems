/*
The digital product of a positive integer , N,  is defined to be the product of its nonzero decimal digits. For example, the digital product of the integer 99 is 9x9 or 81.  The digital product of 81 is 8x1 or 8. The DIGITAL PRODUCT ROOT of a positive integer  N is obtained by repeatedly taking digital products until a single digit is obtained.  In the example above, 8 is the DIGITAL PRODUCT ROOT of 99. 

Write a program which will accept a positive number up to 70 digits long as an input and print out each step in the computation of the DIGITAL PRODUCT ROOT. 


Test your program with the inputs 123456789, 9999999999.

Sample Run

ENTER A NUMBER 123456789
123456789
362880
2304
24
8
THE DIGITAL PRODUCT ROOT IS 8


*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
	unsigned long long Number;
	string c="";
	cout<<"ENTER A NUMBER ";
	cin>>c;
	cout<<c<<endl;
	while (c.length()>1)
	{
		Number=1;
		for (int i=0;i<c.length();++i)
		{
			if (c[i]!='0')
				Number*=c[i]-48;
		}
		ostringstream d;
		d<<Number;
		c=d.str();
		cout<<Number<<endl;
	}
	cout<<"THE DIGITAL PRODUCT ROOT IS "<<Number<<endl;
	return 0;
}