#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "menu.h"
#include "work.h"
#include "staff.h"

void Print_workinfo() {   // �޴� ����Ʈ

	COORD tmp;
	char* workMenuList[workMenuNum] = {
	"�ٹ� ���� �ڵ� �����ϱ�",
	"�ٹ� ���� �˻��ϱ�",
	"���θ޴��� ���ư���"
	};
	int i;

	print_askMenunum();

	for (i = 0; i < workMenuNum; i++)
	{
		tmp.Y += 2;
		gotoxy(tmp.X, tmp.Y);
		printf("%d. %s", i + 1, workMenuList[i]);
	}
}

void Print_workMenu()
{
	getform();
	PrinttodayCalendar();

	PrintMenu();
	Print_workinfo();
}


void Work() {		//�ٹ����� 
	int menu;
	COORD tmp;

	while (1) {
		system("cls"); 
		system("COLOR 07");
		Print_workMenu();

		menu = Ask_Menunum();

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
	system("COLOR F0");

	int day; //�ش� ���� �ϼ�

	day = calculate_day();

	for (i = 0; i < day; i++)
		//�Ѵ� ������ ����
	{
		Sub_Make_Work(0);
		Sub_Make_Work(1);
	}
	system("cls"); 
	MessageBox(NULL, TEXT("�ٹ� �ڵ������� �Ϸ�Ǿ����ϴ�. "), TEXT("Check"), MB_OK | MB_ICONINFORMATION);

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

		for (int x = 0; x < a_count; x++)
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
	int year, mon, Fday, day;

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
	system("COLOR F0");

	int start = 0, last = 4, day;
	int count = 0; //print count
	int key, i = 0;

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("����.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);

	gotoxy(pos_start.X - 15, pos_start.Y - 1);
	printf("�˻��� ������ �̸� : ");
	gotoxy(pos_start.X + 6, pos_start.Y - 1);
	scanf("%s", newname);
	Retrieve();

	if (!retData)
	{
		system("cls"); 
		MessageBox(NULL, TEXT("������ �������� �ʽ��ϴ�."), TEXT("ERR"), MB_OK | MB_ICONSTOP);

	}
	else {
		day = calculate_day();
		while (i <= day) {
			Print_Search_Work(start, last, count);
			key = getch();

			if (keycontrol(key) == 2)
			{
				start += 4;
				last += 4;
				i += 4;

			}
			else if (keycontrol(key) == 1)
			{
				start -= 4;
				last -= 4;
				i -= 4;
			}
		}
	}
}

void Print_Search_Work(int start, int last, int count)
{
	int y = 2;

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("����.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);

	gotoxy(pos_start.X - strlen("* ȫ�浿 ���� �����Դϴ�. *") / 2, pos_start.Y - 6);


	printf("** %s ���� �ٹ� �����Դϴ� **", newname);

	for (int i = start; i < last; i++)
	{

		if (retData->Schedule[i].work_schedule[0] == 1 && retData->Schedule[i].work_schedule[1] == 1)
		{
			gotoxy(pos_start.X - 12, pos_start.Y - y);
			printf("%d�� : 19��~22��, 22��-1��", i + 1);
			y -= 2;
			count++;

		}
		else if (retData->Schedule[i].work_schedule[0] == 1 && retData->Schedule[i].work_schedule[1] == 0)
		{
			gotoxy(pos_start.X - 12, pos_start.Y - y);
			printf("%d�� : 19��~22��", i + 1);
			y -= 2;
			count++;
		}
		else if (retData->Schedule[i].work_schedule[0] == 0 && retData->Schedule[i].work_schedule[1] == 1)
		{
			gotoxy(pos_start.X - 12, pos_start.Y - y);
			printf("%d�� : 22��-1��", i + 1);
			y -= 2;
			count++;
		}
	}

	setFontColor(12);
	gotoxy(pos_start.X - strlen("* ����Ű�� ȭ���� �Ѱ��ּ��� *") / 2, pos_start.Y +10);
	printf("* ����Ű�� ȭ���� �Ѱ��ּ��� *");
	resetFontColor();
}

int keycontrol(int key)
{

	switch (key) {
	case 75:
		return 1;		// ���� ����Ű ����
	case 77:
		return 2;		// ������ ����Ű ����

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