#include <conio.h>

#include "login.h"
#include "DrawLogin.h"

typedef struct login {         // �α��� ����ü
	char ID[10];
	char PW[10];
}login;

void Login()
{
	int s;

	login id = { "0000","0000" };      // �α��� id �ʱ�ȭ
	login* newid = (login*)malloc(sizeof(login));

	setFullscreen();

	print_start();
	s = getch();

	if (s == 13) {
		do {
			system("cls");
			Print_login();

			gotoxy(pos_start.X - 2, pos_start.Y - 2);
			scanf("%s", newid->ID);
			if (strcmp(newid->ID, "0000") == 0) {      // ȸ�� ���� ����
				system("cls");
				Print_ChangeID();               // ȸ�� ���� ���� ȭ�� ���
				gotoxy(pos_start.X - 2, pos_start.Y - 5);
				printf("%s", id.ID);
				gotoxy(pos_start.X - 2, pos_start.Y - 3);
				printf("%s", id.PW);            // ���� id,pw ���
				gotoxy(pos_start.X - 2, pos_start.Y + 1);
				scanf("%s", id.ID);
				gotoxy(pos_start.X - 2, pos_start.Y + 3);
				scanf("%s", id.PW);
			}
			else {                           // ID�� 0000�� �ƴϸ�
				gotoxy(pos_start.X - 2, pos_start.Y);
				get_pw(newid->PW, 5);
				if (strcmp(newid->ID, id.ID) != 0 || strcmp(newid->PW, id.PW) != 0) {   // id, pw�� ��ġ����������
					system("cls");
					MessageBox(NULL, TEXT(" ID,PW�� �߸��Է��ϼ̽��ϴ�."), TEXT("ERR"), MB_OK | MB_ICONSTOP);
				}
			}
		} while (strcmp(newid->ID, id.ID) != 0 || strcmp(newid->PW, id.PW) != 0);         // id,pw ��ġ�Ҷ������� �ݺ�
	}
	else
	{
		Login();
	}
}


void get_pw(char* buf, int size)
{
	int cnt = 0, key;  // �Է� ���� ���� ���� Ű 

	while (1)
	{
		key = getch();  // �� ���� �Է¹���

		if (key == ENTER_KEY)  // ���� �Ǵ� �� Ű�� ����
			break;

		buf[cnt++] = (char)key;   // ���ۿ� ���� �����ϰ� ī��Ʈ 1 ����  
		putchar('*');  // ȭ�鿡 �� ǥ�� 

		if (cnt == size - 1)  // �ִ� ũ�⸦ �Ѿ�� ���� 
			break;
	}

	buf[cnt] = '\0';    // ���ڿ��� ����� ���� �� ���� ������
}

void print_start()
{
	HWND myconsole = GetConsoleWindow();
	HDC mydc = GetDC(myconsole);

	HBITMAP hOldBitmap, hImage;
	HDC hMemDC = CreateCompatibleDC(mydc);

	hImage = (HBITMAP)LoadImage(NULL, TEXT("screen.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 500, 200, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY);

	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);

}