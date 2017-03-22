#include "stdio.h"
#include "conio.h"
void main(void)
{
	int day, month, a;
	printf("Day:");
	scanf_s("%i", &day);
	printf("Month:");
	scanf_s("%i", &month);
	if (day > 31 || day < 1 || month > 12 || month < 1)
		printf("Wrong data\n");
	else
	{
		a = day;
		day = month;
		month = a;
		printf("Day:%i\nMonth:%i\n", day, month);
	}
	switch (_getch());
}
