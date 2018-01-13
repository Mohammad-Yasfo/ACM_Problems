#include <fstream>
#include <string>
using namespace std;
void main()
{
	ifstream fin("encode.in");
	ofstream fout("encode.out");
	string word;
	int number;
	fin>>number;
	while (number--)
	{
		fin>>word;
		for(int i=0;i<word.length();++i)
			if (word[i]>='A' && word[i]<='Z')
				word[i]='Z'-word[i]+'A';
			else if (word[i]>='a' && word[i]<='z')
				word[i]='z'-word[i]+'a';
		fout<<word<<endl;
	}
	fout.close();
}
