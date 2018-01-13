#include <iostream>
using namespace std;
int main()
{
	int i, j, n, s1 = 0, s2 = 0, t1 = 0, t2 = 0, b1 = 0, b2 = 0;
	cin >> n;
	int num[100009];
	for (int a = 0; a < n; ++a)
		cin >> num[a];
	i = 0, j = n - 1;
	while (i < j)
	{
		++t1, ++t2;
		if (t1>num[i])
		{
			++i;
			++b1;
			t1 = 1;
		}
		if (t2 > num[j])
		{
			--j;
			++b2;
			t2 = 1;
		}
	}
	if (t2 > 1)
		++b2;
	else if (t1 > 1)
		++b1;
	else if (i == j && t1 <= 1 && t2 <= 1)
		++b1;
	cout << b1 << " " << b2 << endl;
	return 0;
}