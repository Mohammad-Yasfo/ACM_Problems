#include <fstream>
using namespace std;
int main()
{
	int n;
	int number[100009];
	int dp[100009][2];
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin >> n;
	for (int i = 0; i < n; ++i)
		fin >> number[i];
	dp[0][0] = dp[0][1] = 0;
	if (number[0] >= 0)
		dp[0][1] = dp[0][0] = 1;
	for (int i = 1; i < n; ++i)
	{
		if (number[i]>0)
		{
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = dp[i - 1][1] + 1;
		}
		else if (number[i] < 0)
		{
			dp[i][1] = dp[i - 1][1];
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
		}
		else
		{
			dp[i][1] = dp[i - 1][1] + 1;
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
		}
	}
	fout << dp[n - 1][0] << endl;
}