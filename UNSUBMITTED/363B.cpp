#include <iostream>
using namespace std;
int main()
{
	int n, k;
	int num[200009];
	cin >> n >> k;
	cin >> num[0];
	for (int i = 1; i < n; ++i)
	{
		cin >> num[i];
		num[i] += num[i - 1];
	}
	--k;
	int ind = 0, mins = num[k];
	for (int i = 1; i < n - k; ++i)
	{
		if (num[i + k] - num[i - 1] < mins)
		{
			mins = num[i + k] - num[i - 1];
			ind = i;
		}
	}
	cout << ind + 1 << endl;
	return 0;
}