#include"DefinePage.h"

int PrintHomepage()
{
	setfFullscreen();
	PrintStatusbar();
	PrinttodayCalendar();
	Print_MainMenu();
	Select_Menu();
	return HomePage;
}

int PrintStaffpage()
{
	PrintStatusbar();
	
	return StaffMainPage;
}