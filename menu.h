//menu.h
//class with static function to draw menu
//Author: Hao Vo


#pragma once
#include "text.h"

void drawMainMenu();
void drawLoadMenu();
void drawExitMenu();
void drawMenu();
bool isMouseInside(int x, int y, int w, int h, int xOffset, int yOffset);
