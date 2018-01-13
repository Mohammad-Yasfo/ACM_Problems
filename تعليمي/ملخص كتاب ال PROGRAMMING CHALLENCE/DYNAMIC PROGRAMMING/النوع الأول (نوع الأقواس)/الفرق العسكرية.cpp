#include <iostream>
using namespace std;
int main()
{
	int n,a,b,c,s;
	long long num;
	cin>>n>>a>>b>>c;
	int m[100000];
	int dp[100000];
	for (int i=0;i<n;++i)
	{
		cin>>m[i];
		s=m [i];
		num=a*s*s+b*s+c;
		for (int j=i-1;j>=0;--j)
		{
			dp[i]=max(num+dp[j],(long long)dp[i]);
			s+=m [j];
			num=a*s*s+b*s+c;
		}
		dp [i]=max(num,(long long)dp[i]);
	}
	cout<<dp [n-1]<<endl;
	cin>>n;
	return 0;
}
