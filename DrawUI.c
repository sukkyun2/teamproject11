#include"DrawUI.h"

int width, height;


void getcenter()
{
	getform();

	pos_start.X = (int)(pos_full.X / 2);
	pos_start.Y = (int)(pos_full.Y / 2);
}

void getCenterBoxSize(int width, int height)
{
	getcenter();

	pos_start.X -= (int)(width / 2);
	pos_start.Y -= (int)(height / 2);

	pos_end.X = pos_start.X + width;
	pos_end.Y = pos_start.Y + height;
}

void DrawCenterBox(int width, int height)
{
	getCenterBoxSize(width, height);

	COORD tmp;
	int r, c;

	tmp.X = pos_start.X;   tmp.Y = pos_start.Y;

	gotoxy(tmp.X, tmp.Y);

	for (c = 1; c <= height; c++)
	{
		if (c == 1)
		{
			for (r = 1; r <= width; r++)
			{
				if (r == 1) printf("┌");
				else if (r == width)
					printf("┐");
				else printf("─");
				tmp.X++;   gotoxy(tmp.X, tmp.Y);
			}
		}
		else if (c == height)
		{
			for (r = 1; r <= width; r++)
			{

				if (r == 1) printf("└");
				else if (r == width) printf("┘");
				else printf("─");
				tmp.X++;   gotoxy(tmp.X, tmp.Y);
			}
		}
		else
		{
			for (r = 1; r <= width; r++)
			{
				if ((r == 1) || (r == width))
					printf("│");
				else printf(" ");
				tmp.X++;   gotoxy(tmp.X, tmp.Y);
			}
		}
		tmp.X = pos_start.X;   tmp.Y++;
		gotoxy(tmp.X, tmp.Y);
	}
}

void DrawBOX(COORD pos_start, int width, int height)
{
	int r, c;
	COORD tmp;

	tmp.X = pos_start.X; tmp.Y = pos_start.Y;

	gotoxy(tmp.X, tmp.Y);
	for (c = 1; c <= height; c++)
	{
		if (c == 1)
		{
			for (r = 1; r <= width; r++)
			{
				if (r == 1) printf("┌");
				else if (r == width)
					printf("┐ ");
				else printf("─");
				tmp.X++;   gotoxy(tmp.X, tmp.Y);
			}
		}
		else if (c == height)
		{
			for (r = 1; r <= width; r++)
			{

				if (r == 1) printf("└");
				else if (r == width) printf("┘ ");
				else printf("─");
				tmp.X++;   gotoxy(tmp.X, tmp.Y);
			}
		}
		else
		{
			for (r = 1; r <= width; r++)
			{
				if ((r == 1) || (r == width))
					printf("│ ");
				else printf(" ");
				tmp.X++;   gotoxy(tmp.X, tmp.Y);
			}
		}
		tmp.X = pos_start.X;   tmp.Y++;
		gotoxy(tmp.X, tmp.Y);
	}
}

void DrawboldBOX(COORD pos_start, int width, int height)
{
	int r, c;
	COORD tmp;

	tmp.X = pos_start.X; tmp.Y = pos_start.Y;

	gotoxy(tmp.X, tmp.Y);
	for (c = 1; c <= height; c++)
	{
		if (c == 1)
		{
			for (r = 1; r <= width; r++)
			{
				if (r == 1) printf("┏");
				else if (r == width)
					printf("┓ ");
				else printf("━");
				tmp.X++;   gotoxy(tmp.X, tmp.Y);
			}
		}
		else if (c == height)
		{
			for (r = 1; r <= width; r++)
			{

				if (r == 1) printf("┗");
				else if (r == width) printf("┛ ");
				else printf("━");
				tmp.X++;   gotoxy(tmp.X, tmp.Y);
			}
		}
		else
		{
			for (r = 1; r <= width; r++)
			{
				if ((r == 1) || (r == width))
					printf("┃ ");
				else printf(" ");
				tmp.X++;   gotoxy(tmp.X, tmp.Y);
			}
		}
		tmp.X = pos_start.X;   tmp.Y++;
		gotoxy(tmp.X, tmp.Y);
	}
}

void PrintLoginInputbox()
{
	int i;
	textcolor(BLACK, WHITE);
	for (i = 0; i < 12; i++)
		printf(" ");
	textcolor(WHITE, BLACK);
}

void PrintStatusbarSize()
{
	getform();
	pos_start.X = 0; pos_start.Y = 0;
	pos_end.X = pos_full.X; pos_end.Y = onerows;

	width = pos_end.X - pos_start.X;
	height = pos_end.Y - pos_start.Y;
}

