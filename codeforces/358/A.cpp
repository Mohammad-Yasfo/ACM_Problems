#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[1004];
int b[1003];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a,a+n);
	int left,right;
	for(int i=0;i<n;i++){
		if(b[0]==a[i]){
			left=i-1;
			right=i+1;
		}
	}
	right%=n;
	left=(left+n)%n;
	for(int i=1;i<n;i++){
		if(b[i]==a[right]){
			right++;
			right%=n;
		} else if(b[i]==a[left]){
			left--;
			left=(left+n)%n;
		} else {
			cout<<"yes"<<endl;
			return 0;
		}
	}
	cout<<"no"<<endl;
}
