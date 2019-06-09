#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include "SetScreen.h"

#define _CRT_SECURE_NO_WARNINGS

typedef struct login {			// 로그인 구조체
	char ID[10];
	char PW[10];
}login;

COORD loginpos;

int login_width;
int login_height;

void screen(int x, int y);
void Fullscreen();
void Print_ChangeID();
void Print_login();
void Login();
void Printlogin_background();
void getloginSize();