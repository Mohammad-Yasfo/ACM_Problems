#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,n_v=0,p=0;
	bool vis[109] = { false };
	int num[109];
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
	}
	sort(num, num + n);
	int sum = 0;
	while (n_v < n){
		sum = 0;
		for (int i = 0; i < n; ++i)
		{
			if (vis[i])
				continue;
			if (num[i] >= sum){
				sum++;
				++n_v;
				vis[i] = true;
			}
		}
		++p;
	}
	cout << p<< endl;
	return 0;
}