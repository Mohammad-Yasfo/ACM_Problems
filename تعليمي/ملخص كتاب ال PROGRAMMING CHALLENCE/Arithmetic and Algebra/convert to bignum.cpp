int_to_bignum(int s, bignum *n)
{
int i; /* counter */
int t; /* int to work with */
if (s >= 0) n->signbit = PLUS;
else n->signbit = MINUS;
for (i=0; i<MAXDIGITS; i++) n->digits[i] = (char) 0;
n->lastdigit = -1;
t = abs(s);
while (t > 0) {
n->lastdigit ++;
n->digits[ n->lastdigit ] = (t % 10);
t = t / 10;
}
if (s == 0) n->lastdigit = 0;
}