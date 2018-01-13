#include <fstream>
#include <algorithm>
using namespace std;
struct nod
{
	int k, p, a;
};
bool operator<(nod a1, nod a2)
{
	return a1.k < a2.k || (a1.k == a2.k && a1.p < a2.p);
}
#define mx 23
int main()
{
	ifstream fin("dec.in");
	ofstream fout("dec.out");
	int n, bnum, t;
	nod b[mx];
	fin >> n >> bnum;
	for (int i = 0; i < bnum; ++i)
		fin >> b[i].k >> b[i].p >> b[i].a;
	int dp[(1 << 20) + 5];
	int num[mx][mx];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			fin >> num[i][j];
	sort(b, b + bnum);
	dp[0] = 0;
	int r, q, k;
	int mx_s = 1 << n;
	for (int i = 1; i < mx_s; ++i)
	{
		t = i;
		r = 0;
		q = i;
		k = 1;
		dp[i] = 0;
		while (q)
		{
			if (q % 2)
				++r;
			q /= 2;
			//r++;
		}
		while (t)
		{
			if (t % 2)
			{
				dp[i] = max(dp[i], dp[i - k] + num[q][r - 1]);
			}
			t /= 2;
			k *= 2;
			q++;
		}
		//if (r != q)continue;
		for (int f = 0; f < bnum; ++f)
		{
			if (b[f].k>r)break;
			if (b[f].k < r)continue;
			if (dp[i] >= b[f].p)
				dp[i] += b[f].a;
		}
	}
	fout << dp[mx_s - 1] << endl;
	return 0;
}