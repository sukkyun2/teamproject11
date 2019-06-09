#include "login.h"
#include "DrawLogin.h"

typedef struct login {         // 로그인 구조체
	char ID[10];
	char PW[10];
}login;

void Login()
{
	login id = { "0000","0000" };      // 로그인 id 초기화
	login* newid = (login*)malloc(sizeof(login));
	setfFullscreen();
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
			scanf("%s", newid->PW);
			if (strcmp(newid->ID, id.ID) != 0 || strcmp(newid->PW, id.PW) != 0) {   // id, pw가 일치하지않으면
				system("cls");

				gotoxy(pos_start.X - strlen("ERR :: ID,PW를 잘못입력하셨습니다.") / 2, pos_start.Y - 5);
				printf("ERR :: ID,PW를 잘못입력하셨습니다.");            // 오류메세지 출력
				gotoxy(pos_start.X - strlen("ERR :: ID,PW를 잘못입력하셨습니다.") / 2, pos_start.Y - 3);
				system("PAUSE");
			}
		}
	} while (strcmp(newid->ID, id.ID) != 0 || strcmp(newid->PW, id.PW) != 0);         // id,pw 일치할때까자지 반복

}