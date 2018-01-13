/*
عدد المجموعات الجزئية لمصفوفة بشرط 
*/
#include <iostream>
using namespace std;
int main()
{
	int n,s;
	cin>>n;
	int m[100000];
	int a[100000];
	for (int i=0;i<n;++i)
	{
		cin>>m[i];
		a[i]=0;
		s=m[i];
		for (int j=i-1;j>=0;--j)
		{
			if (s>=0)
				a[i]+=a[j];
			s+=m[j];
		}
		a[i]+=s>=0;
	}
	cout<<a[n-1]<<endl;
	cin>>n;
	return 0;
}
