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