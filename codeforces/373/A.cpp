/*
A. Collecting Beats is Fun
time limit per test
1 second
memory limit per test
256 megabytes
input
standard input
output
standard output

Cucumber boy is fan of Kyubeat, a famous music game.

Kyubeat has 16 panels for playing arranged in 4 × 4 table. When a panel lights up, he has to press that panel.

Each panel has a timing to press (the preffered time when a player should press it), and Cucumber boy is able to press at most k panels in a time with his one hand. Cucumber boy is trying to press all panels in perfect timing, that is he wants to press each panel exactly in its preffered time. If he cannot press the panels with his two hands in perfect timing, his challenge to press all the panels in perfect timing will fail.

You are given one scene of Kyubeat's panel from the music Cucumber boy is trying. Tell him is he able to press all the panels in perfect timing.
Input

The first line contains a single integer k (1 ≤ k ≤ 5) — the number of panels Cucumber boy can press with his one hand.

Next 4 lines contain 4 characters each (digits from 1 to 9, or period) — table of panels. If a digit i was written on the panel, it means the boy has to press that panel in time i. If period was written on the panel, he doesn't have to press that panel.
Output

Output "YES" (without quotes), if he is able to press all the panels in perfect timing. If not, output "NO" (without quotes).
Sample test(s)
Input

1
.135
1247
3468
5789

Output

YES

Input

5
..1.
1111
..1.
..1.

Output

YES

Input

1
....
12.1
.2..
.2..

Output

NO

Note

In the third sample boy cannot press all panels in perfect timing. He can press all the panels in timing in time 1, but he cannot press the panels in time 2 in timing with his two hands.
*/
#include <iostream>
using namespace std;
int main()
{
	int	k;
	char w;
	cin>>k;
	int q[10]={0};
	for (int i=0;i<16;++i)
	{
		cin>>w;
		if (w!='.')
		{
			if (++q[w-48]>k*2)
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
