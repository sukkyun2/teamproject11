#include"MouseControl.h"

void getClickMouse()
{
	while (1)
	{
		ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // 콘솔창 입력을 받아들임.
		if (rec.EventType == MOUSE_EVENT) // 마우스 이벤트일 경우
		{
			if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) // 좌측 버튼이 클릭되었을 경우
			{
				Mouse.X = rec.Event.MouseEvent.dwMousePosition.X; // X값 받아옴
				Mouse.Y = rec.Event.MouseEvent.dwMousePosition.Y; // Y값 받아옴
				// 1. 어떤 메뉴창인지 확인
				// 2. 무엇을 믈릭했는지 확인
					// if MainMEnu창이다. ControlMainmenu();
				return;
			}
		}
	}
}

void ControlMainmenu()
{
	int n, i;
	COORD tmp;
	tmp.X = Mouse.X;	tmp.Y = Mouse.Y;

	getmenuSize();
	if (Mouse.X > pos_start.X && Mouse.X < pos_end.X && Mouse.Y > pos_start.Y && Mouse.Y < pos_end.Y)	// 메뉴창 위치에서
	{
		for (i = 0; 1 < MenuNum; i++)
		{
			tmp.Y = pos_start.Y + 4 + (2 * i);
			n = i + 1;
			if (tmp.Y == pos_start.Y)
			{
				switch (n)
				{
				case 1:
					
					break;
				case 2:
					//일정관리
					break;
				case 3:
					//근무관리
					break;
				case 4:
					//인물검색
					break;
				case 5:
					exit(0);	//프로그램 종료
					break;
				}
			}
		}
		return;
	}
	getCalendarSize();
	if (Mouse.X > pos_start.X && Mouse.X < pos_end.X && Mouse.Y > pos_start.Y && Mouse.Y < pos_end.Y)	// 달력 위치에서
	{
		if (Mouse.Y > (int)((double)(1.0 * onerows) + 3) && Mouse.Y < (int)((double)(2.0 * onerows) + 3) && Mouse.X >(int)((double)(6.5 * onecols)))
		{
			GetToday();	//오늘 날짜 받고
			//다시 달력 그리기
		}

	}
	else if (Mouse.Y == (int)((double)(1.0 * onerows) + 2))
	{
		Mouse.X = (int)((double)(7.0 * onecols) + 4);
		gotoxy(Mouse.X, Mouse.Y);
		GetSelectedday();	//날짜받고
		// 다시 달력 그리기
	}
}



/*
void main()
{
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	while (true)
	{
		CheckMouse();
	}
}

출처: https://10gleza.tistory.com/entry/C언어-콘솔창에서-마우스값-받아오기 [10글자의 게임개발 티스토리]
*/