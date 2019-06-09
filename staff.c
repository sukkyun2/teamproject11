#pragma once

#include "staff.h"
#include "menu.h"
#include "DefinePage.h"
#include "login.h"

typedef struct people *staff;
staff head = NULL;
staff retData;
char newname[10];
int people_num = 0;

#include "DrawMainMenu.h"

void getstaffSize()
{
	pos_start.X = (int)((double)(8.5 * onecols));
	pos_start.Y = (int)((double)(1.0 * onerows) + 6);

	pos_end.X = (int)((double)(11.5 * onecols));
	pos_end.Y = (int)((double)(4.0 * onerows) + 6);

	menu_width = pos_end.X - pos_start.X;
	menu_height = pos_end.Y - pos_start.Y;
}

void Printstaff_background()
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

void Print_Mainstaffinfo() {	// 메뉴 프린트

	COORD tmp;
	char* mainMenuList[MenuNum] = {
	"직원 추가",
	"직원 삭제",
	"직원 수정",
	"직원 검색",
	"메인메뉴로 돌아가기"
	};
	int i;

	tmp.X = pos_start.X + 3;	tmp.Y = pos_start.Y + 2;

	gotoxy(tmp.X, tmp.Y);
	printf("메뉴 번호를 입력해주세요 : ");

	for (i = 0; i < MenuNum; i++)
	{
		tmp.Y += 2;
		gotoxy(tmp.X, tmp.Y);
		printf("%d. %s", i + 1, mainMenuList[i]);
	}
}

void Staff() {		// 직원 관리 실행
	int menu;
	COORD tmp;
	while (1) {
		system("cls");
		getform();
		getstaffSize();
		Printstaff_background();
		Print_Mainstaffinfo();
		tmp.X = pos_start.X + 3 + strlen("메뉴 번호를 입력해주세요 : ");
		tmp.Y = pos_start.Y + 2;
		gotoxy(tmp.X, tmp.Y);
		scanf("%d", &menu);
		switch (menu) {
			
		case 1:
			Insert_Staff();
			break;
		case 2:
			Delete_Staff();
			break;
		case 3:
			Change_Staff();
			break;
		case 4:
			Retrieve_Staff();
			break;
		case 5:
			PrintHomepage();
			break;
		}
	}
}


int Check()
{
	char check[5];
	screen(loginpos.X - 8, loginpos.Y + 15);
	printf("실행하시겠습니까 ? [Yes Or No] : \n ");
	screen(loginpos.X + 25, loginpos.Y + 15);
	scanf("%s", check);
	if (strcmp(check, "Yes") == 0)
		return 1;
	else
		return 0;
}


void Retrieve()
{
	retData = head;
	while (retData)
	{
		if (strcmp(retData->name, newname) == 0)
			return;
		else
			retData = retData->next;
	}
	return;
}

void Insert_Staff() {		// 직원 추가 함수

	system("cls");
	getloginSize();
	Printlogin_background();

	staff prev;

	loginpos.X = 6.0*onecols - 15;
	loginpos.Y = 3.75*onerows - 8;

	screen(loginpos.X, loginpos.Y);
	printf("* 직원 추가 함수 *");
	screen(loginpos.X-2, loginpos.Y + 5);
	printf("직원 이름 : ");
	screen(loginpos.X+10, loginpos.Y + 5);
	scanf("%s", newname);
	Retrieve();

	if (retData!=NULL)
	{
		loginpos.X = 6.0*onecols;
		loginpos.Y = 3.75*onerows;
		system("cls");
		screen(loginpos.X-15, loginpos.Y);
		printf("ERR :: 이미 직원이 존재합니다.");				// 오류메세지 출력
		screen(loginpos.X-15, loginpos.Y+2);
		system("PAUSE");
	}
	else
	{
		people_num++;
		struct people *node = malloc(sizeof(struct people));
		strcpy(node->name, newname);
		screen(loginpos.X-2, loginpos.Y + 7);
		printf("생년 월일 : ");
		screen(loginpos.X +10, loginpos.Y + 7);
		scanf("%s", node->birth);
		screen(loginpos.X-4, loginpos.Y + 9);
		printf("휴대폰 번호 : ");
		screen(loginpos.X + 10, loginpos.Y + 9);
		scanf("%s", node->phone_num);
		node->next = NULL;

		if (head == NULL)
		{
			head = node;
			return;
		}
		else
		{
			prev = head;
			while (prev->next != NULL)
			{
				prev = prev->next;
			}
			prev->next = node;
		}
	}
}

