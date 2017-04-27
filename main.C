
#include "Tetris.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include "Tetris.h"



// определения клавиш
#define KEY_UP 72 
#define KEY_DOWN 80 
#define KEY_LEFT 75 
#define KEY_RIGHT 77 
#define KEY_SPACE 32
#define KEY_ESC 27 
#define KEY_ENTER 13 

#define HorizontalSizeX 16
#define VerticalSizeY 18
#define NumberOfFigures 7 //количество фигур тетриса

#define TRUE 1
#define FALSE 0

#define MapColor  177//закрашивание поля
#define FigureColor  254 //закрашивание фигуры

#define cursor "\x1A" //символ курсора

const char* GAME_TITLE =
"W E L C O M E\t \n \t T O \nT E T R I S\n\n\n"; // заголовок

void gotoxy(int xpos, int ypos); //помещает курсор в точку с координатами  xpos, ypos

int screen[HorizontalSizeX][VerticalSizeY] = { 0 }; // размер экрана
int map[4][4]; //фигура
int px, py, score, nextmap;
int i, j;
int fmap[NumberOfFigures][4][4] = //инициализация фигур
{
	{
		{ 1, 1, 0, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 1, 0, 0, 0 }
	},
	{
		{ 0, 0, 1, 0 },
		{ 1, 1, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 1, 0 },
		{ 1, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 1, 1, 1, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	}
};

void print(void) //печать
{
	int buff[HorizontalSizeX][VerticalSizeY];

	for (i = 0; i < VerticalSizeY; i++) for (j = 0; j < HorizontalSizeX; j++) buff[j][i] = screen[j][i]; //вывод из буфера на экран
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (map[j][i]) buff[j + px][i + py] = 1; //если часть фигуры, то в буфере обозначить 1

	gotoxy(0, 0); //перейти в точку с координатами 0, 0
	for (i = 0; i < VerticalSizeY; i++)
	{
		for (j = 0; j < HorizontalSizeX; j++)
		{

			putchar(buff[j][i] == 0 ? MapColor : FigureColor); //если элемент в буфере не часть фигуры, закрасить полем
		}
		putchar('\n');
	}

	gotoxy(HorizontalSizeX + 1, 0); // передвинуться вбок
	printf("Score: %i", score); // вывести количество очков, набираемое в ходе игры
}
void NextFigure(void) // вывести следющую идущую фигуру в поле
{

	gotoxy(HorizontalSizeX + 1, 2);
	printf("Next: ");

	for (i = 0; i < 4; i++)
	{
		gotoxy(HorizontalSizeX + 2, i + 3);
		for (j = 0; j < 4; j++)
		{
			putchar(fmap[nextmap][j][i] == 0 ? ' ' : FigureColor); // если не является частью фигуры, то закрасить пробелами, иначе закрасить фигурой
		}
	}
}

int GetKey(void)
{
	int c;
	if (_kbhit()) //возвращает истину, если нажата какая-либо клавиша на клавиатуре. 
				  //В противном случае возвращается 0. В любом случае код клавиши не удаляется из входного буфера.
	{
		if ((c = _getch()) == 224) c = _getch(); //если нажата клавиша p, нажать любую для продолжения
		return c;
	}
	return FALSE;
}

void gotoxy(int X_Position, int Y_Position) //функция перехода курсором в точку с координатами xpos, ypos
{
	COORD scrn;
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = X_Position; scrn.Y = Y_Position;
	SetConsoleCursorPosition(ConsoleHandle, scrn);
}

int FallFigure(int x, int y) //падение фигуры (вниз)
{
	int i, j;
	if (x < 0) return FALSE;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (map[j][i])
			{
				if ((j + x >= HorizontalSizeX) || (i + y >= VerticalSizeY)) return FALSE;
				if (screen[j + x][i + y])
				{
					return FALSE;
				}
			}
		}
	}
	return TRUE;
}

/*
inv(0) => 3
inv(1) => 2
inv(2) => 1
inv(3) => 0
*/
#define inv(x) ((x * (-1)) + 3)

void RotateFigure(void) // поворот фигуры
{

	int _map[4][4];
	int  sFrameOfx = 4, sFrameOfy = 4;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			_map[j][i] = map[j][i];
			if (map[j][i])
			{
				if (i < sFrameOfx) sFrameOfx = i;
				if (inv(j) < sFrameOfy) sFrameOfy = inv(j);
			}
			map[j][i] = 0;
		}

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (_map[inv(i)][j]) map[j - sFrameOfx][i - sFrameOfy] = 1;

	if (!FallFigure(px, py)) for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) map[j][i] = _map[j][i];
}

int Random(int max) // рандомизация
{
	max++;
	return (int)(rand() * max / RAND_MAX);
}

void Waiting(int sec) //задержка падения
{
	clock_t t = clock();
	while (clock() - t < sec);
}

