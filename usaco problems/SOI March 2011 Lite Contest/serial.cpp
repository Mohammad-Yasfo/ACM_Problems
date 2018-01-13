/*
الأرقام التسلسلية المميزة
*/
#include <fstream>
#include <string>
using namespace std;
bool check_serial(string number)
{
	int  num_max=number.length()/2;
	int sum;
	while (number.length()>0)
	{
		char num=number[0];
		sum=1;
		for (int i=1;i<number.length();++i){
			if (number[i]==num)
			{
				number.erase(i,1);
				--i;
				++sum;
			}
		}
			number.erase(0,1);
		if (sum>num_max)
			return true;
	}
	return false;
}
int main()
{
	string serial;
	ifstream fin("serial.in");
	ofstream fout("serial.out");
	fin>>serial;
	if (check_serial(serial))
		fout<<serial<<endl;
	else
	{
		while (!check_serial(serial))
		{
			++serial[serial.length()-1];
			for (int i=serial.length()-1;i>=0;--i)
				if (serial[i]==58)
				{
					serial[i]='0';
					/*if (i==0)
						serial.insert(0,"1");
					else*/
					//لانحتاج الخطوة السابقة لأن الشرط سيحقق في حال كان العدد السابق كله 9 و بالتالي سيكون رقماً مميزاً
						++serial[i-1];
				}
		}
		fout<<serial<<endl;
	}
	return 0;
}
