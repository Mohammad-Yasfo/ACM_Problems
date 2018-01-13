#include <iostream>
#include <stack>
using namespace std;
#define inf 9999999
#define min(a,b) (a)<(b)?(a):(b)
int main()
{
	int num, sum, coins[100], dp[100009][2];
	int q;
	cin >> sum >> num;
	for (int i = 0; i < num; ++i)
		cin >> coins[i];
	dp[0][0] = 0;
	for (int i = 1; i <= sum; ++i)
	{
		dp[i][0] = inf;
		for (int j = 0; j < num; ++j)
		{
			if (coins[j] <= i && dp[i][0] > 1 + dp[i - coins[j]][0])
			{
				dp[i][0] = 1 + dp[i - coins[j]][0];
				dp[i][1] = coins[j];
			}
		}
	}
	cout << dp[sum][0] << endl;
	while (sum != 0)
	{
		cout << dp[sum][1] << " ";
		sum -= dp[sum][1];
	}
	cout <<endl;
	return 0;
}