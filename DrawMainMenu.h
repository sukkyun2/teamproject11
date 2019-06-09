#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#include "SetScreen.h"

#define MenuNum 5

int menu_width, menu_height;

void getmenuSize();				// 메뉴의 출력할 크기 측정
void PrintMenu_background();	// 메뉴의 틀 그리기
void Print_MainMenuinfo();		// 메뉴 정보 출력
void Print_MainMenu();			// 메뉴 출력
