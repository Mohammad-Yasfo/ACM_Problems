#include <iostream>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
int main()
{
	int n;
	long long num[100009];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	long long sel = 0, maxs = 0;
	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	for (int i = 2; i < n; ++i)
	{
		if (num[i] == num[i - 1] + num[i - 2])
			++sel;
		else
		{
			maxs = max(maxs, sel);
			sel = 0;
		}
	}
	maxs = max(maxs, sel);
	cout << maxs+2 << endl;
	return 0;
}