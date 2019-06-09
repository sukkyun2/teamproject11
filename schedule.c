#define _CRT_SECURE_NO_WARNINGS

#include "schedule.h"
#include "login.h"

void Print_scheduleinfo() {   // �޴� ����Ʈ

	COORD tmp;
	char* scheduleMenuList[scheduleMenuNum] = {
		"�ް� �߰� �ϱ�",
		"�ް� ���� �ϱ�",
		"���� ���� ���",
		"���θ޴��� ���ư���"
	};
	int i;
	tmp.X = pos_start.X + 3;	tmp.Y = pos_start.Y + 2;
	print_askMenunum();

	for (i = 0; i < scheduleMenuNum; i++)
	{
		tmp.Y += 2;
		gotoxy(tmp.X, tmp.Y);
		printf("%d. %s", i + 1, scheduleMenuList[i]);
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

	tmp.X = pos_start.X + 3;	tmp.Y = pos_start.Y + 2;
	print_askMenunum();

	for (i = 0; i < InsertscheduleMenuNum; i++)
	{
		tmp.Y += 2;
		gotoxy(tmp.X, tmp.Y);
		printf("%d. %s", i + 1, scheduleMenuList[i]);
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

	tmp.X = pos_start.X + 3;	tmp.Y = pos_start.Y + 2;
	print_askMenunum();

	for (i = 0; i < DeletescheduleMenuNum; i++)
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

		menu = Ask_Menunum();

		switch (menu)
		{
		case 1:
			Insert_Schedule();
			break;
		case 2:
			Delete_Schedule();
			break;
		case 3:
			Print_Schedule();
			break;
		case 4:
			PrintHomepage();
			break;
		}
	}
}

void Insert_Schedule()
{
	COORD tmp;

	int menu;
	while (1)
	{
		system("COLOR 07");
		Print_Insert_scheduleSMenu();

		menu = Ask_Menunum();
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
			Schedule();
			break;
		}
	}

}

void Delete_Schedule()
{
	int menu;
	COORD tmp;


	while (1)
	{
		system("COLOR 07");
		Print_Delete_scheduleSMenu();

		menu = Ask_Menunum();

		switch (menu)
		{
		case 1:
			Delete_outside();
			break;
		case 2:
			Delete_vacation();
			break;
		case 3:
			Schedule();
			break;
		}
	}
}


