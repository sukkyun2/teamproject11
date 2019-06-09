#include "schedule.h"

void Print_scheduleinfo() {	// 메뉴 프린트

	COORD tmp;
	char* scheduleMenuList[scheduleMenuNum] = {
	"휴가 추가 하기",
	"휴가 삭제 하기",
	"메인메뉴로 돌아가기"
	};
	int i;

	print_askMenunum(&tmp);

	for (i = 0; i < scheduleMenuNum; i++)
	{
		tmp.Y += 2;
		gotoxy(tmp.X, tmp.Y);
		printf("%d. %s", i + 1, scheduleMenuList[i]);
	}
}


void Schedule() {		// 직원 관리 실행
	int menu;
	COORD tmp;

	while (1) 
	{
		system("cls");
		Print_scheduleSMenu();

		menu=Ask_Menunum(&tmp);

		switch (menu)
		{
		case 1:
			Insert_Schedule();   
			break;
		case 2:
			Delete_Schedule();  
			break;
		case 3:
			PrintHomepage();
			break;
		}
	}
}

void Print_Insert_scheduleSMenu()
{
	getform();
	DrawCenterBox(50, 20);

	PrintSideMenu_background();
	Print_Insert_scheduleinfo();
}

void Print_Insert_scheduleinfo() {	// 메뉴 프린트

	COORD tmp;
	char* scheduleMenuList[InsertscheduleMenuNum] = 
	{
	"외근",
	"휴가",
	"오전 반가",
	"오후 반가",
	"메뉴로 돌아가기"
	};
	int i;

	print_askMenunum(&tmp);

	for (i = 0; i < InsertscheduleMenuNum; i++)
	{
		tmp.Y += 2;
		gotoxy(tmp.X, tmp.Y);
		printf("%d. %s", i + 1, scheduleMenuList[i]);
	}
}

void Insert_Schedule()
{
	COORD tmp;

	int menu;
	while (1)
	{
		system("cls");
		Print_staffMenu();

		menu=Ask_Menunum(&tmp);
		switch (menu)
		{
		case 1:
			Insert_outside();
			break;
		case 2:
			Insert_day();
			break;
		case 3:
			Insert_moning_half();
			break;
		case 4:
			Insert_afternoon_half();
			break;
		case 5:
			Select_Menu(); //메뉴로 돌아가기
			break;
		}
	}

}

void Print_Delete_scheduleSMenu()
{
	getform();
	DrawCenterBox(50, 20);

	PrintSideMenu_background();
	Print_Delete_scheduleinfo();
}

void Print_Delete_scheduleinfo() {	// 메뉴 프린트

	COORD tmp;
	char* scheduleMenuList[DeletescheduleMenuNum] =
	{
	"외근 일정 삭제",
	"휴가, 반가 일정 삭제",
	"메뉴로 돌아가기"
	};
	int i;

	print_askMenunum(&tmp);

	for (i = 0; i < DeletescheduleMenuNum; i++)
	{
		tmp.Y += 2;
		gotoxy(tmp.X, tmp.Y);
		printf("%d. %s", i + 1, scheduleMenuList[i]);
	}
}

void Delete_Schedule()
{
	int menu;
	COORD tmp;

	while (1)
	{
		system("cls");
		Print_staffMenu();

		menu=Ask_Menunum(&tmp);

		switch (menu)
		{
		case 1:
			Delete_outside();
			break;
		case 2:
			Delete_vacation();
			break;
		case 3:
			Select_Menu(); //메뉴로 돌아가기
			break;
		}
	}
}

void Insert_outside()
{
	char search_name[10]; //검색할 직원의 이름
	int front, rear, day;

	system("cls");

	gotoxy(pos_start.X - 15, pos_start.Y);
	printf("외근을  입력할 직원의 이름을 입력해주세요 :");
	gotoxy(111, 23);
	scanf("%s", search_name);  ///변수이름 통일
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - 15, pos_start.Y);
		printf("ERR :: 직원이 존재하지 않습니다.");				// 오류메세지 출력
		gotoxy(pos_start.X - 15, pos_start.Y + 2);
		system("PAUSE");
	}

	system("cls");
	gotoxy(75, 23);
	printf("외근할 날짜를 입력해주세요 ");
	gotoxy(111, 23);
	scanf("%d", &day);
	gotoxy(75, 25);
	printf("외근 시간을 입력해주세요 ");
	gotoxy(111, 25);
	scanf("%d %d", &front, &rear);
	system("cls");
	for (int i = front; i <= rear; i++)
	{
		if (retData->Schedule[day].outside_duty[i] = 1)
			///화면을 띄우고 참고해서 스케줄을 작성 --O
			///겹치는 스케줄을 발견했을 때 확인후 덮어씌우기
			//이미 스케줄이 존재할 떄
		{
			gotoxy(75, 23);
			printf("이미 일정이 존재합니다");
			return 0;
		}
		retData->Schedule[day].outside_duty[i]=1; 
		//외근 입력
	}
	gotoxy(75, 23);
	printf("외근 일정이 입력되었습니다");

}

