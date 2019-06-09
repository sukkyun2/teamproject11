#pragma once

#include "DrawMainMenu.h"

// 함수
void getmenuSize()
{
	pos_start.X = (int)((double)(8.5 * onecols));
	pos_start.Y = (int)((double)(1.0 * onerows) + 6);

	pos_end.X = (int)((double)(11.5 * onecols));
	pos_end.Y = (int)((double)(4.0 * onerows) + 6);

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

void Print_MainMenuinfo() {	// 메뉴 프린트

	COORD tmp;
	char* mainMenuList[MenuNum] = {
	"직원관리",
	"일정관리",
	"근무관리",
	"인물검색",
	"프로그램 종료"
	};
	int i;

	print_askMenunum(&tmp);

	for (i = 0; i < MenuNum; i++)
	{
		tmp.Y += 2;
		gotoxy(tmp.X, tmp.Y);
		printf("%d. %s", i + 1, mainMenuList[i]);
	}
}

void Print_MainMenu()
{
	getform();
	getmenuSize();
	PrintMenu_background();
	Print_MainMenuinfo();
}