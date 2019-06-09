#include"DrawCenterBox.h"

int Box_width, Box_height;

void getcenter()
{
	getform();

	pos_start.X = (int)(pos_start.X / 2);
	pos_start.Y = (int)(pos_start.Y / 2);
}

void getCenterBoxSize(int width, int height)
{
	getcenter();

	pos_start.X -= (int)(width / 2);
	pos_start.Y -= (int)(height / 2);

	pos_end.X = pos_start.X + width;
	pos_end.Y = pos_start.Y + height;

	Box_width = pos_end.X - pos_start.X;
	Box_height = pos_end.Y - pos_start.Y;
}

void DrawCenterBox(int width, int height)
{
	getCenterBoxSize(width, height);

	COORD tmp;
	int r, c;

	tmp.X = pos_start.X;	tmp.Y = pos_start.Y;

	gotoxy(tmp.X, tmp.Y);

	for (c = 1; c <= Box_height; c++)
	{
		if (c == 1)
		{
			for (r = 1; r <= Box_width; r++)
			{

				if (r == 1) printf("¦£");
				else if (r == Box_width) printf("¦¤");
				else printf("¦¡");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		else if (c == Box_height)
		{
			for (r = 1; r <= Box_width; r++)
			{

				if (r == 1) printf("¦¦");
				else if (r == Box_width) printf("¦¥");
				else printf("¦¡");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		else
		{
			for (r = 1; r <= Box_width; r++)
			{
				if ((r == 1) || (r == Box_width)) printf("¦¢");
				else printf(" ");
				tmp.X++;	gotoxy(tmp.X, tmp.Y);
			}
		}
		tmp.X = pos_start.X;	tmp.Y++;
		gotoxy(tmp.X, tmp.Y);
	}
}