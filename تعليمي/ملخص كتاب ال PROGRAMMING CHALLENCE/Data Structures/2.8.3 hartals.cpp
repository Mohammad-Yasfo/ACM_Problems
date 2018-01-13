/*
2.8.3 Hartals
PC/UVa IDs: 110203/10050, Popularity: B, Success rate: high Level: 2
Political parties in Bangladesh show their muscle by calling for regular hartals
(strikes), which cause considerable economic damage. For our purposes, each party
may be characterized by a positive integer h called the hartal parameter that denotes
the average number of days between two successive strikes called by the given party.
Consider three political parties. Assume h1 = 3, h2 = 4, and h3 = 8, where hi is
the hartal parameter for party i. We can simulate the behavior of these three parties
for N = 14 days. We always start the simulation on a Sunday. There are no hartals on
either Fridays or Saturdays.
1 2 3 4 5 6 7 8 9 10 11 12 13 14
Days Su Mo Tu We Th Fr Sa Su Mo Tu We Th Fr Sa
Party 1 x x x x
Party 2 x x x
Party 3 x
Hartals 1 2 3 4 5
There will be exactly five hartals (on days 3, 4, 8, 9, and 12) over the 14 days. There
is no hartal on day 6 since it falls on Friday. Hence we lose five working days in two
weeks.
Given the hartal parameters for several political parties and the value of N, determine
the number of working days lost in those N days.
Input
The first line of the input consists of a single integer T giving the number of test cases
to follow. The first line of each test case contains an integer N (7 ≤ N ≤ 3, 650), giving
the number of days over which the simulation must be run. The next line contains
another integer P (1 ≤ P ≤ 100) representing the number of political parties. The ith
of the next P lines contains a positive integer hi (which will never be a multiple of 7)
giving the hartal parameter for party i (1 ≤ i ≤ P).
Output
For each test case, output the number of working days lost on a separate line.
Sample Input
2
14
3
3
4
8
100
4
12
15
25
40
Sample Output
5
15
*/
#include <iostream>
using namespace std;
int main(){
	int n,d,n_h,g,sum=0;
	bool hartals[3670];
	cin>>n;
	
	for (int i=0;i<n;++i)
	{
		cin>>d;
		cin>>n_h;
		for (int j=0;j<n_h;++j)
		{
			 cin>>g;
			 for (int a=g;a<=d;a+=g)
				 if (a%7!=6 && a%7!=0&&hartals[a])
				 {
					 hartals[a]=false;
					 ++sum;
				 }
		}
		cout<<sum<<endl;
		sum=0;
		for (int a=0;a<=d;++a)
			hartals[a]=true;
	}
}
