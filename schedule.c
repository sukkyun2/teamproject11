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
	int top = 0, top1 = -1, day;
	int start, last;
	int **stack;
	int *stackTop;

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
	scanf("%d %d", &start, &last);
	system("cls");

	stack = (int**)malloc(sizeof(int*));
	stackTop = (int*)malloc(sizeof(int));
	for (int i = 0; i <= 25; i++)
	{
		if (retData->Schedule[day].outside_duty[i] == 1)					//중복되는 외근 시간 체크
		{

			stack[top] = (int*)malloc(sizeof(int));
			stack[top][++top1] = i;

			if (retData->Schedule[day].outside_duty[i + 1] != 1)
			{
				stackTop[top] = top1;
				top1 = -1;
				top++;
				stack = (int**)malloc(sizeof(int*));
			}
		}
	}
	screen(75, 23);
	for (int i = start; i <= last; i++)
	{
		if (retData->Schedule[day].outside_duty[i] == 1)
		{
			for (int j = 0;; j++)
			{
				if (stack[j][0] <= last && stack[j][0] >= start)
				{
					printf("*주의* %d ~ %d 시는 외근이 이미 존재합니다. ( 진행 하실 경우 기존 외근은 삭제됩니다. )\n", stack[j][0], stack[j][stackTop[j]]);
					if (!Check())
						return;																	//진행 안하겠다고 할 시 메뉴로 복귀
					break;
				}
			}
		}
	}
	for (int i = stack[0]; i < 24; i++)											//중복되는 외근과 이어지는 시간 모두 초기화
	{
		if (retData->Schedule[day].outside_duty[i] != 1)
			break;
		retData->Schedule[day].outside_duty[i] == 0;
	}

	for (int i = start; i <= last; i++)									//외근시간 입력
	{
		retData->Schedule[day].outside_duty[i] = 1;
		//외근 입력
	}
	gotoxy(75, 23);
	printf("외근 일정이 입력되었습니다.\n");

}		//외근입력

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
		return;
		// Schedule으로 돌아간다
	}

	system("cls");
	gotoxy(75, 23);
	printf("휴가 날짜를 입력해주세요 ");
	gotoxy(111, 23);
	scanf("%d", &day);

	///외근 스케줄이 있는데 휴가를 사용하는 경우 
	///->외근 일정 기록은 남아있지만 휴가로 덮어씌워짐

	for (int i = 0; i < 24; i++)
	{
		if (retData->Schedule[day].outside_duty[i] = 1)
		{
			gotoxy(78, 26);
			printf("%d일에 외근 일정이 존재합니다 \n", day);
			Check();
			for (int j = 0; j < 24; j++)
			{
				retData->Schedule[day].outside_duty[i] = 0;
				/*외근 일정이 있음에도 휴가를 쓰겠다고 하면
				 외근 일정을 모두 취소 시킨다. */
			}
			break;
		}
	}

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

void Print_Schedule()
{
	char search_name[10]; //검색할 직원의 이름

	int top = 0, top1 = -1, a = 0;

	int **stack;
	int *stackTop;
	int *stackDay;


	stack = (int**)malloc(sizeof(int*));
	stackTop = (int*)malloc(sizeof(int));

	system("cls");
	gotoxy(75, 23);
	printf("외근을  입력할 직원의 이름을 입력해주세요 :");
	gotoxy(111, 23);
	scanf("%s", search_name);  ///변수이름 통일
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(75, 23);
		printf("ERR :: 직원이 존재하지 않습니다.");				// 오류메세지 출력
		gotoxy(75, 25);
		system("PAUSE");
	}

	printf("휴가 : ");
	for (int i = 0; i < 32; i++)
	{
		if (a == 3)
			break;

		if (retData->Schedule[i].day[0] == 1 && retData->Schedule[i].day[1] == 1)
		{
			if (retData->Schedule[i + 1].outside_duty[0] == 1 && retData->Schedule[i + 1].outside_duty[1] == 1)
			{
				printf("%d ~ %d", i, i + 1);
				a = a + 2;
				if (a != 3)
					printf(" , ");
			}
			else
			{
				printf("%d", i);
				a = a + 1;
				if (a != 3)
					printf(" , ");
			}
		}
	}
	printf("일 휴가입니다.\n\n");

	printf("반차 : ");
	for (int i = 0; i < 32; i++)
	{
		if (retData->Schedule[i].day[0] != 1 && retData->Schedule[i].day[1] == 1)
			printf("%d ", i);

		if (retData->Schedule[i].day[0] == 1 && retData->Schedule[i].day[1] != 1)
			printf("%d ", i);
	}
	printf("일 반가입니다.\n\n");


	a = -1;

	for (int day = 0; day < 32; day++)
	{
		printf("%d 일 -> ", i);

		for (int i = 0; i <= 25; i++)
		{
			if (retData->Schedule[day].outside_duty[i] == 1)
			{
				stackDay = (int*)malloc(sizeof(int));
				stackDay[++a] = day;
				break;
			}
		}
	}
	printf("외근 : ");
	for (int day = 0; day < a; day++)
	{
		printf("%d 일 -> ", stackDay[day]);

		for (int i = 0; i <= 25; i++)
		{
			if (retData->Schedule[day].outside_duty[i] == 1)
			{

				stack[top] = (int*)malloc(sizeof(int));
				stack[top][++top1] = i;

				if (retData->Schedule[day].outside_duty[i + 1] != 1)
				{
					stackTop[top] = top1;
					top1 = -1;
					top++;
					stack = (int**)malloc(sizeof(int*));
				}
			}
		}
		for (int i = 0; i < sizeof(stack) / 4; i++)
		{
			printf("%d ~ %d 시 ", stack[i][0], stack[i][stackTop[i]]);
			if ((i + 1) != sizeof(stack))
			{
				printf(" , ");
			}
		}
		printf("\n");
	}

}
