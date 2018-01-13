#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int map[53][53];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			cin >> map[i][j];
			map[i][j] += map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1];
		}
	int sol = 0;
	int sel, s, seli, selj;
	for (int sti = 1; sti <= n; ++sti)
		for (int stj = 1; stj <= n; ++stj){
			for (int i = sti; i <= n; ++i)
				for (int j = stj; j <= n; ++j)
				{
					sel = map[i][j] - map[sti - 1][j] - map[i][stj - 1] + map[sti - 1][stj - 1];
					for (int a = i + 1; a <= n; ++a)
						for (int b = j + 1; b <= n; ++b)
						{
							//if (a == i && b == j)continue;
							s = map[a][b] - map[i][b] - map[a][j] + map[i][j];
							if (sel == s)
								++sol;
						}
					seli = i + 1, selj = stj - 1;
					for (int a = seli; a <= n; ++a)
						for (int b = selj; b > 0; --b)
						{
							//	if (a == seli && b == selj)continue;
							s = map[a][selj] - map[a][b - 1] - map[seli - 1][selj] + map[seli - 1][b - 1];
							if (sel == s)
								++sol;
						}
				}
		}
	cout << sol << endl;
	return 0;
}