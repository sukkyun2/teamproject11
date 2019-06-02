#include "schedule.h"

void Print_scheduleinfo() {   // �޴� ����Ʈ

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


void Schedule() {      // ���� ���� ����
	int menu;
	COORD tmp;

	while (1)
	{
		system("cls");
		Print_scheduleSMenu();

		menu = Ask_Menunum(&tmp);

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


void Print_Insert_scheduleinfo() {   // �޴� ����Ʈ

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
		Print_Insert_scheduleSinfo();

		menu = Ask_Menunum(&tmp);
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
			PrintHomepage();
			break;
		}
	}

}


void Print_Delete_scheduleinfo() {   // �޴� ����Ʈ

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

		menu = Ask_Menunum(&tmp);

		switch (menu)
		{
		case 1:
			Delete_outside();
			break;
		case 2:
			Delete_vacation();
			break;
		case 3:
			PrintHomepage();
			break;
		}
	}
}

void Insert_outside()
{
	int top = 0, top1 = -1, day, tmp = 0;
	int start, last;
	int stack[30][24] = { 0, };
	int stackTop[30] = { 0, };


	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("�ܱ��� ������ �̸� :   ") / 2, pos_start.Y - 2);
	printf("�ܱ��� ������ �̸� :");
	gotoxy(pos_start.X + strlen("�ܱ��� ������ �̸� :") / 2, pos_start.Y - 2);
	scanf("%s", newname);  ///�����̸� ����
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
		DrawCenterBox(50, 20);
		getcenter();

		gotoxy(pos_start.X - strlen("�ܱ��� ��¥�� �Է����ּ��� : ") / 2, pos_start.Y - 2);
		printf("�ܱ��� ��¥�� �Է����ּ��� :  ");
		gotoxy(pos_start.X + strlen("�ܱ��� ��¥�� �Է����ּ��� :   ") / 2, pos_start.Y - 2);
		scanf("%d", &day);
		gotoxy(pos_start.X - strlen("�ܱ� �ð��� �Է����ּ��� :  ") / 2, pos_start.Y);
		printf("�ܱ� �ð��� �Է����ּ��� :  ");
		gotoxy(pos_start.X + strlen("�ܱ� �ð��� �Է����ּ��� : ") / 2, pos_start.Y);
		scanf("%d", &start);
		gotoxy(pos_start.X + strlen("�ܱ� �ð��� �Է����ּ��� : ") / 2 + 2, pos_start.Y);
		printf("~");
		scanf("%d", &last);


		for (int i = 0; i < 25; i++)
		{
			if (retData->Schedule[day].outside_duty[i] == 1)					// �ܱ� �ð� üũ
			{
				stack[top][++top1] = i;

				if (retData->Schedule[day].outside_duty[i + 1] != 1)
				{
					stackTop[top] = top1;
					top1 = -1;
					top++;
				}
			}
		}

		tmp = 0;
		for (int i = 0; i < top; i++)
		{
			for (int j = 0; j <= stackTop[i]; j++)
			{
				if (stack[i][j] >= start && stack[i][j] < last)
				{
					system("cls");
					gotoxy(pos_start.X - strlen("ERR :: %d ~ %d �ô� �ܱ��� �̹� �����մϴ�.") / 2, pos_start.Y - 5);
					printf("ERR :: %d ~ %d �ô� �ܱ��� �̹� �����մϴ�.", stack[j][0], stack[j][stackTop[j]]);            // �����޼��� ���
					gotoxy(pos_start.X - strlen("( ���� �Ͻ� ��� ���� �ܱ��� �����˴ϴ�. )") / 2, pos_start.Y - 3);
					printf("( ���� �Ͻ� ��� ���� �ܱ��� �����˴ϴ�. )");
					gotoxy(pos_start.X - strlen("ERR :: %d ~ %d �ô� �ܱ��� �̹� �����մϴ�.") / 2, pos_start.Y - 3);
					system("PAUSE");

					if (!Check())
						return;                                                   //���� ���ϰڴٰ� �� �� �޴��� ����
					tmp = 1;
					break;
				}
			}
			if (tmp == 1)
				break;
		}
		for (int i = 0; i < top; i++)
		{
			for (int j = 0; j <= stackTop[i]; j++)
			{
				if (stack[i][j] >= start && stack[i][j] < last)
				{
					for (tmp = 0; tmp <= stackTop[i]; tmp++)
					{
						retData->Schedule[day].outside_duty[stack[i][tmp]] = 0;
					}
					break;
				}
			}
		}
		for (int i = start; i < last; i++)									//�ܱٽð� �Է�
		{
			retData->Schedule[day].outside_duty[i] = 1;
			//�ܱ� �Է�
		}

		system("cls");
		gotoxy(pos_start.X - strlen(":: �ܱ� ������ �ԷµǾ����ϴ�.") / 2, pos_start.Y - 5);
		printf(":: �ܱ� ������ �ԷµǾ����ϴ�.");            // �����޼��� ���
		gotoxy(pos_start.X - strlen(":: �ܱ� ������ �ԷµǾ����ϴ�.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}

}

void Insert_day()
{

	int day;

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("�ް����� �߰��� ������ �̸� :   ") / 2, pos_start.Y - 2);
	printf("�ް����� �߰��� ������ �̸� : ");
	gotoxy(pos_start.X + strlen("�ް����� �߰��� ������ �̸� :  ") / 2, pos_start.Y - 2);
	scanf("%s", newname);  ///�����̸� ����
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: ������ �������� �ʽ��ϴ�.") / 2, pos_start.Y - 5);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");            // �����޼��� ���
		gotoxy(pos_start.X - strlen("ERR :: ������ �������� �ʽ��ϴ�.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}

	if (retData->count < 1)  //�ް� �ѵ��� �Ѿ�ٸ�
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: �ް� ��� ����Ƚ���� �ʰ��Ͽ����ϴ�.") / 2, pos_start.Y - 5);
		printf("ERR :: �ް� ��� ����Ƚ���� �ʰ��Ͽ����ϴ�.");            // �����޼��� ���
		gotoxy(pos_start.X - strlen("ERR :: �ް� ��� ����Ƚ���� �ʰ��Ͽ����ϴ�.") / 2, pos_start.Y - 3);
		system("PAUSE");

		return 0;
		// Schedule���� ���ư���
	}

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("�ް� ��¥�� �Է����ּ��� :   ") / 2, pos_start.Y - 2);
	printf("�ް� ��¥�� �Է����ּ��� : ");
	gotoxy(pos_start.X + strlen("�ް� ��¥�� �Է����ּ��� :   ") / 2, pos_start.Y - 2);
	scanf("%d", &day);

	///�ܱ� �������� �ִµ� �ް��� ����ϴ� ��� 
   ///->�ܱ� ���� ����� ���������� �ް��� �������

	for (int i = 0; i < 25; i++)
	{
		if (retData->Schedule[day].outside_duty[i] = 1)
		{
			gotoxy(pos_start.X - strlen("%d�Ͽ� �ܱ� ������ �����մϴ� ") / 2, pos_start.Y - 2);
			printf("%d�Ͽ� �ܱ� ������ �����մϴ� \n", day);
			Check();
			for (int j = 0; j < 25; j++)
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

	system("cls");
	gotoxy(pos_start.X - strlen(":: �ް� ������ �ԷµǾ����ϴ�.") / 2, pos_start.Y - 5);
	printf(":: �ް� ������ �ԷµǾ����ϴ�.");            // �����޼��� ���
	gotoxy(pos_start.X - strlen(":: �ް� ������ �ԷµǾ����ϴ�.") / 2, pos_start.Y - 3);
	system("PAUSE");

}

void Insert_moning_half()
{
	int front, rear, day;

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("�������� �߰��� ������ �̸� :   ") / 2, pos_start.Y - 2);
	printf("�������� �߰��� ������ �̸� : ");
	gotoxy(pos_start.X + strlen("�������� �߰��� ������ �̸� :   ") / 2, pos_start.Y - 2);
	scanf("%s", newname);  ///�����̸� ����
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: ������ �������� �ʽ��ϴ�.") / 2, pos_start.Y - 5);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");            // �����޼��� ���
		gotoxy(pos_start.X - strlen("ERR :: ������ �������� �ʽ��ϴ�.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("���� ��¥�� �Է����ּ��� :   ") / 2, pos_start.Y - 2);
	printf("���� ��¥�� �Է����ּ��� : ");
	gotoxy(pos_start.X + strlen("���� ��¥�� �Է����ּ��� :   ") / 2, pos_start.Y - 2);
	scanf("%d", &day);

	retData->Schedule[day].day[0] = 1;
	retData->Schedule[day].day[1] = 0;
	//���� �Է�
	retData->count = retData->count - 0.5;
	system("PAUSE");
}

void Insert_afternoon_half()
{
	int front, rear, day;

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("�������� �߰��� ������ �̸� :   ") / 2, pos_start.Y - 2);
	printf("�������� �߰��� ������ �̸� : ");
	gotoxy(pos_start.X + strlen("�������� �߰��� ������ �̸� :   ") / 2, pos_start.Y - 2);
	scanf("%s", newname);  ///�����̸� ����
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: ������ �������� �ʽ��ϴ�.") / 2, pos_start.Y - 5);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");            // �����޼��� ���
		gotoxy(pos_start.X - strlen("ERR :: ������ �������� �ʽ��ϴ�.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("���� ��¥�� �Է����ּ��� :   ") / 2, pos_start.Y - 2);
	printf("���� ��¥�� �Է����ּ��� : ");
	gotoxy(pos_start.X + strlen("���� ��¥�� �Է����ּ��� :   ") / 2, pos_start.Y - 2);
	scanf("%d", &day);

	retData->Schedule[day].day[0] = 0;
	retData->Schedule[day].day[1] = 1;
	//���� �Է�
	retData->count = retData->count - 0.5;
	system("PAUSE");

}

void Delete_outside()
{
	int top = 0, top1 = -1, day, tmp;
	int start, last;

	int stack[30][24] = { 0, };
	int stackTop[30] = { 0, };

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("�ܱ����� ������ ������ �̸� :   ") / 2, pos_start.Y - 2);
	printf("�ܱ����� ������ ������ �̸� : ");
	gotoxy(pos_start.X + strlen("�ܱ����� ������ ������ �̸� :   ") / 2, pos_start.Y - 2);
	scanf("%s", newname);  ///�����̸� ����
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: ������ �������� �ʽ��ϴ�.") / 2, pos_start.Y - 5);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");            // �����޼��� ���
		gotoxy(pos_start.X - strlen("ERR :: ������ �������� �ʽ��ϴ�.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}
	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("������ �ܱ� ��¥�� �Է����ּ��� :  ") / 2, pos_start.Y - 2);
	printf("������ �ܱ� ��¥�� �Է����ּ��� :  ");
	gotoxy(pos_start.X + strlen("������ �ܱ� ��¥�� �Է����ּ��� :   ") / 2, pos_start.Y - 2);
	scanf("%d", &day);

	for (int i = 0; i < 25; i++)
	{
		if (retData->Schedule[day].outside_duty[i] == 1)					//�ܱ� �ð� üũ
		{
			stack[top][++top1] = i;
			if (retData->Schedule[day].outside_duty[i + 1] != 1)
			{
				stackTop[top] = top1;
				top1 = -1;
				top++;
			}
		}
	}

	system("cls");
	for (int i = 0; i < top; i++)
	{
		gotoxy(pos_start.X - strlen("%d�� : %d�� ~ %d��") / 2, pos_start.Y - 2);
		printf("%d�� : %d�� ~ %d��\n", i + 1, stack[i][0], stack[i][stackTop[i]] + 1);
	}

	gotoxy(pos_start.X - strlen("� �ܱ��� ���� �Ͻðڽ��ϱ�?") / 2, pos_start.Y);
	printf("� �ܱ��� ���� �Ͻðڽ��ϱ�? : ");
	gotoxy(pos_start.X + strlen("� �ܱ��� ���� �Ͻðڽ��ϱ�?") / 2, pos_start.Y);
	scanf("%d", &tmp);
	for (int i = 0; i <= stackTop[i]; i++)
	{
		retData->Schedule[day].outside_duty[stack[tmp][i]] = 0;
	}

	system("cls");
	gotoxy(pos_start.X - strlen(":: �ܱ� ������ �����Ǿ����ϴ�.") / 2, pos_start.Y - 5);
	printf(":: �ܱ� ������ �����Ǿ����ϴ�.");            // �����޼��� ���
	gotoxy(pos_start.X - strlen(":: �ܱ� ������ �����Ǿ����ϴ�.") / 2, pos_start.Y - 3);
	system("PAUSE");
}

