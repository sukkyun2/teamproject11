// 마우스 제어 시, 각 기능별로 페이지를 분류하기 위함
// 제어하지 않더라도 main함수의 직관성을 목적으로 함

#pragma once
#include"DrawCalendar.h"
#include"DrawMainMenu.h"
#include"DrawStatusbar.h"

//로그인 화면
#define LoginPage 0
#define ChangeIDpage 1

// MainPage
#define HomePage 5	// 로그인 이후 처음 화면



//직원관리
#define StaffMainPage 10	//직원 관리 시작 시 페이지

//일정관리


//근무관리

//인물검색


int PrintHomepage();
int PrintStaffpage();


