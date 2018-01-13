#include <iostream>
using namespace std;
int main()
{
	int n;
	char w[109][109];
	bool vis[109][109];
	cin >> n;
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
	{
		cin >> w[i][j]; vis[i][j] = false;
	}
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
	{
		if (!vis[i][j] && w[i][j] == '#')
		{
			if (i == n - 1 || vis[i + 1][j] || w[i + 1][j] == '.')
			{
				cout << "NO" << endl;
				return 0;
			}
			if (j == n - 1 || vis[i + 1][j + 1] || w[i + 1][j + 1] == '.')
			{
				cout << "NO" << endl;
				return 0;
			}
			if (j == 0 || vis[i + 1][j - 1] || w[i + 1][j - 1] == '.')
			{
				cout << "NO" << endl;
				return 0;
			}
			if (i == n - 2 || vis[i + 2][j] || w[i + 2][j] == '.')
			{
				cout << "NO" << endl;
				return 0;
			}
			vis[i][j] = vis[i + 1][j] = vis[i + 2][j] = vis[i + 1][j + 1] = vis[i + 1][j - 1] = true;
		}
	}
	cout << "YES" << endl;
	return 0;
}