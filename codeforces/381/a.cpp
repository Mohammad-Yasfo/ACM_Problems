#include <iostream>
using namespace std;
int main()
{
	int n,sum1=0,sum2=0;
	bool turn=false;
	int a[1009];
	cin>>n;
	for (int q=0;q<n;++q)
		cin>>a[q];
	int i=0,j=n-1;
	while (i<=j)
	{
		if (!turn)
		{
			if (a[i]>a[j])
				sum1+=a[i++];
			else
				sum1+=a[j--];
		}
		else
		{
			if (a[i]>a[j])
				sum2+=a[i++];
			else
				sum2+=a[j--];
		}
		turn = !turn;
	}
	cout << sum1<<" "<<sum2<<endl;
	return 0;
}
