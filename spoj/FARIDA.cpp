#include <iostream>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
int main()
{
	int t, n;
	long long l1, l2, l3, a, maxs;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> n;
		l1 = l2 = l3 = maxs = 0;
		for (int j = 0; j < n; ++j)
		{
			cin >> a;
			a += max(l2, l3);
			if (maxs < a)
				maxs = a;
			l3 = l2;
			l2 = l1;
			l1 = a;
		}
		cout << "Case " << i + 1 << ": " << maxs << endl;

	}
	return 0;
}