void Insert_outside()
{
	system("COLOR F0");

	int top = 0, top1 = -1, day, tmp = 0;
	int start, last;
	int stack[30][24] = { 0, };
	int stackTop[30] = { 0, };

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("�ܱ�.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);

	gotoxy(pos_start.X - strlen("�ܱ��� ������ �̸� :   ") / 2, pos_start.Y - 2);
	printf("�ܱ��� ������ �̸� :");
	gotoxy(pos_start.X + strlen("�ܱ��� ������ �̸� :") / 2, pos_start.Y - 2);
	scanf("%s", newname);  ///�����̸� ����
	Retrieve();

	if (!retData)
	{
		MessageBox(NULL, TEXT("������ �������� �ʽ��ϴ�."), TEXT("ERR"), MB_OK | MB_ICONSTOP);
	}
	else {
		system("cls");
		DrawCenterBox(50, 20);
		getcenter();

		hImage = (HBITMAP)LoadImage(NULL, TEXT("�ܱ�.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		print_menuimage(hImage);

		gotoxy(pos_start.X - strlen("�ܱ��� ��¥�� �Է����ּ��� : ") / 2, pos_start.Y - 4);
		printf("�ܱ��� ��¥�� �Է����ּ��� :  ");
		gotoxy(pos_start.X - strlen("* ex ) �̹� ���� 15�� -> 15 *") / 2, pos_start.Y - 2);
		printf("* ex ) �̹� ���� 15�� -> 15 *");
		gotoxy(pos_start.X + strlen("�ܱ��� ��¥�� �Է����ּ��� :   ") / 2, pos_start.Y - 4);
		scanf("%d", &day);

		gotoxy(pos_start.X - strlen("�ܱ� �ð��� �Է����ּ��� :  ") / 2, pos_start.Y);
		printf("�ܱ� �ð��� �Է����ּ��� :  ");
		gotoxy(pos_start.X + strlen("�ܱ� �ð��� �Է����ּ��� : ") / 2, pos_start.Y);
		scanf("%d", &start);
		gotoxy(pos_start.X + strlen("�ܱ� �ð��� �Է����ּ��� : ") / 2 + 2, pos_start.Y);
		printf(" ~ ");
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
					DrawCenterBox(50, 20);
					getcenter();

					hImage = (HBITMAP)LoadImage(NULL, TEXT("�ܱ�.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
					print_menuimage(hImage);

					gotoxy(pos_start.X - strlen("ERR :: %d ~ %d �ô� �ܱ��� �̹� �����մϴ�.") / 2, pos_start.Y - 3);
					printf("ERR :: %d ~ %d �ô� �ܱ��� �̹� �����մϴ�.", start, last);            // �����޼��� ���
					gotoxy(pos_start.X - strlen("( ���� �Ͻ� ��� ���� �ܱ��� �����˴ϴ�. )") / 2, pos_start.Y - 1);
					printf("( ���� �Ͻ� ��� ���� �ܱ��� �����˴ϴ�. )");

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
		}					//�ߺ��ܱ� �ʱ�ȭ

		for (int i = start; i < last; i++)									//�ܱٽð� �Է�
		{
			retData->Schedule[day].outside_duty[i] = 1;			//�ܱ� �Է�
		}
		MessageBox(NULL, TEXT("�ܱ� ������ �ԷµǾ����ϴ�."), TEXT("Check"), MB_OK | MB_ICONINFORMATION);
	}
}

void Insert_day()
{
	system("COLOR F0");

	int day;

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("�ް�.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);

	gotoxy(pos_start.X - strlen("�ް����� �߰��� ������ �̸� :   ") / 2, pos_start.Y - 2);
	printf("�ް����� �߰��� ������ �̸� : ");
	gotoxy(pos_start.X + strlen("�ް����� �߰��� ������ �̸� :  ") / 2, pos_start.Y - 2);
	scanf("%s", newname);  ///�����̸� ����
	Retrieve();

	if (!retData) {
		MessageBox(NULL, TEXT("������ �������� �ʽ��ϴ�."), TEXT("ERR"), MB_OK | MB_ICONSTOP);
		return 0;
	}
	if (retData->count < 1) {  //�ް� �ѵ��� �Ѿ�ٸ�
		MessageBox(NULL, TEXT("�ް� ��� ����Ƚ���� �ʰ��Ͽ����ϴ�."), TEXT("ERR"), MB_OK | MB_ICONSTOP);
		return 0;					// Schedule���� ���ư���
	}

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("�ް�.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);


	gotoxy(pos_start.X - strlen("�ް� ��¥�� �Է����ּ��� :   ") / 2, pos_start.Y - 2);
	printf("�ް� ��¥�� �Է����ּ��� : ");
	gotoxy(pos_start.X - strlen("* ex ) �̹� ���� 15�� -> 15 *") / 2, pos_start.Y);
	printf("* ex ) �̹� ���� 15�� -> 15 *");
	gotoxy(pos_start.X + strlen("�ް� ��¥�� �Է����ּ��� :   ") / 2, pos_start.Y - 2);
	scanf("%d", &day);

	///�ܱ� �������� �ִµ� �ް��� ����ϴ� ��� 
	///->�ܱ� ���� ����� ���������� �ް��� �������

	for (int i = 0; i < 25; i++)
	{
		if (retData->Schedule[day].outside_duty[i] == 1)
		{
			system("cls");
			DrawCenterBox(50, 20);
			getcenter();

			hImage = (HBITMAP)LoadImage(NULL, TEXT("�ް�.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
			print_menuimage(hImage);

			gotoxy(pos_start.X - strlen("%d�Ͽ� �ܱ� ������ �����մϴ�.") / 2, pos_start.Y - 3);
			printf("%d�Ͽ� �ܱ� ������ �����մϴ�.\n", day);
			gotoxy(pos_start.X - strlen("( ���� �Ͻ� ��� ���� �ܱ��� �����˴ϴ�. )") / 2, pos_start.Y - 1);

			printf("( ���� �Ͻ� ��� ���� �ܱ��� �����˴ϴ�. )");

			if (!Check())
				return;

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

	MessageBox(NULL, TEXT("�ް� ������ �ԷµǾ����ϴ�."), TEXT("Check"), MB_OK | MB_ICONINFORMATION);

}

void Insert_moning_half()
{
	system("COLOR F0");

	int front, rear, day;

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("����.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);


	gotoxy(pos_start.X - strlen("�������� �߰��� ������ �̸� :  ") / 2, pos_start.Y - 2);
	printf("�������� �߰��� ������ �̸� : ");
	gotoxy(pos_start.X + strlen("�������� �߰��� ������ �̸� :  ") / 2, pos_start.Y - 2);
	scanf("%s", newname);  ///�����̸� ����
	Retrieve();

	if (!retData)
	{
		MessageBox(NULL, TEXT("������ �������� �ʽ��ϴ�."), TEXT("ERR"), MB_OK | MB_ICONSTOP);
		return 0;
	}


	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("����.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);

	gotoxy(pos_start.X - strlen("���� ��¥�� �Է����ּ��� :   ") / 2, pos_start.Y - 2);
	printf("���� ��¥�� �Է����ּ��� : ");
	gotoxy(pos_start.X - strlen("* ex ) �̹� ���� 15�� -> 15 *") / 2, pos_start.Y);
	printf("* ex ) �̹� ���� 15�� -> 15 *");
	gotoxy(pos_start.X + strlen("���� ��¥�� �Է����ּ��� :   ") / 2, pos_start.Y - 2);
	scanf("%d", &day);

	retData->Schedule[day].day[0] = 1;
	retData->Schedule[day].day[1] = 0;
	//���� �Է�
	retData->count = retData->count - 0.5;

	MessageBox(NULL, TEXT("���� ������ �ԷµǾ����ϴ�."), TEXT("Check"), MB_OK | MB_ICONINFORMATION);
}

void Insert_afternoon_half()
{
	system("COLOR F0");

	int front, rear, day;


	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("����.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);

	gotoxy(pos_start.X - strlen("�������� �߰��� ������ �̸� :   ") / 2, pos_start.Y - 2);
	printf("�������� �߰��� ������ �̸� : ");
	gotoxy(pos_start.X + strlen("�������� �߰��� ������ �̸� :   ") / 2, pos_start.Y - 2);
	scanf("%s", newname);  ///�����̸� ����
	Retrieve();

	if (!retData)
	{
		MessageBox(NULL, TEXT("������ �������� �ʽ��ϴ�."), TEXT("ERR"), MB_OK | MB_ICONSTOP);
		return 0;
	}


	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("����.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);

	gotoxy(pos_start.X - strlen("���� ��¥�� �Է����ּ��� :   ") / 2, pos_start.Y - 2);
	printf("���� ��¥�� �Է����ּ��� : ");
	gotoxy(pos_start.X - strlen("* ex ) �̹� ���� 15�� -> 15 *") / 2, pos_start.Y);
	printf("* ex ) �̹� ���� 15�� -> 15 *");
	gotoxy(pos_start.X + strlen("���� ��¥�� �Է����ּ��� :   ") / 2, pos_start.Y - 2);
	scanf("%d", &day);

	retData->Schedule[day].day[0] = 0;
	retData->Schedule[day].day[1] = 1;
	//���� �Է�
	retData->count = retData->count - 0.5;

	MessageBox(NULL, TEXT("���� ������ �ԷµǾ����ϴ�."), TEXT("Check"), MB_OK | MB_ICONINFORMATION);
}

void Delete_outside()
{
	system("COLOR F0");

	int top = 0, top1 = -1, day, tmp;
	int start, last;

	int stack[30][24] = { 0, };
	int stackTop[30] = { 0, };

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("�ܱ�.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);

	gotoxy(pos_start.X - strlen("�ܱ����� ������ ������ �̸� :   ") / 2, pos_start.Y - 2);
	printf("�ܱ����� ������ ������ �̸� : ");
	gotoxy(pos_start.X + strlen("�ܱ����� ������ ������ �̸� :   ") / 2, pos_start.Y - 2);
	scanf("%s", newname);  ///�����̸� ����
	Retrieve();

	if (!retData)
	{
		MessageBox(NULL, TEXT("������ �������� �ʽ��ϴ�."), TEXT("ERR"), MB_OK | MB_ICONSTOP);
		return 0;
	}
	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("�ܱ�.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);


	gotoxy(pos_start.X - strlen("������ �ܱ� ��¥�� �Է����ּ��� :  ") / 2, pos_start.Y - 2);
	printf("������ �ܱ� ��¥�� �Է����ּ��� :  ");
	gotoxy(pos_start.X - strlen("* ex ) �̹� ���� 15�� -> 15 *") / 2, pos_start.Y);
	printf("* ex ) �̹� ���� 15�� -> 15 *");
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
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("�ܱ�.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);

	for (int i = 0; i < top; i++)
	{
		gotoxy(pos_start.X - strlen("%d�� : %d�� ~ %d��") / 2, pos_start.Y - 2);
		printf("%d�� : %d�� ~ %d��\n", i + 1, stack[i][0], stack[i][stackTop[i]] + 1);
	}

	gotoxy(pos_start.X - strlen("� �ܱ��� ���� �Ͻðڽ��ϱ�?") / 2, pos_start.Y);
	printf("� �ܱ��� ���� �Ͻðڽ��ϱ�? : ");
	gotoxy(pos_start.X + strlen("� �ܱ��� ���� �Ͻðڽ��ϱ�?") / 2 + 3, pos_start.Y);
	scanf("%d", &tmp);

	for (int i = 0; i <= stackTop[tmp - 1]; i++)
	{
		retData->Schedule[day].outside_duty[stack[tmp - 1][i]] = 0;
	}

	MessageBox(NULL, TEXT("�ܱ� ������ �����Ǿ����ϴ�."), TEXT("Check"), MB_OK | MB_ICONINFORMATION);
}

void Delete_vacation()
{
	system("COLOR F0");

	int day;

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("�ް�.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);


	gotoxy(pos_start.X - strlen("�ް����� ������ ������ �̸� :   ") / 2, pos_start.Y - 2);
	printf("�ް����� �߰��� ������ �̸� : ");
	gotoxy(pos_start.X + strlen("�ް����� ������ ������ �̸� :  ") / 2, pos_start.Y - 2);
	scanf("%s", newname);  ///�����̸� ����
	Retrieve();

	if (!retData)
	{
		MessageBox(NULL, TEXT("������ �������� �ʽ��ϴ�."), TEXT("ERR"), MB_OK | MB_ICONSTOP);
	}

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("�ް�.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);

	gotoxy(pos_start.X - strlen("������ �ް� ��¥�� �Է����ּ��� :   ") / 2, pos_start.Y - 2);
	printf("������ �ް� ��¥�� �Է����ּ��� : ");
	gotoxy(pos_start.X - strlen("* ex ) �̹� ���� 15�� -> 15 *") / 2, pos_start.Y);
	printf("* ex ) �̹� ���� 15�� -> 15 *");
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

		MessageBox(NULL, TEXT("�ް� ������ �����Ǿ����ϴ�."), TEXT("Check"), MB_OK | MB_ICONINFORMATION);
		return 0;
	}
	else
	{
		MessageBox(NULL, TEXT("�ް� ������ �������� �ʽ��ϴ�."), TEXT("ERR"), MB_OK | MB_ICONSTOP);
		return 0;
	}

}

void Print_Schedule()
{
	system("COLOR F0");

	int top = 0, top1 = -1, day, tmp = 3;
	int start, last;
	int stack[30][24] = { 0, };
	int stackTop[30] = { 0, };
	int stackDay[32] = { 0, };

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("����.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);

	gotoxy(pos_start.X - strlen("�˻��� ������ �̸��� �Է����ּ��� : ") / 2, pos_start.Y - 1);
	printf("�˻��� ������ �̸��� �Է����ּ��� :");
	gotoxy(pos_start.X + strlen("�˻��� ������ �̸��� �Է����ּ��� : ") / 2, pos_start.Y - 1);
	scanf("%s", newname);  ///�����̸� ����
	Retrieve();

	if (!retData)
	{
		MessageBox(NULL, TEXT("������ �������� �ʽ��ϴ�."), TEXT("ERR"), MB_OK | MB_ICONSTOP);
		return 0;
	}

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("����.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);

	gotoxy(pos_start.X - strlen("�ް� : ") / 2, pos_start.Y - 1);
	printf("�ް� : ");
	for (int i = 1; i < 32; i++)
	{
		int j = 0; //��ǥ ���� ����
		if (tmp == retData->count)
			break;

		if (retData->Schedule[i].day[0] == 1 && retData->Schedule[i].day[1] == 1)
		{
			if (retData->Schedule[i + 1].day[0] == 1 && retData->Schedule[i + 1].day[1] == 1)
			{
				if (retData->Schedule[i + 2].day[0] == 1 && retData->Schedule[i + 2].day[1] == 1)					//3�Ͽ������� �ް��� ����� ���
				{
					gotoxy(pos_start.X + strlen("�ް� :   ") / 2, pos_start.Y - 1);
					printf("%d ~ %d ", i, i + 2);
					tmp -= 3;
					break;
				}
				else
				{
					gotoxy(pos_start.X + strlen("�ް� :   ") / 2 + j, pos_start.Y - 1);
					printf("%d ~ %d", i, i + 1);
					tmp = tmp - 2;
					j += 2;
					i++;
					if (tmp != retData->count)
					{
						gotoxy(pos_start.X + strlen("�ް� : ") / 2 + j, pos_start.Y - 1);
						printf(" , ");
						j += 2;
					}
				}
			}
			else if (retData->Schedule[i + 1].day[0] != 1 && retData->Schedule[i + 1].day[1] != 1)				//�Ϸ縸 �ް��� ����� ���
			{
				gotoxy(pos_start.X + strlen("�ް� : ") / 2 + j, pos_start.Y - 1);
				printf(" %d", i);
				tmp = tmp - 1;
				j += 2;
				if (tmp != retData->count)
				{
					gotoxy(pos_start.X + strlen("�ް� : ") / 2 + j, pos_start.Y - 1);
					printf(" , ");
					j += 2;
				}
			}
		}

	}		//�ް� ��� �Ϸ�

	gotoxy(pos_start.X - 18, pos_start.Y + 7);
	system("PAUSE");
	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("����.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);

	gotoxy(pos_start.X - strlen("���� : ") / 2, pos_start.Y - 1);
	printf("���� : ");
	for (int i = 0; i < 32; i++)
	{
		int j = 0; //��ǥ ���� ����
		if (retData->Schedule[i].day[0] != 1 && retData->Schedule[i].day[1] == 1)
		{
			gotoxy(pos_start.X + strlen("���� :   ") / 2 + j, pos_start.Y - 1);
			printf("%d ", i);
			j += 2;
		}

		else if (retData->Schedule[i].day[0] == 1 && retData->Schedule[i].day[1] != 1)
		{
			gotoxy(pos_start.X + strlen("���� :   ") / 2 + j, pos_start.Y - 1);
			printf("%d ", i);
			j += 2;
		}
	} 	//�ݰ� ��� �Ϸ�

	gotoxy(pos_start.X - 18, pos_start.Y + 7);
	system("PAUSE");

	tmp = -1;

	for (int i = 0; i < 32; i++)
	{
		stackDay[i] = 0;
	}

	for (int day = 1; day < 32; day++)
	{
		for (int i = 0; i < 24; i++)
		{
			if (retData->Schedule[day].outside_duty[i] == 1)
			{
				printf("%d %d\n", i, day);
				stackDay[++tmp] = day;
				break;
			}
		}
	}

	system("cls");
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("����.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);

	gotoxy(pos_start.X - strlen("�ܱ� :  ") / 2 - 5, pos_start.Y - 1);
	printf("�ܱ� : ");


	for (int day = 0; day < 32; day++)
	{


		if (stackDay[day] != 0)			//�ܱ� �ִ� ���� ����
		{
			int y = 0;//��ǥ ���� ����

			system("cls");
			hImage = (HBITMAP)LoadImage(NULL, TEXT("����.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
			print_menuimage(hImage);

			gotoxy(pos_start.X - strlen("�ܱ� :  ") / 2 + 2, pos_start.Y - 1 + y);
			printf("%d�� -> ", stackDay[day]);

			top = 0;
			top1 = -1;

			for (int j = 0; j < 25; j++)
			{
				if (retData->Schedule[stackDay[day]].outside_duty[j] == 1)
				{
					stack[top][++top1] = j;
					if (retData->Schedule[stackDay[day]].outside_duty[j + 1] != 1)
					{
						stackTop[top] = top1;
						top1 = -1;
						top++;
					}
				}
			}					//�ܱ� ã�� ����

			for (int j = 0; j < top; j++)
			{
				gotoxy(pos_start.X - strlen("�ܱ� :      ") / 2 + 7, pos_start.Y - 1 + y);
				printf("%d ~ %d �� ", stack[j][0], stack[j][stackTop[j]] + 1);
				if (j != top - 1)
				{
					gotoxy(pos_start.X + strlen("�ܱ� :   ") / 2 + 7, pos_start.Y - 1 + y);
					printf(" , ");
					y += 2;
				}
			}
			y += 2;
			system("PAUSE");
		}
	}

	gotoxy(pos_start.X - 18, pos_start.Y + 11);
	system("PAUSE");

}