/*
أرقام تعريف الكتب
*/
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ifstream fin("isbn.in");
	ofstream fout("isbn.out");
	char m;
	int sum=0;
	int	index;
	for (int i=10;i>=1;--i)
	{
		fin>>m;
		switch(m)
		{
		case '?':
			index=i;
			break;
		case 'X':
			sum+=i*10;
			break;
		case 'x':
			sum+=i*10;
			break;
		default:
			sum+=(m-48)*i;
		}
	}
	sum%=11;
	sum=11-sum;
	if (sum%index!=0)
	{
		fout<<-1<<endl;
		return 0;
	}
	sum/=index;
	if (sum==10)
	{
		if (index!=1)
			fout<<-1<<endl;
		else
			fout<<"X"<<endl;
	}
	else
		fout<<sum<<endl;
	return 0;
}
