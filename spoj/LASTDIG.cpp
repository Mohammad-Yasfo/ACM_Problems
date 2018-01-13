#include <iostream>
using namespace std;
int main()
{
	int square[] = { 0, 1, 4, 9, 6, 5, 6, 9, 4, 1 };
	int t, a, b;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		scanf("%d%d", &a, &b);
		int dig = a % 10;
		int sol = 1;
		while (b)
		{
			if (b % 2)
			{
				sol = (sol*dig) % 10;
			}
			dig = square[dig];
			b /= 2;
		}
		printf("%d", sol);
	}
}