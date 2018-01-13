#include <iostream>
using namespace std;

int n,t,mx=0,sol=0;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		mx=max(mx+t,t);
		sol=max(sol,mx);
	}
	cout<<sol<<endl;
	cin>>n;
}
