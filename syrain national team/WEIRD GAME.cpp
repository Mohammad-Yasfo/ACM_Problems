#include <iostream>
#include <string>
using namespace std;
int main()
{
int n;
int ya=0,y1=0,y2=0,m=0;
bool turn=true;
cin>>n;
string s1,s2;
cin>>s1>>s2;
for(int i=0;i<2*n;++i)
{
if(s1[i]=='1' && s2[i]=='1')
++ya;
else if(s1[i]=='1')
++y1;
else if(s2[i]=='1')
++y2;
}
if(ya%2)
m++,turn=false;
int temp=min(y1,y2);
y1-=temp;
y2-=temp;
if(y1>0)
m+=y1/2;
else if(y2>0)
m-=y2/2;
if(y1%2)
m+=turn;
if (y2%2)
	m-=!turn;
if (m>0)
cout<<"First"<<endl;
else if(m==0)
cout<<"Draw"<<endl;
else
cout<<"Second"<<endl;
return 0;
}