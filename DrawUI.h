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

void PrintSelectdateButton();		// 날짜 선택을 위한 버튼
void PrinttSelectdateInputbox();
void PrinttodaydateButton();		// 오늘 날짜로 돌아가는 버튼

void getCalendarSize();				// 달력의 사이즈를 측정하는 함수(전체크기)
void PrintCalendar_background();	// 달력의 형태를 출력하는 함수
void PrintCalendarweek();
void PrintCalendarform();

void getnavigatorSize();
void Printnavigator_background();

void getmenuSize();				// 메뉴의 출력할 크기 측정
void PrintMenu_background();	// 메뉴의 틀 그리기

void getSideMenuSize();
void PrintSideMenu_background();
void print_askMenunum(COORD* tmp);

#endif