#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int sum, st, en, n, k;
	int num[1000009];
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	sum = 0, st = 0, en = n - 1;
	sort(num, num + n);
	while (st < en)
	{
		if (num[st] + num[en] == k)
		{
			++sum;
			++st;
			--en;
		}
		if (num[st] + num[en] < k)
			++st;
		else if (num[st] + num[en]>k)
			--en;
	}
	cout << sum << endl;
	return 0;
}