void Delete_Staff() {		// 직원 삭제 함수
	staff node;
	node = head;
	
	system("cls");
	getloginSize();
	Printlogin_background();

	loginpos.X = 6.0*onecols - 15;
	loginpos.Y = 3.75*onerows - 8;

	screen(loginpos.X, loginpos.Y);
	printf("* 직원 삭제 함수 *");
	screen(loginpos.X -11, loginpos.Y + 10);
	printf("삭제할 직원의 이름을 입력해주세요 : ");
	screen(loginpos.X + 25, loginpos.Y + 10);
	scanf("%s", newname);
	Retrieve();


	if (!retData)
	{
		loginpos.X = 6.0*onecols;
		loginpos.Y = 3.75*onerows;

		system("cls");
		screen(loginpos.X - 15, loginpos.Y);
		printf("ERR :: 삭제할 직원이 없습니다.");				// 오류메세지 출력
		screen(loginpos.X - 15, loginpos.Y + 2);
		system("PAUSE");
	}
	else {
		system("cls");
		getloginSize();
		Printlogin_background();

		loginpos.X = 6.0*onecols - 15;
		loginpos.Y = 3.75*onerows - 8;

		screen(loginpos.X, loginpos.Y);
		printf("* 직원 삭제 함수 *");
		screen(loginpos.X-2, loginpos.Y+5);
		printf("%s님 의 정보입니다.\n", retData->name);
		screen(loginpos.X - 2, loginpos.Y + 7); 
		printf("직원 이름 : %s\n", retData->name);
		screen(loginpos.X - 2, loginpos.Y + 9);
		printf("생년 월일 : %s\n", retData->birth);
		screen(loginpos.X - 2, loginpos.Y + 11);
		printf("휴대폰 번호 : %s\n", retData->phone_num);

		if (Check() == 1)
		{
			people_num--;
			if (node == retData)
				head = node->next;
			else {
				while (node->next != retData)
				{
					node = node->next;
				}
				node->next = retData->next;
			}
			free(retData);
		}
		else
			return;
	}
}

void Change_Staff() {		// 직원 수정 함수

	system("cls");
	getloginSize();
	Printlogin_background();

	loginpos.X = 6.0*onecols - 15;
	loginpos.Y = 3.75*onerows - 8;

	screen(loginpos.X, loginpos.Y);
	printf("* 직원 수정 함수 *");
	screen(loginpos.X - 11, loginpos.Y + 10);
	printf("수정할 직원의 이름을 입력해주세요 : ");
	screen(loginpos.X + 25, loginpos.Y + 10);
	scanf("%s", newname);
	Retrieve();

	if (!retData)
	{
		loginpos.X = 6.0*onecols;
		loginpos.Y = 3.75*onerows;

		system("cls");
		screen(loginpos.X - 15, loginpos.Y);
		printf("ERR :: 수정할 직원이 없습니다.");				// 오류메세지 출력
		screen(loginpos.X - 15, loginpos.Y + 2);
		system("PAUSE");

	}
	else {
		system("cls");
		getloginSize();
		Printlogin_background();

		loginpos.X = 6.0*onecols - 15;
		loginpos.Y = 3.75*onerows - 8;

		screen(loginpos.X, loginpos.Y);
		printf("* 직원 수정 함수 *");
		screen(loginpos.X - 2, loginpos.Y + 5);
		printf("%s 님의 정보입니다.\n", retData->name);
		screen(loginpos.X - 2, loginpos.Y + 7);
		printf("직원 이름 : %s\n", retData->name);
		screen(loginpos.X - 2, loginpos.Y + 9);
		printf("생년 월일 : %s\n", retData->birth);
		screen(loginpos.X - 2, loginpos.Y + 11);
		printf("휴대폰 번호 : %s\n", retData->phone_num);


		if (Check() == 1) {
			system("cls");
			getloginSize();
			Printlogin_background();

			loginpos.X = 6.0*onecols - 15;
			loginpos.Y = 3.75*onerows - 8;

			screen(loginpos.X - 2, loginpos.Y + 7);
			printf("직원 이름 : ");
			screen(loginpos.X +10, loginpos.Y + 7);
			scanf("%s", retData->name);
			screen(loginpos.X - 2, loginpos.Y + 9);
			printf("생년 월일 : ");
			screen(loginpos.X +10, loginpos.Y + 9);
			scanf("%s", retData->birth);
			screen(loginpos.X - 4, loginpos.Y + 11);
			printf("휴대폰 번호 : ");
			screen(loginpos.X +10, loginpos.Y + 11);
			scanf("%s", retData->phone_num);
		}
		else
			return;
	}
}

void Retrieve_Staff() {		// 직원 검색 함수

	system("cls");
	getloginSize();
	Printlogin_background();

	loginpos.X = 6.0*onecols - 15;
	loginpos.Y = 3.75*onerows - 8;

	screen(loginpos.X, loginpos.Y);
	printf("* 직원 검색 함수 *");
	screen(loginpos.X - 11, loginpos.Y + 10);
	printf("검색할 직원의 이름을 입력해주세요 : ");
	screen(loginpos.X + 25, loginpos.Y + 10);
	scanf("%s", newname);
	Retrieve();

	if (!retData)
	{
		loginpos.X = 6.0*onecols;
		loginpos.Y = 3.75*onerows;

		system("cls");
		screen(loginpos.X - 15, loginpos.Y);
		printf("ERR :: 직원이 존재하지 않습니다..");				// 오류메세지 출력
		screen(loginpos.X - 15, loginpos.Y + 2);
		system("PAUSE");
	}
	else {
		system("cls");
		getloginSize();
		Printlogin_background();

		loginpos.X = 6.0*onecols - 15;
		loginpos.Y = 3.75*onerows - 8;

		screen(loginpos.X, loginpos.Y);
		printf("* 직원 검색 함수 *");
		screen(loginpos.X - 2, loginpos.Y + 5);
		printf("%s 님의 정보입니다.\n", retData->name);
		screen(loginpos.X - 2, loginpos.Y + 7);
		printf("직원 이름 : %s\n", retData->name);
		screen(loginpos.X - 2, loginpos.Y + 9);
		printf("생년 월일 : %s\n", retData->birth);
		screen(loginpos.X - 2, loginpos.Y + 11);
		printf("휴대폰 번호 : %s\n", retData->phone_num);
		screen(loginpos.X - 6, loginpos.Y + 15);
		system("PAUSE");
	}

}
