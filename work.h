#pragma once
#ifndef WORK_H
#define WORK_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "staff.h"


void Print_Work_Menu();
void Work();
void Make_Work();
int calculate_day();
int division_day(int i);
void Search_Work();
void Sub_Make_Work(int part_time);
#endif