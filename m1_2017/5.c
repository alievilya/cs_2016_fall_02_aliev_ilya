#include <stdio.h>
#include <locale.h>


int main()
{
	setlocale(LC_CTYPE, "Russian");
	float bot, top, f;

	printf("Введите нижнюю границу интервала : \n");
	scanf_s("%f", &bot);
	printf("Введите верхнюю границу интервала : \n");
	scanf_s("%f", &top);
	printf("      C      |      F      \n"
		"_____________|_____________\n");
	if (bot <= top)
	{
	
		for (float i = bot; i <= top; i++)
		{
			f = 1.8*bot + 32;
			printf("%12f | %12f\n", bot, f);
			bot += 1;
		} 
			
	}
	else
	{
		printf("Введите правильную границу интервала \n\n");
		
	}
	
	return 0;
}

