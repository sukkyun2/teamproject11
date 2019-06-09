#pragma once

#include"DrawMainMenu.h"
#include"DrawCalendar.h"
#include"SetScreen.h"

COORD pos_start, pos_end;
int onerows, onecols;

HANDLE COUT;	// 콘솔 출력 장치
HANDLE CIN;		// 콘솔 입력 장치

DWORD mode;
WORD key;
COORD pos;

int be_input();
int get_input(WORD* vkey, COORD* pos);
void MouseOn();