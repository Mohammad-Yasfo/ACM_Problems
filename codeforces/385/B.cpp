#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main()
{
	string word, c;
	queue <int> beg, end;
	cin >> word;
	int len = word.length();
	for (int i = 0; i < len - 3; ++i)
	{
		c = word[i], c += word[i + 1], c += word[i + 2], c += word[i + 3];
		if (c == "bear")
		{
			beg.push(i);
			end.push(i + 3);
		}
	}
	long long sum = 0;
	for (int i = 0; i < len && !beg.empty(); ++i)
	{
		sum += len - end.front();
		if (beg.front() == i)
		{
			beg.pop();
			end.pop();
		}
	}
	cout << sum << endl;
}