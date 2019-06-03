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

void Login();
void get_pw(char* buf, int size);
void print_start();

#endif