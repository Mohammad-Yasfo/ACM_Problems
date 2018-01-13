#include <iostream>
#include <string>
using namespace std;
int main()
{
	int dp[109][109] = { 0 };
	string name;
	int n, k;
	cin >> k;
	cin >> name;
	n = name.length();
	for (int i = 0; i < n; ++i)
		dp[1][i] = 1;
	for (int i = 2; i <= k; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int a = j - 1; a >= 0; --a)
			{
				if (name[j]>name[a])
					dp[i][j] += dp[i - 1][a];
			}
		}
	}
	int maxs = 0;
	for (int i = 0; i < n; ++i)
		maxs += dp[k][i];
	cout << maxs << endl;
	return 0;
}
