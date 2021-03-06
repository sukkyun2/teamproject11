#include "staff.h"
#include "login.h"

// 변수
extern staff head = NULL;
extern int people_num = 0;

// 함수
void Print_staffMenu()
{
	getform();
	PrinttodayCalendar();

	PrintMenu();
	Print_staffinfo();
}

void Print_staffinfo() {   // 메뉴 프린트

	COORD tmp;

	char* staffMenuList[staffMenuNum] = {
		"직원 추가",
		"직원 삭제",
		"직원 수정",
		"직원 검색",
		"메인메뉴로 돌아가기"
	};
	int i;

	tmp.X = pos_start.X + 3;   tmp.Y = pos_start.Y + 2;
	print_askMenunum();

	for (i = 0; i < staffMenuNum; i++)
	{
		tmp.Y += 2;
		gotoxy(tmp.X, tmp.Y);
		printf("%d. %s", i + 1, staffMenuList[i]);
	}
}

void Staff() {      // 직원 관리 실행
	int menu;
	COORD tmp;

	while (1)
	{
		system("COLOR 07");

		Print_staffMenu();

		menu = Ask_Menunum();

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

void Insert_Staff() {      // 직원 추가 함수

	system("COLOR F0");

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	staff prev;

	hImage = (HBITMAP)LoadImage(NULL, TEXT("staffinsert.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);

	gotoxy(pos_start.X - 18, pos_start.Y - 5);

	gotoxy(pos_start.X - 10, pos_start.Y - 5);
	printf("직원 이름 : ");
	gotoxy(pos_start.X + 2, pos_start.Y - 5);
	scanf("%s", newname);
	Retrieve();

	if (retData != NULL)
	{
		system("cls");
		MessageBox(NULL, TEXT("이미 직원이 존재합니다."), TEXT("ERR"), MB_OK | MB_ICONSTOP);
	}
	else
	{
		people_num++;
		staff node = malloc(sizeof(struct people));
		strcpy(node->name, newname);
		gotoxy(pos_start.X - 10, pos_start.Y - 3);
		printf("생년 월일 : ");
		gotoxy(pos_start.X + 2, pos_start.Y - 3);
		scanf("%s", node->birth);
		gotoxy(pos_start.X - 12, pos_start.Y - 1);
		printf("휴대폰 번호 : ");
		gotoxy(pos_start.X + 2, pos_start.Y - 1);
		scanf("%s", node->phone_num);



		node->Schedule = (struct Schedule*)malloc(sizeof(struct Schedule) * 32);
		node->count = 3; //일정 초기카운트 설정
		node->WCount = 0; //근무 초기카운트 설정

		for (int i = 0; i < 32; i++)
		{
			for (int j = 0; j < 24; j++)
			{
				node->Schedule[i].outside_duty[j] = 0;
			}
			for (int j = 0; j < 2; j++)
			{
				node->Schedule[i].work_schedule[j] = 0;
				node->Schedule[i].day[j] = 0;
			}
		}

		node->next = NULL;
		system("cls");

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

void Delete_Staff() {      // 직원 삭제 함수
	staff node;
	node = head;

	system("COLOR F0");

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("staffdelete.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);
	gotoxy(pos_start.X - 15, pos_start.Y - 1);
	printf("삭제할 직원의 이름 : ");
	gotoxy(pos_start.X + 6, pos_start.Y - 1);
	scanf("%s", newname);
	Retrieve();


	if (!retData)
	{
		system("cls");
		MessageBox(NULL, TEXT("직원이 존재하지 않습니다"), TEXT("ERR"), MB_OK | MB_ICONSTOP);
	}
	else {
		system("cls");
		DrawCenterBox(50, 20);
		getcenter();

		hImage = (HBITMAP)LoadImage(NULL, TEXT("staffdelete.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		print_menuimage(hImage);
		gotoxy(pos_start.X - strlen("* 천은정 님의 정보입니다. *") / 2, pos_start.Y - 6);
		printf("* %s님의 정보입니다. *", retData->name);
		gotoxy(pos_start.X - 10, pos_start.Y - 3);
		printf("직원 이름 : %s\n", retData->name);
		gotoxy(pos_start.X - 10, pos_start.Y - 1);
		printf("생년 월일 : %s\n", retData->birth);
		gotoxy(pos_start.X - 12, pos_start.Y + 1);
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
	}
	system("cls");
}

void Change_Staff() {      // 직원 수정 함수

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	system("COLOR F0");

	hImage = (HBITMAP)LoadImage(NULL, TEXT("staffmodify.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);
	gotoxy(pos_start.X - 15, pos_start.Y - 1);
	printf("수정할 직원의 이름 : ");
	gotoxy(pos_start.X + 6, pos_start.Y - 1);
	scanf("%s", newname);
	Retrieve();

	if (!retData)
	{
		system("cls");
		MessageBox(NULL, TEXT("직원이 존재하지 않습니다"), TEXT("ERR"), MB_OK | MB_ICONSTOP);
	}
	else {
		system("cls");
		DrawCenterBox(50, 20);
		getcenter();

		hImage = (HBITMAP)LoadImage(NULL, TEXT("staffmodify.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		print_menuimage(hImage);
		gotoxy(pos_start.X - strlen("* 천은정 님의 정보입니다. *") / 2, pos_start.Y - 6);
		printf("* %s님의 정보입니다. *", retData->name);
		gotoxy(pos_start.X - 10, pos_start.Y - 3);
		printf("직원 이름 : %s\n", retData->name);
		gotoxy(pos_start.X - 10, pos_start.Y - 1);
		printf("생년 월일 : %s\n", retData->birth);
		gotoxy(pos_start.X - 12, pos_start.Y + 1);
		printf("휴대폰 번호 : %s\n", retData->phone_num);
		gotoxy(pos_start.X - 18, pos_start.Y + 5);
		system("PAUSE");

		system("cls");
		DrawCenterBox(50, 20);
		getcenter();

		hImage = (HBITMAP)LoadImage(NULL, TEXT("staffmodify.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		print_menuimage(hImage);
		gotoxy(pos_start.X - 10, pos_start.Y - 3);
		printf("직원 이름 : \n");
		gotoxy(pos_start.X + 2, pos_start.Y - 3);
		scanf("%s", retData->name);
		gotoxy(pos_start.X - 10, pos_start.Y - 1);
		printf("생년 월일 : \n");
		gotoxy(pos_start.X + 2, pos_start.Y - 1);
		scanf("%s", retData->birth);
		gotoxy(pos_start.X - 12, pos_start.Y + 1);
		printf("휴대폰 번호 : \n");
		gotoxy(pos_start.X + 2, pos_start.Y + 1);
		scanf("%s", retData->phone_num);

		system("cls");
		MessageBox(NULL, TEXT("직원 정보가 수정되었습니다."), TEXT("Check"), MB_OK | MB_ICONINFORMATION);

		system("cls");
	}

}
void Retrieve_Staff() {      // 직원 검색 함수

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();


	system("COLOR F0");
	hImage = (HBITMAP)LoadImage(NULL, TEXT("staffretrieve.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);
	gotoxy(pos_start.X - 15, pos_start.Y - 1);
	printf("검색할 직원의 이름 : ");
	gotoxy(pos_start.X + 6, pos_start.Y - 1);
	scanf("%s", newname);
	Retrieve();

	if (!retData)
	{
		system("cls");
		MessageBox(NULL, TEXT("직원이 존재하지 않습니다"), TEXT("ERR"), MB_OK | MB_ICONSTOP);
	}
	else {
		system("cls");
		DrawCenterBox(50, 20);
		getcenter();

		hImage = (HBITMAP)LoadImage(NULL, TEXT("staffretrieve.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		print_menuimage(hImage);
		gotoxy(pos_start.X - strlen("* 홍길동 님의 정보입니다. *") / 2, pos_start.Y - 6);
		printf("* %s님의 정보입니다. *", retData->name);
		gotoxy(pos_start.X - 10, pos_start.Y - 3);
		printf("직원 이름 : %s\n", retData->name);
		gotoxy(pos_start.X - 10, pos_start.Y - 1);
		printf("생년 월일 : %s\n", retData->birth);
		gotoxy(pos_start.X - 12, pos_start.Y + 1);
		printf("휴대폰 번호 : %s\n", retData->phone_num);

		gotoxy(pos_start.X - 18, pos_start.Y + 5);
		system("PAUSE");
	}
	system("cls");
}