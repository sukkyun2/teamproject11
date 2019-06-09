#pragma once
#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#include"DrawUI.h"

#define _CRT_SECURE_NO_WARNINGS

#define ENTER_KEY 13

HBITMAP hImage;

void Login();
void get_pw(char* buf, int size);
void print_startimage(HBITMAP hImage);
void print_menuimage(HBITMAP hImage);
void Print_login();
void Print_ChangeID();
void setFontColor(int color);
__inline void resetFontColor();

#endif