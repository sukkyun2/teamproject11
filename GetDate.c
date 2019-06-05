#include"GetDate.h"

// �Լ�
void GetToday()
{
	time_t timer;
	struct tm* t;

	timer = time(NULL); // ���� �ð��� �� ������ ���
	t = localtime(&timer); // �� ������ �ð��� �и��Ͽ� ����ü�� �ֱ�

	today.tm_year = (t->tm_year + 1900);
	today.tm_mon = (t->tm_mon + 1);
	today.tm_day = (t->tm_mday);
	GetDay(today);
}
//http://mwultong.blogspot.com/2006/10/c-current-date-time.html

void GetSelectedday(ldate date)
{
	char buf[11];
	int cnt = 0, key;  // �Է� ���� ���� ���� Ű 
	int i;

	PrinttSelectdateInputbox();
	gotoxy(pos_start.X, pos_start.Y);
	while (1)
	{
		key = getch();  // �� ���� �Է¹���

		if (key == ENTER_KEY)  // ���� �Ǵ� �� Ű�� ����
			break;
		else if (key == BACKSPACE_KEY)	// �齺���̽� Ű
		{
			printf("\b");
			fputs(" ", stdout);
			printf("\b");

			if (cnt > 0)
				cnt--;
		}
		if (cnt != 0)
		{
			gotoxy(pos_start.X + 2, pos_start.Y);
			PrinttSelectdateInputbox_beinput();
		}
		else if (cnt == 0)
		{
			PrinttSelectdateInputbox();
		}

		buf[cnt++] = (char)key;   // ���ۿ� ���� �����ϰ� ī��Ʈ 1 ����
		gotoxy(pos_start.X + 2, pos_start.Y);
		for (i = 0; i < cnt; i++)
			printf("%c", buf[i]);  // ȭ�鿡 �� ǥ�� 

		if (cnt == 10)  // �ִ� ũ�⸦ �Ѿ�� ���� 
			break;
	}

	date.tm_year = 1000 * (buf[0]-'0') + 100 * (buf[1] - '0') + 10 * (buf[2] - '0') + (buf[3] - '0');

	if (buf[6] == '-')
	{
		date.tm_mon = (buf[5] - '0');

		if (buf[8] == '\n')
			date.tm_day = (buf[7] - '0');
		else
			date.tm_day = 10 * (buf[7] - '0') + (buf[8] - '0');
	}
	else
	{
		date.tm_mon = 10 * (buf[5] - '0') + (buf[6] - '0');

		if (buf[9] == '\n')
			date.tm_day = (buf[8] - '0');
		else
			date.tm_day = 10 * (buf[8] - '0') + (buf[9] - '0');
	}
	textcolor(WHITE, BLACK);
	gotoxy(pos_start.X + 2, pos_start.Y);
	for (i = pos_start.X; i < pos_end.X; i++)
		printf(" ");

	if (date.tm_mon > 12)
		PrintHomepage();
	GetMonthDay(date);
	if (date.tm_day > monthday)
		PrintHomepage();
}

void GetMonthDay(ldate date)
{
	switch (date.tm_mon)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		monthday = 31;
		break;

	case 4: case 6: case 9: case 11:
		monthday = 30;
		break;

	case 2:
		if (date.tm_year % 4 == 0 && date.tm_year % 100 != 0 || date.tm_year % 400 == 0)
			monthday = 29;
		else
			monthday = 28;
		break;

	default:
		monthday = 0;
	}
}

void GetWeekDay(ldate date, int day)
{
	if (date.tm_mon == 1 || date.tm_mon == 2) {
		date.tm_year--;
		date.tm_mon += 12;
	}
	weekday = (date.tm_year + date.tm_year / 4 - date.tm_year / 100 + date.tm_year / 400 + (13 * date.tm_mon + 8) / 5 + day) % 7;
}
// https://cafe.naver.com/cafec/165808

void GetDay(ldate date)
{
	GetMonthDay(date);
	GetWeekDay(date, 1);
}