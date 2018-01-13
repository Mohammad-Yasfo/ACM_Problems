#include <iostream>
#include <algorithm>
using namespace std;
#define inf 100009
#define mid (l+r)/2
int sgt[4 * inf];
int idx[inf];
void build(int node, int l, int r)
{
	sgt[node] = 0;
	if (l == r)
	{
		idx[l] = node;
		return;
	}
	build(node * 2, l, mid);
	build(node * 2 + 1, mid + 1, r);
}
void update(int node, int val)
{
	while (node > 0)
	{
		sgt[node]++;
		node /= 2;
	}
}
int query(int node, int l, int r, int s, int e)
{
	if (l > e || r < s)return 0;
	if (s <= l && e >= r)
		return sgt[node];
	int a = query(node * 2, l, mid, s, e);
	int b = query(node * 2 + 1, mid + 1, r, s, e);
	return a + b;
}
struct events
{
public:
	int x;
	int y1, y2;
	bool isver;
	bool isend;
	events()
	{
	}
	events(bool type, int xs, int ys, int y2s, bool is = false)
	{
		isver = type;
		x = xs;
		y1 = ys;
		y2 = y2s;
		isend = is;
	}
};
events nums[inf];
pair<int, int> yaxis[inf];
bool operator<(events y1, events y2)
{
	return  y1.x < y2.x || (y1.x==y2.x && !y1.isver);
}
int binary_search(int l, int r, int k)
{
	while (l < r)
	{
		if (yaxis[mid].first == k)
			return mid;
		if (yaxis[mid].first < k)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return mid;
}
int main()
{
	int x1, x2, y1, y2;
	int n, cnt = 0, cny = 0;
	int sum = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (x1 == x2)
		{
			events q(true, x1, y1, y2);
			nums[cnt++] = q;
		}
		else
		{
			if (y1>y2)
			{
				int temp = y1;
				y1 = y2;
				y2 = temp;
			}
			events q1(false, x1, y1, -1, false);
			events q2(false, x2, y1, -1, true);
			yaxis[cny++] = make_pair(y1, cnt);
			nums[cnt++] = q1;
			yaxis[cny++] = make_pair(y2, cnt);
			nums[cnt++] = q2;
		}
	}
	sort(yaxis, yaxis + cny);
	sort(nums, nums + cnt);
	int vi = 0;
	nums[yaxis[vi].second].y1 = vi;
	for (int i = 1; i < cny; ++i)
	{
		if (yaxis[i].first != yaxis[i - 1].first)
			++vi;
		nums[yaxis[i].second].y1 = vi;
	}
	build(1, 0, vi);
	for (int i = 0; i < cnt; ++i)
	{
		if (nums[i].isver)
		{
			int a = binary_search(0, vi, nums[i].y1);
			int b = binary_search(0, vi, nums[i].y2);
			if (yaxis[a].first < nums[i].y1)
				++a;
			if (yaxis[b].first>nums[i].y2)
				--b;
			if (a>vi || b < 0)
				continue;
			sum += query(1, 0, vi, a, b);
		}
		else
		{
			if (nums[i].isend)
				update(idx[nums[i].y1], -1);
			else
				update(idx[nums[i].y1], 1);
		}
	}
	cout << sum << endl;
	return 0;
}