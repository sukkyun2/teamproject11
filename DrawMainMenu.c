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

	tmp.X = pos_start.X + 3;	tmp.Y = pos_start.Y + 2;
	print_askMenunum();

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
	getMenusize();
	PrintMenu();
	Print_MainMenuinfo();
}