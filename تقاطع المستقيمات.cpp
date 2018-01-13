#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define inf 100009
struct nod
{
	int x;
	int y1, y2;
	bool isend;
	bool isvec;
	nod(bool isv, int x_axis, int yb, int ye, bool is){
		isvec = isv;
		x = x_axis;
		y1 = yb;
		y2 = ye;
		isend = is;
	}
};
int sgt[inf * 8];
void update(int node, int l, int r, int t, int val)
{
	if (t<l || t>r)return;
	if (l == r)
	{
		sgt[node] += val;
		return;
	}
	else
	{
		int m;
		if (l + r < 0 && (l + r) % 2)
			m = (l + r) / 2 - 1;
		else
			m = (l + r) / 2;
		update(node * 2, l, m, t, val);
		update(node * 2 + 1, m + 1, r, t, val);
	}
	sgt[node] = sgt[node * 2] + sgt[node * 2 + 1];
}
int query(int node, int l, int r, int s, int e)
{
	if (l > e || r < s)return 0;
	if (s <= l && e >= r)
		return sgt[node];
	int a, b, m;
	if (l + r < 0 && (l + r) % 2)
		m = (l + r) / 2 - 1;
	else
		m = (l + r) / 2;
	a = query(node * 2, l, m, s, e);
	b = query(node * 2 + 1, m + 1, r, s, e);
	return a + b;
}
bool operator<(nod a1, nod a2)
{
	return a1.x < a2.x || (a1.x == a2.x && a1.isvec);
}
int main()
{
	int n;
	int q, yx1, yx2, yxt;
	scanf_s("%d", &n);
	vector<nod>events;
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d%d%d%d", &q, &yxt, &yx1, &yx2);
		if (q == 0)
		{
			if (yx1>yx2)
				swap(yx1, yx2);
			nod w(false, yx1, yxt, -1, false), w2(false, yx2, yxt, -1, true);
			events.push_back(w);
			events.push_back(w2);
		}
		else
		{
			if (yx1 > yx2)
				swap(yx1, yx2);
			nod v(true, yxt, yx1, yx2, false);
			events.push_back(v);
		}
	}
	int sum = 0;
	sort(events.begin(), events.end());
	for (int i = 0; i < events.size(); ++i)
	{
		if (!events[i].isvec)
		{
			if (events[i].isend)
				update(1, -inf, inf, events[i].y1, -1);
			else
				update(1, -inf, inf, events[i].y1, 1);
		}
		else
		{
			sum += query(1, -inf, inf, events[i].y1, events[i].y2);
		}
	}
	printf("%d\n", sum);
	return 0;
}