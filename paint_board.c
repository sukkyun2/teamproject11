/* 
   안녕하십니까 제작자 가누 입니다 ^^
   보잘것 없는 제 프로그램 소스에 관심 가져주시고 칭찬 해 주셔서 정말 감사하기 따름입니다..
   제가 이렇게 주석을 남기게 된 이유는 이 소스를 보기전에 읽고 가시면 한층 더 도움이 되리라 생각했기 때문입니다 ㅎㅎ
   일단 이 소스의 핵심은 
   1. get_input 사용자 함수의 적절한 변경 및 응용
   2. getchr이라는 사용자 함수를 이용하여 응용할수 있는 범위
   3. 콘솔이 고급함수로 이루어 져야 한다는 것의 관념 파괴입니다.

   제 소스를 보시면 정말 부끄럽지만 지저분 하다고 할 수 있습니다..
   헤더파일과 사용자함수의 적절한 이용도 없이 메인에 주구장창 나열했죠..(제가 여기부분은 개선해야 할 점이네요..ㅠ)

   아무쪼록 제가 의도한 코딩법이 어떤 것인지 잘 파악해보시구 코딩하실때 도움 되시길 바랍니다.
																														*/

#include <stdio.h> 
#include <Windows.h> 

#define col GetStdHandle(STD_OUTPUT_HANDLE) // 콘솔창의 핸들정보 받아오기.
#define RED SetConsoleTextAttribute( col,0x000c); // 빨간색
#define BLUE SetConsoleTextAttribute( col,0x0001 | 0x0008); // 파란색
#define YELLOWGREEN SetConsoleTextAttribute( col,0x00a); // 연두색
#define WHITE SetConsoleTextAttribute( col,0x000f); // 흰색
#define SKY SetConsoleTextAttribute( col,0x000b); // 하늘색
#define YELLOW SetConsoleTextAttribute( col,0x000e); // 노란색
#define FLUORESCENT SetConsoleTextAttribute( col,0x000d); // 형광색
#define GRAY SetConsoleTextAttribute( col,0x0008); // 회색



HANDLE COUT = 0;    // 콘솔 출력 장치
HANDLE CIN = 0;        // 콘솔 입력 장치

////가장 중요한 녹화 변수////
int rec_x[10000],rec_y[10000],rec_font[10000],rec_color[10000];
char rec_save[10000];
int count_x = 0, count_y = 0, count_font = 0, count_color = 0, count_save = 0;


/////////////////////함수호출//////////////////////////////

void gotoxy(int x, int y)      // 좌표 보내기 gotoxy
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
	static int check_pen = 0; // 고정시켜야 펜도 고정됨



    ReadConsoleInput(CIN, &input_record, 1, &input_count);
    switch(input_record.EventType) {
    case MOUSE_EVENT:
        if(pos && (input_record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)) //왼쪽버튼
		{
            CONSOLE_SCREEN_BUFFER_INFO csbi;
    
            GetConsoleScreenBufferInfo(COUT,&csbi);

            *pos = input_record.Event.MouseEvent.dwMousePosition;
            pos->X -= csbi.srWindow.Left;
            pos->Y -= csbi.srWindow.Top;
					
			if(pos->X <= 79 && pos->Y <= 2)
			{/*그릴수 없음*/}
			else if(pos->X <= 79 && pos->Y >= 24)
			{/*그릴수 없음*/}
			else if(pos -> X == 79)
			{/*그릴수 없음*/}
			
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
		else if(pos && (input_record.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED)) // 오른쪽 버튼 눌렀을때
		{
			CONSOLE_SCREEN_BUFFER_INFO csbi;
    
            GetConsoleScreenBufferInfo(COUT,&csbi);

            *pos = input_record.Event.MouseEvent.dwMousePosition;
            pos->X -= csbi.srWindow.Left;
            pos->Y -= csbi.srWindow.Top;
			

			if(pos->X <= 79 && pos->Y <= 2)
			{/*지울수 없음*/}
			else if(pos->X <= 7 && pos->Y<= 24)
			{/*지울수 없음*/}
			else if(pos->X <= 79 && pos->Y >= 24)
			{/*지울수 없음*/}
			else if(pos -> X == 79)
			{/*지울수 없음*/}
			else
			{
			gotoxy(pos->X,pos->Y);
		    printf(" ");
			gotoxy(0,0);
			
			rec_font[count_font] = 6; // 6은 공백
			count_font ++;

			}



			return MOUSE_EVENT;
		}
        break;
		
    }

//    FlushConsoleInputBuffer(CIN);
    return 0;
}


char getchr(int x, int y) // 그 좌표에 들어있는 글자를 출력

{

 COORD pos={x, y};

 TCHAR ch;

 DWORD rd;

 ReadConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), &ch, 1, pos, &rd);

 return ch;

}



