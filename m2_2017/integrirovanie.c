#include <stdio.h>
#include <stdlib.h>

float func(float x)
{
	return x*x;
}

int main()
{
    float low=0.0, high=0.0 , j = 0.0, n=0.0, x = 0.0, p = 0.0;
	float p1=0.0, p2=0.0, res0=0.0, res1=0.0, i=0.0, k=1.0;
    printf("Enter low:\n");
	scanf("%f", &low);
	printf("Enter high:\n");
	scanf("%f", &high);
	printf("Enter n:\n");
	scanf("%f", &n);
    i=(high-low)/(2*n);
    j=(high-low)/(2*n);
    p=(j/3)*(func(low)+func(high));
	while(high > low+2*k*i || high>low+(2*k+1)*i)
    {
        p1=(2*j/3)*(func(low+2*k*i));
        p2=(4*j/3)*(func(low+i*(2*k+1)));
        k=k+1.0;
        res0=res0+p1+p2;
	}
	res1=p+res0;
	printf("%f\n", res1);

    return 0;
}
