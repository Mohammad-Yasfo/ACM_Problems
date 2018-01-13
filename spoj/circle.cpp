#include <iostream>
#include <map>
using  namespace std;
class node
{
public:
int f;
int s;
node()
{
f=s=-1;
}
};
int main()
{
int n,k,a,b;
map<int,node>m;
map<int,node>::iterator it;
while(true){
cin>>n>>k;
if (n==0 && k==0)
break;
m.clear();
for(int i=0;i<k;++i)
{
cin>>a>>b;
if(m[a].f==b || m[a].s==b)
continue;
if (m[a].f!=-1 && m[a].s!=-1)
{
cout<<'N'<<endl;
goto f;
}
if (m[b].f!=-1 && m[b].s!=-1)
{
cout<<'N'<<endl;
goto f;
}
if (m[a].f==-1)
m[a].f=b;
else
m[a].s=b;
if(m[b].f==-1)
m[b].f=a;
else
m[b].s=a;
}
if (k==0){
	cout<<'Y'<<endl;
	continue;
}
for(it=m.begin();it!=m.end();++it)
	if((*it).second.s==-1)
{
cout<<'Y'<<endl;
goto f;
}
cout<<'N'<<endl;
f:;
}
return 0;
}