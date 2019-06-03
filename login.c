#include <conio.h>

#include "login.h"
#include "DrawLogin.h"

typedef struct login {         // 로그인 구조체
	char ID[10];
	char PW[10];
}login;

void Login()
{
	int s;

	login id = { "0000","0000" };      // 로그인 id 초기화
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
			if (strcmp(newid->ID, "0000") == 0) {      // 회원 정보 수정
				system("cls");
				Print_ChangeID();               // 회원 정보 수정 화면 출력
				gotoxy(pos_start.X - 2, pos_start.Y - 5);
				printf("%s", id.ID);
				gotoxy(pos_start.X - 2, pos_start.Y - 3);
				printf("%s", id.PW);            // 기존 id,pw 출력
				gotoxy(pos_start.X - 2, pos_start.Y + 1);
				scanf("%s", id.ID);
				gotoxy(pos_start.X - 2, pos_start.Y + 3);
				scanf("%s", id.PW);
			}
			else {                           // ID에 0000이 아니면
				gotoxy(pos_start.X - 2, pos_start.Y);
				get_pw(newid->PW, 5);
				if (strcmp(newid->ID, id.ID) != 0 || strcmp(newid->PW, id.PW) != 0) {   // id, pw가 일치하지않으면
					system("cls");
					MessageBox(NULL, TEXT(" ID,PW를 잘못입력하셨습니다."), TEXT("ERR"), MB_OK | MB_ICONSTOP);
				}
			}
		} while (strcmp(newid->ID, id.ID) != 0 || strcmp(newid->PW, id.PW) != 0);         // id,pw 일치할때까자지 반복
	}
	else
	{
		Login();
	}
}


void get_pw(char* buf, int size)
{
	int cnt = 0, key;  // 입력 받은 글자 수와 키 

	while (1)
	{
		key = getch();  // 한 글자 입력받음

		if (key == ENTER_KEY)  // 엔터 또는 탭 키면 종료
			break;

		buf[cnt++] = (char)key;   // 버퍼에 글자 저장하고 카운트 1 증가  
		putchar('*');  // 화면에 별 표시 

		if (cnt == size - 1)  // 최대 크기를 넘어가면 종료 
			break;
	}

	buf[cnt] = '\0';    // 문자열로 만들기 위해 널 문자 마무리
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