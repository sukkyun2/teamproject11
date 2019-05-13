#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#define max_people 100

typedef struct people   //����
{
	char name[10]; //�̸�
	char birth[10]; //������� 
	char phone_num[15]; //�޴��� ��ȣ
	struct people *next;
	struct Schedule Schedule[32]; //�迭�� ũ�⸦ �Ѵ޷� ������
	float count; //�ʱⰪ�� 3(�ִ� ��밡���� �ް�,������ ��, �ܱ��� �����Ѵ�)
};

typedef struct Schedule
{
	int outside_duty[24]; //�ܱ�
	int day[2]; //�ε����� 10->���� ����, 01->���� ���� 11->�ް�
	//���� ���� : ���� 2�ø� �������� ���� ������ ���� ������ ����������.
};


typedef struct Work
{
	int weekdays_count; //���� ī��Ʈ
	int weekend_count;  //�ָ� ī��Ʈ

};

void Print_Staff_Menu();
void Staff();
void Insert_Staff();
void Delete_Staff();
void Change_Staff();
void Retrieve_Staff();
void Retrieve();
int Check();


