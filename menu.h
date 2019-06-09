#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#include "SetScreen.h"
#include "staff.h"
#include "schedule.h"

#define _CRT_SECURE_NO_WARNINGS

void Select_Menu();

int Ask_Menunum(COORD* tmp);
