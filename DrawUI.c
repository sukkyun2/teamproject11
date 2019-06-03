#include"DrawUI.h"

int width, height;

void getcenter()
{
	getform();

	pos_start.X = (int)(pos_start.X / 2);
	pos_start.Y = (int)(pos_start.Y / 2);
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

	tmp.X = pos_start.X;	tmp.Y = pos_start.Y;

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
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		else if (c == height)
		{
			for (r = 1; r <= width; r++)
			{

				if (r == 1) printf("└");
				else if (r == width) printf("┘");
				else printf("─");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		else
		{
			for (r = 1; r <= width; r++)
			{
				if ((r == 1) || (r == width))
					printf("│");
				else printf(" ");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		tmp.X = pos_start.X;	tmp.Y++;
		gotoxy(tmp.X, tmp.Y);
	}
}

void getStatusbarSize()
{
	getform();
	pos_start.X = 0; pos_start.Y = 0;
	pos_end = getFullscreen();
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
			textcolor(WHITE, LIGHTGRAY);
			printf(" ");
			tmp.X++;	gotoxy(tmp.X, tmp.Y);
		}
		tmp.X = 0;	 tmp.Y++;
		gotoxy(0, tmp.Y);
	}
	for (c = 0; c < statusbar_width; c++)
	{
		textcolor(WHITE, BLACK);
		printf(" ");
		tmp.X++;	gotoxy(tmp.X, tmp.Y);
	}

	PrintHomeButton();

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

	tmp.X = pos_start.X;	tmp.Y = pos_start.Y;

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
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
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
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}

		tmp.X = pos_start.X;	tmp.Y++;
		gotoxy(pos_start.X, tmp.Y);
	}
}

void PrintSelectdateButton()
{
	COORD pos = getFullscreen();
	pos.X = (int)((double)(0.5 * onecols) + 2);
	pos.Y = (int)((double)(1.0 * onerows) + 2);
	gotoxy(pos.X, pos.Y);
	printf("날짜 입력");
}

void PrinttSelectdateInputbox()
{
	int i;

	COORD pos = getFullscreen();
	pos.X = (int)((double)(0.5 * onecols) + 2 + strlen("날짜 입력 "));
	pos.Y = (int)((double)(1.0 * onerows) + 2);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);

	for (i = pos.X; i < pos_end.X; i++)
		printf(" ");
}

void PrinttodaydateButton()
{
	COORD pos = getFullscreen();
	pos.X = (int)((double)(7.0 * onecols) - 2);
	pos.Y = (int)((double)(1.5 * onerows) + 3);
	gotoxy(pos.X, pos.Y);
	printf("오늘 날짜");
}

void getCalendarSize()
{
	pos_start.X = (int)((double)(0.5 * onecols));
	pos_start.Y = (int)((double)(2.0 * onerows) + 6);

	pos_end.X = (int)((double)(7.5 * onecols));
	pos_end.Y = (int)((double)(7.0 * onerows) + 6);

	calendar_width = pos_end.X - pos_start.X;
	calendar_height = pos_end.Y - pos_start.Y;
}

