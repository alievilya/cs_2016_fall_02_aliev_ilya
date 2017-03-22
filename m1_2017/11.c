#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>

int r(char *a)
{
	
	int j, v = 0, i;
	j = strlen(a) - 1;
	for (i = 0; a[i] != '\0'; ++i)
	{
		if (a[i] == '1')
			v = v + pow(2, j);
		j--;
	}
	return v;
}
int main() 
{
	setlocale(LC_CTYPE, "Russian");

	char N[1000];
	printf("Ââåäèòå äâîè÷íîå ÷èñëî ");
	gets(N);
	printf("%d\n", r(N));
	return 0;
}
