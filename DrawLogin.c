#include "DrawLogin.h"

int login_width, login_height;

void Print_login()
{
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("*���� ���� ���� ���α׷� *") / 2, pos_start.Y - 12);
	printf("* ���� ���� ���� ���α׷� *");
	gotoxy(pos_start.X - 7, pos_start.Y - 2);
	printf("ID : ");
	gotoxy(pos_start.X - 7, pos_start.Y);
	printf("PW : ");
	gotoxy(pos_start.X - strlen("* ID�� 0000�� �Է��Ͻø� ID,PW�� ������ �� �ֽ��ϴ�.") / 2, pos_start.Y + 11);
	printf("* ID�� 0000�� �Է��Ͻø� ID,PW�� ������ �� �ֽ��ϴ�.");
}

void Print_ChangeID()
{
	DrawCenterBox(50, 20);
	getcenter();

	gotoxy(pos_start.X - strlen("*���� ���� ���� ���α׷� *") / 2, pos_start.Y - 12);
	printf("* ���� ���� ���� ���α׷� *");
	gotoxy(pos_start.X - 7, pos_start.Y - 5);
	printf("ID : ");
	gotoxy(pos_start.X - 7, pos_start.Y - 3);
	printf("PW : ");
	gotoxy(pos_start.X - 11, pos_start.Y + 1);
	printf("new ID : ");
	gotoxy(pos_start.X - 11, pos_start.Y + 3);
	printf("new PW : ");

}