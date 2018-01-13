#include <iostream>
#include <minmax.h>
using namespace std;
int main()
{
	int n, a,q, b, c, d,min_a=9999999,ind,min_c=999999,min_j=999999;
	cin >> n;
	for (int i = 0; i < 4; ++i)
	{
		cin >> a >> b >> c >> d;
		q = min(a, b) + min(c, d);
		if (q<min_a)
		{
			ind = i + 1;
			min_c = min(a,b);
			min_j = min(c, d);
			min_a = min_c + min_j;
		}
	}
	if (min_a>n)
	{
		cout << -1 << endl;
		return 0;
	}
	else if (min_a < n)
		min_c += n - min_a;
	cout << ind << " " << min_c << " " << min_j << endl;
	return 0;
}