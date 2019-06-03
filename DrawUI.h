#pragma once

#ifndef DRAWUI_H
#define DRAWUI_H

#include"SetScreen.h"

COORD loginpos;

int statusbar_width, statusbar_height;
int calendar_width, calendar_height;

int menu_width, menu_height;
COORD menupos_start, menupos_end;

COORD controlpos_start, controlpos_end;

COORD navipos_start, navipos_end;
int navigator_height, navigator_width;

void getcenter();
void getCenterBoxSize(int width, int height);
void DrawCenterBox(int width, int height);

void getStatusbarSize();
void PrintStatusbar();
void PrintHomeButton();

void PrintSelectdateButton();		// ��¥ ������ ���� ��ư
void PrinttSelectdateInputbox();
void PrinttodaydateButton();		// ���� ��¥�� ���ư��� ��ư

void getCalendarSize();				// �޷��� ����� �����ϴ� �Լ�(��üũ��)
void PrintCalendar_background();	// �޷��� ���¸� ����ϴ� �Լ�
void PrintCalendarweek();
void PrintCalendarform();

void getnavigatorSize();
void Printnavigator_background();

void getmenuSize();				// �޴��� ����� ũ�� ����
void PrintMenu_background();	// �޴��� Ʋ �׸���

void getSideMenuSize();
void PrintSideMenu_background();
void print_askMenunum(COORD* tmp);

#endif