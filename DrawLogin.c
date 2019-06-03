#include "DrawLogin.h"

int login_width, login_height;

void Print_login()
{
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("*직원 일정 관리 프로그램 *") / 2, pos_start.Y - 12);
	printf("* 직원 일정 관리 프로그램 *");
	gotoxy(pos_start.X - 7, pos_start.Y - 2);
	printf("ID : ");
	gotoxy(pos_start.X - 7, pos_start.Y);
	printf("PW : ");
	gotoxy(pos_start.X - strlen("* ID에 0000을 입력하시면 ID,PW를 수정할 수 있습니다.") / 2, pos_start.Y + 11);
	printf("* ID에 0000을 입력하시면 ID,PW를 수정할 수 있습니다.");
}

void Print_ChangeID()
{
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("*직원 일정 관리 프로그램 *") / 2, pos_start.Y - 12);
	printf("* 직원 일정 관리 프로그램 *");
	gotoxy(pos_start.X - 7, pos_start.Y - 5);
	printf("ID : ");
	gotoxy(pos_start.X - 7, pos_start.Y - 3);
	printf("PW : ");
	gotoxy(pos_start.X - 11, pos_start.Y + 1);
	printf("new ID : ");
	gotoxy(pos_start.X - 11, pos_start.Y + 3);
	printf("new PW : ");

}