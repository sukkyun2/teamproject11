#include"DefinePage.h"

void PrintHomepage()
{
	PAGE = HomePage;
	setFullscreen();
	system("cls");
	PrintStatusbar();
	PrinttodayCalendar();
	Print_MainMenu();
	Print_Navigator();
	Select_Menu();
}

void PrintStaffpage()
{
	PAGE = StaffMainPage;
	PrintStatusbar();
	Staff();
}

void PrintSchedulepage()
{
	PAGE = ScheduleMainPage;
}

void PrintWorkpage()
{
	PAGE = WorkMainPage;
}
