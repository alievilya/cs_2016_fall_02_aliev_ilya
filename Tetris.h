
#ifndef TETRIS_H
#define TETRIS_H




void StartGame(void);
void clearscreen(void);
void createmap(void);
void DeleteLine(void);
void Waiting(int sec);
int Random(int max);
void RotateFigure(void);
int FallFigure(int x, int y);
void gotoxy(int X_Position, int Y_Position);
int GetKey(void);
void NextFigure(void);
void print(void);
void GameMenu(void);


#endif
