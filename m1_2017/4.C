#include <stdio.h>
#define swap1(t,a,b) {t temp; temp = x; x = y; y = temp;}
void main(void)
{
	int x, y;
	printf("enter x, y\n");
	scanf_s("%d %d", &x, &y);
	swap1(int, x, y);
	printf("%d %d\n", x, y);
	switch (_getch());
}
