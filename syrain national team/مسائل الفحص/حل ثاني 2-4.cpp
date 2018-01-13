#include <iostream>
#include <string>
using namespace std;
#define cons 26*4
int sgt[cons];
int dp[109];
string a;
int k;
int n;
void reset()
{
	for (int i = 0; i < cons; ++i)
		sgt[i] = 0;
}
void update(int node, int l, int r, int s, int val)
{
	if (l>s || r < s)return;
	if (l == r)
	{
		if (l == s)
			sgt[node] += val;
		return;
	}
	update(node * 2, l, (r + l) / 2, s, val);
	update(node * 2 + 1, (l + r) / 2 + 1, r, s, val);
	sgt[node] = sgt[2 * node] + sgt[node * 2 + 1];
}
long long query(int node, int l, int r, int s, int e)
{
	if (r<s || l>e)return 0;
	if (s <= l && e >= r)
		return sgt[node];
	long long a = query(node * 2, l, (l + r) / 2, s, e);
	long long b = query(node * 2 + 1, (l + r) / 2 + 1, r, s, e);
	return a + b;
}
int main()
{
	cin >> k;
	cin >> a;
	n = a.length();
	reset();
	for (int i = 0; i < n; ++i)
		dp[i] = 1;
	long long q = 0;
	for (int i = 2; i <= k; ++i)
	{
		reset();
		for (int j = 0; j < n; ++j)
		{
			if (j)
				update(1, 0, n - 1, a[j - 1] - 'A', q);
			q = dp[j];
			dp[j] = query(1, 0, n - 1, 0, a[j] - 'A');
		}

	}
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += dp[i];
	cout << sum << endl;
	return 0;
}