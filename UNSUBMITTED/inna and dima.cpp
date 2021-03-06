#include<iostream>
#include <string>
using namespace std;
const int INF = 1000005;
string s[1005], st = "DIMA";
int dp[1005][1005] = { 0 };
int n, m, ans = 0;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
int dfs(int i, int j, int l)
{
	if (dp[i][j] != 0) return dp[i][j];
	dp[i][j] = INF;
	l = (l + 1) % 4;
	int tmp = 0;
	if (i>0 && s[i - 1][j] == st[l])  tmp = max(tmp, dfs(i - 1, j, l));
	if (i<n - 1 && s[i + 1][j] == st[l])tmp = max(tmp, dfs(i + 1, j, l));
	if (j>0 && s[i][j - 1] == st[l])  tmp = max(tmp, dfs(i, j - 1, l));
	if (j<m - 1 && s[i][j + 1] == st[l])tmp = max(tmp, dfs(i, j + 1, l));
	return dp[i][j] = min(INF, tmp + 1);
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i<n; i++) cin >> s[i];
	for (int i = 0; ans != INF&&i<n; i++)
	for (int j = 0; ans != INF&&j<m; j++)
	if (s[i][j] == 'D') ans = max(ans, dfs(i, j, 0));
	if (ans == INF) cout << "Poor Inna!";
	else if (ans<4) cout << "Poor Dima!";
	else  cout << ans / 4;
	return 0;
}