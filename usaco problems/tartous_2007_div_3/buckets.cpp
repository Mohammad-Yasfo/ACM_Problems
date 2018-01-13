/*
الأوعية
*/
#include <fstream>
#include <algorithm>
using namespace std;
int amount[100];
int N=0;
void trans(int &first,int &last,int amount_last)
{
	if (first<amount_last-last)
	{
		last+=first;
		first=0;
	}
	else
	{
		first-=(amount_last-last);
		last=amount_last;
	}
}
bool is_here (int c)
{
	for (int i=0;i<N;++i)
		if (amount[i]==c)
			return true;
	return false;
}
void add(int c)
{
	if (!is_here(c))
	{
		amount [N]=c;
		++N;
	}
}
int main(){
	ifstream fin("buckets.in");
	ofstream fout("buckets.out");
	int am_a,am_b,am_c;
	fin>>am_a>>am_b>>am_c;
	int a=0,b=0,c=am_c;
	add(c);
	trans(c,b,am_b);
	add(c);
	trans(c,a,am_a);
	trans(b,c,am_c);
	trans(a,b,am_b);
	if (a!=0)
		trans(a,c,am_c);
	add(c);

	a=b=0;
	c=am_c;

	while (b!=am_b && c!=0)
	{
		trans(c,a,am_a);
		trans(a,b,am_b);
		if (a==0)
			add(c);
	}
	if (a!=0)
	{
		trans(a,c,am_c);
		add(c);
	}

	a=b=0;
	c=am_c;

	trans(c,a,am_a);
	trans(c,b,am_b);
	trans(a,c,am_c);
	if (a!=0)
		trans(a,b,am_b);
	add(c);
	sort(amount,amount+N);
	for (int i=0;i<N;++i)
		fout<<amount[i]<<" ";
	fout<<endl;
	return 0;
}

