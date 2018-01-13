#include <iostream>
using namespace std;
int main()
{
	int N,a,maxlog=-1,select_max,numodd=0;
	cin>>N;
	for (int i=0;i<N;++i)
	{
		select_max=0;
		cin>>a;
		while (a>0)
		{
			if (a%2==0)
			{
				a/=2;
				++select_max;
			}
			else
			{
				numodd++;
				a--;
			}
		}
		maxlog=max(select_max,maxlog);
	}
	cout<<maxlog+numodd<<endl;
	return 0;
}
#include <vector>
using namespace std;

class IncrementAndDoubling{
public:
	int getMin(vector <int> numbers){
		int n=numbers.size();
		int maxlog=-1,a,select_max,numodd=0;
	for (int i=0;i<n;++i)
	{
		select_max=0;
		a=numbers[i];
		while (a>0)
		{
			if (a%2==0)
			{
				a/=2;
				++select_max;
			}
			else
			{
				numodd++;
				a--;
			}
		}
		maxlog=max(select_max,maxlog);
	}

	return maxlog+numodd;
	}
};
