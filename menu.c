#pragma once

#include "menu.h"
#include <Windows.h>

int Ask_Menunum()
{
	COORD tmp;
	int menu;

	getMenusize();
	tmp.X = pos_start.X + 3 + strlen("�޴� ��ȣ�� �Է����ּ��� : ");
	tmp.Y = pos_start.Y + 2;
	gotoxy(tmp.X, tmp.Y);
	scanf_s("%d", &menu);

	return menu;
}

int Check()
{
	char check[5];

	getcenter();

	if (MessageBox(NULL, TEXT("�����Ͻðڽ��ϱ� ?"), TEXT("Check Box"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		return 1;
	else
		return 0;

}