#pragma once

#ifndef STAFF_H
#define STAFF_H

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#include "DrawUI.h"
#include "menu.h"

#define max_people 100
#define staffMenuNum 5

// ����
typedef struct people* staff;
typedef struct Schedule* schedule;

staff head;
staff retData;
char newname[10];

typedef struct Schedule
{
	int outside_duty[24]; //�ܱ�
	int day[2]; //�ε����� 10->���� ����, 01->���� ���� 11->�ް�
	int work_schedule[0];
	//���� ���� : ���� 2�ø� �������� ���� ������ ���� ������ ����������.
};
typedef struct people   //����
{
	char name[10]; //�̸�
	char birth[10]; //������� 
	char phone_num[15]; //�޴��� ��ȣ
	float count;
	int WCount;
	schedule Schedule;
	staff next;
};

void Print_staffinfo();

void Staff();
void Insert_Staff();
void Delete_Staff();
void Change_Staff();
void Retrieve_Staff();
void Retrieve();
int Check();

#endif




