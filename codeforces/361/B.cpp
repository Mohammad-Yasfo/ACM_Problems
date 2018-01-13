#include <iostream>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;

	if ( n == k)
	{
		cout << -1 << endl;
		return 0;
	}
if(n==1)
{
cout<<1<<endl;
return 0;
}
	if (k == n - 1)
		cout << 1 << " ";
	else
		cout << n << " ";
	for (int i = 1; i < n; ++i)
	{
		if (k>0)
			cout << i + 1 << " ";
		else if (k == 0)
			cout << 1 << " ";
		else
			cout << i<< " ";
		--k;
	}
	cout << endl;
	return 0;
}