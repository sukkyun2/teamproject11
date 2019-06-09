// 마우스 제어 시, 각 기능별로 페이지를 분류하기 위함
// 제어하지 않더라도 main함수의 직관성을 목적으로 함

#pragma once
#ifndef DEFINEPAGE_H
#define DEFINEPAGE_H

#include"DrawCalendar.h"
#include"DrawMainMenu.h"

#define getselectdaybutton 9
#define gettodaybutton 0

void PrintHomepage();
void PrintStaffpage();
void PrintSchedulepage();
void PrintWorkpage();

#endif