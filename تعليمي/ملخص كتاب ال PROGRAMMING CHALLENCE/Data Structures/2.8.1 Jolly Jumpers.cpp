/*
خاطئة تحتاج إلى ترجمة صحيحة
*/
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{	
	ifstream fin ("jj.in");
	ofstream fout ("jj.out");
start:char n [6000]={0};
	fin.getline (n,6000);
	string c="";
	if (n==c)
		return 0;
	char *g=find (n,n+6000,'-');
	if (*g==-52)
		fout<<"jolly"<<endl;
	else
		fout<<"not jolly"<<endl;
	goto start;
}