/* 
   �ȳ��Ͻʴϱ� ������ ���� �Դϴ� ^^
   ���߰� ���� �� ���α׷� �ҽ��� ���� �����ֽð� Ī�� �� �ּż� ���� �����ϱ� �����Դϴ�..
   ���� �̷��� �ּ��� ����� �� ������ �� �ҽ��� �������� �а� ���ø� ���� �� ������ �Ǹ��� �����߱� �����Դϴ� ����
   �ϴ� �� �ҽ��� �ٽ��� 
   1. get_input ����� �Լ��� ������ ���� �� ����
   2. getchr�̶�� ����� �Լ��� �̿��Ͽ� �����Ҽ� �ִ� ����
   3. �ܼ��� ����Լ��� �̷�� ���� �Ѵٴ� ���� ���� �ı��Դϴ�.

   �� �ҽ��� ���ø� ���� �β������� ������ �ϴٰ� �� �� �ֽ��ϴ�..
   ������ϰ� ������Լ��� ������ �̿뵵 ���� ���ο� �ֱ���â ��������..(���� ����κ��� �����ؾ� �� ���̳׿�..��)

   �ƹ��ɷ� ���� �ǵ��� �ڵ����� � ������ �� �ľ��غ��ñ� �ڵ��ϽǶ� ���� �ǽñ� �ٶ��ϴ�.
																														*/

#include <stdio.h> 
#include <Windows.h> 

#define col GetStdHandle(STD_OUTPUT_HANDLE) // �ܼ�â�� �ڵ����� �޾ƿ���.
#define RED SetConsoleTextAttribute( col,0x000c); // ������
#define BLUE SetConsoleTextAttribute( col,0x0001 | 0x0008); // �Ķ���
#define YELLOWGREEN SetConsoleTextAttribute( col,0x00a); // ���λ�
#define WHITE SetConsoleTextAttribute( col,0x000f); // ���
#define SKY SetConsoleTextAttribute( col,0x000b); // �ϴû�
#define YELLOW SetConsoleTextAttribute( col,0x000e); // �����
#define FLUORESCENT SetConsoleTextAttribute( col,0x000d); // ������
#define GRAY SetConsoleTextAttribute( col,0x0008); // ȸ��



HANDLE COUT = 0;    // �ܼ� ��� ��ġ
HANDLE CIN = 0;        // �ܼ� �Է� ��ġ

////���� �߿��� ��ȭ ����////
int rec_x[10000],rec_y[10000],rec_font[10000],rec_color[10000];
char rec_save[10000];
int count_x = 0, count_y = 0, count_font = 0, count_color = 0, count_save = 0;


/////////////////////�Լ�ȣ��//////////////////////////////

void gotoxy(int x, int y)      // ��ǥ ������ gotoxy
{
     COORD Cur;
     Cur.X=x;
     Cur.Y=y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);
}


int be_input()
{
    INPUT_RECORD input_record;
    DWORD input_count;

    PeekConsoleInput(CIN, &input_record, 1, &input_count);
    return input_count;
}

