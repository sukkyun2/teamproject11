#pragma once

#include "staff.h"
#include "menu.h"
#include "DefinePage.h"
#include "login.h"

typedef struct people *staff;
staff head = NULL;
staff retData;
char newname[10];
int people_num = 0;

#include "DrawMainMenu.h"

void getstaffSize()
{
	pos_start.X = (int)((double)(8.5 * onecols));
	pos_start.Y = (int)((double)(1.0 * onerows) + 6);

	pos_end.X = (int)((double)(11.5 * onecols));
	pos_end.Y = (int)((double)(4.0 * onerows) + 6);

	menu_width = pos_end.X - pos_start.X;
	menu_height = pos_end.Y - pos_start.Y;
}

void Printstaff_background()
{
	COORD tmp;
	int r, c;

	tmp.X = pos_start.X;	tmp.Y = pos_start.Y;

	gotoxy(tmp.X, tmp.Y);

	for (c = 1; c <= menu_height; c++)
	{
		if (c == 1)
		{
			for (r = 1; r <= menu_width; r++)
			{

				if (r == 1) printf("��");
				else if (r == menu_width) printf("��");
				else printf("��");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		else if (c == menu_height)
		{
			for (r = 1; r <= menu_width; r++)
			{

				if (r == 1) printf("��");
				else if (r == menu_width) printf("��");
				else printf("��");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		else
		{
			for (r = 1; r <= menu_width; r++)
			{
				if ((r == 1) || (r == menu_width)) printf("��");
				else printf(" ");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		tmp.X = pos_start.X;	tmp.Y++;
		gotoxy(tmp.X, tmp.Y);
	}
}

void Print_Mainstaffinfo() {	// �޴� ����Ʈ

	COORD tmp;
	char* mainMenuList[MenuNum] = {
	"���� �߰�",
	"���� ����",
	"���� ����",
	"���� �˻�",
	"���θ޴��� ���ư���"
	};
	int i;

	tmp.X = pos_start.X + 3;	tmp.Y = pos_start.Y + 2;

	gotoxy(tmp.X, tmp.Y);
	printf("�޴� ��ȣ�� �Է����ּ��� : ");

	for (i = 0; i < MenuNum; i++)
	{
		tmp.Y += 2;
		gotoxy(tmp.X, tmp.Y);
		printf("%d. %s", i + 1, mainMenuList[i]);
	}
}

void Staff() {		// ���� ���� ����
	int menu;
	COORD tmp;
	while (1) {
		system("cls");
		getform();
		getstaffSize();
		Printstaff_background();
		Print_Mainstaffinfo();
		tmp.X = pos_start.X + 3 + strlen("�޴� ��ȣ�� �Է����ּ��� : ");
		tmp.Y = pos_start.Y + 2;
		gotoxy(tmp.X, tmp.Y);
		scanf("%d", &menu);
		switch (menu) {
			
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


int Check()
{
	char check[5];
	screen(loginpos.X - 8, loginpos.Y + 15);
	printf("�����Ͻðڽ��ϱ� ? [Yes Or No] : \n ");
	screen(loginpos.X + 25, loginpos.Y + 15);
	scanf("%s", check);
	if (strcmp(check, "Yes") == 0)
		return 1;
	else
		return 0;
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

void Insert_Staff() {		// ���� �߰� �Լ�

	system("cls");
	getloginSize();
	Printlogin_background();

	staff prev;

	loginpos.X = 6.0*onecols - 15;
	loginpos.Y = 3.75*onerows - 8;

	screen(loginpos.X, loginpos.Y);
	printf("* ���� �߰� �Լ� *");
	screen(loginpos.X-2, loginpos.Y + 5);
	printf("���� �̸� : ");
	screen(loginpos.X+10, loginpos.Y + 5);
	scanf("%s", newname);
	Retrieve();

	if (retData!=NULL)
	{
		loginpos.X = 6.0*onecols;
		loginpos.Y = 3.75*onerows;
		system("cls");
		screen(loginpos.X-15, loginpos.Y);
		printf("ERR :: �̹� ������ �����մϴ�.");				// �����޼��� ���
		screen(loginpos.X-15, loginpos.Y+2);
		system("PAUSE");
	}
	else
	{
		people_num++;
		struct people *node = malloc(sizeof(struct people));
		strcpy(node->name, newname);
		screen(loginpos.X-2, loginpos.Y + 7);
		printf("���� ���� : ");
		screen(loginpos.X +10, loginpos.Y + 7);
		scanf("%s", node->birth);
		screen(loginpos.X-4, loginpos.Y + 9);
		printf("�޴��� ��ȣ : ");
		screen(loginpos.X + 10, loginpos.Y + 9);
		scanf("%s", node->phone_num);
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

void Delete_Staff() {		// ���� ���� �Լ�
	staff node;
	node = head;
	
	system("cls");
	getloginSize();
	Printlogin_background();

	loginpos.X = 6.0*onecols - 15;
	loginpos.Y = 3.75*onerows - 8;

	screen(loginpos.X, loginpos.Y);
	printf("* ���� ���� �Լ� *");
	screen(loginpos.X -11, loginpos.Y + 10);
	printf("������ ������ �̸��� �Է����ּ��� : ");
	screen(loginpos.X + 25, loginpos.Y + 10);
	scanf("%s", newname);
	Retrieve();


	if (!retData)
	{
		loginpos.X = 6.0*onecols;
		loginpos.Y = 3.75*onerows;

		system("cls");
		screen(loginpos.X - 15, loginpos.Y);
		printf("ERR :: ������ ������ �����ϴ�.");				// �����޼��� ���
		screen(loginpos.X - 15, loginpos.Y + 2);
		system("PAUSE");
	}
	else {
		system("cls");
		getloginSize();
		Printlogin_background();

		loginpos.X = 6.0*onecols - 15;
		loginpos.Y = 3.75*onerows - 8;

		screen(loginpos.X, loginpos.Y);
		printf("* ���� ���� �Լ� *");
		screen(loginpos.X-2, loginpos.Y+5);
		printf("%s�� �� �����Դϴ�.\n", retData->name);
		screen(loginpos.X - 2, loginpos.Y + 7); 
		printf("���� �̸� : %s\n", retData->name);
		screen(loginpos.X - 2, loginpos.Y + 9);
		printf("���� ���� : %s\n", retData->birth);
		screen(loginpos.X - 2, loginpos.Y + 11);
		printf("�޴��� ��ȣ : %s\n", retData->phone_num);

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

void Change_Staff() {		// ���� ���� �Լ�

	system("cls");
	getloginSize();
	Printlogin_background();

	loginpos.X = 6.0*onecols - 15;
	loginpos.Y = 3.75*onerows - 8;

	screen(loginpos.X, loginpos.Y);
	printf("* ���� ���� �Լ� *");
	screen(loginpos.X - 11, loginpos.Y + 10);
	printf("������ ������ �̸��� �Է����ּ��� : ");
	screen(loginpos.X + 25, loginpos.Y + 10);
	scanf("%s", newname);
	Retrieve();

	if (!retData)
	{
		loginpos.X = 6.0*onecols;
		loginpos.Y = 3.75*onerows;

		system("cls");
		screen(loginpos.X - 15, loginpos.Y);
		printf("ERR :: ������ ������ �����ϴ�.");				// �����޼��� ���
		screen(loginpos.X - 15, loginpos.Y + 2);
		system("PAUSE");

	}
	else {
		system("cls");
		getloginSize();
		Printlogin_background();

		loginpos.X = 6.0*onecols - 15;
		loginpos.Y = 3.75*onerows - 8;

		screen(loginpos.X, loginpos.Y);
		printf("* ���� ���� �Լ� *");
		screen(loginpos.X - 2, loginpos.Y + 5);
		printf("%s ���� �����Դϴ�.\n", retData->name);
		screen(loginpos.X - 2, loginpos.Y + 7);
		printf("���� �̸� : %s\n", retData->name);
		screen(loginpos.X - 2, loginpos.Y + 9);
		printf("���� ���� : %s\n", retData->birth);
		screen(loginpos.X - 2, loginpos.Y + 11);
		printf("�޴��� ��ȣ : %s\n", retData->phone_num);


		if (Check() == 1) {
			system("cls");
			getloginSize();
			Printlogin_background();

			loginpos.X = 6.0*onecols - 15;
			loginpos.Y = 3.75*onerows - 8;

			screen(loginpos.X - 2, loginpos.Y + 7);
			printf("���� �̸� : ");
			screen(loginpos.X +10, loginpos.Y + 7);
			scanf("%s", retData->name);
			screen(loginpos.X - 2, loginpos.Y + 9);
			printf("���� ���� : ");
			screen(loginpos.X +10, loginpos.Y + 9);
			scanf("%s", retData->birth);
			screen(loginpos.X - 4, loginpos.Y + 11);
			printf("�޴��� ��ȣ : ");
			screen(loginpos.X +10, loginpos.Y + 11);
			scanf("%s", retData->phone_num);
		}
		else
			return;
	}
}

void Retrieve_Staff() {		// ���� �˻� �Լ�

	system("cls");
	getloginSize();
	Printlogin_background();

	loginpos.X = 6.0*onecols - 15;
	loginpos.Y = 3.75*onerows - 8;

	screen(loginpos.X, loginpos.Y);
	printf("* ���� �˻� �Լ� *");
	screen(loginpos.X - 11, loginpos.Y + 10);
	printf("�˻��� ������ �̸��� �Է����ּ��� : ");
	screen(loginpos.X + 25, loginpos.Y + 10);
	scanf("%s", newname);
	Retrieve();

	if (!retData)
	{
		loginpos.X = 6.0*onecols;
		loginpos.Y = 3.75*onerows;

		system("cls");
		screen(loginpos.X - 15, loginpos.Y);
		printf("ERR :: ������ �������� �ʽ��ϴ�..");				// �����޼��� ���
		screen(loginpos.X - 15, loginpos.Y + 2);
		system("PAUSE");
	}
	else {
		system("cls");
		getloginSize();
		Printlogin_background();

		loginpos.X = 6.0*onecols - 15;
		loginpos.Y = 3.75*onerows - 8;

		screen(loginpos.X, loginpos.Y);
		printf("* ���� �˻� �Լ� *");
		screen(loginpos.X - 2, loginpos.Y + 5);
		printf("%s ���� �����Դϴ�.\n", retData->name);
		screen(loginpos.X - 2, loginpos.Y + 7);
		printf("���� �̸� : %s\n", retData->name);
		screen(loginpos.X - 2, loginpos.Y + 9);
		printf("���� ���� : %s\n", retData->birth);
		screen(loginpos.X - 2, loginpos.Y + 11);
		printf("�޴��� ��ȣ : %s\n", retData->phone_num);
		screen(loginpos.X - 6, loginpos.Y + 15);
		system("PAUSE");
	}

}
