#include"DefinePage.h"

void PrintHomepage()
{
	setfFullscreen();
	system("cls");
	PrintStatusbar();
	PrinttodayCalendar();
	Print_MainMenu();
	Select_Menu();
}

void PrintStaffpage()
{
	PrintStatusbar();

}