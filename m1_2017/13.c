#include <stdio.h>
#include <string.h>

void main(void)
{
	int j=0;
	char c[100];
	gets(c);
	for (j = 0; c[j] != '\0'; j++)
	{
		if (c[j] != ' ')
		{
		printf ("=");
		}
		else
		printf ("\n");
			
	}
	
printf ("\n");
}
