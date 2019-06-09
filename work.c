#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "work.h"
#include "staff.h"



void Print_Work_Menu() {	// ���� ���� �޴� ���

	system("cls");

	gotoxy(135, 7);
	printf("�޴� ��ȣ�� �Է����ּ��� : ");
	gotoxy(135, 9);
	printf("1. �ٹ����� �ڵ������ϱ�");
	gotoxy(135, 11);
	printf("2. �ٹ� ���� �˻��ϱ�");
	gotoxy(135, 13);
	printf("3. ���θ޴��� ���ư���");
}

void Work() {		//�ٹ����� 
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
	int day; //�ش� ���� �ϼ�

	day = calculate_day();

	for (i = 0; i < day; i++)
		//�Ѵ� ������ ����
	{
		Sub_Make_Work(0);
		Sub_Make_Work(1);
		
		
	}
	gotoxy(75, 23);
	printf("*** �ٹ� �ڵ� ������ �Ϸ�Ǿ����ϴ� ***");
	
}

void Sub_Make_Work(int part_time)
{
	staff a[40]; //������ ���� ������� ��Ƶδ� ���Ḯ��Ʈ
	staff tmp = NULL;
	int smallcountPeopleindex;
	int small_count;  //���� ���� WCount�� �����ϴ� ����
	int a_count = 0;   //�ٹ����� ������� ��

	tmp = head;
	for (int k = 0; k < 40; k++)
	{
		a[k] = NULL;
	}

	for (; tmp; tmp = tmp->next)
		//�ٹ������ο� ����
	{

		if (tmp->Schedule[i].day[0] == 0 && tmp->Schedule[i].day[1] == 0)
		{
			a[a_count++] = tmp;
		}
	}

	for (int h = 0; h < 2; h++)   //ù��° ��Ʈ
								  //�� ��Ʈ�� 2�� �Ҵ��Ѵ�
	{
		small_count = a[0]->WCount;



		for (int j = 0; j < a_count; j++)
			//���� ���� �� �� ã��
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

		if (division_day(i) == 0)	//�ָ��̸� +2
		{
			a[smallcountPeopleindex]->WCount += 3;
		}
		else if (division_day(i) == 6)
		{
			a[smallcountPeopleindex]->WCount += 3;
		}
		else                      //�����̸� +1
		{
			a[smallcountPeopleindex]->WCount += 1;
		}
	}
	
}

int calculate_day()
//�ش� ���� �� ���� ����Ͽ��ִ� ���α׷�
{
	struct tm *t;
	time_t timer;
	int year, mon, Fday,day;

	timer = time(NULL);
	t = localtime(&timer);
	mon = t->tm_mon + 1;
	year = t->tm_year + 1900;
	Fday = (year * 365 + year / 4 - year / 100 + year / 400 + 1) % 7; // 1��1�� ����
	switch (mon)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12: day = 31; break;
	case 4:case 6:case 9:case 11: day = 30; break;
	case 2: day = 28; break;
	}				//�� ���� �ϼ� = mon	//	day

	return day;
}

int division_day(int i)
//�ָ��� ������ �������ִ� �Լ�
{
	struct tm *t;
	time_t timer;
	int year, mon, Fday, sum = 0, d;  //i�� ���� ��¥

	timer = time(NULL);
	t = localtime(&timer);
	year = t->tm_year + 1900;
	mon = t->tm_mon + 1;
	Fday = (year * 365 + year / 4 - year / 100 + year / 400 + 1) % 7; // 1��1�� ����
	for (int j = 1; j < mon; j++)
	{
		switch (j)
		{
		case 1:case 3:case 5:case 7:case 8:case 10:case 12: sum += 31; break;
		case 4:case 6:case 9:case 11: sum += 30; break;
		case 2: sum += 28; break;
		}
	}		//�� �ޱ��� �ϼ� ����
	sum = sum + Fday + i;	//���ޱ����� �� �� + ���⵵������ �� �� + ���� ��
	sum %= 7;				//i���� ����

	return sum;
}

void Search_Work()
{
	int day;
	int x=0,y=0; //��ǥ ���� ����
	int count=0; //print count

	system("cls");
	DrawUI(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("* ���� �˻� �Լ� *") / 2, pos_start.Y - 12);
	printf("* ���� �˻� �Լ� *");
	gotoxy(pos_start.X - 15, pos_start.Y - 1);
	printf("�˻��� ������ �̸� : ");
	gotoxy(pos_start.X + 6, pos_start.Y - 1);
	scanf("%s", newname);
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: ������ �������� �ʽ��ϴ�.") / 2, pos_start.Y - 5);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");      
		gotoxy(pos_start.X - strlen("ERR :: ������ �������� �ʽ��ϴ�.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}
	else {
		system("cls");
		DrawUI(50, 20);
		getcenter();

		gotoxy(pos_start.X - strlen("* ���� �˻� �Լ� *") / 2, pos_start.Y - 12);
		printf("* ���� �˻� �Լ� *");
		gotoxy(pos_start.X - strlen("* õ���� ���� �����Դϴ�. *") / 2, pos_start.Y - 6);

		day = calculate_day();
		printf("** %s ���� �ٹ� �����Դϴ� **",newname);
		for (int i = 0; i < day; i++)
		{
			
			if (retData->Schedule[i].work_schedule[0] == 1 && retData->Schedule[i].work_schedule[1] == 1)
			{
				if (count%4==0)
				{
					x += 10;
				}
				gotoxy(50+x, 23+y);
				printf("%d�� : 19��~22��, 22��-1��",i+1);
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
				printf("%d�� : 19��~22��",i+1);
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
				printf("%d�� : 22��-1��",i+1);
				y += 2;
				count++;
			}
			
		}
		
		system("PAUSE");
	}
}

//10�� �����ΰ�� �ȳ�
/*
staff search_work(staff a[], int small_a_count)
{
	int v;
	v = random_index(small_a_count);

	return a[v];
}	//������ ���ڿ� �ִ� ����� ����

int random_index(int small_a_count)
{
	srand(time(NULL));
	int v;
	v = rand() % (small_a_count);

	return v;
}	//������ ����
*/