#pragma once

#include "SetScreen.h"

COORD menupos_start, menupos_end;
COORD controlpos_start, controlpos_end;

int menu_height, menu_width;
int control_height, control_width;

void getSideMenuSize();

void PrintSideMenu_background();

void print_askMenunum(COORD *tmp);
