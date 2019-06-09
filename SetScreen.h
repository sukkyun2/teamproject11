#pragma once

#include <Windows.h>

COORD pos_start, pos_end;
int onerows, onecols;

void setfFullscreen();		// 전체크기로 변화
COORD getfFullscreen();		// 전체크기 측정
void getform();				// 출력물의 기준 크기, 예시(Excel 파일) 참고
void gotoxy(int x, int y);	// 커서 위치 이동
void remove_scrollbar();
