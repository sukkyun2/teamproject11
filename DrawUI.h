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

void getcenter();
void getCenterBoxSize(int width, int height);
void DrawCenterBox(int width, int height);

void DrawBOX(COORD tmp, int width, int height);

void PrintLoginInputbox();

void PrintStatusbarSize();

void PrintStatusbar();

void PrintHomeButton();

void PrintSelectdateButton();

void PrinttSelectdateInputbox();

void PrinttodaydateButton();

void getCalendarSize();

void PrintCalendar_background();

void PrintCalendarweek();

void PrintCalendarform();

void getMenusize();

void PrintMenu();

void print_askMenunum();

void Printmanagement();

#endif