void PrintStatusbar()
{
	COORD tmp;
	int r, c;

	PrintStatusbarSize();
	tmp.X = pos_start.X;   tmp.Y = pos_start.Y;

	//상단바 위치지정
	gotoxy(pos_start.X, pos_start.Y);

	for (r = 0; r < height; r++)
	{
		for (c = 0; c < width; c++)
		{
			textcolor(WHITE, LIGHTGRAY);
			printf(" ");
			tmp.X++;   gotoxy(tmp.X, tmp.Y);
		}
		tmp.X = 0;    tmp.Y++;
		gotoxy(0, tmp.Y);
	}
	for (c = 0; c < width; c++)
	{
		textcolor(WHITE, BLACK);
		printf(" ");
		tmp.X++;   gotoxy(tmp.X, tmp.Y);
	}

	// 끝나면 원상태로
	textcolor(WHITE, BLACK);
}

void PrintHomeButton()
{
	int r, c;
	COORD tmp;

	pos_start.X = (int)((double)(10.5 * onecols));
	pos_start.Y = 0;

	pos_end.X = (int)((double)(11.5 * onecols));
	pos_end.Y = onerows;

	tmp.X = pos_start.X;   tmp.Y = pos_start.Y;

	gotoxy((int)(pos_start.X + (double)(0.5 * onecols) - 2), (int)((double)(0.5 * onerows)));
	textcolor(WHITE, LIGHTGRAY);
	printf("HOME");

	gotoxy(pos_start.X, pos_start.Y);

	for (r = 0; r < onerows; r++)
	{
		if (r == 0)
		{
			for (c = 0; c < onecols; c++)
			{
				if (c >= onecols - 2)
				{
					textcolor(WHITE, DARKGRAY);
					printf(" ");
				}
				else
				{
					textcolor(WHITE, WHITE);
					printf(" ");
				}
			}
		}
		else if (r == onerows - 1)
		{
			for (c = 0; c < onecols; c++)
			{
				if (c <= 1)
				{
					textcolor(WHITE, WHITE);
					printf(" ");
				}
				else
				{
					textcolor(WHITE, DARKGRAY);
					printf(" ");
				}
				tmp.X++;   gotoxy(tmp.X, tmp.Y);
			}
		}
		else
		{
			for (c = 0; c < onecols; c++)
			{
				if (c <= 1)
				{
					textcolor(WHITE, WHITE);
					printf(" ");
				}
				else if (c >= onecols - 2)
				{
					textcolor(WHITE, DARKGRAY);
					printf(" ");
				}
				tmp.X++;   gotoxy(tmp.X, tmp.Y);
			}
		}

		tmp.X = pos_start.X;   tmp.Y++;
		gotoxy(pos_start.X, tmp.Y);
	}
	// 끝나면 원상태로
	textcolor(WHITE, BLACK);
}

void PrintSelectdateButton()
{
	int i;
	pos_start.X = (int)((double)(0.5 * onecols));
	pos_start.Y = (int)((double)(1.0 * onerows) + 1);

	DrawBOX(pos_start, strlen(" 날짜 입력 ") + 2, 3);

	pos_start.X = (int)((double)(0.5 * onecols) + 2);
	pos_start.Y = (int)((double)(1.0 * onerows) + 2);
	gotoxy(pos_start.X, pos_start.Y);
	printf("날짜 입력");

	textcolor(WHITE, BLACK);
	pos_start.X = (int)((double)(0.5 * onecols) + 2 + strlen("날짜 입력   "));
	gotoxy(pos_start.X, pos_start.Y);
	for (i = pos_start.X + strlen("날짜 입력    "); i < pos_end.X; i++)
		printf(" ");
}

void PrinttSelectdateInputbox()
{
	int i;

	pos_start.X = (int)((double)(0.5 * onecols) + 2 + strlen("날짜 입력   "));
	pos_start.Y = (int)((double)(1.0 * onerows) + 2);
	gotoxy(pos_start.X, pos_start.Y);

	textcolor(DARKGRAY, WHITE);
	printf("  1999-02-10 ");
	for (i = pos_start.X + strlen("  1999-02-10"); i < pos_end.X; i++)
		printf(" ");
	textcolor(WHITE, BLACK);   // 원 색깔로
}

void PrinttSelectdateInputbox_beinput()
{
	int i;

	pos_start.X = (int)((double)(0.5 * onecols) + 2 + strlen("날짜 입력   "));
	pos_start.Y = (int)((double)(1.0 * onerows) + 2);

	textcolor(DARKGRAY, WHITE);
	for (i = 0; i < strlen(" 1999-02-10"); i++)
		printf(" ");

	textcolor(BLACK, WHITE);   // 입력색깔
}

void PrinttodaydateButton()
{
	pos_start.X = (int)((double)(6.5 * onecols));
	pos_start.Y = (int)((double)(1.0 * onerows) + 3);

	pos_end.X = (int)((double)(7.5 * onecols));
	pos_end.Y = (int)((double)(2.0 * onerows) + 3);;

	width = pos_end.X - pos_start.X;
	height = pos_end.Y - pos_start.Y;
	DrawBOX(pos_start, width, height);

	pos_start.X = (int)((double)(7.0 * onecols) - (strlen("오늘 날짜") / 2));
	pos_start.Y = (int)((double)(1.5 * onerows) + 3);
	gotoxy(pos_start.X, pos_start.Y);
	printf("오늘 날짜");
}

