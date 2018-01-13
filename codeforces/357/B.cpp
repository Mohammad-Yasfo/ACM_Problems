#include <iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int a, b, c;
	int num[100009] = { 0 };
	bool vis[3];
	for (int i = 0; i < m; ++i)
	{
		vis[0] = vis[1] = vis[2] = false;
		cin >> a >> b >> c;
		if (num[a] != 0) vis[num[a] - 1] = true;
		if (num[b] != 0) vis[num[b] - 1] = true;
		if (num[c] != 0) vis[num[c] - 1] = true;
		if (num[a] == 0)
		for (int i = 0; i < 3; ++i)
		if (!vis[i])
		{
			vis[i] = true;
			num[a] = i + 1;
			break;
		}
		if (num[b] == 0)
		for (int i = 0; i < 3; ++i)
		if (!vis[i])
		{
			vis[i] = true;
			num[b] = i + 1;
			break;
		}
		if (num[c] == 0)
		for (int i = 0; i < 3; ++i)
		if (!vis[i])
		{
			vis[i] = true;
			num[c] = i + 1;
			break;
		}
	}
	for (int i = 1; i <= n; ++i)
		cout << num[i] << " ";
	cout << endl;
	return 0;
}
