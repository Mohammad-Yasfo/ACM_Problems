#include <iostream>
#include <vector>
using namespace std;
vector<long long> q;

long long gs(int a,int b)
{
return q[b]-(a>0?q[a-1]:0);
}
int get_longest(int s,int e,int l)
{
int bs=s++;
for(s;s+l-1<=e;++s)
{
if (gs(s,s+l-1)>gs(bs,bs+l-1))
bs=s;
}
return bs;
}
int main()
{
    long long n,k,a;
    cin>>n>>k;
    cin>>a;
    vector<long long>w;
    q.push_back(a);
    w.push_back(a);
    for (int i=1;i<n;++i)
    {
        cin>>a;
        q.push_back(a);
        w.push_back(a);
        q[i]+=q[i-1];
    }
    int s=get_longest(0,n-1,k);
    w.erase(w.begin()+s,w.begin()+s+k);
    q.clear();
    q.push_back(w[0]);
    for (int i=1;i<n-k;++i)
    {
        w[i]+=w[i-1];
        q.push_back(w[i]);
    }
    int s2=get_longest(0,n-1-k,k);
    if (s2<s && s2+k<=s)
        cout<<s2+1<<" "<<s+1<<endl;
    else if (s2>=s && s2+k>s)
        cout<<s+1<<" "<<s2+k+1<<endl;
    else
    {
        cout<<s2+1<<" "<<s2+k+1<<endl;
    }
}