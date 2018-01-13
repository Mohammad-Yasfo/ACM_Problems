#include <iostream>
using namespace std;
#define inf 109
#define max(a,b) (a)>(b)?(a):(b)
int main()
{
	int sum, n, num[inf][2];
	int dp[inf][2];
	cin >> sum >> n;
	for (int i = 0; i < n; ++i)
		cin >> num[i][0] >> num[i][1];
	for (int i = 0; i < n; ++i)
		dp[i][0] = dp[i][1] = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j <= sum; ++j)
			dp[j][0] = dp[j][1];
		for (int j = 1; j <= sum; ++j)
		{
			if (num[i][1] <= j)
				dp[j][1] = max(dp[j][0], dp[j - num[i][1]][0] + num[i][0]);
			else
				dp[j][1] = dp[j][0];
		}
	}
	cout << dp[sum][1] << endl;
}