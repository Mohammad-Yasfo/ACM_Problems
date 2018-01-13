#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[(1 << 24) + 4];
int s[(1 << 24) + 4];
int lg[(1 << 24) + 4];
int no[2];
int n, k;
int a[26];
int main(){
	cin >> n;
	no[0] = -1;
	no[1] = -1;
	int p2 = 1;
	for (int i = 0; i<n; i++){
		cin >> a[i];
		lg[p2] = i;
		p2 *= 2;
	}
	cin >> k;
	for (int i = 0; i<k; i++){
		cin >> no[i];
	}
	dp[0] = 1;
	for (int i = 1; i<(1 << n); i++){
		s[i] = s[i - (i&-i)] + a[lg[i&-i]];
		dp[i] = 0;
		if (s[i] != no[0] && s[i] != no[1]){
			int t = i;
			while (t>0){
				dp[i] += dp[i - (t&-t)];
				dp[i] %= 1000000007;
				t -= (t&-t);
			}
		}
	}
	cout << dp[(1 << n) - 1] << endl;
}