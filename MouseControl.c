#include"MouseControl.h"

void getClickMouse()
{
	while (1)
	{
		ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // �ܼ�â �Է��� �޾Ƶ���.
		if (rec.EventType == MOUSE_EVENT) // ���콺 �̺�Ʈ�� ���
		{
			if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) // ���� ��ư�� Ŭ���Ǿ��� ���
			{
				Mouse.X = rec.Event.MouseEvent.dwMousePosition.X; // X�� �޾ƿ�
				Mouse.Y = rec.Event.MouseEvent.dwMousePosition.Y; // Y�� �޾ƿ�
				// 1. � �޴�â���� Ȯ��
				// 2. ������ �ɸ��ߴ��� Ȯ��
					// if MainMEnuâ�̴�. ControlMainmenu();
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
	if (Mouse.X > pos_start.X && Mouse.X < pos_end.X && Mouse.Y > pos_start.Y && Mouse.Y < pos_end.Y)	// �޴�â ��ġ����
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
					//��������
					break;
				case 3:
					//�ٹ�����
					break;
				case 4:
					//�ι��˻�
					break;
				case 5:
					exit(0);	//���α׷� ����
					break;
				}
			}
		}
		return;
	}
	getCalendarSize();
	if (Mouse.X > pos_start.X && Mouse.X < pos_end.X && Mouse.Y > pos_start.Y && Mouse.Y < pos_end.Y)	// �޷� ��ġ����
	{
		if (Mouse.Y > (int)((double)(1.0 * onerows) + 3) && Mouse.Y < (int)((double)(2.0 * onerows) + 3) && Mouse.X >(int)((double)(6.5 * onecols)))
		{
			GetToday();	//���� ��¥ �ް�
			//�ٽ� �޷� �׸���
		}

	}
	else if (Mouse.Y == (int)((double)(1.0 * onerows) + 2))
	{
		Mouse.X = (int)((double)(7.0 * onecols) + 4);
		gotoxy(Mouse.X, Mouse.Y);
		GetSelectedday();	//��¥�ް�
		// �ٽ� �޷� �׸���
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

��ó: https://10gleza.tistory.com/entry/C���-�ܼ�â����-���콺��-�޾ƿ��� [10������ ���Ӱ��� Ƽ���丮]
*/