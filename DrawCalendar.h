#pragma once

#include "GetDate.h"
#include "SetScreen.h"

void PrintSelectdateButton();		// ��¥ ������ ���� ��ư
void PrinttSelectdateInputbox();
void PrinttodaydateButton();		// ���� ��¥�� ���ư��� ��ư
void getCalendarSize();				// �޷��� ����� �����ϴ� �Լ�(��üũ��)
void PrintCalendar_background();	// �޷��� ���¸� ����ϴ� �Լ�
void PrintCalendarweek();			// �� �� ȭ �� �� �� �� �� ����ϴ� �Լ�
void PrintCalendarMonth(ldate date);// ���ϴ� ��¥�� ��,�� �� ��ܿ� ����ϴ� �Լ�
void PrintCalendardate(ldate date);	// ���ϴ� �޷��� �� ��(1 ~31)�� ����ϴ� �Լ�(���ϴ� ��¥�� ���������� ���)
void PrinttodayCalendar();			// ������ �޷��� ���(����� ������ �ٽ� ���� ��¥�� üũ)
void PrinttselectedCalendar();		// ������ ��¥�� �޷��� ���