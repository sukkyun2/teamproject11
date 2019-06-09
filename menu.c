#pragma once

#include "menu.h"

void Select_Menu()		// 메뉴 선택하는 함수
{
	int menu;
	COORD tmp;

	while (1) {
		menu=Ask_Menunum(&tmp);

		switch (menu)
		{
		case 1:
			Staff();
			break;
		case 2:
			Schedule();
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			exit(0);
			break;
		}
	}
}

int Ask_Menunum(COORD *tmp)
{
	int menu;

	tmp->X = menupos_start.X + 3 + strlen("메뉴 번호를 입력해주세요 : ");
	tmp->Y = menupos_start.Y + 2;
	gotoxy(tmp->X, tmp->Y);
	scanf_s("%d", &menu);

	return menu;
}

int Check()
{
	char check[5];

	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - 8, pos_start.Y + 15);
	printf("실행하시겠습니까 ? [Yes Or No] : \n ");
	gotoxy(pos_start.X + 25, pos_start.Y + 15);
	scanf("%s", check);
	if (strcmp(check, "Yes") == 0)
		return 1;
	else
		return 0;
}