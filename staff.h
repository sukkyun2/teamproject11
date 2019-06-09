#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

#define max_people 100

typedef struct people   //직원
{
	char name[10]; //이름
	char birth[10]; //생년월일 
	char phone_num[15]; //휴대폰 번호
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