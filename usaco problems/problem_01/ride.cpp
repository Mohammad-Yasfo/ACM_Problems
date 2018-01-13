/*
المركبة الفضائية
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string name1,name2;
	cin>>name1>>name2;
	int num1=1,num2=1;
	for (int i=0;i<name1.length();++i)
		num1*=name1[i]-64;
	for (int i=0;i<name2.length();++i)
		num2*=name2[i]-64;
	if (num1%47==num2%47)
		cout<<"GO"<<endl;
	else
		cout<<"STAY"<<endl;
	return 0;
}
