#include "SetScreen.h"

void setfFullscreen()
{
	SetConsoleDisplayMode(	// <windows.h> 헤더파일 이용
		GetStdHandle(STD_OUTPUT_HANDLE),
		CONSOLE_FULLSCREEN_MODE,
		0
	);
	remove_scrollbar();
}
//https://docs.microsoft.com/en-us/windows/console/setconsoledisplaymode

COORD getfFullscreen()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	return GetLargestConsoleWindowSize(hOut);
}

void getform()
{
	pos_start = getfFullscreen();

	onecols = (int)((double)pos_start.X / 12.0);
	onerows = (int)((double)(pos_start.Y - 6.0) / 7.5);
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