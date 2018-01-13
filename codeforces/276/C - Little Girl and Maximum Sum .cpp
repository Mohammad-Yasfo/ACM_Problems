/*
C. Little Girl and Maximum Sum
time limit per test
2 seconds
memory limit per test
256 megabytes
input
standard input
output
standard output

The little girl loves the problems on array queries very much.

One day she came across a rather well-known problem: you've got an array of n elements (the elements of the array are indexed starting from 1); also, there are q queries, each one is defined by a pair of integers li, ri (1 ≤ li ≤ ri ≤ n). You need to find for each query the sum of elements of the array with indexes from li to ri, inclusive.

The little girl found the problem rather boring. She decided to reorder the array elements before replying to the queries in a way that makes the sum of query replies maximum possible. Your task is to find the value of this maximum sum.
Input

The first line contains two space-separated integers n (1 ≤ n ≤ 2·105) and q (1 ≤ q ≤ 2·105) — the number of elements in the array and the number of queries, correspondingly.

The next line contains n space-separated integers ai (1 ≤ ai ≤ 2·105) — the array elements.

Each of the following q lines contains two space-separated integers li and ri (1 ≤ li ≤ ri ≤ n) — the i-th query.
Output

In a single line print a single integer — the maximum sum of query replies after the array elements are reordered.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.
Sample test(s)
Input

3 3
5 3 2
1 2
2 3
1 3

Output

25

Input

5 3
5 2 4 1 3
1 5
2 3
2 3

Output

33
*/
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n,q,l,r;
    long long sum=0;
    int num[200005];
    int im[200005];
    cin>>n>>q;
    for (int i=0;i<n;++i){
        im[i]=0;
        cin>>num[i];
    }
    sort(num,num+n);
    for (int i=0;i<q;++i)
    {
        cin>>l>>r;
        im [--l]++;
        if (r<n)
            im[r]--;
    }
    for (int i=1;i<n;++i)
    {
        im [i]+=im[i-1];
    }
    sort(im,im+n);
    for (int i=0;i<n;++i)
        sum+=(long long)im[i]*num[i];
    cout<<sum<<endl;
}