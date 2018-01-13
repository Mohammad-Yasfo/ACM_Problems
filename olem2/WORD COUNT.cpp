#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
struct type
{
	int length;
	int howmany;
	bool operator<(type b)
	{
		return howmany<b.howmany;
	}
};
#define MAX 100
int main()
{
	ifstream fin ("word count.in");
	ofstream fout ("word count.out");
	int sum=0;
	string word;
	type *length=new type[MAX];
	for (int i=0;i<MAX;++i)
	{
		length[i].length=i;
		length [i].howmany=0;
	}
	while (!fin.eof())
	{
		fin>>word;
		++sum;
		++length [word.length()-1].howmany;
	}
	sort(length,length+MAX);
	for (int i=MAX-1;i>=0;--i)
		if (length[i].howmany>0)
			fout<<length[i].length<<'\t'<<length[i].howmany<<'\t'<<(float)length[i].howmany*100/sum<<endl;
	fout << "TOTAL = "<<sum<<endl;
	return 0;
}
