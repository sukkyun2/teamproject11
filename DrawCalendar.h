#pragma once
#ifndef DRAWCALENDAR_H
#define DRAWCALENDAR_H

#include "GetDate.h"
#include "DrawUI.h"

void PrintCalendarMonth(ldate date);// ���ϴ� ��¥�� ��,�� �� ��ܿ� ����ϴ� �Լ�
void PrintCalendardate(ldate date);	// ���ϴ� �޷��� �� ��(1 ~31)�� ����ϴ� �Լ�(���ϴ� ��¥�� ���������� ���)
void PrinttodayCalendar();			// ������ �޷��� ���(����� ������ �ٽ� ���� ��¥�� üũ)
void PrinttselectedCalendar();		// ������ ��¥�� �޷��� ���

#endif