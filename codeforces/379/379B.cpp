#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	int n,num[304]={0};
	cin>>n;
	for (int i=0;i<n;++i)
		cin>>num[i];
	for (int i=0;i<n;++i)
	{
		if (num[i]>0)
		cout<<'P';
		if (--num[i]>0)
		while (num[i]--)
		{
			cout<<(i==0?"RLP":"LRP");
		}
		if (i+1<n)
			cout<<"R";
	}
	cout<<endl;
	return 0;
}
