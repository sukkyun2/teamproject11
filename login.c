#include "login.h"

void Login()
{
	login id = { "0000","0000" };		// �α��� id �ʱ�ȭ
	login *newid = (login *)malloc(sizeof(login));
	Fullscreen();
	do {
		system("cls");
		Print_login();						// �α��� ȭ�� ���

		screen(94, 25);
		scanf("%s", newid->ID);
		if (strcmp(newid->ID, "0000") == 0) {		// ȸ�� ���� ����
			system("cls");
			Print_ChangeID();					// ȸ�� ���� ���� ȭ�� ���
			screen(94, 24);
			printf("%s", id.ID);
			screen(94, 25);
			printf("%s", id.PW);				// ���� id,pw ���
			screen(96, 27);
			scanf("%s", id.ID);
			screen(96, 28);
			scanf("%s", id.PW);
		}
		else {									// ID�� 0000�� �ƴϸ�
			screen(94, 26);
			scanf("%s", newid->PW);
			if (strcmp(newid->ID, id.ID) != 0 || strcmp(newid->PW, id.PW) != 0) {	// id, pw�� ��ġ����������
				system("cls");
				screen(75, 23);
				printf("ERR :: ID,PW�� �߸��Է��ϼ̽��ϴ�.");				// �����޼��� ���
				screen(75, 25);
				system("PAUSE");
			}
		}
	} while (strcmp(newid->ID, id.ID) != 0 || strcmp(newid->PW, id.PW) != 0);			// id,pw ��ġ�Ҷ������� �ݺ�

}

void screen(int x, int y) {
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD max_size = GetLargestConsoleWindowSize(screen);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(screen, pos);
}

void Fullscreen() {
	SetConsoleDisplayMode(
		GetStdHandle(STD_OUTPUT_HANDLE),
		CONSOLE_FULLSCREEN_MODE,
		0
	);

}

void Print_login()
{
	system("cls");

	screen(78, 20);
	printf("   * ���� ���� ���� ���α׷� *");
	screen(78, 21);
	printf("---------------------------------");
	screen(78, 22);
	printf("|                               |");
	screen(78, 23);
	printf("|                               |");
	screen(78, 24);
	printf("|                               |");
	screen(78, 25);
	printf("|         ID :                  |");
	screen(78, 26);
	printf("|         PW :                  |");
	screen(78, 27);
	printf("|                               |");
	screen(78, 28);
	printf("|                               |");
	screen(78, 29);
	printf("|                               |");
	screen(78, 30);
	printf("---------------------------------");
	screen(75, 32);
	printf("* ID�� 0000�� �Է��Ͻø� ID,PW�� ������ �� �ֽ��ϴ�.");

}

void Print_ChangeID()
{
	system("cls");

	screen(78, 21);
	printf("---------------------------------");
	screen(78, 22);
	printf("|                               |");
	screen(78, 23);
	printf("|                               |");
	screen(78, 24);
	printf("|         ID :                  |");
	screen(78, 25);
	printf("|         PW :                  |");
	screen(78, 26);
	printf("|                               |");
	screen(78, 27);
	printf("|        new ID :               |");
	screen(78, 28);
	printf("|        new PW :               |");
	screen(78, 29);
	printf("|                               |");
	screen(78, 30);
	printf("|                               |");
	screen(78, 31);
	printf("---------------------------------");

}

