#include <iostream>
using namespace std;
int r,g,b,s=0;
bool is()
{
int a=3,q=0;
if(r%3==0)
++q;
else
a=min(a,r%3);
if(g%3==0)
++q;
else
a=min(a,g%3);
if(b%3==0)
++q;
else
a=min(a,b%3);
return a>q;
}
void get_mo()
{
s+=r/3;
s+=g/3;
s+=b/3;
b%=3;
g%=3;
r%=3;
}
void minu()
{
while(is() && g>0 && b>0 && r>0)
{
--r;
--g;
--b;
++s;
}
}
int main()
{
cin>>r>>g>>b;

minu();
get_mo();
minu();
cout<<s<<endl;
return 0;
}