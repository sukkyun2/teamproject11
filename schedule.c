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
	int top = 0, top1 = -1, day;
	int start, last;
	int **stack;
	int *stackTop;

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
	scanf("%d %d", &start, &last);
	system("cls");

	stack = (int**)malloc(sizeof(int*));
	stackTop = (int*)malloc(sizeof(int));
	for (int i = 0; i <= 25; i++)
	{
		if (retData->Schedule[day].outside_duty[i] == 1)					//�ߺ��Ǵ� �ܱ� �ð� üũ
		{

			stack[top] = (int*)malloc(sizeof(int));
			stack[top][++top1] = i;

			if (retData->Schedule[day].outside_duty[i + 1] != 1)
			{
				stackTop[top] = top1;
				top1 = -1;
				top++;
				stack = (int**)malloc(sizeof(int*));
			}
		}
	}
	screen(75, 23);
	for (int i = start; i <= last; i++)
	{
		if (retData->Schedule[day].outside_duty[i] == 1)
		{
			for (int j = 0;; j++)
			{
				if (stack[j][0] <= last && stack[j][0] >= start)
				{
					printf("*����* %d ~ %d �ô� �ܱ��� �̹� �����մϴ�. ( ���� �Ͻ� ��� ���� �ܱ��� �����˴ϴ�. )\n", stack[j][0], stack[j][stackTop[j]]);
					if (!Check())
						return;																	//���� ���ϰڴٰ� �� �� �޴��� ����
					break;
				}
			}
		}
	}
	for (int i = stack[0]; i < 24; i++)											//�ߺ��Ǵ� �ٰܱ� �̾����� �ð� ��� �ʱ�ȭ
	{
		if (retData->Schedule[day].outside_duty[i] != 1)
			break;
		retData->Schedule[day].outside_duty[i] == 0;
	}

	for (int i = start; i <= last; i++)									//�ܱٽð� �Է�
	{
		retData->Schedule[day].outside_duty[i] = 1;
		//�ܱ� �Է�
	}
	gotoxy(75, 23);
	printf("�ܱ� ������ �ԷµǾ����ϴ�.\n");

}		//�ܱ��Է�

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
		return;
		// Schedule���� ���ư���
	}

	system("cls");
	gotoxy(75, 23);
	printf("�ް� ��¥�� �Է����ּ��� ");
	gotoxy(111, 23);
	scanf("%d", &day);

	///�ܱ� �������� �ִµ� �ް��� ����ϴ� ��� 
	///->�ܱ� ���� ����� ���������� �ް��� �������

	for (int i = 0; i < 24; i++)
	{
		if (retData->Schedule[day].outside_duty[i] = 1)
		{
			gotoxy(78, 26);
			printf("%d�Ͽ� �ܱ� ������ �����մϴ� \n", day);
			Check();
			for (int j = 0; j < 24; j++)
			{
				retData->Schedule[day].outside_duty[i] = 0;
				/*�ܱ� ������ �������� �ް��� ���ڴٰ� �ϸ�
				 �ܱ� ������ ��� ��� ��Ų��. */
			}
			break;
		}
	}

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

void Print_Schedule()
{
	char search_name[10]; //�˻��� ������ �̸�

	int top = 0, top1 = -1, a = 0;

	int **stack;
	int *stackTop;
	int *stackDay;


	stack = (int**)malloc(sizeof(int*));
	stackTop = (int*)malloc(sizeof(int));

	system("cls");
	gotoxy(75, 23);
	printf("�ܱ���  �Է��� ������ �̸��� �Է����ּ��� :");
	gotoxy(111, 23);
	scanf("%s", search_name);  ///�����̸� ����
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(75, 23);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");				// �����޼��� ���
		gotoxy(75, 25);
		system("PAUSE");
	}

	printf("�ް� : ");
	for (int i = 0; i < 32; i++)
	{
		if (a == 3)
			break;

		if (retData->Schedule[i].day[0] == 1 && retData->Schedule[i].day[1] == 1)
		{
			if (retData->Schedule[i + 1].outside_duty[0] == 1 && retData->Schedule[i + 1].outside_duty[1] == 1)
			{
				printf("%d ~ %d", i, i + 1);
				a = a + 2;
				if (a != 3)
					printf(" , ");
			}
			else
			{
				printf("%d", i);
				a = a + 1;
				if (a != 3)
					printf(" , ");
			}
		}
	}
	printf("�� �ް��Դϴ�.\n\n");

	printf("���� : ");
	for (int i = 0; i < 32; i++)
	{
		if (retData->Schedule[i].day[0] != 1 && retData->Schedule[i].day[1] == 1)
			printf("%d ", i);

		if (retData->Schedule[i].day[0] == 1 && retData->Schedule[i].day[1] != 1)
			printf("%d ", i);
	}
	printf("�� �ݰ��Դϴ�.\n\n");


	a = -1;

	for (int day = 0; day < 32; day++)
	{
		printf("%d �� -> ", i);

		for (int i = 0; i <= 25; i++)
		{
			if (retData->Schedule[day].outside_duty[i] == 1)
			{
				stackDay = (int*)malloc(sizeof(int));
				stackDay[++a] = day;
				break;
			}
		}
	}
	printf("�ܱ� : ");
	for (int day = 0; day < a; day++)
	{
		printf("%d �� -> ", stackDay[day]);

		for (int i = 0; i <= 25; i++)
		{
			if (retData->Schedule[day].outside_duty[i] == 1)
			{

				stack[top] = (int*)malloc(sizeof(int));
				stack[top][++top1] = i;

				if (retData->Schedule[day].outside_duty[i + 1] != 1)
				{
					stackTop[top] = top1;
					top1 = -1;
					top++;
					stack = (int**)malloc(sizeof(int*));
				}
			}
		}
		for (int i = 0; i < sizeof(stack) / 4; i++)
		{
			printf("%d ~ %d �� ", stack[i][0], stack[i][stackTop[i]]);
			if ((i + 1) != sizeof(stack))
			{
				printf(" , ");
			}
		}
		printf("\n");
	}

}
