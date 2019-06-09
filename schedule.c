#include "schedule.h"

void Print_scheduleinfo() {	// �޴� ����Ʈ

	COORD tmp;
	char* scheduleMenuList[scheduleMenuNum] = {
	"�ް� �߰� �ϱ�",
	"�ް� ���� �ϱ�",
	"���θ޴��� ���ư���"
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


void Schedule() {		// ���� ���� ����
	int menu;
	COORD tmp;

	while (1) 
	{
		system("cls");
		Print_scheduleSMenu();

		menu=Ask_Menunum(&tmp);

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

void Print_Insert_scheduleSMenu()
{
	getform();
	DrawCenterBox(50, 20);

	PrintSideMenu_background();
	Print_Insert_scheduleinfo();
}

void Print_Insert_scheduleinfo() {	// �޴� ����Ʈ

	COORD tmp;
	char* scheduleMenuList[InsertscheduleMenuNum] = 
	{
	"�ܱ�",
	"�ް�",
	"���� �ݰ�",
	"���� �ݰ�",
	"�޴��� ���ư���"
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
		Print_staffMenu();

		menu=Ask_Menunum(&tmp);
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
			Select_Menu(); //�޴��� ���ư���
			break;
		}
	}

}

void Print_Delete_scheduleSMenu()
{
	getform();
	DrawCenterBox(50, 20);

	PrintSideMenu_background();
	Print_Delete_scheduleinfo();
}

void Print_Delete_scheduleinfo() {	// �޴� ����Ʈ

	COORD tmp;
	char* scheduleMenuList[DeletescheduleMenuNum] =
	{
	"�ܱ� ���� ����",
	"�ް�, �ݰ� ���� ����",
	"�޴��� ���ư���"
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

		menu=Ask_Menunum(&tmp);

		switch (menu)
		{
		case 1:
			Delete_outside();
			break;
		case 2:
			Delete_vacation();
			break;
		case 3:
			Select_Menu(); //�޴��� ���ư���
			break;
		}
	}
}

void Insert_outside()
{
	char search_name[10]; //�˻��� ������ �̸�
	int front, rear, day;

	system("cls");

	gotoxy(pos_start.X - 15, pos_start.Y);
	printf("�ܱ���  �Է��� ������ �̸��� �Է����ּ��� :");
	gotoxy(111, 23);
	scanf("%s", search_name);  ///�����̸� ����
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - 15, pos_start.Y);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");				// �����޼��� ���
		gotoxy(pos_start.X - 15, pos_start.Y + 2);
		system("PAUSE");
	}

	system("cls");
	gotoxy(75, 23);
	printf("�ܱ��� ��¥�� �Է����ּ��� ");
	gotoxy(111, 23);
	scanf("%d", &day);
	gotoxy(75, 25);
	printf("�ܱ� �ð��� �Է����ּ��� ");
	gotoxy(111, 25);
	scanf("%d %d", &front, &rear);
	system("cls");
	for (int i = front; i <= rear; i++)
	{
		if (retData->Schedule[day].outside_duty[i] = 1)
			///ȭ���� ���� �����ؼ� �������� �ۼ� --O
			///��ġ�� �������� �߰����� �� Ȯ���� ������
			//�̹� �������� ������ ��
		{
			gotoxy(75, 23);
			printf("�̹� ������ �����մϴ�");
			return 0;
		}
		retData->Schedule[day].outside_duty[i]=1; 
		//�ܱ� �Է�
	}
	gotoxy(75, 23);
	printf("�ܱ� ������ �ԷµǾ����ϴ�");

}

void Insert_day()
{
	char search_name[10]; //�˻��� ������ �̸�
	int day;
	system("cls");
	gotoxy(75, 23);
	printf("�ް��� �Է��� ������ �̸��� �Է����ּ��� :");
	gotoxy(111, 23);
	scanf("%s", search_name);  
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - 15, pos_start.Y);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");				// �����޼��� ���
		gotoxy(pos_start.X - 15, pos_start.Y + 2);
		system("PAUSE");
	}

	if (retData->count < 1)  //�ް� �ѵ��� �Ѿ�ٸ�
	{
		system("cls");
		gotoxy(75, 23);
		printf("�Ѵ� �ް� ��� ����Ƚ���� �ʰ��Ͽ����ϴ�");
		return 0; 
		// Schedule���� ���ư���
	}

	system("cls");
	gotoxy(75, 23);
	printf("�ް� ��¥�� �Է����ּ��� ");
	gotoxy(111, 23);
	scanf("%d", &day);

    ///�ܱ� �������� �ִµ� �ް��� ����ϴ� ��� 
	///->�ܱ� ���� ����� ���������� �ް��� �������
	
	retData->Schedule[day].day[0] = 1;
	retData->Schedule[day].day[1] = 1; 
	//�ް� �Է�
	retData->count = retData->count - 1;

}

