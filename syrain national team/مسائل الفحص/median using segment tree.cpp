#include <iostream>
#include <algorithm>
using namespace std;
struct nod
{
	int i, n, i_af_s;
};
#define inf 100009
int sgt[4 * inf] = { 0 };
int numbers[inf];
nod num[inf];
bool s = false;
int ind;
bool operator<(nod a, nod b)
{
	return !s && a.n < b.n || s&& a.i < b.i;
}
void update(int node, int l, int r, int t, int val)
{
	if (l>t || r < t)return;
	if (l == r && r == t)
	{
		numbers[r] = val;
		sgt[node] = 1;
		return;
	}
	update(node * 2, l, (l + r) / 2, t, val);
	update(node * 2 + 1, (l + r) / 2 + 1, r, t, val);
	sgt[node] = sgt[node * 2] + sgt[node * 2 + 1];
}
int get_kth(int node, int l, int r, int key)
{
	if (l == r)
		return l;
	if (sgt[node * 2] >= key)
		return get_kth(node * 2, l, (l + r) / 2, key);
	return get_kth(node * 2 + 1, (r + l) / 2 + 1, r, key - sgt[2 * node]);
}
int main()
{
	int k;
	int n = 0, a, b, g;
	cin >> k;
	for (int q = 0; q < k; ++q)
	{
		memset(numbers, 0, n);
		memset(sgt, 0, 4 * n);
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> num[i].n;
			num[i].i = i;
		}
		sort(num, num + n);
		for (int i = 0; i < n; ++i)
		{
			num[i].i_af_s = i;
		}
		s = true;
		sort(num, num + n);
		g = 1;
		update(1, 0, n - 1, num[0].i_af_s, num[0].n);
		cout << num[0].n << " ";
		for (int i = 1; i < n; i += 2)
		{
			update(1, 0, n - 1, num[i].i_af_s, num[i].n);
			update(1, 0, n - 1, num[i + 1].i_af_s, num[i + 1].n);
			cout << numbers[get_kth(1, 0, n - 1, (i + 2) / 2 + 1)];
			++g;
			if (g == 10)
				cout << endl;
			else
				cout << " ";
		}
	}
	return 0;
}