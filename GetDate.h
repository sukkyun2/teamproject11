#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

// ����
int weekday, monthday;

typedef struct localdate
{
	int tm_mday;  /* Day of month (1--31) */
	int tm_mon; /* Month (0--11) */
	int tm_year;  /* Year (calendar year minus 1900) */
}ldate;

ldate today, selcted_day;

void GetToday();				// ���� ��¥ �ޱ�
void GetSelectedday();			// ������ ��¥ �ޱ�
void GetMonthDay(ldate date);			// ���ϴ� ��¥�� �� �� ã�� 	
void GetWeekDay(ldate date, int day);	// ���ϴ� ��¥�� �������� ������ ã��
void GetDay(ldate date);				// ���ϴ� �� ��, �������� ������
