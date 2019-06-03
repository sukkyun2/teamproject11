#pragma once
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <stdio.h>

#include "DrawUI.h"
#include "menu.h"
#include "staff.h"
#include "login.h"

#define scheduleMenuNum 4
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
void Print_Schedule();

#endif