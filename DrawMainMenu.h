#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#include "SetScreen.h"

#define MenuNum 5

int menu_width, menu_height;

void getmenuSize();				// �޴��� ����� ũ�� ����
void PrintMenu_background();	// �޴��� Ʋ �׸���
void Print_MainMenuinfo();		// �޴� ���� ���
void Print_MainMenu();			// �޴� ���
