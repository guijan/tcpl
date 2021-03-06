#include <ctype.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>	/* for atof() */
#include <stdio.h>
#include <math.h>

#define MAXVAL 100	/* maximum depth of val stack*/
#define MAXOP 100	/* max size of operand or operator */
#define NUMBER '0'	/* signal that a number was found */
#define BUFSIZE 100

double pop(void);
int getch(void);
int getch(void);
int getop(char *);
void push(double);
void ungetch(int);
void ungetch(int);

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */
int sp = 0;
double val[MAXVAL];

/* reverse Polish calculator */
int
main(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push(fmod(pop(), op2));
			else
				printf("error: zero modulus\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

int
getch(void) /* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void
ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

/* getop: get next operator or numeric operand */
int
getop(char s[])
{
	int c;
	int i = 0;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	if (c == '-') {
		if (isdigit(c = getch())) {
			s[i] = '-';
		}
		ungetch(c);
	}
	if (!isdigit(c) && c != '.')
		return c;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[++i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}


/* push: push f onto value stack */
void
push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double
pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}
