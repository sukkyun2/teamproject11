#include "setting.h"

void setFullscreen()
{
	system("TITLE 일정관리 프로그램");	// 프로그램명
	system("COLOR 07");					// 화면 색상고정(검은화면/하얀글씨)
	SetConsoleDisplayMode(	// <windows.h> 헤더파일 이용
		GetStdHandle(STD_OUTPUT_HANDLE),
		CONSOLE_FULLSCREEN_MODE,
		0
	);
}
//https://docs.microsoft.com/en-us/windows/console/setconsoledisplaymode

void setLoginscreen()
{
	system("TITLE 로그인");	// 프로그램명
	system("COLOR cf");
	system("mode con cols=50 lines=24");
}

COORD getFullscreen()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	return GetLargestConsoleWindowSize(hOut);
}

void getform()
{
	pos_full = getFullscreen();

	onecols = (int)((double)pos_full.X / 12.0);
	onerows = (int)((double)(pos_full.Y - 6.0) / 7.5);
}

void default_setting()
{
	remove_scrollbar();
	setInput();
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
	// 퀵 모드 해제
	fdwMode = ENABLE_EXTENDED_FLAGS;
	// 입출력 설정
	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
}

void gotoxy(int x, int y)
{                                       // 좌표값 얻기
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}