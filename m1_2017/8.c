#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() 
{
	float a=0, b=0, c=0;
	float D, x1, x2, x;
	printf("vvedite a\n");
	scanf("%f", &a);
	printf("vvedite b\n");
	scanf("%f", &b);
	printf("vvedite c\n");
	scanf("%f", &c);
	
	D = (pow(b, 2) - 4*a*c);
	 
	if (a > 0 || a < 0)
	{
		
		if (D > 0)
		{
			if (c == 0)
			{
				x1 = 0;
				printf("x1=%.2f\n", x1);
				x2 = (-b - b) / (a * 2);
				printf("x2=%.2f\n", x2);
			}
			
			else 
			{
				if (b == 0)

				{
					x1 = sqrt(-4 * a*c) / (2 * a);
					printf("x1=%.2f\n", x1);
					x2 = -sqrt(-4 * a*c) / (2 * a);
					printf("x2=%.2f\n", x2);
				}
				else 
				{
					printf("tut  2 kornya\n");
					x1 = (-b + pow(pow(b, 2) - 4 * a*c, (1 / 2))) / (a * 2);
					printf("x1=%.2f\n", x1);
					x2 = (-b - pow(pow(b, 2) - 4 * a*c, (1 / 2))) / (a * 2);
					printf("x2=%.2f\n", x2);
									
				} 
			}
		}
		else if (D == 0)
		{
			printf("tut  1 koren\n");
			x = (-b) / (2 * a);
			printf("x=%.2f\n", x);
		}

		else
		{
			printf("vvedite normal'no");
		}
		
	}
	else 
	{
			printf("tut 1 koren\n");
			x1 = (-c) / b;
			printf("x1=%.2f\n", x1);
	}
	return 0;
}
