#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, k, a;
	vector<int> num;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		num.push_back(a);
	}
	--k;
	long long f_ind = -1;
st:long long ind = 0, maxs = 0, sel;

	for (int i = 0; i <= k; ++i)
		maxs += num[i];
	sel = maxs;
	for (int i = 1; i < n - k; ++i)
	{
		sel -= num[i - 1];
		sel += num[i + k];
		if (maxs < sel)
		{
			maxs = sel;
			ind = i;
		}
	}
	if (f_ind == -1)
	{
		f_ind = ind;
		num.erase(num.begin() + ind, num.begin() + ind + k + 1);
		n -= k+1;
		goto st;
	}
	if (ind + k < f_ind)
		cout << ind + 1 << " " << f_ind + 1 << endl;
	else if (ind < f_ind && ind + k >= f_ind)
		cout << ind + 1 << " " << ind + k + 2 << endl;
	else
		cout << f_ind + 1 << " " << ind + k + 2 << endl;
	return 0;
}