#pragma once

#include "DrawMainMenu.h"

// �Լ�


void Print_MainMenuinfo() {	// �޴� ����Ʈ

	COORD tmp;
	char* mainMenuList[MenuNum] = {
	"��������",
	"��������",
	"�ٹ�����",
	"���α׷� ����"
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