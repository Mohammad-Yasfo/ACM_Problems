#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<map>
#include<cstdlib>
#include<stdio.h>
#include<set>
#include<cmath>
#include<cstring>
#include<utility>
#include<string>
#include<iomanip>
using namespace std;
void R( int &x ) {
x = 0;
char temp;
temp = getchar();
while( ! isdigit( temp ) && temp != '-' ) {
temp = getchar();
}
bool neg = 0;
if( temp == '-' ) {
neg = 1;
}
else if( isdigit( temp ) ) {
x = ( temp - '0' );
}
temp = getchar();
while( isdigit( temp ) ) {
x *= 10;
x += ( temp - '0' );
temp = getchar();
}
if( neg )
x *= - 1;
}
void R( long long &x ) {
x = 0;
char temp;
temp = getchar();
while( ! isdigit( temp ) && temp != '-' ) {
temp = getchar();
}
bool neg = 0;
if( temp == '-' ) {
neg = 1;
}
else if( isdigit( temp ) ) {
x = ( temp - '0' );
}
temp = getchar();
while( isdigit( temp ) ) {
x *= 10;
x += ( temp - '0' );
temp = getchar();
}
if( neg )
x *= - 1;
}
#define MAX (1<<30)
struct node{
	node *l,*r;
	int val;
	node(int x): val(x),l(0),r(0){}
	node():l(0),r(0){}
};
int v (node * it){
	if(!it)return 0;
	return it->val;
}
void upd(node * & it){
	it->val=v(it->l)+v(it->r);}
void ins(int b, int e, node * & x,int val){
	
	if(b==e){
		x=  new node(1);
		return ;}
	if(!x)x=new node(0);
	if(val>(b+e)/2)ins((b+e)/2+1,e,x->r,val);
	else ins(b,(b+e)/2,x->l,val);
	upd(x);
}
int query(int b, int e, node * x,int val){
	if(val>v(x))return -1;
	if(b==e) return b;
	if(val>v(x->l)) return query( (b+e)/2+1,  e,  x->r, val-v(x->l));
	return query(b,(b+e)/2,x->l,val);
}
void F(node * &x){
	if(!x) return;
	F(x->l),F(x->r);
	delete x;
}
int main(){
	//freopen("in.in","r",stdin);freopen("out.out","w",stdout);
	int T;
	R(T);
	node * root=0;
	while(T--){
		int n,k,tmp;
		R(n),R(k);
		F(root);
		root=0;
		while(n--){
			R(tmp);
			if(tmp)
			ins(1,MAX,root,tmp);
			else printf("%d\n",query(1,MAX,root,k));
		}
	}
}