void getCalendarSize()
{
	pos_start.X = (int)((double)(0.5 * onecols));
	pos_start.Y = (int)((double)(2.0 * onerows) + 6);

	pos_end.X = (int)((double)(7.5 * onecols));
	pos_end.Y = (int)((double)(8.0 * onerows) + 6);

	calendar_width = pos_end.X - pos_start.X;
	calendar_height = pos_end.Y - pos_start.Y;
}

void PrintCalendar_background()
{
	COORD tmp;
	int r, c;

	tmp.X = pos_start.X;   tmp.Y = pos_start.Y;

	gotoxy(tmp.X, tmp.Y);

	for (c = 1; c <= calendar_height; c++)
	{
		if ((c != calendar_height) && (c % onerows) == 0)
		{
			for (r = 1; r <= calendar_width; r++)
			{
				if ((r != calendar_width) && (r % onecols) == 0) printf("┼");
				else if (r == 1) printf("├");
				else if (r == calendar_width) printf("┤ ");
				else printf("─");
				tmp.X++;   gotoxy(tmp.X, tmp.Y);
			}
		}
		else if (c == 1)
		{
			for (r = 1; r <= calendar_width; r++)
			{
				if ((r != calendar_width) && (r % onecols) == 0) printf("┬");
				else if (r == 1) printf("┌");
				else if (r == calendar_width) printf("┐ ");
				else printf("─");
				tmp.X++;   gotoxy(tmp.X, tmp.Y);
			}
		}
		else if (c == calendar_height)
		{
			for (r = 1; r <= calendar_width; r++)
			{
				if ((r != calendar_width) && (r % onecols) == 0) printf("┴");
				else if (r == 1) printf("└");
				else if (r == calendar_width) printf("┘ ");
				else printf("─");
				tmp.X++;   gotoxy(tmp.X, tmp.Y);
			}
		}
		else
		{
			for (r = 1; r <= calendar_width; r++)
			{
				if ((r != calendar_width) && (r % onecols) == 0) printf("│");
				else if (r == 1) printf("│");
				else if (r == calendar_width) printf("│ ");
				else printf(" ");
				tmp.X++;   gotoxy(tmp.X, tmp.Y);
			}
		}
		tmp.X = pos_start.X;   tmp.Y++;
		gotoxy(tmp.X, tmp.Y);
	}
}

void PrintCalendarweek()
{
	COORD date_start, tmp;
	const char* week[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri" ,"Sat" };
	int i;

	date_start.X = (int)((double)(1.0 * onecols) - 1);
	date_start.Y = (int)((double)(2.0 * onerows) + 5);
	tmp.X = date_start.X;   tmp.Y = date_start.Y;

	gotoxy(tmp.X, tmp.Y);
	for (i = 0; i < 7; i++)
	{
		printf("%s", week[i]);
		tmp.X += onecols;
		gotoxy(tmp.X, tmp.Y);
	}
}

void PrintCalendarform()
{
	getform();
	getCalendarSize();
	PrintCalendar_background();
	PrintCalendarweek();
	PrintSelectdateButton();
	PrinttodaydateButton();
}

void getMenusize()
{
	pos_start.X = (int)((double)(8.5 * onecols));
	pos_start.Y = (int)((double)(1.0 * onerows) + 6);

	pos_end.X = (int)((double)(11.5 * onecols));
	pos_end.Y = (int)((double)(8.0 * onerows) + 6);

	width = pos_end.X - pos_start.X;
	height = pos_end.Y - pos_start.Y;
}

void PrintMenu()
{
	getMenusize();
	DrawBOX(pos_start, width, height);
	print_askMenunum();
}

void PrintMenuButton(int menuNum, int menu)
{
	int i;
	COORD button;

	getMenusize();
	button.X = pos_start.X + 2;   button.Y = pos_start.Y + 3;

	for (i = 0; i < menuNum; i++)
	{
		if (i == menu - 1)
			DrawboldBOX(button, width - 4, 3);
		else
			DrawBOX(button, width - 4, 3);
		button.Y += 3;
	}
}

void print_askMenunum()
{
	COORD tmp;
	getMenusize();
	tmp.X = pos_start.X + 3;   tmp.Y = pos_start.Y + 2;

	gotoxy(tmp.X, tmp.Y);
	printf("메뉴 번호를 입력해주세요 :    ");
}

void Printmanagement()
{
	getform();
	pos_start.X = (int)((double)(0.5 * onecols));
	pos_start.Y = (int)((double)(1.0 * onerows) + 3);

	pos_end.X = (int)((double)(7.5 * onecols));
	pos_end.Y = (int)((double)(8.0 * onerows) + 6);

	width = pos_end.X - pos_start.X;
	height = pos_end.Y - pos_start.Y;

	DrawBOX(pos_start, width, height);
}