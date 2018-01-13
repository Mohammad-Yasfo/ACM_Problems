#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}
int main()
{
	int n;
	int num[109];
	cin >> n;
	for (int i = 0; i<n; ++i)
		cin >> num[i];
	sort(num, num + n);
	int min = num[0];
	for (int i = 1; i<n; ++i)
			min = gcd(min,num[i]);
		cout << min*n << endl;
	return 0;
}