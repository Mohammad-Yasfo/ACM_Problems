#include <iostream>
using namespace std;
int main()
{
	long long n, t, num[109][109], maxs;
	scanf("%lld", &t);
	for (int i = 0; i < t; ++i)
	{
		scanf("%lld", &n);
		for (int j = 0; j < n; ++j)
		{
			for (int a = 0; a <= j; ++a)
			{
				scanf("%lld", &num[j][a]);
				if (j == 0)continue;
				num[j][a] += max((a == 0 ? 0 : num[j - 1][a - 1]), (a == j ? 0 : num[j - 1][a]));
			}
		}
		maxs = 0;
		for (int i = 0; i < n; ++i)
			maxs = max(maxs, num[n - 1][i]);
		printf("%lld\n", maxs);
	}
	return 0;
}