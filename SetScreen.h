#pragma once

#include <Windows.h>

COORD pos_start, pos_end;
int onerows, onecols;

void setfFullscreen();		// ��üũ��� ��ȭ
COORD getfFullscreen();		// ��üũ�� ����
void getform();				// ��¹��� ���� ũ��, ����(Excel ����) ����
void gotoxy(int x, int y);	// Ŀ�� ��ġ �̵�
void remove_scrollbar();
