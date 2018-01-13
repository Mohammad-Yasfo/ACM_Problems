#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct cow
{
	int temp;
	int sum;
	bool operator< (cow &rhs)
	{
		return temp<rhs.temp;
	}
};
int main()
{
	int n,lf,rl,a,b,c;
	cin>>n>>a>>b>>c;
	vector<cow> cows;
	cow f;
	f.temp=0;
	f.sum=0;
	cows.push_back(f);
	for (int i=0;i<n;++i)
	{
		cow cs,c2;
		cin>>cs.temp>>c2.temp;
		++c2.temp;
		cows[0].sum+=a;
		cs.sum=b-a;
		c2.sum=c-b;
		cows.push_back(cs);
		cows.push_back(c2);
	}
	sort(cows.begin(),cows.begin()+2*n);
	int max=0,m=0;
	for (int i=0;i<2*n+1;++i)
	{
		m+=cows[i].sum;
		++i;
		while (i<n&& cows[i-1].temp==cows[i].temp)
		{
			m+=cows[i].sum;
			++i;
		}
		--i;
		if (max<m)
			max=m;

	}
	cout<<max<<endl;
	return 0;
}

