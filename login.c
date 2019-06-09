#include <conio.h>

#include "login.h"

int login_width, login_height;

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
	
	system("COLOR F0");

	hImage = (HBITMAP)LoadImage(NULL, TEXT("screen.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_startimage(hImage);
	s = getch();

	if (s == 13) {
		do {

			system("cls"); 
	
			Print_login();


			gotoxy(pos_start.X - 2, pos_start.Y - 2);
			scanf("%s", newid->ID);
			if (strcmp(newid->ID, "0000") == 0) {      // ȸ�� ���� ����
				system("COLOR F0");
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

void Print_login()
{
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("menu.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);
	gotoxy(pos_start.X - 7, pos_start.Y - 2);
	printf("ID : ");
	gotoxy(pos_start.X - 7, pos_start.Y);
	printf("PW : "); 

	setFontColor(12);
	gotoxy(pos_start.X - strlen("* ID�� 0000�� �Է��Ͻø� ID,PW�� ������ �� �ֽ��ϴ�.") / 2, pos_start.Y + 11);
	printf("* ID�� 0000�� �Է��Ͻø� ID,PW�� ������ �� �ֽ��ϴ�.");
	resetFontColor();
}

void Print_ChangeID()
{
	DrawCenterBox(50, 20);
	getcenter();

	hImage = (HBITMAP)LoadImage(NULL, TEXT("menu.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	print_menuimage(hImage);
	gotoxy(pos_start.X - 7, pos_start.Y - 5);
	printf("ID : "); 
	gotoxy(pos_start.X - 7, pos_start.Y - 3);
	printf("PW : ");
	gotoxy(pos_start.X - 11, pos_start.Y + 1);
	printf("new ID : ");
	gotoxy(pos_start.X - 11, pos_start.Y + 3);
	printf("new PW : "); 

}

void setFontColor(int color) {
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (info.wAttributes & 0xf0) | (color & 0xf));
}

__inline void resetFontColor() {
	setFontColor(0);
}


void get_pw(char* buf, int size)
{
	textcolor(BLACK, WHITE);
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
	textcolor(WHITE, BLACK);
}

void print_startimage(HBITMAP hImage)
{
	HWND myconsole = GetConsoleWindow();
	HDC mydc = GetDC(myconsole);

	HBITMAP hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);

	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 500, 200, 200 * 10, 200 * 20, hMemDC, 0, 0, SRCCOPY);

	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);
}

void print_menuimage(HBITMAP hImage)
{


	HWND myconsole = GetConsoleWindow();
	HDC mydc = GetDC(myconsole);

	HBITMAP hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);

	getcenter();
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, 770, 240, 200*10, 200 * 20, hMemDC, 0, 0, SRCCOPY);

	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);

	ReleaseDC(myconsole, mydc);

}