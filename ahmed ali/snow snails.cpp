#include <iostream>
using namespace std;
int main()
{
	int T;
	double sol, n, h;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> n >> h;
		if (n == 1)
			cout << 0 << " " << 0 << endl;
		else
		{
			sol = ((int)(n*(n / 2)))*h;
			cout << 0 << " " << (int)sol << endl;
		}
	}
	return 0;
}