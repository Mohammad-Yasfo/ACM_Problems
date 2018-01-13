#include <iostream>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
int main()
{
	int W, n, year, T;
	int dp[100009][2] = { 0 };
	int num[109];
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> year >> n;
		W = n * 1000;
		for (int j = 0; j < W; ++j)
			dp[j][1] = 0;
		for (int a = 0; a < n; ++a)
			cin >> num[a];
		for (int q = 0; q < n; ++q)
		{
			for (int j = 0; j < W; ++j)
				dp[j][0] = dp[j][1];
			for (int j = 1; j < W; ++j)
			{
				if (j >= num[q])
					dp[j][1] = max(dp[j][0], dp[j - num[q]][0] + num[q]);
				else
					dp[j][1] = dp[j][0];
			}

		}
		for (int i = 1; i < W; ++i)
			if (dp[i][1] == i)
				cout << dp[i][1] + year << endl;
	}

	return 0;
}