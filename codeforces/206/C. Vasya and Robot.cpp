/*
A. Vasya and Robot 
time limit per test1 second 
memory limit per test256 megabytes 
inputstandard input 
outputstandard output 
Vasya has n items lying in a line. The items are consecutively numbered by numbers from 1 to n in such a way that the leftmost item has number 1, the rightmost item has number n. Each item has a weight, the i-th item weights wi kilograms.
Vasya needs to collect all these items, however he won't do it by himself. He uses his brand new robot. The robot has two different arms — the left one and the right one. The robot can consecutively perform the following actions: 
Take the leftmost item with the left hand and spend wi · l energy units (wi is a weight of the leftmost item, l is some parameter). If the previous action was the same (left-hand), then the robot spends extra Ql energy units; 
Take the rightmost item with the right hand and spend wj · r energy units (wj is a weight of the rightmost item, r is some parameter). If the previous action was the same (right-hand), then the robot spends extra Qr energy units; 
Naturally, Vasya wants to program the robot in a way that the robot spends as little energy as possible. He asked you to solve this problem. Your task is to find the minimum number of energy units robot spends to collect all items.
Input 
The first line contains five integers n, l, r, Ql, Qr (1 ≤ n ≤ 105; 1 ≤ l, r ≤ 100; 1 ≤ Ql, Qr ≤ 104).
The second line contains n integers w1, w2, ..., wn (1 ≤ wi ≤ 100).
Output 
In the single line print a single number — the answer to the problem.
Sample test(s) 
Input
3 4 4 19 1
42 3 99
Output
576
Input
4 7 2 3 9
1 2 3 4
Output
34
Note 
Consider the first sample. As l = r, we can take an item in turns: first from the left side, then from the right one and last item from the left. In total the robot spends 4·42 + 4·99 + 4·3 = 576 energy units.
The second sample. The optimal solution is to take one item from the right, then one item from the left and two items from the right. In total the robot spends (2·4) + (7·1) + (2·3) + (2·2 + 9) = 34 energy units.

*/
#include<iostream>
using namespace std;
int main(){
	int n,l,r,p,q,w[100000],ans=500000000,sum=0,sub=0;
	cin>>n>>l>>r>>p>>q;
	for(int i=0;i<n;i++){cin>>w[i]; sum+=w[i];}
	for(int i=0;i<=n;i++){
		int ret=sum*r+sub*l;
		if(i<=n-i){
			ret+=max(0,n-i-i-1)*q;
		}
		else {
			ret+=max(0,i-n+i-1)*p;
		}
		if(ret<ans)ans=ret;
		if(i!=n){sum-=w[i]; sub+=w[i];}
	}
	cout<<ans<<endl;
}
