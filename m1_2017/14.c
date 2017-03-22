#include <stdio.h>
#include <string.h>
char reverse(char *c)
{
	int j = 0, i, m;
	char mas[1000];
	m = strlen(c);
	for (i = m - 1; i >= 0; --i)
	{
		mas[j] = c[i];
		j++;
	}
	for (i = 0; c[i] != '\0'; ++i)
	{
		c[i] = mas[i];
	}
	return *c;
}
void main(void)
{
	int i;
	char mas[1000];
	gets(mas);
	reverse(mas);
	for (i = 0; mas[i] != '\0'; ++i)
	{
		printf("%c", mas[i]);
	}
	
}
