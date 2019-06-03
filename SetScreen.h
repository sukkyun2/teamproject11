#pragma once
#ifndef SETSCREEN_H
#define SETSCREEN_H

#include <stdio.h>
#include <Windows.h>

#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15

HANDLE hStdin;
DWORD fdwSaveOldMode;
DWORD cNumRead, fdwMode, i;
INPUT_RECORD irInBuf[128];

int onecols, onerows;
COORD pos_start, pos_end;

void setFullscreen();		// ��üũ��� ��ȭ
COORD getFullscreen();		// ��üũ�� ����
void getform();				// ��¹��� ���� ũ��, ����(Excel ����) ����
void gotoxy(int x, int y);	// Ŀ�� ��ġ �̵�
void remove_scrollbar();
void setInput();

void textcolor(int foreground, int background);

#endif