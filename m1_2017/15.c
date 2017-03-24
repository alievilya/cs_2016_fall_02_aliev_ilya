#include <stdio.h>
#include <string.h>

void main(void)
{

	int i, j = 0;
	char b[100], c[100];
	gets(b);
	c[0] = b[0];
	for (i = 0; b[i] != '\0'; i++)
	{
		if (c[j - 1] != b[i]) {
			c[j] = b[i];
			printf("%c", c[j]);
			j++;
		}
	}	
	printf ("\n");

}
