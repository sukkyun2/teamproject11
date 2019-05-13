#pragma once

#include "staff.h"
#include "menu.h"

typedef struct people *staff;
staff head = NULL;
staff retData;
char newname[10];
int people_num = 0;

void Staff() {		// 직원 관리 실행
	int menu;

	while (1) {
		Print_Staff_Menu();
		screen(163, 7);
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
			Select_Menu();
			break;
		}
	}
}

int Check()
{
	char check[5];
	screen(78, 28);
	printf("진행하시겠습니까 ? [Yes Or No] : \n ");
	screen(111, 28);
	scanf("%s", check);
	if (strcmp(check, "Yes") == 0)
		return 1;
	else
		return 0;
}

void Print_Staff_Menu() {	// 직원 메뉴 출력

	system("cls");

	screen(135, 7);
	printf("메뉴 번호를 입력해주세요 : ");
	screen(135, 9);
	printf("1. 직원 추가 하기");
	screen(135, 11);
	printf("2. 직원 삭제 하기");
	screen(135, 13);
	printf("3. 직원 수정 하기");
	screen(135, 15);
	printf("4. 직원 검색 하기");
	screen(135, 17);
	printf("5. 메인메뉴로 돌아가기");
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
	staff prev;
	
	screen(78, 22);
	printf("직원 이름 : ");
	screen(90, 22);
	scanf("%s", newname);
	Retrieve();

	if (retData!=NULL)
	{
		system("cls");
		screen(75, 23);
		printf("ERR :: 이미 직원이 존재합니다.");				// 오류메세지 출력
		screen(75, 25);
		system("PAUSE");
	}
	else
	{
		people_num++;
		struct people *node = malloc(sizeof(struct people));
		strcpy(node->name, newname);
		screen(78, 24);
		printf("생년 월일 : ");
		screen(90, 24);
		scanf("%s", node->birth);
		screen(76, 26);
		printf("휴대폰 번호 : ");
		screen(90, 26);
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
	screen(75, 23);
	printf("삭제할 직원의 이름을 입력해주세요 : ");
	screen(111, 23);
	scanf("%s", newname);
	Retrieve();

	if (!retData)
	{
		system("cls");
		screen(75, 23);
		printf("ERR :: 삭제할 직원이 없습니다.");				// 오류메세지 출력
		screen(75, 25);
		system("PAUSE");
	}
	else {
		system("cls");
		screen(78, 20);
		printf("%s의 정보입니다.\n", retData->name);
		screen(78, 22);
		printf("직원 이름 : %s\n", retData->name);
		screen(78, 24);
		printf("생년 월일 : %s\n", retData->birth);
		screen(78, 26);
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
	screen(75, 23);
	printf("수정할 직원의 이름을 입력해주세요 : ");
	screen(111, 23);
	scanf("%s", newname);
	Retrieve();

	if (!retData)
	{
		system("cls");
		screen(75, 23);
		printf("ERR :: 수정할 직원이 없습니다.");				// 오류메세지 출력
		screen(75, 25);
		system("PAUSE");
	}
	else {
		system("cls");
		screen(78, 20);
		printf("%s의 정보입니다.\n", retData->name);
		screen(78, 22);
		printf("직원 이름 : %s\n", retData->name);
		screen(78, 24);
		printf("생년 월일 : %s\n", retData->birth);
		screen(78, 26);
		printf("휴대폰 번호 : %s\n", retData->phone_num);

		if (Check() == 1) {
			system("cls");
			screen(78, 22);
			printf("직원 이름 : ");
			screen(90, 22);
			scanf("%s", retData->name);
			screen(78, 24);
			printf("생년 월일 : ");
			screen(90, 24);
			scanf("%s", retData->birth);
			screen(76, 26);
			printf("휴대폰 번호 : ");
			screen(90, 26);
			scanf("%s", retData->phone_num);
		}
		else
			return;
	}
}

void Retrieve_Staff() {		// 직원 검색 함수
	system("cls");
	screen(75, 23);
	printf("검색할 직원의 이름을 입력해주세요 : ");
	screen(111, 23);
	scanf("%s", newname);
	Retrieve();

	if (!retData)
	{
		system("cls");
		screen(75, 23);
		printf("ERR :: 직원이 존재하지 않습니다.");				// 오류메세지 출력
		screen(75, 25);
		system("PAUSE");
	}
	else {
		system("cls");
		screen(78, 20);
		printf("%s의 정보입니다.\n", retData->name);
		screen(78, 22);
		printf("직원 이름 : %s\n", retData->name);
		screen(78, 24);
		printf("생년 월일 : %s\n", retData->birth);
		screen(78, 26);
		printf("휴대폰 번호 : %s\n", retData->phone_num);
		screen(78, 28);
		system("PAUSE");
	}

}
