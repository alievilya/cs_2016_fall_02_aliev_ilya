#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float func(float x)
{
	return (x*x+4);
}

double integral(double low, double high, int n)
{
    int i=1;
    double a=0.0, res=0.0, s=0.0, s1=0.0, r=0.0;
    r=(high-low)/n;
    a=low;
   while(a<high)
	{
        a=a+r;
                if(i%2!=0)
                {
                   s+=func(a); 
                }
                else
                {
                   s1+=func(a);
                }
                i++;

    } 
    res=r/3*(func(low)+func(high)+4*s+2*s1);
    return res;
}
int main()
{
    double low_border,high_border;
    int number_of_fragmentation;
    printf("Enter low border of function: y=x*x+4 \n");
    scanf("%lf",&low_border);
    printf("Enter high border of func\n");
    scanf("%lf",&high_border);
    printf("Enter number of fragmentation\n");
    scanf("%i",&number_of_fragmentation);
    printf("Integral = %lf\n",integral(low_border,high_border,number_of_fragmentation));
    return 0;
}
