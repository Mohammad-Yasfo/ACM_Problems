/*
قاموس النمل
*/
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
string word;
void convert (){
	for (int i=0;i<word.length();++i){
		if (isupper(word [i]))
			word [i]+=32;
		else if ((word [i]<90) || (word [i]>122))
			word.erase(i);
	}
}
int main()
{
	ifstream fin ("dic.in");
	ofstream fout ("dic.out");
	string words [5000];
	int number=0;
	while (!fin.eof()){
		fin>>word;
		string c="";
		convert ();
		string *u=find(words,words+number,word);
		if ((u->size()==0) && (word!=c))
			words[number++]=word;
	}
	sort(words,words+number);
	for (int i=0;i<number;++i)
		fout<<words [i]<<endl;
	return 0;
}