#include"GetDate.h"

// 함수
void GetToday()
{
	time_t timer;
	struct tm* t;

	timer = time(NULL); // 현재 시각을 초 단위로 얻기
	t = localtime(&timer); // 초 단위의 시간을 분리하여 구조체에 넣기

	today.tm_year = (t->tm_year + 1900);
	today.tm_mon = (t->tm_mon + 1);
	today.tm_mday = (t->tm_mday);
	GetDay(today);
}
//http://mwultong.blogspot.com/2006/10/c-current-date-time.html

void GetSelectedday()
{
	while (1)
	{
		scanf_s("%d-%d-%d", &selcted_day.tm_year, &selcted_day.tm_mon, &selcted_day.tm_mday);
		scanf_s("%*c");
		if (selcted_day.tm_mon >= 1 && selcted_day.tm_mon <= 12)
			break;
	}
	GetDay(selcted_day);
}

void GetMonthDay(ldate date)
{
	switch (date.tm_mon)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		monthday = 31;
		break;

	case 4: case 6: case 9: case 11:
		monthday = 30;
		break;

	case 2:
		if (date.tm_year % 4 == 0 && date.tm_year % 100 != 0 || date.tm_year % 400 == 0)
			monthday = 29;
		else
			monthday = 28;
		break;

	default:
		monthday = 0;
	}
}

void GetWeekDay(ldate date, int day)
{
	if (date.tm_mon == 1 || date.tm_mon == 2) {
		date.tm_year--;
		date.tm_mon += 12;
	}
	weekday = (date.tm_year + date.tm_year / 4 - date.tm_year / 100 + date.tm_year / 400 + (13 * date.tm_mon + 8) / 5 + day) % 7;
}
// https://cafe.naver.com/cafec/165808

void GetDay(ldate date)
{
	GetMonthDay(date);
	GetWeekDay(date, 1);
}