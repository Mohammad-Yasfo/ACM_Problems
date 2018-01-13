#include <iostream>
#include <map>
using namespace std;
map<int, long long>m;
#define max(a,b) (a)>(b) ? (a):(b)
long long dp(long long number)
{
	if (m[number] > 0 || number == 0)
		return m[number];
	long long a = (number >= 2 ? dp(number / 2) : 0), b = (number >= 3 ? dp(number / 3) : 0), c = (number >= 4 ? dp(number / 4) : 0);
	m[number] = max(number, a + b + c);
	return m[number];
}
int main()
{
	m[0] = 0;
	int num;
	while (cin >> num)
	{
		cout << dp(num) << endl;
	}
	return 0;
}