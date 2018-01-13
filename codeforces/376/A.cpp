#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
	long long sum=0;
	string w;
	stack<int>f;
	cin >> w;
	int i = 0;
	for (; i < w.length(); ++i)
	{
		if (w[i] == '^')
			break;
		if (w[i] == '=')
			f.push(0);
		else
			f.push(w[i] - 48);
	}
	++i;
	for (int s = 1; i < w.length(); ++i,++s)
	{
		if (w[i] != '=')
			sum += s*(w[i] - 48);
	}
	for (int j = 1; !f.empty(); ++j)
	{
		sum -= j*f.top();
		f.pop();
	}
	if (sum == 0)
		cout << "balance"<<endl;
	else if (sum > 0)
		cout << "right"<<endl;
	else
		cout << "left"<<endl;
}