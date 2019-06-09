#pragma once
#include <stdio.h> 
#include <Windows.h>
#include "SetScreen.h"
#include"DrawMainMenu.h"
#include"DrawCalendar.h"

INPUT_RECORD rec;
DWORD        dwNOER;

COORD Mouse;

//출처: https://10gleza.tistory.com/entry/C언어-콘솔창에서-마우스값-받아오기 [10글자의 게임개발 티스토리]

void getClickMouse();

void ControlMainmenu();
