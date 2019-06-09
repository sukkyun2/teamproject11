#include "DrawCalendar.h"

// 변수
int calendar_width, calendar_height;

// 함수
void getCalendarSize()
{
	pos_start.X = (int)((double)(0.5 * onecols));
	pos_start.Y = (int)((double)(2.0 * onerows) + 6);

	pos_end.X= (int)((double)(7.5 * onecols));
	pos_end.Y = (int)((double)(7.0 * onerows) + 6);

	calendar_width = pos_end.X - pos_start.X;
	calendar_height = pos_end.Y - pos_start.Y;
}

void PrintCalendar_background()
{
	COORD tmp;
	int r, c;

	tmp.X = pos_start.X;	tmp.Y = pos_start.Y;

	gotoxy(tmp.X, tmp.Y);

	for (c = 1; c <= calendar_height; c++)
	{
		if ((c != calendar_height) && (c % onerows) == 0)
		{
			for (r = 1; r <= calendar_width; r++)
			{
				if ((r != calendar_width) && (r % onecols) == 0) printf("┼");
				else if (r == 1) printf("├");
				else if (r == calendar_width) printf("┤");
				else printf("─");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		else if (c == 1)
		{
			for (r = 1; r <= calendar_width; r++)
			{
				if ((r != calendar_width) && (r % onecols) == 0) printf("┬");
				else if (r == 1) printf("┌");
				else if (r == calendar_width) printf("┐");
				else printf("─");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		else if (c == calendar_height)
		{
			for (r = 1; r <= calendar_width; r++)
			{
				if ((r != calendar_width) && (r % onecols) == 0) printf("┴");
				else if (r == 1) printf("└");
				else if (r == calendar_width) printf("┘");
				else printf("─");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		else
		{
			for (r = 1; r <= calendar_width; r++)
			{
				if ((r != calendar_width) && (r % onecols) == 0) printf("│");
				else if (r == 1) printf("│");
				else if (r == calendar_width) printf("│");
				else printf(" ");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		tmp.X = pos_start.X;	tmp.Y++;
		gotoxy(tmp.X, tmp.Y);
	}
}

void PrintCalendarweek()
{
	COORD date_start, tmp;
	char* week[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri" ,"Sat" };
	int i;

	date_start.X = (int)((double)(1.0 * onecols) - 1);
	date_start.Y = (int)((double)(2.0 * onerows) + 5);
	tmp.X = date_start.X;	tmp.Y = date_start.Y;

	gotoxy(tmp.X, tmp.Y);
	for (i = 0; i < 7; i++)
	{
		printf("%s", week[i]);
		tmp.X += onecols;
		gotoxy(tmp.X, tmp.Y);
	}
}

void PrintCalendarMonth(ldate date)
{
	COORD tmp;
	char* month[12] = { "Jan"," Feb"," Mar"," Apr"," May"," Jun"," Jul"," Aug"," Sep"," Oct"," Nov"," Dec" };
	int i = date.tm_mon - 1;

	tmp.X = (int)((double)(3.5 * onecols) - 3);
	tmp.Y = (int)((double)(1.5 * onerows) + 3);
	gotoxy(tmp.X, tmp.Y);
	printf("%d %s", date.tm_year, month[i]);
}


void PrintCalendardate(ldate date)
{
	COORD date_start, tmp;
	int n, d;

	date_start.X = (int)((double)(0.5 * onecols) + 2);
	date_start.Y = (int)((double)(2.0 * onerows) + 7);
	tmp.X = date_start.X;	tmp.Y = date_start.Y;

	for (n = 0; n < weekday; n++)	// 달력의 시작 위치로
		tmp.X += onecols;

	gotoxy(tmp.X, tmp.Y);

	for (d = 1; d <= monthday; d++)	// 일 수
	{
		// 글자색
		if (d == date.tm_mday)	// 원하는 날짜이면
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);	// 빨간색(배경 빨강, 검은 글자)
		else
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);	// 아니면 원래 글자색으로
		
		// 날짜 출력
			printf("%2d", d);

		if ((n % 7) == 6 && d != monthday)	// 일주일이 다 지나면
		{
			tmp.X = date_start.X;
			tmp.Y += onerows;
			gotoxy(tmp.X, tmp.Y);			// 아래칸으로
		}
		else
		{
			tmp.X += onecols;
			gotoxy(tmp.X, tmp.Y);			// 옆칸으로
		}
		n++;
	}
}

void PrintCalendarform()
{
	getform();
	getCalendarSize();
	PrintCalendar_background();
	PrintCalendarweek();
	PrintSelectdateButton();
	PrinttodaydateButton();
}

void PrinttodayCalendar()
{
	GetToday();
	GetDay(today);
	PrintCalendarform();
	PrintCalendarMonth(today);
	PrintCalendardate(today);
}
void PrinttselectedCalendar()
{
	GetToday();
	GetDay(selcted_day);
	PrintCalendarform();
	PrintCalendarMonth(today);
	PrintCalendardate(today);
}

void PrintSelectdateButton()
{
	COORD pos = getfFullscreen();
	pos.X = (int)((double)(0.5 * onecols) + 2);
	pos.Y = (int)((double)(1.0 * onerows) + 2);
	gotoxy(pos.X, pos.Y);
	printf("날짜 입력");
}

void PrinttSelectdateInputbox()
{
	int i;

	COORD pos = getfFullscreen();
	pos.X = (int)((double)(0.5 * onecols) + 2 + strlen("날짜 입력 "));
	pos.Y = (int)((double)(1.0 * onerows) + 2);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);

	for (i = pos.X; i < pos_end.X; i++)
		printf(" ");
}

void PrinttodaydateButton()
{
	COORD pos = getfFullscreen();
	pos.X = (int)((double)(7.0 * onecols) - 2);
	pos.Y = (int)((double)(1.5 * onerows) + 3);
	gotoxy(pos.X, pos.Y);
	printf("오늘 날짜");
}