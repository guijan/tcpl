

int
main(void)
{

}

/* setbits: return x with the n bits that begin at position p set to the
 * rightmost n bits of y.
 */
int
setbits(int x, const int p, const int n, int y)
{
	int mask;
	/* Leave only the n bits we want set on the mask. */
	mask = ~(~0 << n);
	/* Move the set bits to the proper position. */
	mask <<= p;
	/* Now only the count of bits at the position we want are not set */
	mask = ~mask;

	/* Clear all bits except the first n bits. */
	y &= ~(~0 << n);
	/* Move the set bits to the proper position. */
	y <<= p;

	x &= mask;
	x |= y;
	return x;
}
