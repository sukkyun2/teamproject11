#include "DrawCalendar.h"

// 함수
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
		if (d == date.tm_day)	// 원하는 날짜이면
			textcolor(BLACK, RED);	// 빨간색(배경 빨강, 검은 글자)
		else
			textcolor(WHITE, BLACK);	// 아니면 원래 글자색으로
		
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
	GetDay(selected_day);
	PrintCalendarform();
	PrintCalendarMonth(today);
	PrintCalendardate(today);
}

