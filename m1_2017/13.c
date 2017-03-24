#include <stdio.h>
#include <string.h>

void main(void)
{
	int m = -1, i, b[100], j = 0, k = 0, x;
	char c[100];
	gets(c);
	for (i = 0; c[i] != '\0'; i++)
	{
		if (c[i] == ' ')
		{
				b[j] = i;
				j++;
				
				m = 0;
		}
		else
			if (c[i + 1] == '\0')
			{
				b[j] = i - k - m;
				j++;
			}
	}
	for (i = 0; i<j; i++)
	{
		for (x = 0; x<b[i]; x++)
			printf("=");
		printf("\n\n");
	}

}
