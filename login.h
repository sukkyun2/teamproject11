#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

typedef struct login {			// �α��� ����ü
	char ID[10];
	char PW[10];
}login;

void screen(int x, int y);
void Fullscreen();
void Print_ChangeID();
void Print_login();
void Login();
