#include "DrawSideMenu.h"

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

void print_askMenunum(COORD *tmp)
{
	getSideMenuSize();
	tmp->X = menupos_start.X + 3;	tmp->Y = menupos_start.Y + 2;

	gotoxy(tmp->X, tmp->Y);
	printf("메뉴 번호를 입력해주세요 :    ");
}