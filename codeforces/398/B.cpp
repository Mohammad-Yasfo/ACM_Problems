#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
	stack<int>f;
	string w;
	bool num[52];
	int n;
	cin >> n;
	cin >> w;
	for (int i = 0; i < w.length(); ++i)
	{
		if (w[i] == 'R')
			num[i] = true;
		else
			num[i] = false;

	}
	int q = 0;
	long long dp[52] = { 0 };
	dp[0] = 0;

	while (q < n)
	{
		dp[q + 1] = dp[q];
		if (!num[q])
		{
			dp[q + 1] += (1 << q);
		}
		++q;
	}
	cout << dp[n] << endl;
	return 0;
}