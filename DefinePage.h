// ���콺 ���� ��, �� ��ɺ��� �������� �з��ϱ� ����
// �������� �ʴ��� main�Լ��� �������� �������� ��

#pragma once
#ifndef DEFINEPAGE_H
#define DEFINEPAGE_H

#include"DrawCalendar.h"
#include"DrawMainMenu.h"

//�α��� ȭ��
#define LoginPage 0
#define ChangeIDpage 1

// MainPage
#define HomePage 5	// �α��� ���� ó�� ȭ��



//��������
#define StaffMainPage 10	//���� ���� ���� �� ������

//��������
#define ScheduleMainPage 20

//�ٹ�����
#define WorkMainPage 30

//�ι��˻�

int PAGE;

void PrintHomepage();
void PrintStaffpage();
void PrintSchedulepage();
void PrintWorkpage();

#endif