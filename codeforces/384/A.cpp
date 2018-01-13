#include <iostream>
using namespace std;
int main()
{
	int n, sum = 0;

	bool r = false;
	cin >> n;
	cout << (n / 2)*n + (n % 2 ? (n + 1) / 2 : 0)<<endl;
	for (int i = 0; i < n; ++i){
		if (r)
			cout << '.';
		for (int j = 0 + r; j < n ; j += 2)
		{
			cout << "C";
			if (j + 1 < n)
				cout << '.';
		}
		cout << endl;
		r = !r;
	}
	return 0;
}