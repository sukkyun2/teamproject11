#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "work.h"
#include "staff.h"



void Print_Work_Menu() {	// 일정 관리 메뉴 출력

	system("cls");

	gotoxy(135, 7);
	printf("메뉴 번호를 입력해주세요 : ");
	gotoxy(135, 9);
	printf("1. 근무일정 자동생성하기");
	gotoxy(135, 11);
	printf("2. 근무 일정 검색하기");
	gotoxy(135, 13);
	printf("3. 메인메뉴로 돌아가기");
}

void Work() {		//근무관리 
	int menu;
	
	while (1) {
		Print_Work_Menu();
		gotoxy(163, 7);
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			Make_Work();   
			break;
		case 2:
			Search_Work();  
			break;
		case 3:
			PrintHomepage();
			break;
		}
	}
}

void Make_Work()
{
	int day; //해당 월의 일수

	day = calculate_day();

	for (i = 0; i < day; i++)
		//한달 단위로 생성
	{
		Sub_Make_Work(0);
		Sub_Make_Work(1);
		
		
	}
	gotoxy(75, 23);
	printf("*** 근무 자동 생성이 완료되었습니다 ***");
	
}

void Sub_Make_Work(int part_time)
{
	staff a[40]; //일정이 없는 사람들을 모아두는 연결리스트
	staff tmp = NULL;
	int smallcountPeopleindex;
	int small_count;  //가장 적은 WCount를 저장하는 변수
	int a_count = 0;   //근무가능 사람들의 수

	tmp = head;
	for (int k = 0; k < 40; k++)
	{
		a[k] = NULL;
	}

	for (; tmp; tmp = tmp->next)
		//근무가능인원 추출
	{

		if (tmp->Schedule[i].day[0] == 0 && tmp->Schedule[i].day[1] == 0)
		{
			a[a_count++] = tmp;
		}
	}

	for (int h = 0; h < 2; h++)   //첫번째 파트
								  //한 파트당 2명씩 할당한다
	{
		small_count = a[0]->WCount;



		for (int j = 0; j < a_count; j++)
			//가장 적은 일 수 찾기
		{
			if (small_count >= a[j]->WCount)
			{
				small_count = a[j]->WCount;

			}
		}

		for (int x = 0; x<a_count; x++)
		{
			if (small_count == a[x]->WCount)
			{
				smallcountPeopleindex = x;
				break;
			}
		}

		a[smallcountPeopleindex]->Schedule[i].work_schedule[part_time] = 1;

		if (division_day(i) == 0)	//주말이면 +2
		{
			a[smallcountPeopleindex]->WCount += 3;
		}
		else if (division_day(i) == 6)
		{
			a[smallcountPeopleindex]->WCount += 3;
		}
		else                      //평일이면 +1
		{
			a[smallcountPeopleindex]->WCount += 1;
		}
	}
	
}

int calculate_day()
//해당 월에 일 수를 계산하여주는 프로그램
{
	struct tm *t;
	time_t timer;
	int year, mon, Fday,day;

	timer = time(NULL);
	t = localtime(&timer);
	mon = t->tm_mon + 1;
	year = t->tm_year + 1900;
	Fday = (year * 365 + year / 4 - year / 100 + year / 400 + 1) % 7; // 1월1일 요일
	switch (mon)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12: day = 31; break;
	case 4:case 6:case 9:case 11: day = 30; break;
	case 2: day = 28; break;
	}				//당 월의 일수 = mon	//	day

	return day;
}

int division_day(int i)
//주말과 평일을 구분해주는 함수
{
	struct tm *t;
	time_t timer;
	int year, mon, Fday, sum = 0, d;  //i는 현재 날짜

	timer = time(NULL);
	t = localtime(&timer);
	year = t->tm_year + 1900;
	mon = t->tm_mon + 1;
	Fday = (year * 365 + year / 4 - year / 100 + year / 400 + 1) % 7; // 1월1일 요일
	for (int j = 1; j < mon; j++)
	{
		switch (j)
		{
		case 1:case 3:case 5:case 7:case 8:case 10:case 12: sum += 31; break;
		case 4:case 6:case 9:case 11: sum += 30; break;
		case 2: sum += 28; break;
		}
	}		//전 달까지 일수 더함
	sum = sum + Fday + i;	//전달까지의 일 수 + 전년도까지의 일 수 + 현재 일
	sum %= 7;				//i일의 요일

	return sum;
}

void Search_Work()
{
	int day;
	int x=0,y=0; //좌표 설정 변수
	int count=0; //print count

	system("cls");
	DrawUI(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("* 직원 검색 함수 *") / 2, pos_start.Y - 12);
	printf("* 직원 검색 함수 *");
	gotoxy(pos_start.X - 15, pos_start.Y - 1);
	printf("검색할 직원의 이름 : ");
	gotoxy(pos_start.X + 6, pos_start.Y - 1);
	scanf("%s", newname);
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: 직원이 존재하지 않습니다.") / 2, pos_start.Y - 5);
		printf("ERR :: 직원이 존재하지 않습니다.");      
		gotoxy(pos_start.X - strlen("ERR :: 직원이 존재하지 않습니다.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}
	else {
		system("cls");
		DrawUI(50, 20);
		getcenter();

		gotoxy(pos_start.X - strlen("* 직원 검색 함수 *") / 2, pos_start.Y - 12);
		printf("* 직원 검색 함수 *");
		gotoxy(pos_start.X - strlen("* 천은정 님의 정보입니다. *") / 2, pos_start.Y - 6);

		day = calculate_day();
		printf("** %s 님의 근무 일정입니다 **",newname);
		for (int i = 0; i < day; i++)
		{
			
			if (retData->Schedule[i].work_schedule[0] == 1 && retData->Schedule[i].work_schedule[1] == 1)
			{
				if (count%4==0)
				{
					x += 10;
				}
				gotoxy(50+x, 23+y);
				printf("%d일 : 19시~22시, 22시-1시",i+1);
				y += 2;
				count++;
				
			}
			else if (retData->Schedule[i].work_schedule[0] == 1 && retData->Schedule[i].work_schedule[1] == 0)
			{
				if (count%4==0)
				{
					x += 10;
				}
				gotoxy(50 + x, 23 + y);
				printf("%d일 : 19시~22시",i+1);
				y += 2;
				count++;
			}
			else if (retData->Schedule[i].work_schedule[0] == 0 && retData->Schedule[i].work_schedule[1] == 1)
			{
				if (count%4==0)
				{
					x += 10;
				}
				gotoxy(50 + x, 23 + y);
				printf("%d일 : 22시-1시",i+1);
				y += 2;
				count++;
			}
			
		}
		
		system("PAUSE");
	}
}

//10장 독립인경우 안냄
/*
staff search_work(staff a[], int small_a_count)
{
	int v;
	v = random_index(small_a_count);

	return a[v];
}	//랜덤한 숫자에 있는 사람을 리턴

int random_index(int small_a_count)
{
	srand(time(NULL));
	int v;
	v = rand() % (small_a_count);

	return v;
}	//랜덤수 리턴
*/