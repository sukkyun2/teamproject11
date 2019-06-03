#include"DrawNavigator.h"

void Print_navigatorinfo()
{
	COORD tmp;

	getnavigatorSize();
	tmp.X = navipos_start.X + 3;	tmp.Y = navipos_start.Y + 2;
	gotoxy(tmp.X, tmp.Y);
	printf("당일 근무자");
	// 입력 받아오기 getstaffinfo("파일명");
	
	tmp.Y++;	gotoxy(tmp.X, tmp.Y);
	printf("당일 휴무자");
	// 입력 받아오기 getstaffinfo("파일명");
}

void Print_Navigator()
{
	Printnavigator_background();
	Print_navigatorinfo();
}