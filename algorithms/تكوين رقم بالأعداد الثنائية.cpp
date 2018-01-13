#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	int p2=1;
	while(n>0){
		if(n%2){
			cout<<p2<<" ";
		} 
		p2*=2;
		n/=2;
	}
}
