#include <Windows.h>
#include<vector>
#include <stdlib.h>
#include<string>
#include<iostream>

using namespace std;

struct login {
	string ID = "0000";
	string PW = "0000";
};
login *id = new login();

void Print_login();
void Fullscreen();
void 	Print_ChangeID();
void screen(int x, int y);

int main()
{
	string newID;
	string newPW;
	string buffer;

	Fullscreen();							// 전체 화면 출력
	do {
		system("cls");
		Print_login();						// 로그인 화면 출력

		screen(88, 25);
		getline(cin, newID);
		if (newID == "0000") {		// 회원 정보 수정
			system("cls");
			Print_ChangeID();			// 회원 정보 수정 화면 출력
			screen(88, 24);
			cout << id->ID;
			screen(88, 25);
			cout << id->PW;
			screen(90, 27);
			cin >> id->ID;
			screen(90, 28);
			cin >> id->PW;
		}
		else {								// ID에 0000이 아니면
			screen(88, 26);
			getline(cin, newPW);
			if ((newID != id->ID) || (newPW != id->PW)) {
				system("cls");
				screen(75, 23);
				cout << "ERR :: ID,PW를 잘못입력하셨습니다.";
				screen(75, 24);
				cout << " 다시 입력하시려면 Enter를 눌러주십시오.";
				getline(cin, buffer);
			}
		}
	} while ((newID != id->ID) || (newPW != id->PW));
}

void screen(int x, int y) {
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD max_size = GetLargestConsoleWindowSize(screen);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(screen, pos);
}

void Fullscreen() {
	SetConsoleDisplayMode(
		GetStdHandle(STD_OUTPUT_HANDLE),
		CONSOLE_FULLSCREEN_MODE,
		0
	);

}

void Print_login()
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD max_size = GetLargestConsoleWindowSize(screen);

	std::vector<std::string>login{
		"    * 직원 일정 관리 프로그램 *",
		"---------------------------------",
		"|                               |",
		"|                               |",
		"|                               |",
		"|         ID :                  |",
		"|         PW :                  |",
		"|                               |",
		"|                               |",
		"|                               |",
		"---------------------------------",
		"",
		"* ID에 0000을 입력하시면 ID,PW를 수정할 수 있습니다.",
	};

	COORD pos;
	for (int i = 0; i < login.size(); i++)
	{

		pos.X = (max_size.X - login.at(2).capacity()) / 2;
		pos.Y = (max_size.Y - login.size()) / 2 + i;
		SetConsoleCursorPosition(screen, pos);
		cout << login.at(i);
	}

}

void Print_ChangeID()
{
	system("cls");
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD max_size = GetLargestConsoleWindowSize(screen);

	std::vector<std::string>login{
		"---------------------------------",
		"|                               |",
		"|                               |",
		"|         ID :                  |",
		"|         PW :                  |",
		"|                               |",
		"|        new ID :               |",
		"|        new PW :               |",
		"|                               |",
		"|                               |",
		"---------------------------------",
	};

	COORD pos;
	for (int i = 0; i < login.size(); i++)
	{

		pos.X = (max_size.X - login.at(2).capacity()) / 2;
		pos.Y = (max_size.Y - login.size()) / 2 + i;
		SetConsoleCursorPosition(screen, pos);
		cout << login.at(i);
	}
}

