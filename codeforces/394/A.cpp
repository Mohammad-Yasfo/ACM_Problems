#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	string word;
	cin >> word;
	int n1 = 0, n2 = 0, n3 = 0, t;
	for (t = 0; word[t] != '+'; ++t)
		++n1;
	++t;
	for (t; word[t] != '='; ++t)
		++n2;
	++t;
	for (t; t < word.length(); ++t)
		++n3;
	if (abs(n1 + n2 - n3)>2 || abs(n1 + n2 - n3) == 1)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	if (n3 > n1 + n2)
	{
		n1++;
		n3--;
	}
	else if (n3 < n1 + n2)
	{
		if (n1 <= 1)
			n2--;
		else
			n1--;
		n3++;
	}
	for (int i = 0; i < n1; ++i)
		cout << "|";
	cout << "+";
	for (int i = 0; i < n2; ++i)
		cout << "|";
	cout << "=";
	for (int i = 0; i < n3; ++i)
		cout << "|";
	cout << endl;
	return 0;
}