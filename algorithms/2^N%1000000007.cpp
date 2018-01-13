#include <iostream>
using namespace std;
long long mod=1000000007; 
long long n; 
long long solution=1; 

int main()
{
 cin>>n;
 long long sp=2; 
while(n)
{
 if(n%2)
{ 
solution=(solution*sp)%mod;
 }
 n/=2;
 sp=(sp*sp)%mod;
 }
 cout<<solution<<endl;
}
