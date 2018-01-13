/*
فيه خطأ

*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
#define MAXDIGITS 100 /* maximum length bignum */
#define PLUS 1 /* positive sign bit */
#define MINUS -1 /* negative sign bit */
typedef struct {
string digits; /* represent the number */
int signbit; /* PLUS or MINUS */
} bignum;
void zero_justify(bignum *n)
{
	int f=-1;
	while ((n->digits.length()!=f) && (n->digits[ n->digits.length()-1-f ]==0))
		++f;
	
	n->digits.erase(n->digits.length()-1-f,n->digits.length()-1);

	if (n->digits.length()==1&&n->digits[0]=='0')
		n->signbit=PLUS;
}
void print_bignum(bignum *n)
{
int i;
if (n->signbit == MINUS) printf("- ");
for (i=n->digits.length()-1; i>=0; i--)
printf("%c",'0'+ n->digits[i]);
printf("\n");
}
void initialize_bignum(bignum* n)
{
	n->digits="";
	n->signbit=PLUS;
}
void change_bignum(bignum *n)
{
	int temp;
	for (int i=0;i<n->digits.length();++i)
		n->digits[i]-=48;
	for (int i=0;i<n->digits.length()/2;++i)
	{
		temp=n->digits[i];
		n->digits[i]=n->digits[n->digits.length()-1-i];
		n->digits[n->digits.length()-1-i]=temp;
	}
}