int get_input(WORD *vkey, COORD *pos)
{
    INPUT_RECORD input_record;
    DWORD input_count;
	static int check_pen = 0; // �������Ѿ� �浵 ������



    ReadConsoleInput(CIN, &input_record, 1, &input_count);
    switch(input_record.EventType) {
    case MOUSE_EVENT:
        if(pos && (input_record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)) //���ʹ�ư
		{
            CONSOLE_SCREEN_BUFFER_INFO csbi;
    
            GetConsoleScreenBufferInfo(COUT,&csbi);

            *pos = input_record.Event.MouseEvent.dwMousePosition;
            pos->X -= csbi.srWindow.Left;
            pos->Y -= csbi.srWindow.Top;
					
			if(pos->X <= 79 && pos->Y <= 2)
			{/*�׸��� ����*/}
			else if(pos->X <= 79 && pos->Y >= 24)
			{/*�׸��� ����*/}
			else if(pos -> X == 79)
			{/*�׸��� ����*/}
			
			else if(pos->X <= 7 && pos->Y <= 24)
			{		
				
				if(pos->X >= 0 && pos->X<= 2)
				{
					if(pos->Y >= 9 && pos->Y <= 10)
					{
						check_pen = 0;
					}
					else if(pos->Y >= 11 && pos->Y<= 12)
					{
						check_pen = 1;
					}
					else if(pos->Y >= 13 && pos->Y<= 14)
					{
						check_pen = 2;
					}
				}
				else if(pos->X >= 4 && pos->X <= 6)
				{
					if(pos->Y >= 9 && pos->Y <=10)
					{
						check_pen = 3;
					}
					else if(pos->Y >= 11 && pos->Y<= 12)
					{
						check_pen = 4;
					}
					else if(pos->Y >= 13 && pos->Y<= 14)
					{
						check_pen = 5;
					}
				}
			
			}
			

				
	

			else
			{



				if(check_pen == 0)
				{
					gotoxy(pos->X,pos->Y);
					printf(".");
					gotoxy(0,0);
					
					rec_font[count_font] = 0;
					count_font ++;

				}
				else if(check_pen == 1)
				{
					gotoxy(pos->X,pos->Y);
					printf("*");
					gotoxy(0,0);
					
					rec_font[count_font] = 1;
					count_font ++;

				}
				else if(check_pen == 2)
				{
					gotoxy(pos->X,pos->Y);
					printf("+");
					gotoxy(0,0);
					
					rec_font[count_font] = 2;
					count_font ++;

				}
				else if(check_pen == 3)
				{
					gotoxy(pos->X,pos->Y);
					printf("#");
					gotoxy(0,0);
					
					rec_font[count_font] = 3;
					count_font ++;

				}
				else if(check_pen == 4)
				{
					gotoxy(pos->X,pos->Y);
					printf("=");
					gotoxy(0,0);
					
					rec_font[count_font] = 4;
					count_font ++;

				}
				else if(check_pen == 5)
				{
					gotoxy(pos->X,pos->Y);
					printf("-");
					gotoxy(0,0);
					
					rec_font[count_font] = 5;
					count_font ++;

				}
			}

            return MOUSE_EVENT;
        }
		else if(pos && (input_record.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED)) // ������ ��ư ��������
		{
			CONSOLE_SCREEN_BUFFER_INFO csbi;
    
            GetConsoleScreenBufferInfo(COUT,&csbi);

            *pos = input_record.Event.MouseEvent.dwMousePosition;
            pos->X -= csbi.srWindow.Left;
            pos->Y -= csbi.srWindow.Top;
			

			if(pos->X <= 79 && pos->Y <= 2)
			{/*����� ����*/}
			else if(pos->X <= 7 && pos->Y<= 24)
			{/*����� ����*/}
			else if(pos->X <= 79 && pos->Y >= 24)
			{/*����� ����*/}
			else if(pos -> X == 79)
			{/*����� ����*/}
			else
			{
			gotoxy(pos->X,pos->Y);
		    printf(" ");
			gotoxy(0,0);
			
			rec_font[count_font] = 6; // 6�� ����
			count_font ++;

			}



			return MOUSE_EVENT;
		}
        break;
		
    }

//    FlushConsoleInputBuffer(CIN);
    return 0;
}


char getchr(int x, int y) // �� ��ǥ�� ����ִ� ���ڸ� ���

{

 COORD pos={x, y};

 TCHAR ch;

 DWORD rd;

 ReadConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), &ch, 1, pos, &rd);

 return ch;

}



