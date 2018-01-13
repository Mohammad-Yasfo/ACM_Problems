/*
سلسلة مجاميع العاملي
*/
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
long long get_fact(int x)
{
	if (x==0)return 1;
	long long num=1;
	while (x>0)
	{
		num*=x;
		--x;
	}
	return num;
}
int main(){
	ifstream fin("factsum.in");
	ofstream fout("factsum.out");
	long long n;
	fin>>n;
	vector<int>range;
	range.push_back(n);
	st:string word=static_cast<ostringstream*>( &(ostringstream() << n) )->str();
	n=0;
	for (int i=0;i<word.length();++i)
	{
		n+=get_fact(word[i]-48);
	}
	for (int i=0;i<range.size();++i)
	{
		if (range[i]==n)
		{
			fout<<n<<endl<<range.size()+1<<endl;
			return 0;
		}
	}
	range.push_back(n);
	goto st;
	return 0;
}

