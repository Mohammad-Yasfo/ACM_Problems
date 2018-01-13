#include <iostream>
using namespace std;
int main()
{
	int n, m, a;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a;
			if (a == 1 && (j == 0 || i == 0 || i == n - 1 || j == m - 1))
			{
				cout << 2 << endl;
				return 0;
			}
		}
	}
	cout << 4 << endl;
	return 0;
}
