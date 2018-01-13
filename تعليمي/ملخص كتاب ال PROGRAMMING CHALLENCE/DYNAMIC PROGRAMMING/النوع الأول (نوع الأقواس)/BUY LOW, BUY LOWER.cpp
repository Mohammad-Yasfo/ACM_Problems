/*
BUY LOW, BUY LOWER
Time Limit: 1000MS		Memory Limit: 30000K
Total Submissions: 7991		Accepted: 2759

Description
The advice to "buy low" is half the formula to success in the bovine stock market.To be considered a great investor you must also follow this problems' advice:

                    "Buy low; buy lower"


Each time you buy a stock, you must purchase it at a lower price than the previous time you bought it. The more times you buy at a lower price than before, the better! Your goal is to see how many times you can continue purchasing at ever lower prices.

You will be given the daily selling prices of a stock (positive 16-bit integers) over a period of time. You can choose to buy stock on any of the days. Each time you choose to buy, the price must be strictly lower than the previous time you bought stock. Write a program which identifies which days you should buy stock in order to maximize the number of times you buy.

Here is a list of stock prices:

 Day   1  2  3  4  5  6  7  8  9 10 11 12

Price 68 69 54 64 68 64 70 67 78 62 98 87



The best investor (by this problem, anyway) can buy at most four times if each purchase is lower then the previous purchase. One four day sequence (there might be others) of acceptable buys is:

Day    2  5  6 10

Price 69 68 64 62

Input
* Line 1: N (1 <= N <= 5000), the number of days for which stock prices are given

* Lines 2..etc: A series of N space-separated integers, ten per line except the final line which might have fewer integers.

Output
Two integers on a single line:
* The length of the longest sequence of decreasing prices
* The number of sequences that have this length (guaranteed to fit in 31 bits)

In counting the number of solutions, two potential solutions are considered the same (and would only count as one solution) if they repeat the same string of decreasing prices, that is, if they "look the same" when the successive prices are compared. Thus, two different sequence of "buy" days could produce the same string of decreasing prices and be counted as only a single solution.

Sample Input

12
68 69 54 64 68 64 70 67 78 62
98 87

Sample Output

4 2

Source
USACO 2002 February
*/
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int m[100000];
	int a[100000];
	for (int i=0;i<n;++i)
	{
		cin>>m[i];
		a[i]=0;
		for (int j=i-1;j>=0;--j)
		{
			if (m[i]<m [j])
				a[i]=max(a[i],a[j]);
		}
		a[i]++;
	}
	int max=0,num=0;
	for (int i=0;i<n;++i)
		if (a[i]>max)
		{
			num=1;
			max=a[i];
		}
		else if (a[i]==max)
			++num;
	cout<<max<<" "<<num<<endl;
	cin>>n;
	return 0;
}
