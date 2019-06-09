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

void Print_staffinfo() {	// �޴� ����Ʈ

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

void Staff() {		// ���� ���� ����
	int menu;
	COORD tmp;

	while (1)
	{
		Print_staffMenu();

		menu=Ask_Menunum(&tmp);

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

void Insert_Staff() {		// ���� �߰� �Լ�

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	staff prev;

	pos_start.X = 6.0*onecols - 15;
	pos_start.Y = 3.75*onerows - 8;

	gotoxy(pos_start.X, pos_start.Y);
	printf("* ���� �߰� �Լ� *");
	gotoxy(pos_start.X-2, pos_start.Y + 5);
	printf("���� �̸� : ");
	gotoxy(pos_start.X+10, pos_start.Y + 5);
	scanf("%s", newname);
	Retrieve();

	if (retData!=NULL)
	{
		pos_start.X = 6.0*onecols;
		pos_start.Y = 3.75*onerows;
		system("cls");
		gotoxy(pos_start.X-15, pos_start.Y);
		printf("ERR :: �̹� ������ �����մϴ�.");				// �����޼��� ���
		//���������ϰ�� �����غ���
		gotoxy(pos_start.X-15, pos_start.Y+2);
		system("PAUSE");
	}
	else
	{
		people_num++;
		struct people *node = malloc(sizeof(struct people));
		strcpy(node->name, newname);
		gotoxy(pos_start.X-2, pos_start.Y + 7);
		printf("���� ���� : ");
		gotoxy(pos_start.X +10, pos_start.Y + 7);
		scanf("%s", node->birth);
		gotoxy(pos_start.X-4, pos_start.Y + 9);
		printf("�޴��� ��ȣ : ");
		gotoxy(pos_start.X + 10, pos_start.Y + 9);
		scanf("%s", node->phone_num);
		node->count = 3; //�ʱ�ī��Ʈ ����
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
	DrawCenterBox(50, 20);
	getcenter();

	pos_start.X = 6.0*onecols - 15;
	pos_start.Y = 3.75*onerows - 8;

	gotoxy(pos_start.X, pos_start.Y);
	printf("* ���� ���� �Լ� *");
	gotoxy(pos_start.X -11, pos_start.Y + 10);
	printf("������ ������ �̸��� �Է����ּ��� : ");
	gotoxy(pos_start.X + 25, pos_start.Y + 10);
	scanf("%s", newname);
	Retrieve();


	if (!retData)
	{
		pos_start.X = 6.0*onecols;
		pos_start.Y = 3.75*onerows;

		system("cls");
		gotoxy(pos_start.X - 15, pos_start.Y);
		printf("ERR :: ������ ������ �����ϴ�.");				// �����޼��� ���
		gotoxy(pos_start.X - 15, pos_start.Y + 2);
		system("PAUSE");
	}
	else {
		system("cls");
		DrawCenterBox(50, 20);
		getcenter();

		pos_start.X = 6.0*onecols - 15;
		pos_start.Y = 3.75*onerows - 8;

		gotoxy(pos_start.X, pos_start.Y);
		printf("* ���� ���� �Լ� *");
		gotoxy(pos_start.X-2, pos_start.Y+5);
		printf("%s�� �� �����Դϴ�.\n", retData->name);
		gotoxy(pos_start.X - 2, pos_start.Y + 7); 
		printf("���� �̸� : %s\n", retData->name);
		gotoxy(pos_start.X - 2, pos_start.Y + 9);
		printf("���� ���� : %s\n", retData->birth);
		gotoxy(pos_start.X - 2, pos_start.Y + 11);
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
	DrawCenterBox(50, 20);
	getcenter();

	pos_start.X = 6.0*onecols - 15;
	pos_start.Y = 3.75*onerows - 8;

	gotoxy(pos_start.X, pos_start.Y);
	printf("* ���� ���� �Լ� *");
	gotoxy(pos_start.X - 11, pos_start.Y + 10);
	printf("������ ������ �̸��� �Է����ּ��� : ");
	gotoxy(pos_start.X + 25, pos_start.Y + 10);
	scanf("%s", newname);
	Retrieve();

	if (!retData)
	{
		pos_start.X = 6.0*onecols;
		pos_start.Y = 3.75*onerows;

		system("cls");
		gotoxy(pos_start.X - 15, pos_start.Y);
		printf("ERR :: ������ ������ �����ϴ�.");				// �����޼��� ���
		gotoxy(pos_start.X - 15, pos_start.Y + 2);
		system("PAUSE");

	}
	else {
		system("cls");
		DrawCenterBox(50, 20);
		getcenter();

		pos_start.X = 6.0*onecols - 15;
		pos_start.Y = 3.75*onerows - 8;

		gotoxy(pos_start.X, pos_start.Y);
		printf("* ���� ���� �Լ� *");
		gotoxy(pos_start.X - 2, pos_start.Y + 5);
		printf("%s ���� �����Դϴ�.\n", retData->name);
		gotoxy(pos_start.X - 2, pos_start.Y + 7);
		printf("���� �̸� : %s\n", retData->name);
		gotoxy(pos_start.X - 2, pos_start.Y + 9);
		printf("���� ���� : %s\n", retData->birth);
		gotoxy(pos_start.X - 2, pos_start.Y + 11);
		printf("�޴��� ��ȣ : %s\n", retData->phone_num);


		if (Check() == 1) {
			system("cls");
			DrawCenterBox(50, 20);
			getcenter();

			pos_start.X = 6.0*onecols - 15;
			pos_start.Y = 3.75*onerows - 8;

			gotoxy(pos_start.X - 2, pos_start.Y + 7);
			printf("���� �̸� : ");
			gotoxy(pos_start.X +10, pos_start.Y + 7);
			scanf("%s", retData->name);
			gotoxy(pos_start.X - 2, pos_start.Y + 9);
			printf("���� ���� : ");
			gotoxy(pos_start.X +10, pos_start.Y + 9);
			scanf("%s", retData->birth);
			gotoxy(pos_start.X - 4, pos_start.Y + 11);
			printf("�޴��� ��ȣ : ");
			gotoxy(pos_start.X +10, pos_start.Y + 11);
			scanf("%s", retData->phone_num);
		}
		else
			return;
	}
}

void Retrieve_Staff() {		// ���� �˻� �Լ�

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	pos_start.X = 6.0*onecols - 15;
	pos_start.Y = 3.75*onerows - 8;

	gotoxy(pos_start.X, pos_start.Y);
	printf("* ���� �˻� �Լ� *");
	gotoxy(pos_start.X - 11, pos_start.Y + 10);
	printf("�˻��� ������ �̸��� �Է����ּ��� : ");
	gotoxy(pos_start.X + 25, pos_start.Y + 10);
	scanf("%s", newname);
	Retrieve();

	if (!retData)
	{
		pos_start.X = 6.0*onecols;
		pos_start.Y = 3.75*onerows;

		system("cls");
		gotoxy(pos_start.X - 15, pos_start.Y);
		printf("ERR :: ������ �������� �ʽ��ϴ�..");				// �����޼��� ���
		gotoxy(pos_start.X - 15, pos_start.Y + 2);
		system("PAUSE");
	}
	else {
		system("cls");
		DrawCenterBox(50, 20);
		getcenter();

		pos_start.X = 6.0*onecols - 15;
		pos_start.Y = 3.75*onerows - 8;

		gotoxy(pos_start.X, pos_start.Y);
		printf("* ���� �˻� �Լ� *");
		gotoxy(pos_start.X - 2, pos_start.Y + 5);
		printf("%s ���� �����Դϴ�.\n", retData->name);
		gotoxy(pos_start.X - 2, pos_start.Y + 7);
		printf("���� �̸� : %s\n", retData->name);
		gotoxy(pos_start.X - 2, pos_start.Y + 9);
		printf("���� ���� : %s\n", retData->birth);
		gotoxy(pos_start.X - 2, pos_start.Y + 11);
		printf("�޴��� ��ȣ : %s\n", retData->phone_num);
		gotoxy(pos_start.X - 6, pos_start.Y + 15);
		system("PAUSE");
	}

}
