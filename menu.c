#pragma once

#include "menu.h"
#include "staff.h"

void Select_Menu()		// 메뉴 선택하는 함수
{
	int menu;

	while (1) {
		Print_Menu();
		screen(163, 7);
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			Staff();
			break;
		case 2:
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

void Print_Menu() {	// 메뉴 프린트

	system("cls");

	screen(135, 7);
	printf("메뉴 번호를 입력해주세요 : ");
	screen(135, 9);
	printf("1. 직원관리");
	screen(135, 11);
	printf("2. 일정관리");
	screen(135, 13);
	printf("3. 근무관리");
	screen(135, 15);
	printf("4. 인물검색");
	screen(135, 17);
	printf("5. 프로그램 종료");
}