//////////////////본격적인 소스////////////////////////
int main()      
{
    DWORD mode;
    WORD key;
    COORD pos;
	int event;																								// 마우스 이벤트에 이용
	int x;																									// 마우스의 x좌표 저장소
	int y;																									// 마우스의 y좌표 저장소
	int make_frame = 0;	// 테두리 작성 변수
	int clear_width = 8,clear_length = 3;
	int check_help = 0;
	POINT mouse;
	FILE *paintboard_save;
	
	system("mode con: cols=80 lines=26"); // 화면 고정


    CIN = GetStdHandle(STD_INPUT_HANDLE);
    COUT = GetStdHandle(STD_OUTPUT_HANDLE);

    // 마우스 활성화
    GetConsoleMode(CIN,&mode);
    SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	// 사용자 함수로 넣기 //
		GRAY;
		while(make_frame != 80) // 가로줄 채우기
		{
			gotoxy(make_frame,2); printf("*"); 
			gotoxy(make_frame,24); printf("*");
			make_frame ++;
		}
		make_frame = 0;
		while(make_frame != 25) // 세로줄 채우기
		{
			gotoxy(7,make_frame); printf("*");
			gotoxy(79,make_frame); printf("*");
			make_frame++;
		}

		make_frame = 2;
		while(make_frame != 26) // 세로줄에 ........한것 
		{
			gotoxy(0,make_frame); printf("*******");
			make_frame = make_frame + 2;
		}
		WHITE;


		gotoxy(0,3); WHITE;printf("가");	gotoxy(0,5); YELLOW;printf("가");		gotoxy(0,7); RED;printf("가");WHITE;
		gotoxy(4,3); GRAY;printf("가");		gotoxy(4,5); SKY;printf("가");			gotoxy(4,7); YELLOWGREEN;printf("가");WHITE;
		
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
		
		gotoxy(63,1); printf("made by :: 가누");
		
		// -- - -- - - - ----- - -//	
	
		
		
	while(1)																// 항상 마우스 클릭이 되도록 while(1)로 설정
    {	
		
        if(be_input() ) 
		{	
            if(get_input(&key,&pos) != 0  )									// 마우스 클릭할수있도록 만들어진 함수
			{ 
			
			MOUSE_EVENT;	
			x = pos.X;													// 마우스클릭값이 x,y변수에 저장되도록함
			y = pos.Y;
				
			//가로 최대 79
			//세로 최대 24
							
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

				if(x >= 8 && x <= 78) // 녹화시작 그리고 좌표표시
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







				if( x>=0 && x<= 6) // 도구상자 범위
				{
					if(y >= 15 && y <=16) // RESET
					{
						count_x = 0; count_y = 0; count_font = 0, count_color = 0; WHITE;
						while(count_x <= 5000)
						{
							rec_x[count_x] = 0; rec_y[count_y] = 0; rec_font[count_font] = 0, rec_color[count_color] = 0;  // 녹화 리셋
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

						while(count_save != 1491) // 저장소 초기화
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

						// 리셋 후 //

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
						check_help = 1; // 다음번에 누르면 꺼지도록
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

						
						
						

						// 리셋 후 //
						WHITE;

						gotoxy(14,3); printf("#"); gotoxy(12,4); printf("###"); gotoxy(10,5); printf("##########");
						gotoxy(14,7); printf("#"); gotoxy(12,6); printf("###"); 

						gotoxy(30,5);	printf("이곳을 클릭하시면 다양한 "); RED;printf("색상");WHITE;printf("으로");
						gotoxy(30,6);	printf("그림을 그리실 수 있습니다.");

						gotoxy(14,9); printf("#"); gotoxy(12,10); printf("###"); gotoxy(10,11); printf("##########");
						gotoxy(14,13); printf("#"); gotoxy(12,12); printf("###"); 
						
						gotoxy(32,8); printf(" *** 오른쪽 마우스키 : 지우개 ***");
						gotoxy(30,11);	printf("이곳을 클릭하시면 다양한 "); RED;printf("모양");WHITE;printf("으로");
						gotoxy(30,12);	printf("그림을 그리실 수 있습니다.");

						gotoxy(11,15); RED;printf("<");WHITE;  printf("그림판을 지워줍니다. 이때 저장되어있던 것 또한 초기화 됩니다.");
						gotoxy(11,17); RED;printf("<");WHITE;  printf("그림판에 그렸는 그림을 text파일로 저장해 줍니다.");
						gotoxy(11,19); RED;printf("<");WHITE;  printf("지금까지 그렸던 장면을 처음부터 다시 보여줍니다.");
						gotoxy(11,21); RED;printf("<");WHITE;  printf("도움말");
						gotoxy(11,23); RED;printf("<");WHITE;  printf("종료하기");
					

						gotoxy(35,22);RED;printf("**  ");WHITE; printf("Help키를 다시 누르시면 ");gotoxy(35,23); printf("도움말이 종료됩니다.");
					}

					else if(y >= 21 && y <= 22 && check_help == 1) // Help off
					{
						check_help = 0; // 다음번에 누르면 켜지도록
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