void Insert_moning_half()
{
	char search_name[10]; //�˻��� ������ �̸�
	int front, rear, day;
	system("cls");
	gotoxy(75, 23);
	printf("������ �Է��� ������ �̸��� �Է����ּ��� :");
	gotoxy(111, 23);
	scanf("%s", search_name);
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - 15, pos_start.Y);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");				// �����޼��� ���
		gotoxy(pos_start.X - 15, pos_start.Y + 2);
		system("PAUSE");
	}

	system("cls");
	gotoxy(75, 23);
	printf("���� ��¥�� �Է����ּ��� ");
	gotoxy(111, 23);
	scanf("%d", &day);

	retData->Schedule[day].day[0] = 1;
	retData->Schedule[day].day[1] = 0;
	//���� �Է�
	retData->count = retData->count - 0.5;

}

void Insert_afternoon_half()
{
	char search_name[10]; //�˻��� ������ �̸�
	int front, rear, day;
	system("cls");
	gotoxy(75, 23);
	printf("������ �Է��� ������ �̸��� �Է����ּ��� :");
	gotoxy(111, 23);
	scanf("%s", search_name);
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - 15, pos_start.Y);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");				// �����޼��� ���
		gotoxy(pos_start.X - 15, pos_start.Y + 2);
		system("PAUSE");
	}

	system("cls");
	gotoxy(75, 23);
	printf("���� ��¥�� �Է����ּ��� ");
	gotoxy(111, 23);
	scanf("%d", &day);

	retData->Schedule[day].day[0] = 0;
	retData->Schedule[day].day[1] = 1;
	//���� �Է�
	retData->count = retData->count - 0.5;

}

void Delete_outside()
{
	char search_name[10]; //�˻��� ������ �̸�
	int front, rear, day;
	system("cls");
	gotoxy(75, 23);
	printf("�ܱ���  �Է��� ������ �̸��� �Է����ּ��� :");
	scanf("%s", search_name);
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - 15, pos_start.Y);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");				// �����޼��� ���
		gotoxy(pos_start.X - 15, pos_start.Y + 2);
		system("PAUSE");
	}
	system("cls");
	gotoxy(75, 23);
	printf("������ �ܱ� ��¥�� �Է����ּ��� ");
	gotoxy(111, 23);
	scanf("%d", &day);
	gotoxy(75, 25);
	printf("������ �ܱ� �ð��� �Է����ּ��� ");
	gotoxy(111, 23);
	scanf("%d %d", &front, &rear);
	///delete�Լ��� ����Ѵٸ� �� ��¥�� �ܱ� ������ ���� �����ϴ� ��� x
    ///�ð��� �Է����� �ʰ� 1�� 2�� ������ �Է¹޾Ƽ� �����ϴ¹�� -> ���Ǽ� ������
	for (int i = front; i <= rear; i++)
	{
		retData->Schedule[day].outside_duty[i] = 0;
		//�ܱ� �Է�
	}
	printf("�ܱ� ������ ���� �Ǿ����ϴ�");
}

void Delete_vacation()
{
	char search_name[10]; //�˻��� ������ �̸�
	int day;
	system("cls");
	gotoxy(75, 23);
	printf("�ް��� ������ ������ �̸��� �Է����ּ��� :");
	gotoxy(111, 23);
	scanf("%s", search_name);
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - 15, pos_start.Y);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");				// �����޼��� ���
		gotoxy(pos_start.X - 15, pos_start.Y + 2);
		system("PAUSE");
	}

	system("cls");
	gotoxy(75, 23);
	printf("�ް� ��¥�� �Է����ּ��� ");
	gotoxy(111, 23);
	scanf("%d", &day);

	if ((retData->Schedule[day].day[0] = 1) || (retData->Schedule[day].day[1] = 1))
	{
		retData->Schedule[day].day[0] = 0;
		retData->Schedule[day].day[1] = 0;
		if ((retData->Schedule[day].day[0] = 1) && (retData->Schedule[day].day[1] = 1))
		{
			retData->count = retData->count + 1;
		}
		else
		retData->count = retData->count + 0.5;
		system("cls");
		gotoxy(75, 23);
		printf("�ް��� ���� �Ǿ����ϴ�.");
	}
	else
	{
		system("cls");
		gotoxy(75, 23);
		printf("�ް� ������ �������� �ʽ��ϴ�");
		
	}
	
}

