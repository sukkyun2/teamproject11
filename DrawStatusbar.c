#include"DrawStatusbar.h"

void getStatusbarSize()
{
	getform();
	pos_start.X = 0; pos_start.Y = 0;
	pos_end = getfFullscreen();
	pos_end.Y = onerows;

	statusbar_width = pos_end.X - pos_start.X;
	statusbar_height = pos_end.Y - pos_start.Y;
}

void PrintStatusbar()
{
	int r, c;
	COORD tmp;

	getStatusbarSize();

	tmp.X = pos_start.X;	tmp.Y = pos_start.Y;

	//상단바 위치지정
	gotoxy(pos_start.X, pos_start.Y);

	for (r = 0; r < statusbar_height; r++)
	{
		for (c = 0; c < statusbar_width; c++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
			printf(" ");
			tmp.X++;	gotoxy(tmp.X, tmp.Y);
		}
		tmp.X = 0;	 tmp.Y++;
		gotoxy(0, tmp.Y);
	}
	for (c = 0; c < statusbar_width; c++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		printf(" ");
		tmp.X++;	gotoxy(tmp.X, tmp.Y);
	}

	PrintHomeButton();

	// 끝나면 원상태로
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void PrintHomeButton()
{
	int r, c;
	COORD tmp;

	pos_start.X = (int)((double)(10.5 * onecols));
	pos_start.Y = 0;

	pos_end.X = (int)((double)(11.5 * onecols));
	pos_end.Y = onerows;

	tmp.X = pos_start.X;	tmp.Y = pos_start.Y;

	gotoxy((int)(pos_start.X + (double)(0.5 * onecols) - 2), (int)((double)(0.5 * onerows)));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
	printf("HOME");

	gotoxy(pos_start.X, pos_start.Y);

	for (r = 0; r < onerows; r++)
	{
		for (c = 0; c < onecols; c++)
		{
			if (c == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
				printf(" ");
			}
			else if (c == onecols - 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				printf(" ");
			}
			tmp.X++;	gotoxy(tmp.X, tmp.Y);
		}
		tmp.X = pos_start.X;	tmp.Y++;
		gotoxy(pos_start.X, tmp.Y);
	}
}