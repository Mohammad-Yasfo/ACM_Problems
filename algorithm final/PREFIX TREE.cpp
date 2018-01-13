#include <iostream>
#include <string>
using namespace std;
class node{
public:
	int words;
	int prefixs;
	node *sons[26];
	node()
	{
		words = prefixs = 0;
		for (int i = 0; i < 26; ++i)
			sons[i] = NULL;
	}
};
node *root = new node();
#define letter_type 97
void addword(node *	v, string word)
{
	v->prefixs++;
	if (word == "")
		v->words++;
	else{
		int k = word[0] - letter_type;
		if (v->sons[k] == NULL)
			v->sons[k] = new node();
		word = word.erase(0,1);
		addword(v->sons[k], word);
	}
}
int count_prefix(node*v, string prefix)
{
	if (prefix == "")
		return v->prefixs;
	else
	{
		int k = prefix[0] - letter_type;
		if (v->sons[k] == NULL)
			return 0;
		else
		{
			prefix = prefix.erase(0,1);
			return count_prefix(v->sons[k], prefix);
		}
	}
}
int main()
{
	int n, q;
	string word;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> q >> word;
		if (q == 0)
			addword(root, word);
		else if (q == 1)
			cout << count_prefix(root, word) << endl;
		else
			cout << "invalid\n";
	}
	return 0;
}