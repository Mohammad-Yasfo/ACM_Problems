#include <iostream> 
using namespace std; 
int n; int arr[200];
int dp[200][200]; 
int col[200][200]; 
int calc(int i,int j)
{ 
if(dp[i][j]!=1000000000)
 return dp[i][j];
 for(int k=i;k<j;k++)
{ 
dp[i][j]=min(dp[i][j],calc(i,k)+calc(k+1,j)+col[i][k]*col[k+1][j]); 
col[i][j]=(col[i][k]+col[k+1][j])%100; 
} 
return dp[i][j]; 
}
 int main()
{
 while(cin>>n)
{ 
for(int i=0;i<n;i++)
{
 for(int j=0;j<n;j++) 
dp[i][j]=1000000000;
 }
 for(int i=0;i<n;i++)
{ 
cin>>arr[i]; 
col[i][i]=arr[i]; 
dp[i][i]=0;
 } 
cout<<calc(0,n-1)<<endl;
} 
}
