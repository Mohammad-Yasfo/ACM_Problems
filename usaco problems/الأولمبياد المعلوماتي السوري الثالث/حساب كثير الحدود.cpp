#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x,n;
	int varibles[1000];
	cin>>n;
	for (int i=0;i<=n;++i)
		cin>>varibles[i];
	cin>>x;
	long long sum=0;
	for (int i=0;i<=n;++i)
	{
		sum+=varibles[i]*pow(x,n-i);
	}
	cout<<sum<<endl;
	return 0;
}
