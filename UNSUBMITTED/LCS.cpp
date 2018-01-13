#include <iostream>
#include <string>
using namespace std;
int arr[109][109];
string w1, w2;
#define max(a,b) (a)>(b)?(a):(b)
int main()
{
	int n, m;
	cin >> n >> m;
	cin >> w1 >> w2;;
	memset(&arr, -1, sizeof (arr));
	arr[0][0] = arr[0][1] = arr[1][0] = 0;
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= m; ++j)
	{
		if (w1[i - 1] == w2[j - 1])
			arr[i][j] = arr[i - 1][j - 1] + 1;
		else
			arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
	}
	string word = "";
	int i = n, j = m;
	while (i > 0 || j > 0)
	{
		if (i>0 && arr[i - 1][j] == arr[i][j])
			--i;
		else if (j>0 && arr[i][j - 1] == arr[i][j])
			--j;
		else
		{
			word += w1[i-1];
			--i, --j;
		}
	}

	for (int i = 0; i < word.length()/2; ++i)
		swap(word[i], word[word.length() - 1 - i]);
	cout << arr[n][m] << endl << word << endl;
}