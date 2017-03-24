#include "stdio.h"

void main(void)
{
	int day, month, a;
	printf("Day:");
	scanf("%i", &day);
	printf("Month:");
	scanf("%i", &month);
	if (day > 31 || day < 1 || month > 12 || month < 1)
		printf("Wrong data\n");
	else
	{
		a = day;
		day = month;
		month = a;
		printf("Day:%i\nMonth:%i\n", day, month);
	}
	
}
