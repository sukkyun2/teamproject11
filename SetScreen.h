#pragma once

#include <stdio.h>
#include <Windows.h>

int onecols, onerows;
COORD pos_start, pos_end;

void setfFullscreen();		// ��üũ��� ��ȭ
COORD getfFullscreen();		// ��üũ�� ����
void getform();				// ��¹��� ���� ũ��, ����(Excel ����) ����
void gotoxy(int x, int y);	// Ŀ�� ��ġ �̵�
void remove_scrollbar();