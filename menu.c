#pragma once

#include "menu.h"
#include <Windows.h>

void Select_Menu()		// 메뉴 선택하는 함수
{
	int menu;
	COORD tmp;

	while (1) {
		menu = Ask_Menunum(&tmp);

		switch (menu)
		{
		case 1:
			Staff();
			break;
		case 2:
			Schedule();
			break;
		case 3:
			Work();
			break;
		case 4:
			system("cls");
			if (MessageBox(NULL, TEXT("종료하시겠습니까?"), TEXT("Check Box"), MB_YESNO | MB_ICONQUESTION) == IDYES)
				exit(0);
			else
				PrintHomepage();
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

	getcenter();

	if (MessageBox(NULL, TEXT("진행하시겠습니까 ?"), TEXT("Check Box"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		return 1;
	else
		return 0;

}