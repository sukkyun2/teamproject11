#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "work.h"
#include "staff.h"

void Print_Work_Menu() 
{	// ���� ���� �޴� ���

	system("cls");

	screen(135, 7);
	printf("�޴� ��ȣ�� �Է����ּ��� : ");
	screen(135, 9);
	printf("1. �ٹ����� �ڵ������ϱ�");
	screen(135, 11);
	printf("2. �ٹ� ���� �˻��ϱ�");
	screen(135, 13);
	printf("3. ���θ޴��� ���ư���");
}

void Work() 
{		//�ٹ����� 
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
	struct people* a = NULL; //�ް��ڰ� �ƴ� ������� ��Ƶδ� ���Ḯ��Ʈ
	
	int a_count = 0;			

	int small_count = -1;

	timer = time(NULL);
	t = localtime(&timer);
	year = t->tm_year + 1900;
	mon = t->tm_mon + 1;
	Fday = (year * 365 + year / 4 - year / 100 + year / 400 + 1) % 7; //1��1�� ����
	switch (mon)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12: a = 31; break;
	case 4:case 6:case 9:case 11: a = 30; break;
	case 2: a = 28; break;
	}

	for (i = 0; i < a; i++)
		//�Ѵ� ������ ����
	{
		for (tmp = head; tmp;)
		{
			if (tmp->Schedule[i].day[0] == 0 && tmp->Schedule[i].day[1] == 0)
				//�ް��� ���� ������ ���� ���
			{
				if (a == NULL)
					//ù��°��尡 �������� �ʴ´ٸ�
				{
					a = tmp;
					tmp_a = a;
					tmp = tmp->next;
					a_count++; //�������� �˾Ƴ��� ���� ����
				}
				else
				{
					tmp_a->next = tmp;
					tmp = tmp->next;
					tmp_a = tmp_a->next;
					a_count++;
				}
				//���Ḯ��Ʈ a�� �߰��Ѵ�.
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

		// ù��°��Ʈ
		while (tmp_a->WCount != small_count)
		{
			search_work(tmp_a, a,a_count);
		}
		tmp_a->Schedule[i].work_schedule[0] = 1;  
		if (sum == 0 || sum==6)
			tmp_a->WCount += 2.5;
		else
			tmp_a->WCount += 1;
		
		// �ι�°��Ʈ
		while (tmp_a->WCount != small_count)
		{
			search_work(tmp_a, a,a_count);
		}
		tmp_a->Schedule[i].work_schedule[1] = 1;
		if (sum == 0 || sum == 6)
			//�ָ��ϰ��
			tmp_a->WCount += 2.5;
		else
			//�����ϰ��
			tmp_a->WCount += 1;
    
	}
}

void search_work(struct people *tmp_a,struct people* a,int a_count)
//�����ε����� �̾� �� �ε����� �̵���Ű�� �Լ�
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
//�����ε����� �̴� �Լ�
{
	srand(time(NULL));
	int v;
	v = rand() % (a_count)+1;

	return v;
}


///�ڵ������� �س��� ���¿��� � ����� �ް��� �߰������� --> �� ����� �ϴ� �����ϰ� �������� �Ǵ� �ٸ������ ã�Ƽ� �־���