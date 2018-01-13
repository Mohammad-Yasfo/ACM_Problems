/*
تقارب السلسلة
*/
#include <fstream>
#include <cmath>
using namespace std;
const double golden_num=((sqrt((double)5)+1)/2);
double number;
bool is_enough(int num1,int num2)
{
	double m=(double)num2/num1;
	m=abs(golden_num-m);
	return m<number;
}
int main()
{	
	ifstream fin ("fib.in");
	ofstream fout("fib.out");
	fin>>number;
	int a=1,b=1,c=1;
	while (!is_enough(b,c))
	{
		a=b;
		b=c;
		c=a+b;
	}
	fout<<b<<"  "<<c<<endl;
	return 0;
}
