#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	string w1, w2;
	int T,sum;
	map<char, int>m;
	map<char, int>::iterator it;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		sum = 0;
		cin >> w1 >> w2;
		m.clear();
		for (int j = 0; j < w1.length(); ++j)
			++m[w1[j]];
		for (int j = 0; j < w2.length(); ++j)
			--m[w2[j]];
		for (it=m.begin(); it!=m.end(); ++it)
		{
			if (it->second > 0)
				sum += it->second;
			if (it->second< 0)
				sum += -(it->second);
		}
		cout << sum << endl;
	}
	return 0;
}