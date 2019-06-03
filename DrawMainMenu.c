#pragma once

#include "DrawMainMenu.h"

// 함수


void Print_MainMenuinfo() {	// 메뉴 프린트

	COORD tmp;
	char* mainMenuList[MenuNum] = {
	"직원관리",
	"일정관리",
	"근무관리",
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