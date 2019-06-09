#pragma once

#include "GetDate.h"
#include "SetScreen.h"

void PrintSelectdateButton();		// 날짜 선택을 위한 버튼
void PrinttSelectdateInputbox();
void PrinttodaydateButton();		// 오늘 날짜로 돌아가는 버튼
void getCalendarSize();				// 달력의 사이즈를 측정하는 함수(전체크기)
void PrintCalendar_background();	// 달력의 형태를 출력하는 함수
void PrintCalendarweek();			// 일 월 화 수 목 금 토 를 출력하는 함수
void PrintCalendarMonth(ldate date);// 원하는 날짜의 년,월 을 상단에 출력하는 함수
void PrintCalendardate(ldate date);	// 원하는 달력의 월 수(1 ~31)을 출력하는 함수(원하는 날짜는 붉은색으로 출력)
void PrinttodayCalendar();			// 오늘의 달력을 출력(출력할 때마다 다시 오늘 날짜를 체크)
void PrinttselectedCalendar();		// 선택한 날짜의 달력을 출력