#include <iostream>
using namespace std;
int main()
{
	int n,k,l,r,all,sk;
	int s[1009];
	cin>>n>>k>>l>>r>>all>>sk;
	int m=sk/k;
	for (int i=0;i<k;++i)
		s[i]=m;
	all-=sk;
	if(k!=0)
	sk%=k;
	for (int i=0;i<k && sk>0;++i,--sk)
		s[i]++;
	m=n-k;
	for (int i=k;i<n;++i)
		s[i]=all/m;
	if (m!=0)
		all%=m;
	else
		all=0;
	for (int i=k;i<n && all>0;++i,--all)
		s[i]++;
	for (int i=0;i<n;++i)
		cout<<s[i]<<" ";
	cout<<endl;
	return 0;
}