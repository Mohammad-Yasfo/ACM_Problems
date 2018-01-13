#include <algorithm>
#include <iostream>
using namespace std;
#define inf 200009
int sgt[inf * 4];
pair<int, int> nums[inf];
int arr[inf];
int idx[inf];
int real[inf];
int n;
#define mid (l+r)/2
void build(int node, int l, int r)
{
	if (l == r)
	{
		idx[l] = node;
		return;
	}
	build(node * 2, l, mid);
	build(node * 2 + 1, mid + 1, r);
}
void add(int node)
{
	if (sgt[node] > 0)
		return;
	while (node > 0)
	{
		sgt[node] ++;
		node /= 2;
	}
	++n;
}
void del(int node)
{
	if (sgt[node] == 0)
		return;
	while (node > 0)
	{
		sgt[node] --;
		node /= 2;
	}
	--n;
}
int query(int node, int l, int r, int k)
{
st:
	if (l == r)
	{
		return real[l];
	}
	if (sgt[node * 2] >= k)
	{
		r = mid;
		node *= 2;
		goto st;
	}
	else
	{
		l = mid + 1;
		k -= sgt[node * 2];
		node = node * 2 + 1;
		goto st;
	}

}
int binary_search(int l, int r, int k)
{
	int  middle;
	while (l < r)
	{
		middle = (l + r) / 2;
		if (real[middle] == k)
			return middle;
		if (real[middle] < k)
			l = middle + 1;
		else
			r = middle - 1;
	}
	return l;
}
int sum(int node, int l, int r, int s, int e)
{
	if (l>e || r < s)return 0;
	if (s <= l &&e >= r)
		return sgt[node];
	int a = sum(node * 2, l, mid, s, e);
	int b = sum(node * 2 + 1, mid + 1, r, s, e);
	return a + b;
}
int main()
{
	scanf("%d", &n);
	//cin >> n;
	//	cin.sync_with_stdio(false);
	int cur = 0, comidx = 0;
	pair<char, int> com[inf];
	char q;
	int e;
	for (int i = 0; i < n; ++i)
	{
		//cin >> q >> e;
		scanf(" %c %d", &q, &e);
		if (q == 'I')
			nums[cur++] = make_pair(e, cur);
		com[comidx++] = make_pair(q, e);
	}
	sort(nums, nums + cur);
	int vi = 0;
	real[vi] = nums[0].first;
	for (int i = 1; i < cur; ++i)
	{
		if (nums[i].first != nums[i - 1].first)
			++vi;
		real[vi] = nums[i].first;
	}
	int mx = vi, a;
	n = 0;
	build(1, 0, mx);
	for (int i = 0; i < comidx; ++i)
	{
		if (com[i].first == 'I')
		{
			a = binary_search(0, mx, com[i].second);
			add(idx[a]);
		}
		else if (com[i].first == 'D')
		{
			a = binary_search(0, mx, com[i].second);
			if (real[a] == com[i].second)
				del(idx[a]);

		}
		else if (com[i].first == 'K')
		{
			if (com[i].second > n)
				printf("invalid\n");
			else
				printf("%d\n", query(1, 0, mx, com[i].second));
		}
		else if (com[i].first == 'C')
		{
			a = binary_search(0, mx, com[i].second);
			if (real[a] >= com[i].second)
				--a;
			if (a >= 0)
				printf("%d\n", sum(1, 0, mx, 0, a));
			else
				printf("0\n");

		}
	}
	return 0;
}