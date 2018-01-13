/*
One day Jeff got hold of an integer sequence a1, a2, ..., an of length n. The boy immediately decided to analyze the sequence. For that, he needs to find all values of x, for which these conditions hold:
x occurs in sequence a. 
Consider all positions of numbers x in the sequence a (such i, that ai = x). These numbers, sorted in the increasing order, must form an arithmetic progression. 
Help Jeff, find all x that meet the problem conditions.
Input 
The first line contains integer n (1 ≤ n ≤ 105). The next line contains integers a1, a2, ..., an (1 ≤ ai ≤ 105). The numbers are separated by spaces.
Output 
In the first line print integer t — the number of valid x. On each of the next t lines print two integers x and px, where x is current suitable value, px is the common difference between numbers in the progression (if x occurs exactly once in the sequence, px must equal 0). Print the pairs in the order of increasing x.
Sample test(s) 
Input
1
2
Output
1
2 0
Input
8
1 2 1 3 1 2 1 5
Output
4
1 2
2 4
3 0
5 0
Note 
In the first test 2 occurs exactly once in the sequence, ergo p2 = 0.

*/
#include <iostream>
using namespace std;
#define MAX 100000
int main()
{
    int N,Q,sum=0;
    int *nums_index=new int [MAX];
    int *range=new int [MAX];
    for (int i=0;i<MAX;++i)
    {
        nums_index[i]=-1;
        range[i]=0;
    } 
    cin>>N;
    for (int i=0;i<N;++i)
    {
        cin>>Q;
        if (range[Q-1]==-1)
            continue;
        if (nums_index[Q-1]==-1)
            ++sum;
        else if (range[Q-1]==0)
            range[Q-1]=i-nums_index[Q-1];
        else if (range [Q-1]!=i-nums_index[Q-1])
        {
                range[Q-1]=-1;
                --sum;
        }
        nums_index[Q-1]=i;
    }
    cout<<sum<<endl;
    for (int i=0;i<MAX;++i)
        if (nums_index[i]>-1 && range[i]>-1)
            cout<<i+1<<" "<<range[i]<<endl;
    return 0;
}
