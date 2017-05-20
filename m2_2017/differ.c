#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float func(float x)
{
	return x*x*x;
}

void main()
{
	float step = 0.0, x = 0.0, low=0.0, high=0.0;
	float F = 0.0, F1=0.0, F2=0.0;
	int i;

	printf("Please Enter low:\n");
	scanf("%f", &low);
	
	printf("Please Enter high:\n");
	scanf("%f", &high);
	
	printf("Please Enter step:\n");
	scanf("%f", &step);
	x = low;
	F1 = ((-3) * func(x) + 4 * (func(x+step)) - (func(x+2*step)))/(2*step);
	F2 = (1 / (2 * step))*(-func(x) + func(x + 2 * step));
	printf("%f\n", F1);
	printf("%f\n", F2);
	while  (x+2*step <= high)
	{
		F = (1 / (2 * step))*(func(x) - 4 * (func(x + step))+3*(func(x+2*step)));
		
		printf("%f\n", F);
		x = x + step;
	}
	


}