void Insert_day()
{
	char search_name[10]; //검색할 직원의 이름
	int day;
	system("cls");
	gotoxy(75, 23);
	printf("휴가를 입력할 직원의 이름을 입력해주세요 :");
	gotoxy(111, 23);
	scanf("%s", search_name);  
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - 15, pos_start.Y);
		printf("ERR :: 직원이 존재하지 않습니다.");				// 오류메세지 출력
		gotoxy(pos_start.X - 15, pos_start.Y + 2);
		system("PAUSE");
	}

	if (retData->count < 1)  //휴가 한도를 넘어섰다면
	{
		system("cls");
		gotoxy(75, 23);
		printf("한달 휴가 사용 가능횟수를 초과하였습니다");
		return 0; 
		// Schedule으로 돌아간다
	}

	system("cls");
	gotoxy(75, 23);
	printf("휴가 날짜를 입력해주세요 ");
	gotoxy(111, 23);
	scanf("%d", &day);

    ///외근 스케줄이 있는데 휴가를 사용하는 경우 
	///->외근 일정 기록은 남아있지만 휴가로 덮어씌워짐
	
	retData->Schedule[day].day[0] = 1;
	retData->Schedule[day].day[1] = 1; 
	//휴가 입력
	retData->count = retData->count - 1;

}

void Insert_moning_half()
{
	char search_name[10]; //검색할 직원의 이름
	int front, rear, day;
	system("cls");
	gotoxy(75, 23);
	printf("반차를 입력할 직원의 이름을 입력해주세요 :");
	gotoxy(111, 23);
	scanf("%s", search_name);
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - 15, pos_start.Y);
		printf("ERR :: 직원이 존재하지 않습니다.");				// 오류메세지 출력
		gotoxy(pos_start.X - 15, pos_start.Y + 2);
		system("PAUSE");
	}

	system("cls");
	gotoxy(75, 23);
	printf("반차 날짜를 입력해주세요 ");
	gotoxy(111, 23);
	scanf("%d", &day);

	retData->Schedule[day].day[0] = 1;
	retData->Schedule[day].day[1] = 0;
	//반차 입력
	retData->count = retData->count - 0.5;

}

void Insert_afternoon_half()
{
	char search_name[10]; //검색할 직원의 이름
	int front, rear, day;
	system("cls");
	gotoxy(75, 23);
	printf("반차를 입력할 직원의 이름을 입력해주세요 :");
	gotoxy(111, 23);
	scanf("%s", search_name);
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - 15, pos_start.Y);
		printf("ERR :: 직원이 존재하지 않습니다.");				// 오류메세지 출력
		gotoxy(pos_start.X - 15, pos_start.Y + 2);
		system("PAUSE");
	}

	system("cls");
	gotoxy(75, 23);
	printf("반차 날짜를 입력해주세요 ");
	gotoxy(111, 23);
	scanf("%d", &day);

	retData->Schedule[day].day[0] = 0;
	retData->Schedule[day].day[1] = 1;
	//반차 입력
	retData->count = retData->count - 0.5;

}

void Delete_outside()
{
	char search_name[10]; //검색할 직원의 이름
	int front, rear, day;
	system("cls");
	gotoxy(75, 23);
	printf("외근을  입력할 직원의 이름을 입력해주세요 :");
	scanf("%s", search_name);
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - 15, pos_start.Y);
		printf("ERR :: 직원이 존재하지 않습니다.");				// 오류메세지 출력
		gotoxy(pos_start.X - 15, pos_start.Y + 2);
		system("PAUSE");
	}
	system("cls");
	gotoxy(75, 23);
	printf("삭제할 외근 날짜를 입력해주세요 ");
	gotoxy(111, 23);
	scanf("%d", &day);
	gotoxy(75, 25);
	printf("삭제할 외근 시간을 입력해주세요 ");
	gotoxy(111, 23);
	scanf("%d %d", &front, &rear);
	///delete함수를 사용한다면 그 날짜의 외근 일정을 전부 삭제하는 방법 x
    ///시간을 입력하지 않고 1번 2번 식으로 입력받아서 삭제하는방법 -> 편의성 증가함
	for (int i = front; i <= rear; i++)
	{
		retData->Schedule[day].outside_duty[i] = 0;
		//외근 입력
	}
	printf("외근 일정이 삭제 되었습니다");
}

void Delete_vacation()
{
	char search_name[10]; //검색할 직원의 이름
	int day;
	system("cls");
	gotoxy(75, 23);
	printf("휴가를 삭제할 직원의 이름을 입력해주세요 :");
	gotoxy(111, 23);
	scanf("%s", search_name);
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - 15, pos_start.Y);
		printf("ERR :: 직원이 존재하지 않습니다.");				// 오류메세지 출력
		gotoxy(pos_start.X - 15, pos_start.Y + 2);
		system("PAUSE");
	}

	system("cls");
	gotoxy(75, 23);
	printf("휴가 날짜를 입력해주세요 ");
	gotoxy(111, 23);
	scanf("%d", &day);

	if ((retData->Schedule[day].day[0] = 1) || (retData->Schedule[day].day[1] = 1))
	{
		retData->Schedule[day].day[0] = 0;
		retData->Schedule[day].day[1] = 0;
		if ((retData->Schedule[day].day[0] = 1) && (retData->Schedule[day].day[1] = 1))
		{
			retData->count = retData->count + 1;
		}
		else
		retData->count = retData->count + 0.5;
		system("cls");
		gotoxy(75, 23);
		printf("휴가가 삭제 되었습니다.");
	}
	else
	{
		system("cls");
		gotoxy(75, 23);
		printf("휴가 일정이 존재하지 않습니다");
		
	}
	
}

