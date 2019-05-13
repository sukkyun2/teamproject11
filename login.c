#include "login.h"

void Login()
{
	login id = { "0000","0000" };		// 로그인 id 초기화
	login *newid = (login *)malloc(sizeof(login));
	Fullscreen();
	do {
		system("cls");
		Print_login();						// 로그인 화면 출력

		screen(94, 25);
		scanf("%s", newid->ID);
		if (strcmp(newid->ID, "0000") == 0) {		// 회원 정보 수정
			system("cls");
			Print_ChangeID();					// 회원 정보 수정 화면 출력
			screen(94, 24);
			printf("%s", id.ID);
			screen(94, 25);
			printf("%s", id.PW);				// 기존 id,pw 출력
			screen(96, 27);
			scanf("%s", id.ID);
			screen(96, 28);
			scanf("%s", id.PW);
		}
		else {									// ID에 0000이 아니면
			screen(94, 26);
			scanf("%s", newid->PW);
			if (strcmp(newid->ID, id.ID) != 0 || strcmp(newid->PW, id.PW) != 0) {	// id, pw가 일치하지않으면
				system("cls");
				screen(75, 23);
				printf("ERR :: ID,PW를 잘못입력하셨습니다.");				// 오류메세지 출력
				screen(75, 25);
				system("PAUSE");
			}
		}
	} while (strcmp(newid->ID, id.ID) != 0 || strcmp(newid->PW, id.PW) != 0);			// id,pw 일치할때까자지 반복

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
	printf("   * 직원 일정 관리 프로그램 *");
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
	printf("* ID에 0000을 입력하시면 ID,PW를 수정할 수 있습니다.");

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

