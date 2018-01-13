/*
.1.1 Finding Primes
The easiest way to test if a given number x is prime uses repeated division. Start from
the smallest candidate divisor, and then try all possible divisors up from there. Since
2 is the only even prime, once we verify that x isn’t even we only need try the odd
numbers as candidate factors. Further, we can bless n as prime the instant we have
shown that it has no non-trivial prime factors below
√n. Why? Suppose not – i.e., x
is composite but has a smallest non-trivial prime factor p which is greater than
√n.
Then x/p must also divide x, and must be larger than p, or else we would have seen
it earlier. But the product of two numbers greater than
√n must be larger than n,a
contradiction.
Computing the prime factorization involves not only ﬁnding the ﬁrst prime factor,
but stripping off all occurrences of this factor and recurring on the remaining product:

*/
prime_factorization(long x)
{
	long i; /* counter */
	long c; /* remaining product to factor */
	c=x;
	while ((c % 2) == 0)
	{

	}
	printf("%ld\n",2);
	c=c/2;
	
	i=3;
	while (i <= (sqrt(c)+1))
	{
		if((c%i)==0){
			printf("%ld\n",i);
			c=c/i;
		}
		else
			i=i+2;
	}
	if (c > 1)
		printf("%ld\n",c);
}