#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

#define max_people 100

typedef struct people   //����
{
	char name[10]; //�̸�
	char birth[10]; //������� 
	char phone_num[15]; //�޴��� ��ȣ
	struct people *next;
};

void Print_Staff_Menu();
void Staff();
void Insert_Staff();
void Delete_Staff();
void Change_Staff();
void Retrieve_Staff();
void Retrieve();
int Check();