#include"KeyMouseControl.h"

void ErrorExit(LPSTR);
void KeyEventProc(KEY_EVENT_RECORD);
void MouseEventProc(MOUSE_EVENT_RECORD);
void ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);

int control(void) 
{
	while (1)
	{
		// Wait for the events. 

		if (!ReadConsoleInput(
			hStdin,      // input buffer handle 
			irInBuf,     // buffer to read into 
			128,         // size of read buffer 
			&cNumRead)) // number of records read 
			ErrorExit("ReadConsoleInput");

		// Dispatch the events to the appropriate handler. 

		for (i = 0; i < cNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT: // 키보드 이벤트 
				KeyEventProc(irInBuf[i].Event.KeyEvent);
				break;

			case MOUSE_EVENT: // 마우스 이벤트
				MouseEventProc(irInBuf[i].Event.MouseEvent);
				break;

			case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
				ResizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);
				break;

			case FOCUS_EVENT:  // disregard focus events 

			case MENU_EVENT:   // disregard menu events 
				break;

			default:
				break;
			}
		}
	}

	// Restore input mode on exit.

	SetConsoleMode(hStdin, fdwSaveOldMode);

	return 0;
}

void ErrorExit(LPSTR lpszMessage)
{
	fprintf(stderr, "%s\n", lpszMessage);

	// Restore input mode on exit.

	SetConsoleMode(hStdin, fdwSaveOldMode);

	ExitProcess(0);
}

void KeyEventProc(KEY_EVENT_RECORD ker)
{
	printf("Key event: ");

	if (ker.bKeyDown)
		printf("key pressed\n");
	else printf("key released\n");
}

void MouseEventProc(MOUSE_EVENT_RECORD mer)
{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif

	switch (mer.dwEventFlags)
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)	// 왼쪽 버튼
		{
			
		}
		else
		{
			
		}
		break;
	case DOUBLE_CLICK:
			
		break;
	case MOUSE_HWHEELED:
			
		break;
	case MOUSE_MOVED:
			
		break;
	case MOUSE_WHEELED:
			
		break;
	default:
			
		break;
	}
}

void ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD wbsr)
{
	printf("Resize event\n");
	printf("Console screen buffer is %d columns by %d rows.\n", wbsr.dwSize.X, wbsr.dwSize.Y);
}
