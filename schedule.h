#pragma once
#include <stdio.h>

#include "DrawSideMenu.h"
#include "menu.h"
#include "staff.h"
#include "login.h"

#define scheduleMenuNum 3
#define InsertscheduleMenuNum 5
#define DeletescheduleMenuNum 3

void Print_scheduleinfo();

void Schedule();

void Print_Insert_scheduleinfo();
void Insert_Schedule();
void Print_Delete_scheduleinfo();
void Delete_Schedule();
void Insert_outside();
void Insert_day();
void Insert_moning_half();
void Insert_afternoon_half();
void Delete_outside();
void Delete_vacation();