void PrintCalendar_background()
{
	COORD tmp;
	int r, c;

	tmp.X = pos_start.X;	tmp.Y = pos_start.Y;

	gotoxy(tmp.X, tmp.Y);

	for (c = 1; c <= calendar_height; c++)
	{
		if ((c != calendar_height) && (c % onerows) == 0)
		{
			for (r = 1; r <= calendar_width; r++)
			{
				if ((r != calendar_width) && (r % onecols) == 0) printf("┼");
				else if (r == 1) printf("├");
				else if (r == calendar_width) printf("┤");
				else printf("─");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		else if (c == 1)
		{
			for (r = 1; r <= calendar_width; r++)
			{
				if ((r != calendar_width) && (r % onecols) == 0) printf("┬");
				else if (r == 1) printf("┌");
				else if (r == calendar_width) printf("┐");
				else printf("─");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		else if (c == calendar_height)
		{
			for (r = 1; r <= calendar_width; r++)
			{
				if ((r != calendar_width) && (r % onecols) == 0) printf("┴");
				else if (r == 1) printf("└");
				else if (r == calendar_width) printf("┘");
				else printf("─");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		else
		{
			for (r = 1; r <= calendar_width; r++)
			{
				if ((r != calendar_width) && (r % onecols) == 0) printf("│");
				else if (r == 1) printf("│");
				else if (r == calendar_width) printf("│");
				else printf(" ");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		tmp.X = pos_start.X;	tmp.Y++;
		gotoxy(tmp.X, tmp.Y);
	}
}

void PrintCalendarweek()
{
	COORD date_start, tmp;
	char* week[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri" ,"Sat" };
	int i;

	date_start.X = (int)((double)(1.0 * onecols) - 1);
	date_start.Y = (int)((double)(2.0 * onerows) + 5);
	tmp.X = date_start.X;	tmp.Y = date_start.Y;

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

void getnavigatorSize()
{
	getform();
	navipos_start.X = (int)((double)(8.5 * onecols));
	navipos_start.Y = (int)((double)(4.0 * onerows) + 7);

	navipos_end.X = (int)((double)(11.5 * onecols));
	navipos_end.Y = (int)((double)(7.0 * onerows) + 6);

	navigator_width = navipos_end.X - navipos_start.X;
	navigator_height = navipos_end.Y - navipos_start.Y;
}

void Printnavigator_background()
{
	COORD tmp;
	int r, c;

	getnavigatorSize();
	tmp.X = navipos_start.X;	tmp.Y = navipos_start.Y;

	gotoxy(tmp.X, tmp.Y);

	for (c = 1; c <= navigator_height; c++)
	{
		if (c == 1)
		{
			for (r = 1; r <= navigator_width; r++)
			{

				if (r == 1) printf("┌");
				else if (r == navigator_width) printf("┐");
				else printf("─");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		else if (c == navigator_height)
		{
			for (r = 1; r <= navigator_width; r++)
			{

				if (r == 1) printf("└");
				else if (r == navigator_width) printf("┘");
				else printf("─");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		else
		{
			for (r = 1; r <= navigator_width; r++)
			{
				if ((r == 1) || (r == navigator_width)) printf("│");
				else printf(" ");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		tmp.X = navipos_start.X;	tmp.Y++;
		gotoxy(tmp.X, tmp.Y);
	}
}

void getmenuSize()
{
	pos_start.X = (int)((double)(8.5 * onecols));
	pos_start.Y = (int)((double)(1.0 * onerows) + 6);

	pos_end.X = (int)((double)(11.5 * onecols));
	pos_end.Y = (int)((double)(4.0 * onerows) + 5);

	menu_width = pos_end.X - pos_start.X;
	menu_height = pos_end.Y - pos_start.Y;
}

void PrintMenu_background()
{
	COORD tmp;
	int r, c;

	tmp.X = pos_start.X;	tmp.Y = pos_start.Y;

	gotoxy(tmp.X, tmp.Y);

	for (c = 1; c <= menu_height; c++)
	{
		if (c == 1)
		{
			for (r = 1; r <= menu_width; r++)
			{

				if (r == 1) printf("┌");
				else if (r == menu_width) printf("┐");
				else printf("─");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		else if (c == menu_height)
		{
			for (r = 1; r <= menu_width; r++)
			{

				if (r == 1) printf("└");
				else if (r == menu_width) printf("┘");
				else printf("─");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		else
		{
			for (r = 1; r <= menu_width; r++)
			{
				if ((r == 1) || (r == menu_width)) printf("│");
				else printf(" ");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		tmp.X = pos_start.X;	tmp.Y++;
		gotoxy(tmp.X, tmp.Y);
	}
}

void getSideMenuSize()
{
	getform();
	menupos_start.X = (int)((double)(8.5 * onecols));
	menupos_start.Y = (int)((double)(1.0 * onerows) + 6);

	menupos_end.X = (int)((double)(11.5 * onecols));
	menupos_end.Y = (int)((double)(7.0 * onerows) + 6);

	menu_width = menupos_end.X - menupos_start.X;
	menu_height = menupos_end.Y - menupos_start.Y;
}

void PrintSideMenu_background()
{
	COORD tmp;
	int r, c;

	getSideMenuSize();
	tmp.X = menupos_start.X;	tmp.Y = menupos_start.Y;

	gotoxy(tmp.X, tmp.Y);

	for (c = 1; c <= menu_height; c++)
	{
		if (c == 1)
		{
			for (r = 1; r <= menu_width; r++)
			{

				if (r == 1) printf("┌");
				else if (r == menu_width) printf("┐");
				else printf("─");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		else if (c == menu_height)
		{
			for (r = 1; r <= menu_width; r++)
			{

				if (r == 1) printf("└");
				else if (r == menu_width) printf("┘");
				else printf("─");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		else
		{
			for (r = 1; r <= menu_width; r++)
			{
				if ((r == 1) || (r == menu_width)) printf("│");
				else printf(" ");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		tmp.X = menupos_start.X;	tmp.Y++;
		gotoxy(tmp.X, tmp.Y);
	}
}

void print_askMenunum(COORD* tmp)
{
	getSideMenuSize();
	tmp->X = menupos_start.X + 3;	tmp->Y = menupos_start.Y + 2;

	gotoxy(tmp->X, tmp->Y);
	printf("메뉴 번호를 입력해주세요 :    ");
}