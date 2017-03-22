#include <stdio.h>
#include <conio.h>
#include <math.h>

void main(void) 
{
	int a=0, b, c;
	float D, x1, x2, x;
	printf("vvedite a\n", a);
	scanf_s("%d", &a);
	printf("vvedite b\n", &b);
	scanf_s("%d", &b);
	printf("vvedite c\n", &c);
	scanf_s("%d", &c);
	
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
			
			else //åñëè ñ íå ðàâíî íóëþ
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
	switch (_getch());
}
