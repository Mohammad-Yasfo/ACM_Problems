#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define min(a,b) (a)<(b)?(a):(b)
int main()
{
	string word;
	int nums[25];
	int N, B, sel, mins = 21000009, f;
	scanf_s("%d", &N);
	scanf_s("%d", &B);
	int Q = 1<<N;
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d", &nums[i]);
	}
	int j, t;
	for (int i = 0; i < Q; ++i)
	{
		word = "";
		f = i;
		sel = 0, j = 0;
		while (f > 0)
		{
			t = (f % 2);
			if (t == 1)
				sel += nums[j];
			f /= 2;
			++j;
		}
		if (sel >= B)
			mins = min(mins, sel - B);
	}
	printf("%d", mins);
	cout << endl;
	return 0;
}