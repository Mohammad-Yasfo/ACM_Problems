#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, n_c=0 ,n_c2= 0;
	int num[109];
	int couple[2][1000009];
	int q1 = 0, q2 = 0;
	long long sel = 0, sol = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &num[i]);
	for (int a = 0; a < n; ++a)
		for (int b = 0; b < n; ++b)
			for (int c = 0; c < n; ++c)
			{
				couple[0][n_c++] = num[a] * num[b] + num[c];
				if (num[a]!=0)
					couple[1][n_c2++] = num[a] * (num[b] + num[c]);
			}
	sort(couple[0], couple[0] + n_c);
	sort(couple[1], couple[1] + n_c2);
	while (q1 < n_c && q2 < n_c2)
	{
		if (couple[0][q1] >= couple[1][q2])
		{
			if (couple[0][q1] == couple[1][q2])
				++sel;
			++q2;
		}
		else
		{
			sol += sel;
			while (true){
				++q1;
				if (q1 < n_c && couple[0][q1] == couple[0][q1 - 1])
					sol += sel;
				else
					break;
			}
			sel = 0;
		}
	}
	sol += sel;
	while (true){
		++q1;
		if (q1 < n_c && couple[0][q1] == couple[0][q1 - 1])
			sol += sel;
		else
			break;
	}
	cout << sol << endl;
}
