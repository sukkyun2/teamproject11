#include"DrawNavigator.h"

void Print_navigatorinfo()
{
	COORD tmp;

	getnavigatorSize();
	tmp.X = navipos_start.X + 3;	tmp.Y = navipos_start.Y + 2;
	gotoxy(tmp.X, tmp.Y);
	printf("���� �ٹ���");
	// �Է� �޾ƿ��� getstaffinfo("���ϸ�");
	
	tmp.Y++;	gotoxy(tmp.X, tmp.Y);
	printf("���� �޹���");
	// �Է� �޾ƿ��� getstaffinfo("���ϸ�");
}

void Print_Navigator()
{
	Printnavigator_background();
	Print_navigatorinfo();
}