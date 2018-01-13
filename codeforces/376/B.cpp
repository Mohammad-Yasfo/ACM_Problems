#include <iostream>	
#include <map>
using namespace std;
int main()
{
	int n, m, a, b, c, sum = 0;
	int num[109] = { 0 };
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		num[a-1] -= c;
		num[b-1] += c;
	}
	for (int i = 0; i < 100; ++i)
		sum +=(num[i]>0)? num[i]:0;
	cout << sum << endl;
	return 0;
}	