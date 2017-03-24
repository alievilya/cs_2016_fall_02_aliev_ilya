#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 

int main()
{

	int i = 0;
	int x = 0, y = 0; int c = 1;
	char z = 0;
	scanf("%d %c %d", &x, &z, &y);

	if (z == '+')
	{
		x = x + y;
		printf("%d\n", x);
	}
	else if (z == '-')
	{
		x = x - y;
		printf("%d\n", x);
	}
	else if (z == '/')
	{
		x = x / y;
		printf("%d\n", x);
	}
	else if (z == '%')
	{
		x = x % y;
		printf("%d\n", x);
	}
	else if (z == '^')
	{
		for (i = 0; i < y; i++)
		{
			c = c*x;
		}
		if (y == 0)
		{
			printf("1");
		}
		printf("%d\n", c);
	}
	else if (z == '*')
	{
		x = x*y;
		printf("%d\n", x);
	}
	else
	{
		printf("INCORRECT");
	}
	
	return 0;
}
