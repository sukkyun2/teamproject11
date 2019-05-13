#include <stdio.h>
#include "menu.h"
#include "staff.h"
#include "schedule.h"



void Schedule() {		// ���� ���� ����
	int menu;

	while (1) {
		Print_Schedule_Menu();
		screen(163, 7);
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			Insert_Schedule();   
			break;
		case 2:
			Delete_Schedule();  
			break;
		case 3:
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

void Print_Schedule_Menu() {	// ���� ���� �޴� ���

	system("cls");

	screen(135, 7);
	printf("�޴� ��ȣ�� �Է����ּ��� : ");
	screen(135, 9);
	printf("1. �ް� �߰� �ϱ�");
	screen(135, 11);
	printf("2. �ް� ���� �ϱ�");
	screen(135, 13);
	printf("3. ���θ޴��� ���ư���");
}

void Insert_Schedule()
{
	system("cls");
	
	int menu;
	while (1) {
		screen(135, 7);
		printf("�޴��� �������ּ���");
		screen(135, 9);
		printf("1.�ܱ�");
		screen(135, 11);
		printf("2.�ް�");
		screen(135, 13);
		printf("3.���� �ݰ�");
		screen(135, 15);
		printf("4.���� �ݰ�");
		screen(135, 17);
		printf("5.�޴��� ���ư���");
		
		screen(163, 7);
		scanf("%d", &menu);
		switch (menu) {
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

void Delete_Schedule()
{
	int menu;
	while (1) {
		screen(135, 7);
		printf("�޴��� �������ּ���");
		screen(135, 9);
		printf("1.�ܱ� ���� ����");
		screen(135, 11);
		printf("2.�ް�, �ݰ� ���� ����");
		screen(135, 13);
		printf("3.�޴��� ���ư���");
		
		screen(163, 7);
		scanf("%d", &menu);
		switch (menu) {
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
	screen(75, 23);
	printf("�ܱ���  �Է��� ������ �̸��� �Է����ּ��� :");
	screen(111, 23);
	scanf("%s", search_name);  ///�����̸� ����
	Retrieve();

	if (!retData)
	{
		system("cls");
		screen(75, 23);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");				// �����޼��� ���
		screen(75, 25);
		system("PAUSE");
	}
	system("cls");
	screen(75, 23);
	printf("�ܱ��� ��¥�� �Է����ּ��� ");
	screen(111, 23);
	scanf("%d", &day);
	screen(75, 25);
	printf("�ܱ� �ð��� �Է����ּ��� ");
	screen(111, 25);
	scanf("%d %d", &front, &rear);
	system("cls");
	for (int i = front; i <= rear; i++)
	{
		if (retData->Schedule[day].outside_duty[i] = 1)
			///ȭ���� ���� �����ؼ� �������� �ۼ� --O
			///��ġ�� �������� �߰����� �� Ȯ���� ������
			//�̹� �������� ������ ��
		{
			screen(75, 23);
			printf("�̹� ������ �����մϴ�");
			return 0;
		}
		retData->Schedule[day].outside_duty[i]=1; 
		//�ܱ� �Է�
	}
	screen(75, 23);
	printf("�ܱ� ������ �ԷµǾ����ϴ�");

}

void Insert_day()
{
	char search_name[10]; //�˻��� ������ �̸�
	int day;
	system("cls");
	screen(75, 23);
	printf("�ް��� �Է��� ������ �̸��� �Է����ּ��� :");
	screen(111, 23);
	scanf("%s", search_name);  
	Retrieve();

	if (!retData)
	{
		system("cls");
		screen(75, 23);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");				// �����޼��� ���
		screen(75, 25);
		system("PAUSE");
	}

	if (retData->count < 1)  //�ް� �ѵ��� �Ѿ�ٸ�
	{
		system("cls");
		screen(75, 23);
		printf("�Ѵ� �ް� ��� ����Ƚ���� �ʰ��Ͽ����ϴ�");
		return 0; 
		// Schedule���� ���ư���
	}

	system("cls");
	screen(75, 23);
	printf("�ް� ��¥�� �Է����ּ��� ");
	screen(111, 23);
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
	screen(75, 23);
	printf("������ �Է��� ������ �̸��� �Է����ּ��� :");
	screen(111, 23);
	scanf("%s", search_name);
	Retrieve();

	if (!retData)
	{
		system("cls");
		screen(75, 23);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");				// �����޼��� ���
		screen(75, 25);
		system("PAUSE");
	}

	system("cls");
	screen(75, 23);
	printf("���� ��¥�� �Է����ּ��� ");
	screen(111, 23);
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
	screen(75, 23);
	printf("������ �Է��� ������ �̸��� �Է����ּ��� :");
	screen(111, 23);
	scanf("%s", search_name);
	Retrieve();

	if (!retData)
	{
		system("cls");
		screen(75, 23);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");				// �����޼��� ���
		screen(75, 25);
		system("PAUSE");
	}

	system("cls");
	screen(75, 23);
	printf("���� ��¥�� �Է����ּ��� ");
	screen(111, 23);
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
	screen(75, 23);
	printf("�ܱ���  �Է��� ������ �̸��� �Է����ּ��� :");
	scanf("%s", search_name);
	Retrieve();

	if (!retData)
	{
		system("cls");
		screen(75, 23);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");				// �����޼��� ���
		screen(75, 25);
		system("PAUSE");
	}
	system("cls");
	screen(75, 23);
	printf("������ �ܱ� ��¥�� �Է����ּ��� ");
	screen(111, 23);
	scanf("%d", &day);
	screen(75, 25);
	printf("������ �ܱ� �ð��� �Է����ּ��� ");
	screen(111, 23);
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
	screen(75, 23);
	printf("�ް��� ������ ������ �̸��� �Է����ּ��� :");
	screen(111, 23);
	scanf("%s", search_name);
	Retrieve();

	if (!retData)
	{
		system("cls");
		screen(75, 23);
		printf("ERR :: ������ �������� �ʽ��ϴ�.");				// �����޼��� ���
		screen(75, 25);
		system("PAUSE");
	}

	system("cls");
	screen(75, 23);
	printf("�ް� ��¥�� �Է����ּ��� ");
	screen(111, 23);
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
		screen(75, 23);
		printf("�ް��� ���� �Ǿ����ϴ�.");
	}
	else
	{
		system("cls");
		screen(75, 23);
		printf("�ް� ������ �������� �ʽ��ϴ�");
		
	}
	
}

