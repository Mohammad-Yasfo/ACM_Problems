#include <iostream>
using namespace std;
int main()
{
	int n,a;
	scanf("%d", &n);
	int sum = 0;
	bool ish[20009] = { false };
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		++sum;
		if (a>0 && ish[a - 1])
			--sum;
		if (ish[a + 1])
			--sum;
		ish[a] = true;
		printf("%d\n", sum);
	}
	printf("Justice\n");
	return 0;
}