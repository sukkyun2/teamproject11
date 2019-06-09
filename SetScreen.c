#include "SetScreen.h"

void setFullscreen()
{
	SetConsoleDisplayMode(	// <windows.h> 헤더파일 이용
		GetStdHandle(STD_OUTPUT_HANDLE),
		CONSOLE_FULLSCREEN_MODE,
		0
	);
	remove_scrollbar();
	setInput();
	textcolor(WHITE, BLACK);
}
//https://docs.microsoft.com/en-us/windows/console/setconsoledisplaymode

COORD getFullscreen()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	return GetLargestConsoleWindowSize(hOut);
}

void getform()
{
	pos_full.X = getFullscreen().X;
	pos_full.Y = getFullscreen().Y;

	onecols = (int)((double)pos_full.X / 12.0);
	onerows = (int)((double)(pos_full.Y - 6.0) / 8.5);
}

void gotoxy(int x, int y)
{                                       // 좌표값 얻기
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void remove_scrollbar()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}
//출처: https://wowan.tistory.com/6?category=682208 [DevWarehouse]
void setInput()
{
	// 기본 입출력 설정
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
		;

	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		;
	// 윈도우 10 필수 사항

// 퀵 모드 해제
	fdwMode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(hStdin, fdwMode))
		;
	// 입출력 설정
	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode))
		;
}

void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}