void Delete_vacation()
{
	int day;

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("�ް����� ������ ������ �̸� :   ") / 2, pos_start.Y - 2);
	printf("�ް����� �߰��� ������ �̸� : ");
	gotoxy(pos_start.X + strlen("�ް����� ������ ������ �̸� :  ") / 2, pos_start.Y - 2);
	scanf("%s", newname);  ///�����̸� ����
	Retrieve();


	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: ������ �������� �ʽ��ϴ�.") / 2, pos_start.Y - 5);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");            // �����޼��� ���
		gotoxy(pos_start.X - strlen("ERR :: ������ �������� �ʽ��ϴ�.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}


	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("������ �ް� ��¥�� �Է����ּ��� :   ") / 2, pos_start.Y - 2);
	printf("������ �ް� ��¥�� �Է����ּ��� : ");
	gotoxy(pos_start.X + strlen("������ �ް� ��¥�� �Է����ּ��� :   ") / 2, pos_start.Y - 2);
	scanf("%d", &day);

	if ((retData->Schedule[day].day[0] = 1) || (retData->Schedule[day].day[1] = 1))
	{
		if ((retData->Schedule[day].day[0] = 1) && (retData->Schedule[day].day[1] = 1))
		{
			retData->count = retData->count + 1;
		}
		else
		{
			retData->count = retData->count + 0.5;
		}

		retData->Schedule[day].day[0] = 0;
		retData->Schedule[day].day[1] = 0;
		system("cls");
		gotoxy(pos_start.X - strlen(":: �ް� ������ �����Ǿ����ϴ�.") / 2, pos_start.Y - 5);
		printf(":: �ް� ������ �����Ǿ����ϴ�.");            // �����޼��� ���
		gotoxy(pos_start.X - strlen(":: �ް� ������ �����Ǿ����ϴ�.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}
	else
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: �ް� ������ �������� �ʽ��ϴ�.") / 2, pos_start.Y - 5);
		printf("ERR :: �ް� ������ �������� �ʽ��ϴ�.");            // �����޼��� ���
		gotoxy(pos_start.X - strlen("ERR :: �ް� ������ �������� �ʽ��ϴ�.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}

}

void Print_Schedule()
{
	int top = 0, top1 = -1, day, tmp = 0;
	int start, last;
	int stack[30][24] = { 0, };
	int stackTop[30] = { 0, };
	int stackDay[32] = { 0, };


	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("�˻��� ������ �̸��� �Է����ּ��� : "), pos_start.Y - 1);
	printf("�˻��� ������ �̸��� �Է����ּ��� :");
	gotoxy(pos_start.X + strlen("�˻��� ������ �̸��� �Է����ּ��� : "), pos_start.Y - 1);
	scanf("%s", search_name);  ///�����̸� ����
	Retrieve();

	if (!retData)
	{
		system("cls");
		gotoxy(pos_start.X - strlen("ERR :: ������ �������� �ʽ��ϴ�.") / 2, pos_start.Y - 5);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");            // �����޼��� ���
		gotoxy(pos_start.X - strlen("ERR :: ������ �������� �ʽ��ϴ�.") / 2, pos_start.Y - 3);
		system("PAUSE");
	}


	printf("�ް� : ");
	for (int i = 1; i < 32; i++)
	{
		int j = 0; //��ǥ ���� ����
		if (tmp == 3)
			break;

		if (retData->Schedule[i].day[0] == 1 && retData->Schedule[i].day[1] == 1)
		{
			if (retData->Schedule[i + 1].outside_duty[0] == 1 && retData->Schedule[i + 1].outside_duty[1] == 1)
			{
				if (retData->Schedule[i + 2].outside_duty[0] == 1 && retData->Schedule[i + 2].outside_duty[1] == 1)
					//3�Ͽ������� �ް��� ����� ���
				{
					gotoxy(111, 23);
					printf("%d ~ %d ", i + 1, i + 3);
					tmp += 3;
					break;
				}
				else
				{
					gotoxy(111 + j, 23);
					printf("%d ~ %d", i, i + 1);
					tmp = tmp + 2;
					j += 2;
					if (tmp != 3)
					{
						gotoxy(111 + j, 23);
						printf(" , ");
						j += 2;
					}
				}
			}
			if (retData->Schedule[i + 1].outside_duty[0] != 1 && retData->Schedule[i + 1].outside_duty[1] != 1)
				//�Ϸ縸 �ް��� ����� ���
			{
				gotoxy(111 + j, 23);
				printf("%d", i);
				tmp = tmp + 1;
				j += 2;
				if (tmp != 3)
				{
					gotoxy(111 + j, 23);
					printf(" , ");
					j += 2;
				}
			}
		}

	}
	//�ް� ��� �Ϸ�

	printf("���� : ");
	for (int i = 0; i < 32; i++)
	{
		int j = 0; //��ǥ ���� ����
		if (retData->Schedule[i].day[0] != 1 && retData->Schedule[i].day[1] == 1)
		{
			gotoxy(111 + j, 25);
			printf("%d ", i);
			j += 2;
		}

		if (retData->Schedule[i].day[0] == 1 && retData->Schedule[i].day[1] != 1)
		{
			gotoxy(111 + j, 25);
			printf("%d ", i);
			j += 2;
		}
	}
	//�ݰ� ��� �Ϸ�


	tmp = -1;

	for (int day = 1; day < 32; day++)
	{
		for (int i = 0; i < 25; i++)
		{
			if (retData->Schedule[day].outside_duty[i] == 1)
			{
				stackDay[++tmp] = day;
				break;
			}
		}
	}

	gotoxy(75, 27);
	printf("�ܱ� : ");

	for (int day = 1; day < 32; day++)
	{

		if (stackDay[day] != 0)			//�ܱ� �ִ� ���� ����
		{
			int x = 0;//��ǥ ���� ����
			int y = 0;//��ǥ ���� ����

			gotoxy(111 + x, 27 + y);
			printf("%d�� -> ", stackDay[day]);

			top = 0;
			top1 = -1;

			for (int j = 0; j < 25; j++)
			{
				if (retData->Schedule[day].outside_duty[j] == 1)
				{
					stack[top][++top1] = day;

					if (retData->Schedule[day].outside_duty[j + 1] != 1)
					{
						stackTop[top] = top1;
						top1 = -1;
						top++;
					}
				}
			}					//�ܱ� ã�� ����

			for (int j = 0; j <= top; j++)
			{
				x += 5;
				gotoxy(111 + x, 27);
				printf("%d ~ %d �� ", stack[j][0], stack[j][stackTop[j]] + 1);
				if (j != top)
				{
					x += 2;
					printf(" , ");
				}
			}
			y += 2;
		}
	}

}