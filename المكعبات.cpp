#include <iostream>
#include <set>
#include <minmax.h>
using namespace std;
int n, a, mx = 0, sel = 0;
bool vis[100009] = { false };
int num[100009];
int main()
{
	set<pair<int, int> >f;
	cin >> n;
	for (int q = 0; q < n; ++q)
	{
		cin >> num[q];
	}

	int i = 0, j = 0, sel = 0, mx = 0;
	vis[num[0]] = true;
	while (j < n)
	{
		if (i == j)
			++j, sel++;
		if (vis[num[j]])
		{
			f.erase(f.find(make_pair(num[i], i)));
			vis[num[i]] = false;
			++i;
			--sel;
		}
		else
		{
			vis[num[j]] = true;
			f.insert(make_pair(num[j], j));
			++sel;
			++j;
			if ((*f.rbegin()).first == sel)
				if (mx < sel)
					mx = sel;
		}
	}
	cout << mx << endl;
	return 0;
}