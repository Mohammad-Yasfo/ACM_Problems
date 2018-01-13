#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct node
{
	int l;
	int index;
};
bool operator<(node a1, node a2)
{
	if (a1.index == a2.index)
		return a1.l < a2.l;
	return a1.index < a2.index;
}
int main()
{
	int t, n = 0, nv;
	node num[10009];
	bool vis[10009];
	queue<int> numbers;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> n;
		for (int j = 0; j < n; ++j)
			cin >> num[j].l;
		for (int j = 0; j < n; ++j)
		{
			cin >> num[j].index;
			vis[j] = false;
		}
		sort(num, num + n);
		nv = 1;
		if (n>0)
			numbers.push(num[0].l);
		bool th = true;
		vis[0] = true;
		while (nv < n)
		{
			for (int i = 1; i < n; ++i){
				if (num[i].index != num[i - 1].index)
					th = false;
				if (!vis[i] && !th)
				{
					numbers.push(num[i].l);
					++nv;
					vis[i] = true;
					th = true;
				}
			}
			th = false;
		}
		while (!numbers.empty())
		{
			cout << numbers.front()<<" ";
			numbers.pop();
		}
		cout << endl;
	}
	return 0;
}