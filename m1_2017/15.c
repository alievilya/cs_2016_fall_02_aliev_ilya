#include <stdio.h>
#include <string.h>

void main(void)
{

	int i, j = 0;
	char c[100], b[100];
	gets(c);
	b[0] = c[0];
	for (i = 0; c[i] != '\0'; i++)
	{
		if (b[j - 1] != c[i]) {
			b[j] = c[i];
			printf("%c", b[j]);
			j++;
		}
	}

}
