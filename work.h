#pragma once

#ifndef WORK_H
#define WORK_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "staff.h"
#include "DrawUI.h"

#define workMenuNum 3

void Print_workinfo();
void Print_workMenu();

void Work();
void Make_Work();
int calculate_day();
int division_day(int i);
void Search_Work();
void Sub_Make_Work(int part_time);
void Print_Search_Work(int start, int last, int count);
int keycontrol(int key);

#endif