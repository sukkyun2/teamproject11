#include "login.h"
#include "DrawLogin.h"

typedef struct login {         // �α��� ����ü
	char ID[10];
	char PW[10];
}login;

void Login()
{
	login id = { "0000","0000" };      // �α��� id �ʱ�ȭ
	login* newid = (login*)malloc(sizeof(login));
	setfFullscreen();
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
			scanf("%s", newid->PW);
			if (strcmp(newid->ID, id.ID) != 0 || strcmp(newid->PW, id.PW) != 0) {   // id, pw�� ��ġ����������
				system("cls");

				gotoxy(pos_start.X - strlen("ERR :: ID,PW�� �߸��Է��ϼ̽��ϴ�.") / 2, pos_start.Y - 5);
				printf("ERR :: ID,PW�� �߸��Է��ϼ̽��ϴ�.");            // �����޼��� ���
				gotoxy(pos_start.X - strlen("ERR :: ID,PW�� �߸��Է��ϼ̽��ϴ�.") / 2, pos_start.Y - 3);
				system("PAUSE");
			}
		}
	} while (strcmp(newid->ID, id.ID) != 0 || strcmp(newid->PW, id.PW) != 0);         // id,pw ��ġ�Ҷ������� �ݺ�

}