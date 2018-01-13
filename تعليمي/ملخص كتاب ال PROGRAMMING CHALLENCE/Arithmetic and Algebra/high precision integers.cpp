void add_bignum(bignum*,bignum*,bignum*);
int compare_bignum(bignum *a, bignum *b)
{
int i; /* counter */
if ((a->signbit==MINUS) && (b->signbit==PLUS)) return(PLUS);
if ((a->signbit==PLUS) && (b->signbit==MINUS)) return(MINUS);
if (b->digits.length() > a->digits.length()) return (PLUS * a->signbit);
if (a->digits.length() > b->digits.length()) return (MINUS * a->signbit);
for (i = a->digits.length()-1; i>=0; i--) {
if (a->digits[i] > b->digits[i])
return(MINUS * a->signbit);
if (b->digits[i] > a->digits[i])
return(PLUS * a->signbit);	
}
return(0);
}
void subtract_bignum(bignum *a, bignum *b, bignum *c,bool first=true)
{if (first){
	change_bignum(a);
	change_bignum(b);
}
int borrow; /* anything borrowed? */
int v; /* placeholder digit */
int i; /* counter */
if ((a->signbit == MINUS) || (b->signbit == MINUS)) {
b->signbit = -1 * b->signbit;
add_bignum(a,b,c);
b->signbit = -1 * b->signbit;
return;
}
if (compare_bignum(a,b) == PLUS) {
subtract_bignum(b,a,c,false);
c->signbit = MINUS;
return;
}
int length = b->digits.length();
borrow = 0;
for (i=0; i<length; i++) {
v = (a->digits[i] - borrow - b->digits[i]);
borrow=v<0;
if (v < 0)
v = v + 10;
c->digits += v;
}
for (i=length; i<a->digits.length(); i++) {
v = (a->digits[i] - borrow);
borrow=v<0;
if (v < 0)
v = v + 10;
c->digits += v;
}
zero_justify(c);
}
void add_bignum(bignum *a, bignum *b, bignum *c)
{
	change_bignum(a);
	change_bignum(b);
int carry; /* carry digit */
int i; /* counter */
initialize_bignum(c);
if (a->signbit == b->signbit) c->signbit = a->signbit;
else {
if (a->signbit == MINUS) {
a->signbit = PLUS;
subtract_bignum(b,a,c);
a->signbit = MINUS;
} else {
b->signbit = PLUS;
subtract_bignum(a,b,c);
b->signbit = MINUS;
}
return;
}
carry=0;
bignum *max_num=a->digits.length()>b->digits.length()?a:b;
int length=min(a->digits.length(),b->digits.length());
for (int i=0;i<length;++i)
{
	c->digits+=(char)(carry+a->digits[i]+b->digits[i]) % 10;
	carry = (carry + a->digits[i] + b->digits[i]) / 10;
}
for (int i=length;i<max_num->digits.length();++i)
{
	c->digits+=(char)(carry+max_num->digits[i]) % 10;
	carry = (carry + max_num->digits[i]) / 10;
}
if (carry>0)
	c->digits+='1';
}
void digit_shift(bignum *n, int d) /* multiply n by 10ˆd */
{
int i; /* counter *//*
if ((n->lastdigit == 0) && (n->digits[0] == 0)) return;
for (i=n->lastdigit; i>=0; i--)
n->digits[i+d] = n->digits[i];
for (i=0; i<d; i++) n->digits[i] = 0;
n->lastdigit = n->lastdigit + d;*/
}
void multiply_bignum(bignum *a, bignum *b, bignum *c)
{
bignum row; /* represent shifted row */
bignum tmp; /* placeholder bignum */
int i,j; /* counters */
initialize_bignum(c);
row = *a;
for (i=0; i<=b->digits.length(); i++) {	
for (j=1; j<=b->digits[i]; j++) {
add_bignum(c,&row,&tmp);
*c = tmp;
}
digit_shift(&row,1);
}
c->signbit = a->signbit * b->signbit;
}

void divide_bignum(bignum *a, bignum *b, bignum *c)
{
bignum row; /* represent shifted row */
bignum tmp; /* placeholder bignum */
int asign, bsign; /* temporary signs */
int i,j; /* counters */
initialize_bignum(c);
c->signbit = a->signbit * b->signbit;
asign = a->signbit;
bsign = b->signbit;
a->signbit = PLUS;
b->signbit = PLUS;
initialize_bignum(&row);
initialize_bignum(&tmp);

for (i=a->digits.length(); i>=0; i--) {
digit_shift(&row,1);
row.digits[0] = a->digits[i];
c->digits[i] = 0;
while (compare_bignum(&row,b) != PLUS) {
c->digits[i] ++;
subtract_bignum(&row,b,&tmp);
row = tmp;
}
}
a->signbit= asign;
b->signbit = bsign;
}
int main()
{
	bignum *a=new bignum,*b=new bignum,*c=new bignum;
	initialize_bignum(a);
	initialize_bignum(b);
	cin>>a->digits;

	cin>>b->digits;
	subtract_bignum(a,b,c);
	print_bignum(c);
	cin>>a->digits;
	return 0;
}
