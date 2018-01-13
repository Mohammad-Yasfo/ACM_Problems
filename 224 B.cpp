#include <iostream>
using namespace std;
#define min(a,b) (a)<(b)? (a):(b);
int main()
{
	int num[100009];
	int q[100009] = { 0 };
	int n, k;
	cin >> n >> k;
	for (int w = 0; w < n; ++w)
	{
		cin >> num[w];
	}
	int i = 0, j = -1, sel = 0, sol = 9999999, l = -1, r = -1;
	while (i < n)
	{
		if (sel < k)
		{
			++j;
			if (j == n)
				break;
			if (q[num[j]] == 0)
				++sel;
			++q[num[j]];
		}
		if (sel == k)
		{
			if (sol>j - i + 1)
			{
				sol = j - i + 1;
				l = i + 1;
				r = j + 1;
			}
			--q[num[i]];
			if (q[num[i]] == 0)
				--sel;
			++i;
		}
	}
	cout << l << " " << r << endl;
	return 0;
}