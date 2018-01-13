#include <iostream>
using namespace std;
#define max 100009
int main()
{
	int n, m,a;
	int num[max];
	bool place[max] = { false };
	int dp[max] = { 0 };
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	dp[n-1] = 1;
	place[num[n - 1]] = true;
	for (int i = n - 2; i >= 0; --i)
	{
		if (place[num[i]])
			dp[i] = dp[i + 1];
		else
		{
			place[num[i]] = true;
			dp[i] = dp[i + 1] + 1;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> a;
		cout << dp[a - 1] << endl;
	}
	return 0;
}