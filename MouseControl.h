#pragma once
#include <stdio.h> 
#include <Windows.h>
#include "SetScreen.h"
#include"DrawMainMenu.h"
#include"DrawCalendar.h"

INPUT_RECORD rec;
DWORD        dwNOER;

COORD Mouse;

//��ó: https://10gleza.tistory.com/entry/C���-�ܼ�â����-���콺��-�޾ƿ��� [10������ ���Ӱ��� Ƽ���丮]

void getClickMouse();

void ControlMainmenu();
