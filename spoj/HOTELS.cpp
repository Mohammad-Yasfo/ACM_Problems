#include <iostream>
using namespace std;
int main()
{
	int N, M;
	int num[300009];
	cin >> N >> M;
	for (int a = 0; a < N; ++a)
		scanf("%d",&num[a]);
	int i = 0, j = 0;
	long long sel = 0, maxs = 0;
	while (j < N)
	{
		if (num[j] + sel <= M)
		{
			sel += num[j];
			if (maxs < sel)
				maxs = sel;
			++j;
		}
		else
		{
			sel -= num[i];
			++i;
			if (i>j)
				j = i;
		}
	}
	cout << maxs << endl;
	return 0;
}