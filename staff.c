#include "staff.h"

// 변수
extern staff head = NULL;
extern int people_num = 0;

// 함수
void Print_staffMenu()
{
	getform();
	PrinttodayCalendar();
	PrintSideMenu_background();
	Print_staffinfo();
}

void Print_staffinfo() {	// 메뉴 프린트

	COORD tmp;
	char* staffMenuList[staffMenuNum] = {
	"직원 추가",
	"직원 삭제",
	"직원 수정",
	"직원 검색",
	"메인메뉴로 돌아가기"
	};
	int i;

	print_askMenunum(&tmp);

	for (i = 0; i < staffMenuNum; i++)
	{
		tmp.Y += 2;
		gotoxy(tmp.X, tmp.Y);
		printf("%d. %s", i + 1, staffMenuList[i]);
	}
}

void Staff() {		// 직원 관리 실행
	int menu;
	COORD tmp;

	while (1)
	{
		Print_staffMenu();

		menu=Ask_Menunum(&tmp);

		switch (menu) 
		{
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
	DrawCenterBox(50, 20);
	getcenter();

	staff prev;

	pos_start.X = 6.0*onecols - 15;
	pos_start.Y = 3.75*onerows - 8;

	gotoxy(pos_start.X, pos_start.Y);
	printf("* 직원 추가 함수 *");
	gotoxy(pos_start.X-2, pos_start.Y + 5);
	printf("직원 이름 : ");
	gotoxy(pos_start.X+10, pos_start.Y + 5);
	scanf("%s", newname);
	Retrieve();

	if (retData!=NULL)
	{
		pos_start.X = 6.0*onecols;
		pos_start.Y = 3.75*onerows;
		system("cls");
		gotoxy(pos_start.X-15, pos_start.Y);
		printf("ERR :: 이미 직원이 존재합니다.");				// 오류메세지 출력
		//동명이인일경우 생각해보기
		gotoxy(pos_start.X-15, pos_start.Y+2);
		system("PAUSE");
	}
	else
	{
		people_num++;
		struct people *node = malloc(sizeof(struct people));
		strcpy(node->name, newname);
		gotoxy(pos_start.X-2, pos_start.Y + 7);
		printf("생년 월일 : ");
		gotoxy(pos_start.X +10, pos_start.Y + 7);
		scanf("%s", node->birth);
		gotoxy(pos_start.X-4, pos_start.Y + 9);
		printf("휴대폰 번호 : ");
		gotoxy(pos_start.X + 10, pos_start.Y + 9);
		scanf("%s", node->phone_num);
		node->count = 3; //초기카운트 설정
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
	DrawCenterBox(50, 20);
	getcenter();

	pos_start.X = 6.0*onecols - 15;
	pos_start.Y = 3.75*onerows - 8;

	gotoxy(pos_start.X, pos_start.Y);
	printf("* 직원 삭제 함수 *");
	gotoxy(pos_start.X -11, pos_start.Y + 10);
	printf("삭제할 직원의 이름을 입력해주세요 : ");
	gotoxy(pos_start.X + 25, pos_start.Y + 10);
	scanf("%s", newname);
	Retrieve();


	if (!retData)
	{
		pos_start.X = 6.0*onecols;
		pos_start.Y = 3.75*onerows;

		system("cls");
		gotoxy(pos_start.X - 15, pos_start.Y);
		printf("ERR :: 삭제할 직원이 없습니다.");				// 오류메세지 출력
		gotoxy(pos_start.X - 15, pos_start.Y + 2);
		system("PAUSE");
	}
	else {
		system("cls");
		DrawCenterBox(50, 20);
		getcenter();

		pos_start.X = 6.0*onecols - 15;
		pos_start.Y = 3.75*onerows - 8;

		gotoxy(pos_start.X, pos_start.Y);
		printf("* 직원 삭제 함수 *");
		gotoxy(pos_start.X-2, pos_start.Y+5);
		printf("%s님 의 정보입니다.\n", retData->name);
		gotoxy(pos_start.X - 2, pos_start.Y + 7); 
		printf("직원 이름 : %s\n", retData->name);
		gotoxy(pos_start.X - 2, pos_start.Y + 9);
		printf("생년 월일 : %s\n", retData->birth);
		gotoxy(pos_start.X - 2, pos_start.Y + 11);
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
	DrawCenterBox(50, 20);
	getcenter();

	pos_start.X = 6.0*onecols - 15;
	pos_start.Y = 3.75*onerows - 8;

	gotoxy(pos_start.X, pos_start.Y);
	printf("* 직원 수정 함수 *");
	gotoxy(pos_start.X - 11, pos_start.Y + 10);
	printf("수정할 직원의 이름을 입력해주세요 : ");
	gotoxy(pos_start.X + 25, pos_start.Y + 10);
	scanf("%s", newname);
	Retrieve();

	if (!retData)
	{
		pos_start.X = 6.0*onecols;
		pos_start.Y = 3.75*onerows;

		system("cls");
		gotoxy(pos_start.X - 15, pos_start.Y);
		printf("ERR :: 수정할 직원이 없습니다.");				// 오류메세지 출력
		gotoxy(pos_start.X - 15, pos_start.Y + 2);
		system("PAUSE");

	}
	else {
		system("cls");
		DrawCenterBox(50, 20);
		getcenter();

		pos_start.X = 6.0*onecols - 15;
		pos_start.Y = 3.75*onerows - 8;

		gotoxy(pos_start.X, pos_start.Y);
		printf("* 직원 수정 함수 *");
		gotoxy(pos_start.X - 2, pos_start.Y + 5);
		printf("%s 님의 정보입니다.\n", retData->name);
		gotoxy(pos_start.X - 2, pos_start.Y + 7);
		printf("직원 이름 : %s\n", retData->name);
		gotoxy(pos_start.X - 2, pos_start.Y + 9);
		printf("생년 월일 : %s\n", retData->birth);
		gotoxy(pos_start.X - 2, pos_start.Y + 11);
		printf("휴대폰 번호 : %s\n", retData->phone_num);


		if (Check() == 1) {
			system("cls");
			DrawCenterBox(50, 20);
			getcenter();

			pos_start.X = 6.0*onecols - 15;
			pos_start.Y = 3.75*onerows - 8;

			gotoxy(pos_start.X - 2, pos_start.Y + 7);
			printf("직원 이름 : ");
			gotoxy(pos_start.X +10, pos_start.Y + 7);
			scanf("%s", retData->name);
			gotoxy(pos_start.X - 2, pos_start.Y + 9);
			printf("생년 월일 : ");
			gotoxy(pos_start.X +10, pos_start.Y + 9);
			scanf("%s", retData->birth);
			gotoxy(pos_start.X - 4, pos_start.Y + 11);
			printf("휴대폰 번호 : ");
			gotoxy(pos_start.X +10, pos_start.Y + 11);
			scanf("%s", retData->phone_num);
		}
		else
			return;
	}
}

void Retrieve_Staff() {		// 직원 검색 함수

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	pos_start.X = 6.0*onecols - 15;
	pos_start.Y = 3.75*onerows - 8;

	gotoxy(pos_start.X, pos_start.Y);
	printf("* 직원 검색 함수 *");
	gotoxy(pos_start.X - 11, pos_start.Y + 10);
	printf("검색할 직원의 이름을 입력해주세요 : ");
	gotoxy(pos_start.X + 25, pos_start.Y + 10);
	scanf("%s", newname);
	Retrieve();

	if (!retData)
	{
		pos_start.X = 6.0*onecols;
		pos_start.Y = 3.75*onerows;

		system("cls");
		gotoxy(pos_start.X - 15, pos_start.Y);
		printf("ERR :: 직원이 존재하지 않습니다..");				// 오류메세지 출력
		gotoxy(pos_start.X - 15, pos_start.Y + 2);
		system("PAUSE");
	}
	else {
		system("cls");
		DrawCenterBox(50, 20);
		getcenter();

		pos_start.X = 6.0*onecols - 15;
		pos_start.Y = 3.75*onerows - 8;

		gotoxy(pos_start.X, pos_start.Y);
		printf("* 직원 검색 함수 *");
		gotoxy(pos_start.X - 2, pos_start.Y + 5);
		printf("%s 님의 정보입니다.\n", retData->name);
		gotoxy(pos_start.X - 2, pos_start.Y + 7);
		printf("직원 이름 : %s\n", retData->name);
		gotoxy(pos_start.X - 2, pos_start.Y + 9);
		printf("생년 월일 : %s\n", retData->birth);
		gotoxy(pos_start.X - 2, pos_start.Y + 11);
		printf("휴대폰 번호 : %s\n", retData->phone_num);
		gotoxy(pos_start.X - 6, pos_start.Y + 15);
		system("PAUSE");
	}

}
