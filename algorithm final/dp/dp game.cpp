/*
TASK: game1
LANG: C++
ID: mbmcpp1
*/
#include <fstream>
using namespace std;
int n, s;
int nums[209];
int par[209] = { 0 };
int dp[209][209];
#define inf 999999999
int calc(int i, int j)
{
	if (dp[i][j] != inf)
		return dp[i][j];
	dp[i][j] = (par[j] - (i == 1 ? 0 : par[i - 1])) - min(calc(i + 1, j), calc(i, j - 1));
	return dp[i][j];
}
int main()
{
	ifstream fin("game1.in");
	ofstream fout("game1.out");
	fin >> n;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			dp[i][j] = inf;
	for (int i = 1; i <= n; ++i)
	{
		fin >> nums[i];
		par[i] = par[i - 1] + nums[i];
		dp[i][i] = nums[i];
		s += nums[i];
	}
	int sol = calc(1, n);
	fout << sol << " " << s - sol << endl;
	return 0;
}