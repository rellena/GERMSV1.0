//menu.h
//class with global function to draw menu
//Author: Hao Vo


#pragma once
#include "text.h"
#include "sprites.h"

class menu
{
public:
	menu();
	void drawMenu();
private:
	void drawMainMenu();
	void drawLoadMenu();
	void drawExitMenu();
	void drawInGameMenu();
	bool isMouseInside(int x, int y, int w, int h, float xOffset, float yOffset);
	float xOffset, yOffset;
	const int orgHeight, orgWidth;
	sprites menuLogo;
};