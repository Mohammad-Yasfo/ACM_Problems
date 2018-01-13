#include <iostream>
#include<vector>
using namespace std;
#define inf 100009
int num[inf];
vector<int> sgt[4 * inf];
#define mid (l+r)/2
#define le sgt[node*2]
#define ri sgt[node*2+1]
#define sel sgt[node]
int n, m;
void build(int node, int l, int r)
{
	if (l == r)
	{
		sgt[node].push_back(num[l]);
		return;
	}
	build(node * 2, l, mid);
	build(node * 2 + 1, mid + 1, r);
	int a1 = 0, a2 = 0, n1 = mid - l + 1, n2 = r - mid;
	while (a1 < n1 && a2 < n2)
	{
		if (le[a1] < ri[a2])
			sel.push_back(le[a1++]);
		else
			sel.push_back(ri[a2++]);
	}
	while (a1 < n1)
		sel.push_back(le[a1++]);
	while (a2 < n2)
		sel.push_back(ri[a2++]);
}
int que1(int node, int l, int r, int s, int e, int val)
{
	if (r<s || l>e)return 0;
	if (s <= l && e >= r)
	{
		int a1 = 0, a2 = sel.size() - 1, middle;
		while (a1 < a2)
		{
			middle = (a1 + a2) / 2;
			if (sel[middle] < val)
				a1 = middle + 1;
			else
				a2 = middle - 1;
		}
		if (sel[a1] >= val)
			--a1;
		return a1 + 1;
	}
	int a = que1(node * 2, l, mid, s, e, val);
	int b = que1(node * 2 + 1, mid + 1, r, s, e, val);
	return a + b;
}
pair<int, bool> que2(int node, int l, int r, int s, int e, int val)
{
	if (r<s || l>e)return make_pair(-1, false);
	if (s <= l && e >= r)
	{
		int a1 = 0, a2 = sel.size() - 1, middle, h;
		while (a1 < a2)
		{
			middle = (a1 + a2) / 2;
			h = que1(1, 0, n - 1, s, e, sel[middle]);
			if (h + 1 == val)
				return make_pair(sel[middle], true);
			else if (h < val)
				a1 = middle + 1;
			else
				a2 = middle - 1;
		}
		h = que1(1, 0, n - 1, s, e, sel[a1]);
		if (h + 1 == val)
			return make_pair(sel[a1], true);
		return make_pair(-1, false);
	}
	pair<int, bool> a = que2(node * 2, l, mid, s, e, val);
	pair<int, bool> b = que2(node * 2 + 1, mid + 1, r, s, e, val);
	if (a.second)
		return a;
	return b;
}
int main()
{
	int  a, b, k;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	build(1, 0, n - 1);
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> k;
		cout << que2(1, 0, n - 1, a - 1, b - 1, k).first << endl;
	}
	return 0;
}