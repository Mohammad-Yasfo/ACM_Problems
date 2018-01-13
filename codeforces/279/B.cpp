#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,t,a[100006],current=0,maxs=0;
    cin>>n>>t;
    for (int i=0;i<n;++i){
        cin>>a[i];
    }
    int j=1;
    long long sum=0;
    sum=a[0];
    int w=0;
    if (a[w]<=t)
        maxs=1;
    while (j<n)
    {
        
       for (j;j<n&& sum+a[j]<=t;++j)
           sum+=a[j];
       if (sum<=t)
       maxs=max(maxs,j-w);
       if (j!=w)
        sum-=a[w];
       ++w;
       if (j<w)
           j=w;
       if (w>=n || n-w<=maxs)
           break;
    }
    cout<<maxs<<endl;
    return 0;
}
