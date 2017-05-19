#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float func(float x)
{
	return x*(x+1);
}

void main()
{
	float step = 0.0, x = 0.0, low=0.0, high=0.0;
	float P = 0.0, P1=0.0, P2=0.0;
	int i;

	printf("Enter low:\n");
	scanf("%f", &low);
	printf("Enter high:\n");
	scanf("%f", &high);
	printf("Enter step:\n");
	scanf("%f", &step);
	x = low;
	P1 = ((-3) * func(x) + 4 * (func(x+step)) - (func(x+2*step)))/(2*step);
	P2 = (1 / (2 * step))*(-func(x) + func(x + 2 * step));
	printf("%f\n", P1);
	printf("%f\n", P2);
	do
	{
		P = (1 / (2 * step))*(func(x) - 4 * (func(x + step))+3*(func(x+2*step)));
		x = x + step;
		printf("%f\n", P);
	}
	while  (x+2*step <= high);


}
