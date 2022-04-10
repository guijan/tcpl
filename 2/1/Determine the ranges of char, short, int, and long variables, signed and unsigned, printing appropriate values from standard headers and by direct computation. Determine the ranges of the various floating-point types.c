#include <stdio.h>
#include <limits.h>
#include <assert.h>

#define preurange(s, max) \
		(printf("%-11s\t%-20lu .. %-20lu\n", s, 0, (unsigned long)max))
#define presrange(s, min, max) \
		(printf("%-11s\t%-20ld .. %-20ld\n", s, \
			(signed long)min, (signed long)max))
#define TYPEBITS(n) (CHAR_BIT * (sizeof(n)))

unsigned long powlu(const unsigned long, const unsigned long);
signed long powld(const signed long, const signed long);
unsigned long udtsize(const unsigned long);
long sdtsize(const unsigned long, const int);

int
main(void)
{

	printf("%s\n", "FROM HEADER:");
	printf("%-11s\t%-20s\n", "TYPE", "RANGE");
	printf("%-11s\t%-20d .. %-20d\n", "unsigned char", 0, UCHAR_MAX);
	printf("%-11s\t%-20d .. %-20d\n", "signed char", CHAR_MIN, CHAR_MAX);
	printf("%-11s\t%-20u .. %-20u\n", "unsigned short", 0, USHRT_MAX);
	printf("%-11s\t%-20d .. %-20d\n", "signed short", SHRT_MIN, SHRT_MAX);
	printf("%-11s\t%-20u .. %-20u\n", "unsigned int", 0, UINT_MAX);
	printf("%-11s\t%-20d .. %-20d\n", "signed int", INT_MIN, INT_MAX);
	printf("%-11s\t%-20lu .. %-20lu\n", "unsigned long", 0UL, ULONG_MAX);
	printf("%-11s\t%-20ld .. %-20ld\n", "signed long", LONG_MIN, LONG_MAX);

	putchar('\n');
	printf("%s\n", "CALCULATED:");
	printf("%-11s\t%-20s\n", "TYPE", "RANGE");
	printf("%-11s\t%-20lu .. %-20lu\n", "unsigned char", 0UL,
		udtsize(sizeof(unsigned char))
	);
	printf("%-11s\t%-20ld .. %-20ld\n", "signed char",
		sdtsize(sizeof(signed char), -1),
		sdtsize(sizeof(signed char), 0)
	);
	printf("%-11s\t%-20lu .. %-20lu\n", "unsigned short", 0UL,
		udtsize(sizeof(unsigned short))
	);
	printf("%-11s\t%-20ld .. %-20ld\n", "signed short",
		sdtsize(sizeof(signed short), -1),
		sdtsize(sizeof(signed short), 0)
	);
	printf("%-11s\t%-20lu .. %-20lu\n", "unsigned int", 0UL,
		udtsize(sizeof(unsigned int))
	);
	printf("%-11s\t%-20ld .. %-20ld\n", "signed int",
		sdtsize(sizeof(signed int), -1),
		sdtsize(sizeof(signed int), 0)
	);
	printf("%-11s\t%-20lu .. %-20lu\n", "unsigned long", 0UL,
		udtsize(sizeof(unsigned long))
	);
	printf("%-11s\t%-20ld .. %-20ld\n", "signed long",
		sdtsize(sizeof(signed long), -1),
		sdtsize(sizeof(signed long), 0)
	);
}

unsigned long
powlu(const unsigned long x, const unsigned long y)
{
	unsigned long i;
	unsigned long n = x;
	const unsigned long max = ULONG_MAX / y + ULONG_MAX % y;

	for (i = 1; i < y; i++) { /* start at 1 to avoid being off by 1 power */
		if (max < n)
			return 0;
		n *= x;
	}

	return n;
}

signed long
powld(const signed long x, const signed long y)
{
	signed long i;
	signed long n = x;
	const signed long max = ULONG_MAX / y + ULONG_MAX % y;

	for (i = 1; i < y; i++) { /* start at 1 to avoid being off by 1 power */
		if (max < n)
			return 0;
		n *= x;
	}

	return n;
}

/* sdtsize: Returns the maximum/minimum of a signed integer datatype.
 *
 * x is the sizeof() of the datatype.
 * If neg true, return the minimum of the datatype.
 */
long
sdtsize(size_t x, const int neg)
{
	unsigned long n = ~0UL >> 1; /* All bits but the sign set. */
	long *const nview = (long *)&n;
	const unsigned long bitdiff = (sizeof(long) - x) * CHAR_BIT;

	assert(x <= sizeof(long));

	n >>= bitdiff;

	/* (-1 != ~1) returns 1 if the machine is two's complement, 0 if not. */
	return (neg ? -*nview - (-1 != ~1) : *nview);
}

/* udtsize: Returns the maximum of unsigned integer datatype.
 *
 * x is the sizeof() of the datatype.
 */
unsigned long
udtsize(const unsigned long x)
{
	unsigned long n = ~0UL;
	const unsigned int bitdiff = (sizeof(unsigned long) - x) * CHAR_BIT;

	assert(x <= sizeof(unsigned long));

	n >>= bitdiff;

	return n;
}