void DeleteLine(void) // очищение ряда
{
	int  k, cl;

	for (i = VerticalSizeY - 1; i >= 0; i--)
	{
		cl = 1;
		for (j = 0, cl = 1; j < HorizontalSizeX; j++)
		{
			if (!screen[j][i]) cl = 0;
		}
		if (cl)
		{
			/* Animation */
			gotoxy(0, i);
			for (k = 0; k < HorizontalSizeX; k++) putchar('_'), Waiting(20);
			/* --------- */

			score += (((i * (-1)) + VerticalSizeY) * 10);

			for (k = i; k > 0; k--)
			{
				for (j = 0; j < HorizontalSizeX; j++)
				{
					screen[j][k] = screen[j][k - 1];
				}
			}
			i++;
			print();
		}
	}
}

void createmap(void) //ñîçäàíèå ôèãóðû
{
	int i, j;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			map[j][i] = fmap[nextmap][j][i];
	py = 0;
	px = HorizontalSizeX / 2;

	nextmap = Random(NumberOfFigures - 1);
	NextFigure();
}

void clearscreen(void) //î÷èñòêà ýêðàíà
{
	int i, j;
	for (i = 0; i < VerticalSizeY; i++)
		for (j = 0; j < HorizontalSizeX; j++)
			screen[j][i] = 0;
}



void StartGame(void) // начало игры
{

	int  c;
	time_t tm;

	system("cls");
	px = HorizontalSizeX / 2;
	py = 0;
	score = 0;

	tm = clock();

	nextmap = Random(NumberOfFigures - 1);
	createmap();

	while (TRUE)
	{
		c = GetKey();

		switch (c)
		{
		case KEY_UP:
			RotateFigure();
			break;
		case KEY_SPACE:
			RotateFigure();
			break;
		case KEY_DOWN:
			for (; FallFigure(px, py + 1); py++);
			for (i = 0; i < 4; i++)
				for (j = 0; j < 4; j++)
					if (map[j][i]) screen[px + j][py + i] = 1;

			print();
			DeleteLine();
			createmap();
			break;
		case KEY_LEFT:
			if (FallFigure(px - 1, py)) px--;
			break;
		case KEY_RIGHT:
			if (FallFigure(px + 1, py)) px++;
			break;
		case 'p':
			_getch();
			break;
		case KEY_ESC:
			return;
		}

		if ((clock() - tm) > 320)
		{
			tm = clock();

			if (!(FallFigure(px, py + 1)))
			{
				for (i = 0; i < 4; i++)
					for (j = 0; j < 4; j++)
						if (map[j][i]) screen[px + j][py + i] = 1;

				createmap();
				DeleteLine();
			}
			else py++;
		}

		print();

		for (i = 0; i < HorizontalSizeX; i++)
		{
			if (screen[i][0])
			{
				system("cls");
				gotoxy(2, 8);
				printf("Game Over :(");
				return;
			}
		}
	}
}

void GameMenu(void) //меню игры
{
	int p = 1, c = 0;
	const char* GAME_MENU =
		"\t" cursor "1. Start\n"
		"\t 2. Info\n"
		"\t 3. Exit";
	system("cls"); printf("%s%s", GAME_TITLE, GAME_MENU);
	while (TRUE) // навигация в меню
	{
		c = _getch();

		gotoxy(8, 8 + p - 1); //стрелка пропадает
		putchar(' ');

		switch (c)
		{
		case '1':
		case '2':
		case '3':

			p = c - '0';
		case KEY_ENTER:
			switch (p)
			{
			case 1:
				clearscreen();
				StartGame();
				gotoxy(0, VerticalSizeY); printf("Press ESC to exit to main menu...\n"); while (_getch() != KEY_ESC);
				break;

			case 2:
				system("cls");
				printf("%s%s", GAME_TITLE,
					"\t\x1B       Left \n"
					"\t\x1A       Right\n"
					"\t\x19       Put Down\n"
					"\tSpace   Rotate\n"
					"\tP       Pause\n"
					"\tESC     Exit\n\n"

					"Press any key...\n");
				_getch(); if (_kbhit()) _getch();
				break;
			case 3: return;
			}
			system("cls"); printf("%s%s", GAME_TITLE, GAME_MENU);
			p = 1;
			break;
		case KEY_UP:
			if (p > 1) p--;
			break;
		case KEY_DOWN:
			if (p < 4) p++;
			break;
		case KEY_ESC:
			return;
		}
		gotoxy(8, 8 + p - 1); //ñòàâèì ñòðåëî÷êó
		putchar('\x1A');
	}
}

int main()
{
	//srand((unsigned)time(NULL));
	printf("%s%s", GAME_TITLE,
		"Press any key to begin...\n");
	_getch(); if (_kbhit()) _getch();
GameMenu();
return 0;
}
