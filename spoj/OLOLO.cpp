#include <iostream>
#include <map>
#include <set>
using namespace std;
#define ncin(a) scanf("%d",&a);
int main()
{
	int a, n, ans = 0;
	ncin(n);
	for (int i = 0; i < n; ++i)
	{
		ncin(a);
		ans ^= a;
	}
	cout << ans << endl;
	return 0;
}