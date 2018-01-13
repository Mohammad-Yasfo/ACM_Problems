/*
أكبر سلسلة متزايدة (عدد الأعداد أكبر ما يمكن)
*/
#include <iostream>
using namespace std;
int main()
{
	int n,r;
	cin>>n;
	int m[100000];
	int a[100000];
	for (int i=0;i<n;++i)
	{
		cin>>m[i];
		r=0;
		for (int j=i-1;j>=0;--j)
		{
			r=max(r,m[j]<=m[i]?a[j]:0);
		}
		a[i]=1+r;
	}
	r=-1;
	for (int i=0;i<n;++i)
		r=max(r,a[i]);
	cout<<r<<endl;
	return 0;
}
