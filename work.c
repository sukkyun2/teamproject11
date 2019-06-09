#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "work.h"
#include "staff.h"

void Print_Work_Menu() 
{	// 일정 관리 메뉴 출력

	system("cls");

	screen(135, 7);
	printf("메뉴 번호를 입력해주세요 : ");
	screen(135, 9);
	printf("1. 근무일정 자동생성하기");
	screen(135, 11);
	printf("2. 근무 일정 검색하기");
	screen(135, 13);
	printf("3. 메인메뉴로 돌아가기");
}

void Work() 
{		//근무관리 
	int menu;
	
	while (1) {
		Print_Work_Menu();
		screen(163, 7);
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			Make_Work();   
			break;
		case 2:
			Search_Work();  
			break;
		case 3:
			Select_Menu(); 
			break;
		}
	}
}

void Make_Work()
{
	struct tm *t;
	time_t timer;
	int year, mon, Fday, sum = 0, i, a;

	struct people* tmp = NULL;
	struct pepple* tmp_a = NULL;
	struct people* a = NULL; //휴가자가 아닌 사람들을 모아두는 연결리스트
	
	int a_count = 0;			

	int small_count = -1;

	timer = time(NULL);
	t = localtime(&timer);
	year = t->tm_year + 1900;
	mon = t->tm_mon + 1;
	Fday = (year * 365 + year / 4 - year / 100 + year / 400 + 1) % 7; //1월1일 요일
	switch (mon)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12: a = 31; break;
	case 4:case 6:case 9:case 11: a = 30; break;
	case 2: a = 28; break;
	}

	for (i = 0; i < a; i++)
		//한달 단위로 생성
	{
		for (tmp = head; tmp;)
		{
			if (tmp->Schedule[i].day[0] == 0 && tmp->Schedule[i].day[1] == 0)
				//휴가나 반차 일정이 없는 경우
			{
				if (a == NULL)
					//첫번째노드가 존재하지 않는다면
				{
					a = tmp;
					tmp_a = a;
					tmp = tmp->next;
					a_count++; //직원수를 알아내기 위한 변수
				}
				else
				{
					tmp_a->next = tmp;
					tmp = tmp->next;
					tmp_a = tmp_a->next;
					a_count++;
				}
				//연결리스트 a에 추가한다.
			}
		}

		for (int i = 1; i < mon; i++)
		{
			switch (i)
			{
			case 1:case 3:case 5:case 7:case 8:case 10:case 12: sum += 31; break;
			case 4:case 6:case 9:case 11: sum += 30; break;
			case 2: sum += 28; break;
			}
		}
		sum = sum + i + 1;
		sum %= 7;

		// 첫번째파트
		while (tmp_a->WCount != small_count)
		{
			search_work(tmp_a, a,a_count);
		}
		tmp_a->Schedule[i].work_schedule[0] = 1;  
		if (sum == 0 || sum==6)
			tmp_a->WCount += 2.5;
		else
			tmp_a->WCount += 1;
		
		// 두번째파트
		while (tmp_a->WCount != small_count)
		{
			search_work(tmp_a, a,a_count);
		}
		tmp_a->Schedule[i].work_schedule[1] = 1;
		if (sum == 0 || sum == 6)
			//주말일경우
			tmp_a->WCount += 2.5;
		else
			//평일일경우
			tmp_a->WCount += 1;
    
	}
}

void search_work(struct people *tmp_a,struct people* a,int a_count)
//랜덤인덱스를 뽑아 그 인덱스로 이동시키는 함수
{
	int v;
	v = random_index();

	tmp_a = a;
	for (int i = 0; i < v - 1; i++)
	{
		tmp_a = tmp_a->next;
	}
}

int random_index(int a_count)
//랜덤인덱스를 뽑는 함수
{
	srand(time(NULL));
	int v;
	v = rand() % (a_count)+1;

	return v;
}


///자동생성을 해놓은 상태에서 어떤 사람이 휴가를 추가했을때 --> 그 사람만 일단 제외하고 스케줄이 되는 다른사람을 찾아서 넣어줌