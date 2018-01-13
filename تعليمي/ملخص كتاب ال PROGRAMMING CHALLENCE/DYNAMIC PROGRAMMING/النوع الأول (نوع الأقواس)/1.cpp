/*
أصغر مجموعة من الأعداد حيث تحقق العلاقة الآتية
الفرق بين عددين متتاليين أصغر من K  وكذلك الفرق بين أول عنصر مختار وأول عنصر مدخل و الفرق بين آخر عنصر مختار و آخر عنصر مدخل
*/
#include <iostream>
using namespace std;
int main()
{
	int n,k,r;
	cin>>n>>k;
	int m[100000];
	int a[100000];
	for (int i=0;i<n;++i)
	{
		cin>>m[i];
		r=9999999;
		for (int h=1;h<=k+1;++h)
		{
			r=min(r,i-h<0?0:a[i-h]);
		}
		a[i]=m[i]+r;
	}
	r=9999999;
	for (int i=0;i<k;++i)
		r=min(r,a[n-1-i]);
	cout<<r<<endl;
	return 0;
}
