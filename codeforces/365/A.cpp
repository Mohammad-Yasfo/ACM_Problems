#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n, k, sum = 0;
	string w;

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		bool q[10] = { false };
		cin >> w;
		for (int j = 0; j < w.length(); ++j)
		{
			q[w[j] - 48] = true;
		}
		for (int i = 0; i <= k; ++i)
		if (!q[i])
			goto f;
		++sum;
	f:;
	}
	cout << sum << endl;
	return 0;
}