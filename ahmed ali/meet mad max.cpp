#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int T, N, M;
	long long num[109];
	int sel, sol,n1,n2;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> M >> N;
		sol = -1;
		for (int q = 0; q < N; ++q)
			cin >> num[q];
		sort(num, num + N);
		for (int a = 0; a < N; ++a)
		{
			for (int b = a + 1; b < N; ++b)
			{
				long long e = ((num[a] % M)*(num[b] % M)) % M;
				if (sol<e)
				{
					sol = e;
					n1 = num[a];
					n2 = num[b];
				}
			}
		}
		cout << n1<<" "<<n2 << endl;
	}
	return 0;
}