#include <iostream>
#include <map>
using namespace std;
bool is_prime(long long a)
{
	int t = sqrt((long double)a);
	if (a % 2 == 0)
		return false;
	for (int i = 3; i <= t; i += 2)
	if (a%i == 0)
		return false;
	return true;
}
#define inf 10009
int main()
{
	long long n, m;
	long long primes[inf + 1] = { 0 };
	long long a, r;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		r = sqrt(a);
		if (is_prime(a))
		{
			++primes[a];
			continue;
		}
		if (a % 2 == 0)
			++primes[2];
		while (a % 2 == 0)
			a /= 2;

		for (int j = 3; j <= r && a > 1; j += 2)
		{

			if (a%j == 0)
			{
				++primes[j];
			}
			while (a%j == 0)
				a /= j;
			if (is_prime(a))
			{
				++primes[a];
				break;
			}
		}

	}
	for (int i = 1; i < inf; ++i)
		primes[i] += primes[i - 1];
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> r;
		if (a >= inf){
			cout << 0 << endl;
			continue;
		}
		else if (r>inf)
			r = inf - 1;
		cout << primes[r] - (a > 0 ? primes[a - 1] : 0) << endl;
	}
}