#pragma once
#ifndef DRAWCALENDAR_H
#define DRAWCALENDAR_H

#include "GetDate.h"
#include "DrawUI.h"

void PrintCalendarMonth(ldate date);// 원하는 날짜의 년,월 을 상단에 출력하는 함수
void PrintCalendardate(ldate date);	// 원하는 달력의 월 수(1 ~31)을 출력하는 함수(원하는 날짜는 붉은색으로 출력)
void PrinttodayCalendar();			// 오늘의 달력을 출력(출력할 때마다 다시 오늘 날짜를 체크)
void PrinttselectedCalendar();		// 선택한 날짜의 달력을 출력

#endif