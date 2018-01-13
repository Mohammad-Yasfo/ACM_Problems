#include<iostream>
#include<string>
using namespace std;
#define max_word 1009
#define max_pattern 109
int f[max_word];
int lenword, lenprefix;
void set_table(string word)
{
	f[0] = f[1] = 0;
	int j;
	for (int i = 2; i <= lenprefix; ++i){
		j = f[i - 1];
		while (true)
		{
			if (word[j] == word[i - 1])
			{
				f[i] = j + 1;
				break;
			}
			if (j == 0)
			{
				f[i] = 0;
				break;
			}
			j = f[i];
		}
	}
}
int kmp(string text, string pattern)
{
	set_table(pattern);
	int i = 0, j = 0,sum=0;
	while (true)
	{
		if (j == lenword)break;
		if (text[j] == pattern[i])
		{
			++i;
			++j;
			if (i == lenprefix)
			{
				++sum;
			}
		}
		else if (i > 0)
			i = f[i];
		else
			++j;
	}
	return sum;
}
int main()
{
	lenword = 8, lenprefix = 2;
	cout << kmp("aaaaaaaa", "aa") << endl;
	return 0;	
}