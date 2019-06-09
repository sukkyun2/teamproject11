#include "staff.h"

// ����
extern staff head = NULL;
extern int people_num = 0;

// �Լ�
void Print_staffMenu()
{
	getform();
	PrinttodayCalendar();

	PrintSideMenu_background();
	Print_staffinfo();
}

void Print_staffinfo() {   // �޴� ����Ʈ

	COORD tmp;
	char* staffMenuList[staffMenuNum] = {
	"���� �߰�",
	"���� ����",
	"���� ����",
	"���� �˻�",
	"���θ޴��� ���ư���"
	};
	int i;

	print_askMenunum(&tmp);

	for (i = 0; i < staffMenuNum; i++)
	{
		tmp.Y += 2;
		gotoxy(tmp.X, tmp.Y);
		printf("%d. %s", i + 1, staffMenuList[i]);
	}
}

void Staff() {      // ���� ���� ����
	int menu;
	COORD tmp;

	while (1)
	{
		Print_staffMenu();

		menu = Ask_Menunum(&tmp);

		switch (menu)
		{
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

void Insert_Staff() {      // ���� �߰� �Լ�

	system("cls");
	DrawUI(50, 20);
	getcenter();

	staff prev;

	gotoxy(pos_start.X - strlen("* ���� �߰� �Լ� *") / 2, pos_start.Y - 12);
	printf("* ���� �߰� �Լ� *");
	gotoxy(pos_start.X - 10, pos_start.Y - 5);
	printf("���� �̸� : ");
	gotoxy(pos_start.X + 2, pos_start.Y - 5);
	scanf("%s", newname);
	Retrieve();

	if (retData != NULL)
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: �̹� ������ �����մϴ�.") / 2, pos_start.Y - 5);
		printf("ERR :: �̹� ������ �����մϴ�.");            // �����޼��� ���
		//���������ϰ�� �����غ���
		gotoxy(pos_start.X - strlen("ERR :: �̹� ������ �����մϴ�.") / 2, pos_start.Y - 3);
		system("PAUSE");
		system("cls");
	}
	else
	{
		people_num++;
		staff node = malloc(sizeof(struct people));
		strcpy(node->name, newname);
		gotoxy(pos_start.X - 10, pos_start.Y - 3);
		printf("���� ���� : ");
		gotoxy(pos_start.X + 2, pos_start.Y - 3);
		scanf("%s", node->birth);
		gotoxy(pos_start.X - 12, pos_start.Y - 1);
		printf("�޴��� ��ȣ : ");
		gotoxy(pos_start.X + 2, pos_start.Y - 1);
		scanf("%s", node->phone_num);

		

		node->Schedule = (struct Schedule*)malloc(sizeof(struct Schedule) * 32);
		node->count = 3; //���� �ʱ�ī��Ʈ ����
		node->WCount = 0; //�ٹ� �ʱ�ī��Ʈ ����

		for (int i = 0; i < 32; i++)
		{
			for (int j = 0; j < 24; j++)
			{
				node->Schedule[i].outside_duty[j] = 0;
			}
			for (int j = 0; j < 2; j++)
			{
				node->Schedule[i].work_schedule[j] = 0;
				node->Schedule[i].day[j] = 0;
			}
		}

		node->next = NULL;
		system("cls");

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

void Delete_Staff() {      // ���� ���� �Լ�
	staff node;
	node = head;

	system("cls");
	DrawUI(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("* ���� ���� �Լ� *") / 2, pos_start.Y - 12);
	printf("* ���� ���� �Լ� *");
	gotoxy(pos_start.X - 15, pos_start.Y - 1);
	printf("������ ������ �̸� : ");
	gotoxy(pos_start.X + 6, pos_start.Y - 1);
	scanf("%s", newname);
	Retrieve();


	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: ������ �������� �ʽ��ϴ�.") / 2, pos_start.Y - 5);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");            // �����޼��� ���
		gotoxy(pos_start.X - strlen("ERR :: ������ �������� �ʽ��ϴ�.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}
	else {
		system("cls");
		DrawUI(50, 20);
		getcenter();

		gotoxy(pos_start.X - strlen("* ���� ���� �Լ� *") / 2, pos_start.Y - 12);
		printf("* ���� ���� �Լ� *");
		gotoxy(pos_start.X - strlen("* õ���� ���� �����Դϴ�. *") / 2, pos_start.Y - 6);
		printf("* %s���� �����Դϴ�. *", retData->name);
		gotoxy(pos_start.X - 10, pos_start.Y - 3);
		printf("���� �̸� : %s\n", retData->name);
		gotoxy(pos_start.X - 10, pos_start.Y - 1);
		printf("���� ���� : %s\n", retData->birth);
		gotoxy(pos_start.X - 12, pos_start.Y + 1);
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
	system("cls");
}

void Change_Staff() {      // ���� ���� �Լ�

	system("cls");
	DrawUI(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("* ���� ���� �Լ� *") / 2, pos_start.Y - 12);
	printf("* ���� ���� �Լ� *");
	gotoxy(pos_start.X - 15, pos_start.Y - 1);
	printf("������ ������ �̸� : ");
	gotoxy(pos_start.X + 6, pos_start.Y - 1);
	scanf("%s", newname);
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: ������ �������� �ʽ��ϴ�.") / 2, pos_start.Y - 5);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");            // �����޼��� ���
		gotoxy(pos_start.X - strlen("ERR :: ������ �������� �ʽ��ϴ�.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}
	else {
		system("cls");
		DrawUI(50, 20);
		getcenter();

		gotoxy(pos_start.X - strlen("* ���� ���� �Լ� *") / 2, pos_start.Y - 12);
		printf("* ���� ���� �Լ� *");
		gotoxy(pos_start.X - strlen("* õ���� ���� �����Դϴ�. *") / 2, pos_start.Y - 6);
		printf("* %s���� �����Դϴ�. *", retData->name);
		gotoxy(pos_start.X - 10, pos_start.Y - 3);
		printf("���� �̸� : %s\n", retData->name);
		gotoxy(pos_start.X - 10, pos_start.Y - 1);
		printf("���� ���� : %s\n", retData->birth);
		gotoxy(pos_start.X - 12, pos_start.Y + 1);
		printf("�޴��� ��ȣ : %s\n", retData->phone_num);

		if (Check() == 1) {
			system("cls");
			DrawUI(50, 20);
			getcenter();

			gotoxy(pos_start.X - strlen("* ���� ���� �Լ� *") / 2, pos_start.Y - 12);
			printf("* ���� ���� �Լ� *");
			gotoxy(pos_start.X - 10, pos_start.Y - 3);
			printf("���� �̸� : \n");
			gotoxy(pos_start.X + 2, pos_start.Y - 3);
			scanf("%s", retData->name);
			gotoxy(pos_start.X - 10, pos_start.Y - 1);
			printf("���� ���� : \n");
			gotoxy(pos_start.X + 2, pos_start.Y - 1);
			scanf("%s", retData->birth);
			gotoxy(pos_start.X - 12, pos_start.Y + 1);
			printf("�޴��� ��ȣ : \n");
			gotoxy(pos_start.X + 2, pos_start.Y + 1);
			scanf("%s", retData->phone_num);
		}
		else
			return;
	}
	system("cls");
}

void Retrieve_Staff() {      // ���� �˻� �Լ�

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
		printf("ERR :: ������ �������� �ʽ��ϴ�.");            // �����޼��� ���
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
		printf("* %s���� �����Դϴ�. *", retData->name);
		gotoxy(pos_start.X - 10, pos_start.Y - 3);
		printf("���� �̸� : %s\n", retData->name);
		gotoxy(pos_start.X - 10, pos_start.Y - 1);
		printf("���� ���� : %s\n", retData->birth);
		gotoxy(pos_start.X - 12, pos_start.Y + 1);
		printf("�޴��� ��ȣ : %s\n", retData->phone_num);

		gotoxy(pos_start.X - 18, pos_start.Y + 5);
		system("PAUSE");
	}
	system("cls");
}