#include <iostream>
#include <string>
using namespace std;
#define max(a,b) (((a) > (b) ? (a) : (b)))
int main()
{
	string w;
	int dp[10009] = { 0 };
	cin >> w;
	dp[0] = 0;
	int a, b;
	for (int i = 1; i < w.length(); ++i)
	{
		a = w[i] - 48;
		b = (w[i - 1] - 48) * 10 + a;
		if (b>26)
		{
			dp[i] = 0;
			continue;
		}
		dp[i] = dp[i - 1];
		if (i > 1)
		{
			b = (w[i - 2] - 48) * 10 + a;
			if (b <= 26)
				dp[i] = dp[i - 2] + dp[i];
		}
		dp[i]++;
	}
	int sum = 0, sel = 0;
	for (int i = 1; i < w.length(); ++i)
	{
		if (dp[i] == 0)
		{
			if (sel>0){
				if (sum == 0)
					sum = sel + 1;
				else
					sum *= sel + 1;
			}
			sel = 0;
		}
		else
			sel = max(sel, dp[i]);
	}
	if (sel > 0){
		if (sum == 0)
			sum = sel + 1;
		else
			sum *= sel + 1;
	}
	cout << sum << endl;
	return 0;
}