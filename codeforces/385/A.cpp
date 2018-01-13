#include <iostream>
using namespace std;
int main()
{
	long long n, c,ind=-1,maxs=0;
	long long num[109];
	cin >> n >> c;
	cin >> num[0];
	for (int i = 1; i < n; ++i)
	{
		cin >> num[i];
		if (num[i - 1] - num[i]>maxs)
		{
			maxs = num[i - 1] - num[i];
			ind = i - 1;
		}
	}
	if (ind == -1)
		cout << 0 << endl;
	else if (num[ind] - num[ind + 1] - c > 0)
		cout << num[ind] - num[ind + 1] - c << endl;
	else
		cout << 0 << endl;
	return 0;
}