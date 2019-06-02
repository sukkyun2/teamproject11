#include "schedule.h"

void Print_scheduleinfo() {   // 메뉴 프린트

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


void Schedule() {      // 직원 관리 실행
	int menu;
	COORD tmp;

	while (1)
	{
		system("cls");
		Print_scheduleSMenu();

		menu = Ask_Menunum(&tmp);

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


void Print_Insert_scheduleinfo() {   // 메뉴 프린트

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
		Print_Insert_scheduleSinfo();

		menu = Ask_Menunum(&tmp);
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
			PrintHomepage();
			break;
		}
	}

}


void Print_Delete_scheduleinfo() {   // 메뉴 프린트

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

		menu = Ask_Menunum(&tmp);

		switch (menu)
		{
		case 1:
			Delete_outside();
			break;
		case 2:
			Delete_vacation();
			break;
		case 3:
			PrintHomepage();
			break;
		}
	}
}

void Insert_outside()
{
	int top = 0, top1 = -1, day, tmp = 0;
	int start, last;
	int stack[30][24] = { 0, };
	int stackTop[30] = { 0, };


	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("외근할 직원의 이름 :   ") / 2, pos_start.Y - 2);
	printf("외근할 직원의 이름 :");
	gotoxy(pos_start.X + strlen("외근할 직원의 이름 :") / 2, pos_start.Y - 2);
	scanf("%s", newname);  ///변수이름 통일
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: 직원이 존재하지 않습니다.") / 2, pos_start.Y - 5);
		printf("ERR :: 직원이 존재하지 않습니다.");            // 오류메세지 출력
		gotoxy(pos_start.X - strlen("ERR :: 직원이 존재하지 않습니다.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}
	else {
		system("cls");
		DrawCenterBox(50, 20);
		getcenter();

		gotoxy(pos_start.X - strlen("외근할 날짜를 입력해주세요 : ") / 2, pos_start.Y - 2);
		printf("외근할 날짜를 입력해주세요 :  ");
		gotoxy(pos_start.X + strlen("외근할 날짜를 입력해주세요 :   ") / 2, pos_start.Y - 2);
		scanf("%d", &day);
		gotoxy(pos_start.X - strlen("외근 시간을 입력해주세요 :  ") / 2, pos_start.Y);
		printf("외근 시간을 입력해주세요 :  ");
		gotoxy(pos_start.X + strlen("외근 시간을 입력해주세요 : ") / 2, pos_start.Y);
		scanf("%d", &start);
		gotoxy(pos_start.X + strlen("외근 시간을 입력해주세요 : ") / 2 + 2, pos_start.Y);
		printf("~");
		scanf("%d", &last);


		for (int i = 0; i < 25; i++)
		{
			if (retData->Schedule[day].outside_duty[i] == 1)					// 외근 시간 체크
			{
				stack[top][++top1] = i;

				if (retData->Schedule[day].outside_duty[i + 1] != 1)
				{
					stackTop[top] = top1;
					top1 = -1;
					top++;
				}
			}
		}

		tmp = 0;
		for (int i = 0; i < top; i++)
		{
			for (int j = 0; j <= stackTop[i]; j++)
			{
				if (stack[i][j] >= start && stack[i][j] < last)
				{
					system("cls");
					gotoxy(pos_start.X - strlen("ERR :: %d ~ %d 시는 외근이 이미 존재합니다.") / 2, pos_start.Y - 5);
					printf("ERR :: %d ~ %d 시는 외근이 이미 존재합니다.", stack[j][0], stack[j][stackTop[j]]);            // 오류메세지 출력
					gotoxy(pos_start.X - strlen("( 진행 하실 경우 기존 외근은 삭제됩니다. )") / 2, pos_start.Y - 3);
					printf("( 진행 하실 경우 기존 외근은 삭제됩니다. )");
					gotoxy(pos_start.X - strlen("ERR :: %d ~ %d 시는 외근이 이미 존재합니다.") / 2, pos_start.Y - 3);
					system("PAUSE");

					if (!Check())
						return;                                                   //진행 안하겠다고 할 시 메뉴로 복귀
					tmp = 1;
					break;
				}
			}
			if (tmp == 1)
				break;
		}
		for (int i = 0; i < top; i++)
		{
			for (int j = 0; j <= stackTop[i]; j++)
			{
				if (stack[i][j] >= start && stack[i][j] < last)
				{
					for (tmp = 0; tmp <= stackTop[i]; tmp++)
					{
						retData->Schedule[day].outside_duty[stack[i][tmp]] = 0;
					}
					break;
				}
			}
		}
		for (int i = start; i < last; i++)									//외근시간 입력
		{
			retData->Schedule[day].outside_duty[i] = 1;
			//외근 입력
		}

		system("cls");
		gotoxy(pos_start.X - strlen(":: 외근 일정이 입력되었습니다.") / 2, pos_start.Y - 5);
		printf(":: 외근 일정이 입력되었습니다.");            // 오류메세지 출력
		gotoxy(pos_start.X - strlen(":: 외근 일정이 입력되었습니다.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}

}

void Insert_day()
{

	int day;

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("휴가일정 추가할 직원의 이름 :   ") / 2, pos_start.Y - 2);
	printf("휴가일정 추가할 직원의 이름 : ");
	gotoxy(pos_start.X + strlen("휴가일정 추가할 직원의 이름 :  ") / 2, pos_start.Y - 2);
	scanf("%s", newname);  ///변수이름 통일
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: 직원이 존재하지 않습니다.") / 2, pos_start.Y - 5);
		printf("ERR :: 직원이 존재하지 않습니다.");            // 오류메세지 출력
		gotoxy(pos_start.X - strlen("ERR :: 직원이 존재하지 않습니다.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}

	if (retData->count < 1)  //휴가 한도를 넘어섰다면
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: 휴가 사용 가능횟수를 초과하였습니다.") / 2, pos_start.Y - 5);
		printf("ERR :: 휴가 사용 가능횟수를 초과하였습니다.");            // 오류메세지 출력
		gotoxy(pos_start.X - strlen("ERR :: 휴가 사용 가능횟수를 초과하였습니다.") / 2, pos_start.Y - 3);
		system("PAUSE");

		return 0;
		// Schedule으로 돌아간다
	}

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("휴가 날짜를 입력해주세요 :   ") / 2, pos_start.Y - 2);
	printf("휴가 날짜를 입력해주세요 : ");
	gotoxy(pos_start.X + strlen("휴가 날짜를 입력해주세요 :   ") / 2, pos_start.Y - 2);
	scanf("%d", &day);

	///외근 스케줄이 있는데 휴가를 사용하는 경우 
   ///->외근 일정 기록은 남아있지만 휴가로 덮어씌워짐

	for (int i = 0; i < 25; i++)
	{
		if (retData->Schedule[day].outside_duty[i] = 1)
		{
			gotoxy(pos_start.X - strlen("%d일에 외근 일정이 존재합니다 ") / 2, pos_start.Y - 2);
			printf("%d일에 외근 일정이 존재합니다 \n", day);
			Check();
			for (int j = 0; j < 25; j++)
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

	system("cls");
	gotoxy(pos_start.X - strlen(":: 휴가 일정이 입력되었습니다.") / 2, pos_start.Y - 5);
	printf(":: 휴가 일정이 입력되었습니다.");            // 오류메세지 출력
	gotoxy(pos_start.X - strlen(":: 휴가 일정이 입력되었습니다.") / 2, pos_start.Y - 3);
	system("PAUSE");

}

void Insert_moning_half()
{
	int front, rear, day;

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("반차일정 추가할 직원의 이름 :   ") / 2, pos_start.Y - 2);
	printf("반차일정 추가할 직원의 이름 : ");
	gotoxy(pos_start.X + strlen("반차일정 추가할 직원의 이름 :   ") / 2, pos_start.Y - 2);
	scanf("%s", newname);  ///변수이름 통일
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: 직원이 존재하지 않습니다.") / 2, pos_start.Y - 5);
		printf("ERR :: 직원이 존재하지 않습니다.");            // 오류메세지 출력
		gotoxy(pos_start.X - strlen("ERR :: 직원이 존재하지 않습니다.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("반차 날짜를 입력해주세요 :   ") / 2, pos_start.Y - 2);
	printf("반차 날짜를 입력해주세요 : ");
	gotoxy(pos_start.X + strlen("반차 날짜를 입력해주세요 :   ") / 2, pos_start.Y - 2);
	scanf("%d", &day);

	retData->Schedule[day].day[0] = 1;
	retData->Schedule[day].day[1] = 0;
	//반차 입력
	retData->count = retData->count - 0.5;
	system("PAUSE");
}

void Insert_afternoon_half()
{
	int front, rear, day;

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("반차일정 추가할 직원의 이름 :   ") / 2, pos_start.Y - 2);
	printf("반차일정 추가할 직원의 이름 : ");
	gotoxy(pos_start.X + strlen("반차일정 추가할 직원의 이름 :   ") / 2, pos_start.Y - 2);
	scanf("%s", newname);  ///변수이름 통일
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: 직원이 존재하지 않습니다.") / 2, pos_start.Y - 5);
		printf("ERR :: 직원이 존재하지 않습니다.");            // 오류메세지 출력
		gotoxy(pos_start.X - strlen("ERR :: 직원이 존재하지 않습니다.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("반차 날짜를 입력해주세요 :   ") / 2, pos_start.Y - 2);
	printf("반차 날짜를 입력해주세요 : ");
	gotoxy(pos_start.X + strlen("반차 날짜를 입력해주세요 :   ") / 2, pos_start.Y - 2);
	scanf("%d", &day);

	retData->Schedule[day].day[0] = 0;
	retData->Schedule[day].day[1] = 1;
	//반차 입력
	retData->count = retData->count - 0.5;
	system("PAUSE");

}

void Delete_outside()
{
	int top = 0, top1 = -1, day, tmp;
	int start, last;

	int stack[30][24] = { 0, };
	int stackTop[30] = { 0, };

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("외근일정 삭제할 직원의 이름 :   ") / 2, pos_start.Y - 2);
	printf("외근일정 삭제할 직원의 이름 : ");
	gotoxy(pos_start.X + strlen("외근일정 삭제할 직원의 이름 :   ") / 2, pos_start.Y - 2);
	scanf("%s", newname);  ///변수이름 통일
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: 직원이 존재하지 않습니다.") / 2, pos_start.Y - 5);
		printf("ERR :: 직원이 존재하지 않습니다.");            // 오류메세지 출력
		gotoxy(pos_start.X - strlen("ERR :: 직원이 존재하지 않습니다.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}
	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("삭제할 외근 날짜를 입력해주세요 :  ") / 2, pos_start.Y - 2);
	printf("삭제할 외근 날짜를 입력해주세요 :  ");
	gotoxy(pos_start.X + strlen("삭제할 외근 날짜를 입력해주세요 :   ") / 2, pos_start.Y - 2);
	scanf("%d", &day);

	for (int i = 0; i < 25; i++)
	{
		if (retData->Schedule[day].outside_duty[i] == 1)					//외근 시간 체크
		{
			stack[top][++top1] = i;
			if (retData->Schedule[day].outside_duty[i + 1] != 1)
			{
				stackTop[top] = top1;
				top1 = -1;
				top++;
			}
		}
	}

	system("cls");
	for (int i = 0; i < top; i++)
	{
		gotoxy(pos_start.X - strlen("%d번 : %d시 ~ %d시") / 2, pos_start.Y - 2);
		printf("%d번 : %d시 ~ %d시\n", i + 1, stack[i][0], stack[i][stackTop[i]] + 1);
	}

	gotoxy(pos_start.X - strlen("어떤 외근을 삭제 하시겠습니까?") / 2, pos_start.Y);
	printf("어떤 외근을 삭제 하시겠습니까? : ");
	gotoxy(pos_start.X + strlen("어떤 외근을 삭제 하시겠습니까?") / 2, pos_start.Y);
	scanf("%d", &tmp);
	for (int i = 0; i <= stackTop[i]; i++)
	{
		retData->Schedule[day].outside_duty[stack[tmp][i]] = 0;
	}

	system("cls");
	gotoxy(pos_start.X - strlen(":: 외근 일정이 삭제되었습니다.") / 2, pos_start.Y - 5);
	printf(":: 외근 일정이 삭제되었습니다.");            // 오류메세지 출력
	gotoxy(pos_start.X - strlen(":: 외근 일정이 삭제되었습니다.") / 2, pos_start.Y - 3);
	system("PAUSE");
}

void Delete_vacation()
{
	int day;

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("휴가일정 삭제할 직원의 이름 :   ") / 2, pos_start.Y - 2);
	printf("휴가일정 추가할 직원의 이름 : ");
	gotoxy(pos_start.X + strlen("휴가일정 삭제할 직원의 이름 :  ") / 2, pos_start.Y - 2);
	scanf("%s", newname);  ///변수이름 통일
	Retrieve();


	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: 직원이 존재하지 않습니다.") / 2, pos_start.Y - 5);
		printf("ERR :: 직원이 존재하지 않습니다.");            // 오류메세지 출력
		gotoxy(pos_start.X - strlen("ERR :: 직원이 존재하지 않습니다.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}


	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("삭제할 휴가 날짜를 입력해주세요 :   ") / 2, pos_start.Y - 2);
	printf("삭제할 휴가 날짜를 입력해주세요 : ");
	gotoxy(pos_start.X + strlen("삭제할 휴가 날짜를 입력해주세요 :   ") / 2, pos_start.Y - 2);
	scanf("%d", &day);

	if ((retData->Schedule[day].day[0] = 1) || (retData->Schedule[day].day[1] = 1))
	{
		if ((retData->Schedule[day].day[0] = 1) && (retData->Schedule[day].day[1] = 1))
		{
			retData->count = retData->count + 1;
		}
		else
		{
			retData->count = retData->count + 0.5;
		}

		retData->Schedule[day].day[0] = 0;
		retData->Schedule[day].day[1] = 0;
		system("cls");
		gotoxy(pos_start.X - strlen(":: 휴가 일정이 삭제되었습니다.") / 2, pos_start.Y - 5);
		printf(":: 휴가 일정이 삭제되었습니다.");            // 오류메세지 출력
		gotoxy(pos_start.X - strlen(":: 휴가 일정이 삭제되었습니다.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}
	else
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: 휴가 일정이 존재하지 않습니다.") / 2, pos_start.Y - 5);
		printf("ERR :: 휴가 일정이 존재하지 않습니다.");            // 오류메세지 출력
		gotoxy(pos_start.X - strlen("ERR :: 휴가 일정이 존재하지 않습니다.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}

}

void Print_Schedule()
{
	int top = 0, top1 = -1, day, tmp = 0;
	int start, last;
	int stack[30][24] = { 0, };
	int stackTop[30] = { 0, };
	int stackDay[32] = { 0, };


	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("검색할 직원의 이름을 입력해주세요 : "), pos_start.Y - 1);
	printf("검색할 직원의 이름을 입력해주세요 :");
	gotoxy(pos_start.X + strlen("검색할 직원의 이름을 입력해주세요 : "), pos_start.Y - 1);
	scanf("%s", search_name);  ///변수이름 통일
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: 직원이 존재하지 않습니다.") / 2, pos_start.Y - 5);
		printf("ERR :: 직원이 존재하지 않습니다.");            // 오류메세지 출력
		gotoxy(pos_start.X - strlen("ERR :: 직원이 존재하지 않습니다.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}


	printf("휴가 : ");
	for (int i = 1; i < 32; i++)
	{
		int j = 0; //좌표 설정 변수
		if (tmp == 3)
			break;

		if (retData->Schedule[i].day[0] == 1 && retData->Schedule[i].day[1] == 1)
		{
			if (retData->Schedule[i + 1].outside_duty[0] == 1 && retData->Schedule[i + 1].outside_duty[1] == 1)
			{
				if (retData->Schedule[i + 2].outside_duty[0] == 1 && retData->Schedule[i + 2].outside_duty[1] == 1)
					//3일연속으로 휴가를 사용한 경우
				{
					gotoxy(111, 23);
					printf("%d ~ %d ", i + 1, i + 3);
					tmp += 3;
					break;
				}
				else
				{
					gotoxy(111 + j, 23);
					printf("%d ~ %d", i, i + 1);
					tmp = tmp + 2;
					j += 2;
					if (tmp != 3)
					{
						gotoxy(111 + j, 23);
						printf(" , ");
						j += 2;
					}
				}
			}
			if (retData->Schedule[i + 1].outside_duty[0] != 1 && retData->Schedule[i + 1].outside_duty[1] != 1)
				//하루만 휴가를 사용한 경우
			{
				gotoxy(111 + j, 23);
				printf("%d", i);
				tmp = tmp + 1;
				j += 2;
				if (tmp != 3)
				{
					gotoxy(111 + j, 23);
					printf(" , ");
					j += 2;
				}
			}
		}

	}
	//휴가 출력 완료

	printf("반차 : ");
	for (int i = 0; i < 32; i++)
	{
		int j = 0; //좌표 설정 변수
		if (retData->Schedule[i].day[0] != 1 && retData->Schedule[i].day[1] == 1)
		{
			gotoxy(111 + j, 25);
			printf("%d ", i);
			j += 2;
		}

		if (retData->Schedule[i].day[0] == 1 && retData->Schedule[i].day[1] != 1)
		{
			gotoxy(111 + j, 25);
			printf("%d ", i);
			j += 2;
		}
	}
	//반가 출력 완료


	tmp = -1;

	for (int day = 1; day < 32; day++)
	{
		for (int i = 0; i < 25; i++)
		{
			if (retData->Schedule[day].outside_duty[i] == 1)
			{
				stackDay[++tmp] = day;
				break;
			}
		}
	}

	gotoxy(75, 27);
	printf("외근 : ");

	for (int day = 1; day < 32; day++)
	{

		if (stackDay[day] != 0)			//외근 있는 날에 실행
		{
			int x = 0;//좌표 설정 변수
			int y = 0;//좌표 설정 변수

			gotoxy(111 + x, 27 + y);
			printf("%d일 -> ", stackDay[day]);

			top = 0;
			top1 = -1;

			for (int j = 0; j < 25; j++)
			{
				if (retData->Schedule[day].outside_duty[j] == 1)
				{
					stack[top][++top1] = day;

					if (retData->Schedule[day].outside_duty[j + 1] != 1)
					{
						stackTop[top] = top1;
						top1 = -1;
						top++;
					}
				}
			}					//외근 찾아 놓음

			for (int j = 0; j <= top; j++)
			{
				x += 5;
				gotoxy(111 + x, 27);
				printf("%d ~ %d 시 ", stack[j][0], stack[j][stackTop[j]] + 1);
				if (j != top)
				{
					x += 2;
					printf(" , ");
				}
			}
			y += 2;
		}
	}

}