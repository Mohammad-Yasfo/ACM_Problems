#include <iostream>
using namespace std;
int main()
{
	int n,m,k,a;
	cin>>n>>m>>k;
	for (int i=0;i<n;++i)
	{
		cin>>a;
		if (a==2)
			if (k>0){
				--k;
				continue;
			}
		--m;
	}
	cout<<(m<0?0-m:0)+(k<0?0-k:0)<<endl;
	return 0;
}
