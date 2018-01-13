#include <iostream>
using namespace std;
int main()
{
	int n;
	int num[23];
	int dp[(1 << 15) + 4][16][2];
	while (cin >> n){
		if (n == 0)
			break;
		for (int i = 0; i < n; ++i)
			cin >> num[i];
		//	num[0] = 0;
		int mx = 1 << n;
		int t, r, q, s;
		//dp[0][0];
		for (int i = 0; i < mx; ++i)
		{
			t = i, r = 0, q = 1;
			for (int j = 0; j < n; ++j)
				dp[i][j][0] = dp[i][j][1] = 0;

			while (t)
			{
				if (t % 2)
				{
					if (i == q)
					{
						dp[i][r][0] = num[r] * 2;
						dp[i][r][1] = 1;
					}
					else{
						for (int j = 0; j < n; ++j)
						{
							s = dp[i - q][j][0] + 2 * num[r] - 2 * min(num[j], num[r]);
							if (dp[i][r][0] < s)
							{
								dp[i][r][0] = s;
								dp[i][r][1] = dp[i - q][j][1];
							}
							else if (dp[i][r][0] == s)
							{
								dp[i][r][1] += dp[i - q][j][1];
							}

						}
					}
				}
				t /= 2;
				q *= 2;
				r++;
			}
		}
		int sel = 0, c = 0;
		mx--;
		for (int j = 0; j <= n; ++j)
		{
			if (dp[mx][j][0] > sel)
			{
				sel = dp[mx][j][0];
				c = dp[mx][j][1];
			}
			else if (dp[mx][j][0] == sel)
			{
				c += dp[mx][j][1];
			}
		}
		cout << sel + 2 * n << " " << c << endl;
	}
	return 0;
}