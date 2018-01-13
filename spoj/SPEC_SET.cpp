#include <iostream>
#include <set>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	int n, k, sum;
	set<int>m;
	for (int i = 0; i < t; ++i)
	{
		scanf("%d%d", &n, &k);
		if (k == 1)
		{
			printf("0\n");
			continue;
		}
		sum = n;
		m.clear();
		for (int q = 1; q*k <= n; ++q)
		{
			if (m.find(q)!=m.end())
				continue;
			--sum;
			m.insert(q*k);
		}
		printf("%d\n", sum);
	}
	return 0;
}