//////////////////�������� �ҽ�////////////////////////
int main()      
{
    DWORD mode;
    WORD key;
    COORD pos;
	int event;																								// ���콺 �̺�Ʈ�� �̿�
	int x;																									// ���콺�� x��ǥ �����
	int y;																									// ���콺�� y��ǥ �����
	int make_frame = 0;	// �׵θ� �ۼ� ����
	int clear_width = 8,clear_length = 3;
	int check_help = 0;
	POINT mouse;
	FILE *paintboard_save;
	
	system("mode con: cols=80 lines=26"); // ȭ�� ����


    CIN = GetStdHandle(STD_INPUT_HANDLE);
    COUT = GetStdHandle(STD_OUTPUT_HANDLE);

    // ���콺 Ȱ��ȭ
    GetConsoleMode(CIN,&mode);
    SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	// ����� �Լ��� �ֱ� //
		GRAY;
		while(make_frame != 80) // ������ ä���
		{
			gotoxy(make_frame,2); printf("*"); 
			gotoxy(make_frame,24); printf("*");
			make_frame ++;
		}
		make_frame = 0;
		while(make_frame != 25) // ������ ä���
		{
			gotoxy(7,make_frame); printf("*");
			gotoxy(79,make_frame); printf("*");
			make_frame++;
		}

		make_frame = 2;
		while(make_frame != 26) // �����ٿ� ........�Ѱ� 
		{
			gotoxy(0,make_frame); printf("*******");
			make_frame = make_frame + 2;
		}
		WHITE;


		gotoxy(0,3); WHITE;printf("��");	gotoxy(0,5); YELLOW;printf("��");		gotoxy(0,7); RED;printf("��");WHITE;
		gotoxy(4,3); GRAY;printf("��");		gotoxy(4,5); SKY;printf("��");			gotoxy(4,7); YELLOWGREEN;printf("��");WHITE;
		
		gotoxy(1,9); printf(".");		gotoxy(1,11); printf("*");			gotoxy(1,13); printf("+");WHITE;
		gotoxy(5,9); printf("#");		gotoxy(5,11); printf("=");			gotoxy(5,13); printf("-");WHITE;
		
		gotoxy(1,15); printf("Reset");	gotoxy(1,17); printf("Save");	
		gotoxy(0,19); printf("Replay"); gotoxy(1,21); printf("Help"); gotoxy(1,23); printf("EXIT");

		GRAY;
		make_frame = 3;
		while(make_frame != 15)
		{
			gotoxy(3,make_frame); printf("*");
			make_frame = make_frame + 2;
		}
		WHITE;

		gotoxy(30,1); printf("C program Paint Board");
		GRAY; gotoxy(60,1); printf("*");gotoxy(60,0); printf("*"); WHITE;
		
		gotoxy(63,1); printf("made by :: ����");
		
		// -- - -- - - - ----- - -//	
	
		
		
	while(1)																// �׻� ���콺 Ŭ���� �ǵ��� while(1)�� ����
    {	
		
        if(be_input() ) 
		{	
            if(get_input(&key,&pos) != 0  )									// ���콺 Ŭ���Ҽ��ֵ��� ������� �Լ�
			{ 
			
			MOUSE_EVENT;	
			x = pos.X;													// ���콺Ŭ������ x,y������ ����ǵ�����
			y = pos.Y;
				
			//���� �ִ� 79
			//���� �ִ� 24
							
				if(x >= 0 && x<= 2)
				{
					if(y >= 3 && y<= 4)
					{
						WHITE;
						rec_color[count_color] = 1;
						
					}
					else if(y >= 5 && y<= 6)
					{
						YELLOW;
						rec_color[count_color] = 2;
						
					}
					else if(y >= 7 && y <= 8)
					{
						RED;
						rec_color[count_color] = 3;
						
					}


				}
				else if(x >= 4 && x <= 6)
				{
					if(y >= 3 && y<= 4)
					{
						GRAY;
						rec_color[count_color] = 4;
						
					}
					else if(y >= 5 && y<= 6)
					{
						SKY;
						rec_color[count_color] = 5;
						
					}
					else if(y >= 7 && y <= 8)
					{
						YELLOWGREEN;
						rec_color[count_color] = 6;
						
					}
					

				}

				////

				if(x >= 8 && x <= 78) // ��ȭ���� �׸��� ��ǥǥ��
			{
				if(y >= 3 && y <= 23)
				{
				rec_x[count_x] = pos.X;
				rec_y[count_y] = pos.Y;
				count_x ++; count_y ++; count_color ++;

						gotoxy(1,1);
						printf("     ");
						gotoxy(1,1);
						printf("%d,%d",x,y);
				}
			}







				if( x>=0 && x<= 6) // �������� ����
				{
					if(y >= 15 && y <=16) // RESET
					{
						count_x = 0; count_y = 0; count_font = 0, count_color = 0; WHITE;
						while(count_x <= 5000)
						{
							rec_x[count_x] = 0; rec_y[count_y] = 0; rec_font[count_font] = 0, rec_color[count_color] = 0;  // ��ȭ ����
							count_x ++; count_y ++; count_font ++; count_color ++;
						}
						clear_length = 3;
						clear_width = 8;
						while(clear_length <= 23)
						{
							while(clear_width <= 78)
							{
								gotoxy(clear_width,clear_length);printf(" ");
								clear_width ++;
								
							}
							clear_width = 8;
							clear_length ++;
							Sleep(1);
						}
						
					}


					else if(y >= 17 && y <= 18) // SAVE
					{
						clear_length = 3;
						clear_width = 8;
						paintboard_save = fopen("paintboard_save","w");
						count_save = 0;

						while(count_save != 1491) // ����� �ʱ�ȭ
						{
							rec_save[count_save] = 0; 
							count_save ++;
						}

						count_save = 0;
						while(clear_length <= 23)
						{
							while(clear_width <= 78)
							{
								gotoxy(clear_width,clear_length);
								
								if(getchr(clear_width,clear_length) == '.' ||getchr(clear_width,clear_length) == '*' ||getchr(clear_width,clear_length) == '+' ||getchr(clear_width,clear_length) == '#' ||getchr(clear_width,clear_length) == '=' ||getchr(clear_width,clear_length) == '-')
								{
									rec_save[count_save] = getchr(clear_width,clear_length);
								}
								else
								{
									rec_save[count_save] = ' ';
								}
								
								clear_width ++;	
								count_save++;
													
							}
							Sleep(1);
							clear_width = 8;
							clear_length ++;
						}

						count_save = 0;

						while(count_save != 1491)
						{
						
						fprintf(paintboard_save,"%c",rec_save[count_save]);
						if(count_save % 71 == 0)
						{
							if(count_save == 0)
							{
							}
							else
							{
							fprintf(paintboard_save,"\n");
						
							}
						}
						count_save ++;
						}




						fclose(paintboard_save);
					}

					else if(y >= 19 && y <= 20) // Replay
					{
						clear_length = 3;
						clear_width = 8;
						while(clear_length <= 23)
						{
							while(clear_width <= 78)
							{
								gotoxy(clear_width,clear_length);printf(" ");
								clear_width ++;
								
							}
							clear_width = 8;
							clear_length ++;
							Sleep(50);
						}

						
						
						count_x = 0; count_y = 0; count_font = 0, count_color = 0; WHITE;

						// ���� �� //

						while(rec_x[count_x] != 0)
						{
							gotoxy(rec_x[count_x],rec_y[count_y]);
	
							if(rec_color[count_color] == 1)
							{	printf("");WHITE;	}

							else if(rec_color[count_color] == 2)
							{	printf("");YELLOW;	}

							else if(rec_color[count_color] == 3)
							{	printf("");RED;	}
							
							else if(rec_color[count_color] == 4)
							{	printf("");GRAY;	}
							
							else if(rec_color[count_color] == 5)
							{	printf("");SKY;	}
							
							else if(rec_color[count_color] == 6)
							{	printf("");YELLOWGREEN;	}


							if(rec_font[count_font] == 0)
							{	printf(".");	}

							else if(rec_font[count_font] == 1)
							{	printf("*");	}

							else if(rec_font[count_font] == 2)
							{	printf("+");	}

							else if(rec_font[count_font] == 3)
							{	printf("#");	}

							else if(rec_font[count_font] == 4)
							{	printf("=");	}

							else if(rec_font[count_font] == 5)
							{	printf("-");	}

							else if(rec_font[count_font] == 6)
							{	printf(" ");	}



							count_x++; count_y++; count_font++, count_color++;;
							Sleep(15);
						}

					}

					else if(y >= 21 && y <= 22 && check_help == 0) // Help on
					{
						check_help = 1; // �������� ������ ��������
						clear_length = 3;
						clear_width = 8;
						while(clear_length <= 23)
						{
							while(clear_width <= 78)
							{
								gotoxy(clear_width,clear_length);printf(" ");
								clear_width ++;
								
							}
							clear_width = 8;
							clear_length ++;
						}

						
						
						

						// ���� �� //
						WHITE;

						gotoxy(14,3); printf("#"); gotoxy(12,4); printf("###"); gotoxy(10,5); printf("##########");
						gotoxy(14,7); printf("#"); gotoxy(12,6); printf("###"); 

						gotoxy(30,5);	printf("�̰��� Ŭ���Ͻø� �پ��� "); RED;printf("����");WHITE;printf("����");
						gotoxy(30,6);	printf("�׸��� �׸��� �� �ֽ��ϴ�.");

						gotoxy(14,9); printf("#"); gotoxy(12,10); printf("###"); gotoxy(10,11); printf("##########");
						gotoxy(14,13); printf("#"); gotoxy(12,12); printf("###"); 
						
						gotoxy(32,8); printf(" *** ������ ���콺Ű : ���찳 ***");
						gotoxy(30,11);	printf("�̰��� Ŭ���Ͻø� �پ��� "); RED;printf("���");WHITE;printf("����");
						gotoxy(30,12);	printf("�׸��� �׸��� �� �ֽ��ϴ�.");

						gotoxy(11,15); RED;printf("<");WHITE;  printf("�׸����� �����ݴϴ�. �̶� ����Ǿ��ִ� �� ���� �ʱ�ȭ �˴ϴ�.");
						gotoxy(11,17); RED;printf("<");WHITE;  printf("�׸��ǿ� �׷ȴ� �׸��� text���Ϸ� ������ �ݴϴ�.");
						gotoxy(11,19); RED;printf("<");WHITE;  printf("���ݱ��� �׷ȴ� ����� ó������ �ٽ� �����ݴϴ�.");
						gotoxy(11,21); RED;printf("<");WHITE;  printf("����");
						gotoxy(11,23); RED;printf("<");WHITE;  printf("�����ϱ�");
					

						gotoxy(35,22);RED;printf("**  ");WHITE; printf("HelpŰ�� �ٽ� �����ø� ");gotoxy(35,23); printf("������ ����˴ϴ�.");
					}

					else if(y >= 21 && y <= 22 && check_help == 1) // Help off
					{
						check_help = 0; // �������� ������ ��������
						clear_length = 3;
						clear_width = 8;
						while(clear_length <= 23)
						{
							while(clear_width <= 78)
							{
								gotoxy(clear_width,clear_length);printf(" ");
								clear_width ++;
								
							}
							clear_width = 8;
							clear_length ++;
						}
					}
					
					else if(y >= 23 && y <= 24) // EXIT
					{
						 return 0;
					}

				}




			}// if(get_input(&key,&pos) != 0  )
		}// if(be_input())




	}
}
