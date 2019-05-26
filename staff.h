#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#include "DrawSideMenu.h"
#include "menu.h"
#include "login.h"

#define max_people 100
#define staffMenuNum 5

// 변수
typedef struct people* staff;
typedef struct Schedule* schedule;

staff retData;
char newname[10];



typedef struct Schedule
{
	int outside_duty[24]; //외근
	int day[2]; //인덱스가 10->오전 반차, 01->오후 반차 11->휴가
	//반차 설명 : 오후 2시를 기준으로 오전 반차와 오후 반차로 나누어진다.
};
typedef struct people   //직원
{
	char name[10]; //이름
	char birth[10]; //생년월일 
	char phone_num[15]; //휴대폰 번호
	float count;
	schedule Schedule;
	struct people* next;
};
typedef struct Work
{
	int weekdays_count; //평일 카운트
	int weekend_count;  //주말 카운트

};

void Print_staffinfo();

void Staff();
void Insert_Staff();
void Delete_Staff();
void Change_Staff();
void Retrieve_Staff();
void Retrieve();
int Check();