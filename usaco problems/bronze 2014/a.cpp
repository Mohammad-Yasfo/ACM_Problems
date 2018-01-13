#include <fstream>
#include <algorithm>
using namespace std;
int main()
{
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");
	long long selected=0,mins=-1,n;
	long long a[1009];
	fin>>n;
	for (int q=0;q<n;++q)
		fin>>a[q];
	sort(a,a+n);
	int i=0,j=1,w=0;

	while (j<n)
	{
		++i;
		if (j<i)
			j=i;
		if (i==n)
			break;
		selected=0;
		while (j<n && a[j]-a[i]<=17)
			++j;
		--j;
		for (int k=j+1;k<n;++k)
			selected+=(long long)(a[k]-a[j])*(a[k]-a[j]);
		for (int k=0;k<i;++k)
			selected+=(long long)(a[i]-a[k])*(a[i]-a[k]);
		if (mins!=-1)
		mins=min(mins,selected);
		else
			mins=selected;
	}
	fout<<mins<<endl;
	return 0;
}
