#include <iostream>
#include <algorithm>
using namespace std;
bool s=false;
struct node
{
	int i;
	int n;
};
bool operator<(node a1,node a2)
{
	return s && a1.i<a2.i || !s && a1.n<a2.n;
}
int main()
{
	int n;
	node num[300005];
	cin>>n;
	for (int i=0;i<n;++i)
		cin>>num[i].n,num[i].i=i;
 	sort(num,num+n);
	int e=0;
	for (int i=1;i<n;++i){
		if (num[i].n+e==num[i-1].n)
			num[i].n=num[i-1].n+1,e++;
		else
		{
			e=0;
			if (num [i].n<=num [i-1].n)
				num[i].n=num[i-1].n+1;
		}
	}
	s=true;
	sort(num,num+n);
	for (int i=0;i<n;++i)
		cout<<num[i].n<<" ";
	cout<<endl;
}