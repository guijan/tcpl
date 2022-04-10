
int
main(void)
{

}

/* invert: Return x with the n bits that begin at position p inverted,
 * leaving the others unchanged.
 */
int
invert(int x, const int p, const int n)
{
	int mask = ~(~0 << n) << p;
	x ^= mask;
	return x;
}
