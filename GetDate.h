#pragma once
#ifndef GETDATE_H
#define GETDATE_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include"DrawUI.h"

// 변수
int weekday, monthday;

typedef struct localdate
{
	int tm_day;  /* Day of month (1--31) */
	int tm_mon; /* Month (0--11) */
	int tm_year;  /* Year (calendar year minus 1900) */
}ldate;

ldate today, selected_day;

void GetToday();				// 오늘 날짜 받기
void GetSelectedday(ldate date);			// 선택한 날짜 받기
void GetMonthDay(ldate date);			// 원하는 날짜의 월 수 찾기 	
void GetWeekDay(ldate date, int day);	// 원하는 날짜의 일주일의 시작점 찾기
void GetDay(ldate date);				// 원하는 월 수, 일주일의 시작점

#endif