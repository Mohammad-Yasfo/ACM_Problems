#include <iostream>
using namespace std;
#define max(a,b)(a)>(b)?(a):(b)
class ZigZag
{
public:
	int longestZigZag(int num[])
	{
		int n = sizeof(num);
		int dp[109][2] = { 0 };
		dp[0][0] = dp[0][1] = 1;
		for (int i = 1; i < n; ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (num[i] > num[j])
					dp[i][0] = max(dp[i][0], dp[j][1]);
				else if (num[i] < num[j])
					dp[i][1] = max(dp[i][1], dp[j][0]);
			}
			dp[i][0]++, dp[i][1]++;
		}
		long long q = 0;
		for (int i = 0; i < n; ++i)
		{
			q = max(q, dp[i][0]);
			q = max(q, dp[i][1]);
		}
		return q;
	}
};

int main()
{

	ZigZag q;
	int num[] = { 1, 7, 4, 9, 2, 5 };
	cout << q.longestZigZag(num) << endl;
		
}