#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	long long a,b,n;
	cin>>a>>b>>n;
	n=(long long)ceil((double)a/n)*ceil((double)b/n);
	cout<<n;
	return 0;
}
