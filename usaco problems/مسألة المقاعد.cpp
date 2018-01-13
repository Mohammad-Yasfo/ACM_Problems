/*#include <iostream>
#include <algorithm>
using namespace std;
struct nod
{
	int p, e;
};
bool operator< (nod a1, nod a2)
{
	return a1.e>a2
}
int main()
{
	int n, k;
	cin >> n >> k;
	nod num[100009];
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i].p >> num[i].e;
	}
	sort(num, num + n);
	return 0;
}*/
#include <fstream>
#include <iostream>
using namespace std;
struct nod
{
	int l, r, m;
};
#define MAX 500009
int sumfail = 0;
nod sgt[4 * MAX];
int lzy[4 * MAX];
#define sel sgt[node]
#define le sgt[2*node]
#define ri sgt[2*node+1]
#define max(a,b) (a)>(b)?(a):(b)
int n, m, b, c;

void syc(int node, int l, int r)
{
	sel.l = le.l;
	if (le.l == (l + r) / 2 - l + 1)
	{
		sel.l += ri.l;
	}
	sel.r = ri.r;
	if (ri.r == r - ((l + r) / 2 + 1) + 1)
	{
		sel.r += le.r;
	}
	sel.m = max(le.m, ri.m);
	sel.m = max(sel.m, ri.l + le.r);
}
void build(int node, int l, int r)
{
	lzy[node] = -1;
	if (l == r)
	{
		sel.l = sel.r = sel.m = 1;
		return;
	}
	build(node * 2, l, (l + r) / 2);
	build(node * 2 + 1, (l + r) / 2 + 1, r);
	syc(node, l, r);
}
void lazy_update(int node, int l, int r)
{
	if (lzy[node] == -1)
		return;
	if (l != r)
	{
		lzy[node * 2] = lzy[node];
		lzy[node * 2 + 1] = lzy[node];
	}
	sel.l = sel.m = sel.r = lzy[node] * (r - l + 1);
	lzy[node] = -1;
}
void update(int node, int l, int r, int s, int e, int val)
{
	lazy_update(node, l, r);
	if (r<s || l>e)return;
	if (s <= l && e >= r)
	{
		lzy[node] = val;
		lazy_update(node, l, r);
		return;
	}
	update(node * 2, l, (l + r) / 2, s, e, val);
	update(node * 2 + 1, (l + r) / 2 + 1, r, s, e, val);
	syc(node, l, r);
}
void add(int node, int l, int r, int num)
{
	lazy_update(node, l, r);
	lazy_update(node * 2, l, (r + l) / 2);
	lazy_update(node * 2 + 1, (l + r) / 2 + 1, r);
	if (l != r)
	{
		if (le.m >= num)
		{
			add(node * 2, l, (l + r) / 2, num);
			return;
		}

	}
	if (num == r - l + 1 && sel.m == r - l + 1)
	{
		update(1, 0, n - 1, l, l + num - 1, 0);
		return;
	}
	if (le.r + ri.l >= num)
	{
		int st = (l + r) / 2 + 1 - le.r;
		update(1, 0, n - 1, st, st + num - 1, 0);
		return;
	}
	if (l != r)
	{
		if (ri.m >= num)
		{
			add(node * 2 + 1, (l + r) / 2 + 1, r, num);
			return;
		}
	}
	++sumfail;
}
int main()
{
	ifstream fin("seating.in");
	ofstream fout("seating.out");
	fin >> n >> m;
	char a;
	build(1, 0, n - 1);
	for (int i = 0; i < m; ++i)
	{
		fin >> a;
		if (a == 'A')
		{
			fin >> b;
			add(1, 0, n - 1, b);

		}
		else
		{
			fin >> b >> c;
			update(1, 0, n - 1, b - 1, c - 1, 1);

		}
	}
	fout << sumfail << endl;
	return 0;
}