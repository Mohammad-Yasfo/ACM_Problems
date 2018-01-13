#include <iostream>
#include <map>
using namespace std;
int main()
{
	int T, year, N,sol,l,j;
	int num[19];
	cin >> T;
	map<int, int>m;
	map<int, int>::iterator it;
	for (int i = 0; i < T; ++i)
	{
		cin >> year >> N;
		for (int a = 0; a < N; ++a)
			cin >> num[a];
		m.clear();

		for (int s = 1; s < 1 << N; ++s)
		{
			sol = 0;
			j = 0;
			l = s;
			while (l)
			{
				if (l % 2)
					sol += num[j];
				l /= 2;
				++j;
			}
			m[year + sol]++;
		}
		for (it = m.begin(); it != m.end(); ++it)
			if (it->first != year)
				cout << it->first << endl;
	}
	return 0;
}