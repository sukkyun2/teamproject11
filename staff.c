#pragma once

#include "staff.h"
#include "menu.h"

typedef struct people *staff;
staff head = NULL;
staff retData;
char newname[10];
int people_num = 0;

void Staff() {		// ���� ���� ����
	int menu;

	while (1) {
		Print_Staff_Menu();
		screen(163, 7);
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
			Select_Menu();
			break;
		}
	}
}

int Check()
{
	char check[5];
	screen(78, 28);
	printf("�����Ͻðڽ��ϱ� ? [Yes Or No] : \n ");
	screen(111, 28);
	scanf("%s", check);
	if (strcmp(check, "Yes") == 0)
		return 1;
	else
		return 0;
}

void Print_Staff_Menu() {	// ���� �޴� ���

	system("cls");

	screen(135, 7);
	printf("�޴� ��ȣ�� �Է����ּ��� : ");
	screen(135, 9);
	printf("1. ���� �߰� �ϱ�");
	screen(135, 11);
	printf("2. ���� ���� �ϱ�");
	screen(135, 13);
	printf("3. ���� ���� �ϱ�");
	screen(135, 15);
	printf("4. ���� �˻� �ϱ�");
	screen(135, 17);
	printf("5. ���θ޴��� ���ư���");
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
	staff prev;
	
	screen(78, 22);
	printf("���� �̸� : ");
	screen(90, 22);
	scanf("%s", newname);
	Retrieve();

	if (retData!=NULL)
	{
		system("cls");
		screen(75, 23);
		printf("ERR :: �̹� ������ �����մϴ�.");				// �����޼��� ���
		screen(75, 25);
		system("PAUSE");
	}
	else
	{
		people_num++;
		struct people *node = malloc(sizeof(struct people));
		strcpy(node->name, newname);
		screen(78, 24);
		printf("���� ���� : ");
		screen(90, 24);
		scanf("%s", node->birth);
		screen(76, 26);
		printf("�޴��� ��ȣ : ");
		screen(90, 26);
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
	screen(75, 23);
	printf("������ ������ �̸��� �Է����ּ��� : ");
	screen(111, 23);
	scanf("%s", newname);
	Retrieve();

	if (!retData)
	{
		system("cls");
		screen(75, 23);
		printf("ERR :: ������ ������ �����ϴ�.");				// �����޼��� ���
		screen(75, 25);
		system("PAUSE");
	}
	else {
		system("cls");
		screen(78, 20);
		printf("%s�� �����Դϴ�.\n", retData->name);
		screen(78, 22);
		printf("���� �̸� : %s\n", retData->name);
		screen(78, 24);
		printf("���� ���� : %s\n", retData->birth);
		screen(78, 26);
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
	screen(75, 23);
	printf("������ ������ �̸��� �Է����ּ��� : ");
	screen(111, 23);
	scanf("%s", newname);
	Retrieve();

	if (!retData)
	{
		system("cls");
		screen(75, 23);
		printf("ERR :: ������ ������ �����ϴ�.");				// �����޼��� ���
		screen(75, 25);
		system("PAUSE");
	}
	else {
		system("cls");
		screen(78, 20);
		printf("%s�� �����Դϴ�.\n", retData->name);
		screen(78, 22);
		printf("���� �̸� : %s\n", retData->name);
		screen(78, 24);
		printf("���� ���� : %s\n", retData->birth);
		screen(78, 26);
		printf("�޴��� ��ȣ : %s\n", retData->phone_num);

		if (Check() == 1) {
			system("cls");
			screen(78, 22);
			printf("���� �̸� : ");
			screen(90, 22);
			scanf("%s", retData->name);
			screen(78, 24);
			printf("���� ���� : ");
			screen(90, 24);
			scanf("%s", retData->birth);
			screen(76, 26);
			printf("�޴��� ��ȣ : ");
			screen(90, 26);
			scanf("%s", retData->phone_num);
		}
		else
			return;
	}
}

void Retrieve_Staff() {		// ���� �˻� �Լ�
	system("cls");
	screen(75, 23);
	printf("�˻��� ������ �̸��� �Է����ּ��� : ");
	screen(111, 23);
	scanf("%s", newname);
	Retrieve();

	if (!retData)
	{
		system("cls");
		screen(75, 23);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");				// �����޼��� ���
		screen(75, 25);
		system("PAUSE");
	}
	else {
		system("cls");
		screen(78, 20);
		printf("%s�� �����Դϴ�.\n", retData->name);
		screen(78, 22);
		printf("���� �̸� : %s\n", retData->name);
		screen(78, 24);
		printf("���� ���� : %s\n", retData->birth);
		screen(78, 26);
		printf("�޴��� ��ȣ : %s\n", retData->phone_num);
		screen(78, 28);
		system("PAUSE");
	}

}
