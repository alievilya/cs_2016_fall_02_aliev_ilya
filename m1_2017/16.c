#include <stdio.h>
#include <string.h>
#include <conio.h>

void StrCopy(char *t, char *s, int n)
{
	int i = 1;
	while (i <= 2)
	{
		if ((*s++ = *t++) != 0)
			i++;
	}
}

void StrCat(char *t1, char *s1, int n)
{
	int i = 1;
	while (*s1 != 0)
		s1++;
	while (i <= 2)
	{
		if ((*s1++ = *t1++) != 0)
			i++;
	}
}

int StrCompare(char *t2, char *s2, int n)
{
	int i = 1;
	while (*t2 == *s2 && *t2 != 0 && i <= n)
	{
		t2++, s2++;
		i++;
	}
	return *t2 - *s2;
}

void main(void)
{
	char t[] = "abcd";
	char s[] = "aaaa";
	StrCopy(t, s, 2);
	printf("%s %s\n", t, s);
	printf("\n");

	char t1[] = "abcd";
	char s1[] = "aaaa";
	StrCat(t1, s1, 2);
	printf("%s %s\n", t1, s1);

	char t2[] = "abaa";
	char s2[] = "abaa";
	printf("%i\n", StrCompare(s2, t2, 2));
}
