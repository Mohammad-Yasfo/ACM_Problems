#include <iostream>
using namespace std;
#define inf 100009
#define mod 5000000
int sgt[4 * inf];
int num[inf];
int n, k;
void reset()
{
	for (int i = 0; i < 4 * inf; ++i)
		sgt[i] = 0;
}
void update(int node, int l, int r, int t, int val)
{
	if (l == r)
	{
		if (r == t)
			sgt[node] += val;
		return;
	}
	if ((l + r) / 2 >= t)
		update(node * 2, l, (l + r) / 2, t, val);
	if ((l + r) / 2 + 1 <= t)
		update(node * 2 + 1, (l + r) / 2 + 1, r, t, val);
	sgt[node] = (sgt[2 * node] + sgt[2 * node + 1]) % mod;
}
int query(int node, int l, int r, int s, int e)
{
	if (s <= l && e >= r)
		return sgt[node];
	int a = 0, b = 0;
	if ((l + r) / 2 >= s)
		a = query(node * 2, l, (l + r) / 2, s, e);
	if ((l + r) / 2 + 1 <= e)
		b = query(node * 2 + 1, (l + r) / 2 + 1, r, s, e);
	return (a + b) % mod;
}
int main()
{
	int dp[inf];
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &num[i]);
		dp[i] = 1;
	}
	if (n == 0 || k == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	int q;
	for (int i = 2; i <= k; ++i)
	{
		reset();
		for (int j = 0; j < n; ++j)
		{
			if (j)
				update(1, 0, inf, num[j - 1], q);
			q = dp[j];
			if (num[j] == 0)
				dp[j] = 0;
			else
				dp[j] = query(1, 0, inf, 0, num[j] - 1);
		}
	}
	q = 0;
	for (int i = 0; i < n; ++i)
	{
		q += dp[i];
		q %= mod;
	}
	printf("%d\n", q%mod);
	return 0;
}
