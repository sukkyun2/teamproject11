#pragma once

#include "menu.h"
#include "staff.h"

void Select_Menu()		// �޴� �����ϴ� �Լ�
{
	int menu;
	COORD tmp;

	tmp.X = pos_start.X + 3;	tmp.Y = pos_start.Y + 2;
	gotoxy(tmp.X, tmp.Y);

	while (1) {
		tmp.X = pos_start.X + 3 + strlen("�޴� ��ȣ�� �Է����ּ��� : ");
		gotoxy(tmp.X, tmp.Y);

		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			Staff();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			exit(0);
			break;
		}
	}
}

void Print_Menu() {	// �޴� ����Ʈ

	system("cls");

	screen(135, 7);
	printf("�޴� ��ȣ�� �Է����ּ��� : ");
	screen(135, 9);
	printf("1. ��������");
	screen(135, 11);
	printf("2. ��������");
	screen(135, 13);
	printf("3. �ٹ�����");
	screen(135, 15);
	printf("4. �ι��˻�");
	screen(135, 17);
	printf("5. ���α׷� ����");

}

