#include "login.h"

void Login()
{
	login id = { "0000","0000" };		// �α��� id �ʱ�ȭ
	login *newid = (login *)malloc(sizeof(login));
	Fullscreen();
	do {
		system("cls");
		getloginSize();
		Print_login();

		screen(loginpos.X+5, loginpos.Y + 9);
		scanf("%s", newid->ID);
		if (strcmp(newid->ID, "0000") == 0) {		// ȸ�� ���� ����
			system("cls");
			Print_ChangeID();					// ȸ�� ���� ���� ȭ�� ���
			screen(loginpos.X+5, loginpos.Y + 5);
			printf("%s", id.ID);
			screen(loginpos.X+5, loginpos.Y + 7);
			printf("%s", id.PW);				// ���� id,pw ���
			screen(loginpos.X+10, loginpos.Y + 11);
			scanf("%s", id.ID);
			screen(loginpos.X+10, loginpos.Y + 13);
			scanf("%s", id.PW);
		}
		else {									// ID�� 0000�� �ƴϸ�
			screen(loginpos.X + 5, loginpos.Y + 11);
			scanf("%s", newid->PW);
			if (strcmp(newid->ID, id.ID) != 0 || strcmp(newid->PW, id.PW) != 0) {	// id, pw�� ��ġ����������
				system("cls");
				loginpos.X = 6.0*onecols - 20;
				loginpos.Y = 3.75*onerows;
				screen(loginpos.X, loginpos.Y);
				printf("ERR :: ID,PW�� �߸��Է��ϼ̽��ϴ�.");				// �����޼��� ���
				screen(loginpos.X, loginpos.Y+2);
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
	Printlogin_background();
	getform();

	loginpos.X = 6.0*onecols - 17;
	loginpos.Y = 3.75*onerows - 8;

	screen(loginpos.X, loginpos.Y);
	printf("* ���� ���� ���� ���α׷� *");
	screen(loginpos.X, loginpos.Y+9);
	printf("ID : ");
	screen(loginpos.X, loginpos.Y+11);
	printf("PW : ");
	screen(loginpos.X-13, loginpos.Y+21);	
	printf("* ID�� 0000�� �Է��Ͻø� ID,PW�� ������ �� �ֽ��ϴ�.");

	

}

void getloginSize()
{

	getform();

	loginpos.X = 6.0*onecols - 15;
	loginpos.Y = 3.75*onerows ;

	screen(loginpos.X, loginpos.Y);

	pos_start.X = (int)((double)(6.0*onecols ) -30);
	pos_start.Y = (int)((double)(3.75*onerows) - 7);

	pos_end.X = (int)((double)(6.0*onecols) +20);
	pos_end.Y = (int)((double)(3.75*onerows) + 13);

	login_width = pos_end.X - pos_start.X;
	login_height = pos_end.Y - pos_start.Y;
}

void Printlogin_background()
{
	getloginSize();

	COORD tmp;
	int r, c;

	tmp.X = pos_start.X;	tmp.Y = pos_start.Y;

	gotoxy(tmp.X, tmp.Y);

	for (c = 1; c <= login_height; c++)
	{
		if (c == 1)
		{
			for (r = 1; r <= login_width; r++)
			{

				if (r == 1) printf("��");
				else if (r == login_width) printf("��");
				else printf("��");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		else if (c == login_height)
		{
			for (r = 1; r <= login_width; r++)
			{

				if (r == 1) printf("��");
				else if (r == login_width) printf("��");
				else printf("��");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		else
		{
			for (r = 1; r <= login_width; r++)
			{
				if ((r == 1) || (r == login_width)) printf("��");
				else printf(" ");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		tmp.X = pos_start.X;	tmp.Y++;
		gotoxy(tmp.X, tmp.Y);
	}
}

void Print_ChangeID()
{
	Printlogin_background();
	getform();

	loginpos.X = 6.0*onecols - 17;
	loginpos.Y = 3.75*onerows - 8;

	screen(loginpos.X, loginpos.Y + 5);
	printf("ID : ");
	screen(loginpos.X, loginpos.Y + 7);
	printf("PW : ");
	screen(loginpos.X, loginpos.Y + 11);
	printf("new ID : ");
	screen(loginpos.X, loginpos.Y + 13);
	printf("new PW : ");

}

