/*
B. Color the Fence 
time limit per test2 seconds 
memory limit per test256 megabytes 
inputstandard input 
outputstandard output 
Igor has fallen in love with Tanya. Now Igor wants to show his feelings and write a number on the fence opposite to Tanya's house. Igor thinks that the larger the number is, the more chance to win Tanya's heart he has. 
Unfortunately, Igor could only get v liters of paint. He did the math and concluded that digit d requires ad liters of paint. Besides, Igor heard that Tanya doesn't like zeroes. That's why Igor won't use them in his number.
Help Igor find the maximum number he can write on the fence.
Input 
The first line contains a positive integer v (0 ≤ v ≤ 106). The second line contains nine positive integers a1, a2, ..., a9 (1 ≤ ai ≤ 105).
Output 
Print the maximum number Igor can write on the fence. If he has too little paint for any digit (so, he cannot write anything), print -1.
Sample test(s) 
Input
5
5 4 3 2 1 2 3 4 5
Output
55555
Input
2
9 11 1 12 5 8 9 10 6
Output
33
Input
0
1 1 1 1 1 1 1 1 1
Output
-1

*/
#include<iostream>
using namespace std;
int i,n,s=1000001,l,a[9];
int main(){
  cin>>n;
  while(cin>>a[i++]) 
  	s=min(s,a[i-1]); 
  l=n/s; 
  if(!l)
  	cout<<-1;
  while(l--) 
  	for(i=8;i>=0;i--)
   		if((n-a[i])/s==l && n>=a[i]){
     		cout<<i+1; 
     		n-=a[i]; 
     		break;
   }
 return 0;
}
