/*
B. Vasya and Public Transport 
time limit per test1 second 
memory limit per test256 megabytes 
inputstandard input 
outputstandard output 
Vasya often uses public transport. The transport in the city is of two types: trolleys and buses. The city has n buses and m trolleys, the buses are numbered by integers from 1 to n, the trolleys are numbered by integers from 1 to m.
Public transport is not free. There are 4 types of tickets: 
A ticket for one ride on some bus or trolley. It costs c1 burles; 
A ticket for an unlimited number of rides on some bus or on some trolley. It costs c2 burles; 
A ticket for an unlimited number of rides on all buses or all trolleys. It costs c3 burles; 
A ticket for an unlimited number of rides on all buses and trolleys. It costs c4 burles. 
Vasya knows for sure the number of rides he is going to make and the transport he is going to use. He asked you for help to find the minimum sum of burles he will have to spend on the tickets.
Input 
The first line contains four integers c1, c2, c3, c4 (1 ≤ c1, c2, c3, c4 ≤ 1000) — the costs of the tickets.
The second line contains two integers n and m (1 ≤ n, m ≤ 1000) — the number of buses and trolleys Vasya is going to use.
The third line contains n integers ai (0 ≤ ai ≤ 1000) — the number of times Vasya is going to use the bus number i.
The fourth line contains m integers bi (0 ≤ bi ≤ 1000) — the number of times Vasya is going to use the trolley number i.
Output 
Print a single number — the minimum sum of burles Vasya will have to spend on the tickets.
Sample test(s) 
Input
1 3 7 19
2 3
2 5
4 4 4
Output
12
Input
4 3 2 1
1 3
798
1 2 3
Output
1
Input
100 100 8 100
3 5
7 94 12
100 1 47 0 42
Output
16
Note 
In the first sample the profitable strategy is to buy two tickets of the first type (for the first bus), one ticket of the second type (for the second bus) and one ticket of the third type (for all trolleys). It totals to (2·1) + 3 + 7 = 12 burles.
In the second sample the profitable strategy is to buy one ticket of the fourth type.
In the third sample the profitable strategy is to buy two tickets of the third type: for all buses and for all trolleys.

*/
#include <iostream>
using namespace std;
int main() 
{
 int c1,c2,c3,c4,m,n,sumbus=0,sumtro=0,number;
 cin>>c1>>c2>>c3>>c4>>n>>m;
 for (int i=0;i<n;++i)
 {
 cin>>number;
 sumbus+=min(c1*number,c2);
 }
 sumbus=min(c3,sumbus);
 for (int i=0;i<m;++i)
 {
 cin>>number;
 sumtro+=min(c1*number,c2);
 }
 sumtro=min(c3,sumtro);
 sumbus=min(sumbus+sumtro,c4); 
cout<<sumbus<<endl;
 return 0;
 }
