#include <iostream>
#include <string>
using namespace std;
int main()
{
	string word;
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> word;
		if (word[0] == 'X')
		{
			if (word[1] == '+')
				++sum;
			else
				--sum;
		}
		else if (word[0] == '+')
			++sum;
		else
			--sum;
	}
	cout << sum << endl;
}