#pragma once
#ifndef GETDATE_H
#define GETDATE_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include"DrawUI.h"

// ����
int weekday, monthday;

typedef struct localdate
{
	int tm_day;  /* Day of month (1--31) */
	int tm_mon; /* Month (0--11) */
	int tm_year;  /* Year (calendar year minus 1900) */
}ldate;

ldate today, selected_day;

void GetToday();				// ���� ��¥ �ޱ�
void GetSelectedday(ldate date);			// ������ ��¥ �ޱ�
void GetMonthDay(ldate date);			// ���ϴ� ��¥�� �� �� ã�� 	
void GetWeekDay(ldate date, int day);	// ���ϴ� ��¥�� �������� ������ ã��
void GetDay(ldate date);				// ���ϴ� �� ��, �������� ������

#endif