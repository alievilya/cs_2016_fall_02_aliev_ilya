#include "stdio.h"
#include "math.h"
#include "conio.h"
#include "stdlib.h"

long int fac(long int n)
{
	if (n == 0 || n == 1)
		return 1;
	return n * fac(n - 1);
}

void main(int)
{
	long int n;
	printf("Input n: ");
	scanf("%d", &n);
	if (n >= 0)
		printf("%d! = %d\n", n, fac(n));
	else
		printf("Error n must be >= 0\n");
	switch (_getch());
}
