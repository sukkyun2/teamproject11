#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#define max_people 100

typedef struct people   //직원
{
	char name[10]; //이름
	char birth[10]; //생년월일 
	char phone_num[15]; //휴대폰 번호
	struct people *next;
	struct Schedule Schedule[32]; //배열의 크기를 한달로 설정함
	float count; //초기값은 3(최대 사용가능한 휴가,반차의 합, 외근은 제외한다)
};

typedef struct Schedule
{
	int outside_duty[24]; //외근
	int day[2]; //인덱스가 10->오전 반차, 01->오후 반차 11->휴가
	//반차 설명 : 오후 2시를 기준으로 오전 반차와 오후 반차로 나누어진다.
};


typedef struct Work
{
	int weekdays_count; //평일 카운트
	int weekend_count;  //주말 카운트

};

void Print_Staff_Menu();
void Staff();
void Insert_Staff();
void Delete_Staff();
void Change_Staff();
void Retrieve_Staff();
void Retrieve();
int Check();


