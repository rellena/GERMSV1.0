//menu.cpp
//class with global function to draw menu
//Author: Hao Vo


#include "gameinclude.h"

extern Point mouseP;
extern bool wasclicked_LB, ingame;
extern int screenheight, screenwidth;

bool inMainMenu = true, inExitMenu, inLoadMenu, inOptionMenu, inGameMenu;

menu::menu(): orgHeight(720), orgWidth(1280)
{}

void menu::drawMainMenu()
{
	//each char has height of around 20 pixel
	text newGame = text((const unsigned char*) "Newgame",100,350,0.2,0.2);
	text cont = text((const unsigned char*) "Continue",100,400,0.2,0.2);
	text opt = text((const unsigned char*) "Option",100,450,0.2,0.2);
	text ext = text((const unsigned char*) "Exit",100,620,0.2,0.2);


	glColor4f(1.0,1.0,1.0,1.0);
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(2.0);
	newGame.drawText();
	cont.drawText();
	opt.drawText();
	ext.drawText();

	if (isMouseInside(90,320,200,40,xOffset,yOffset))
	{
		newGame.drawTextBox(90,320,200,40);
		if (wasclicked_LB)
		{
			ingame = true;
			inMainMenu = false;
		}
	}
	
	if (isMouseInside(90,370,200,40,xOffset,yOffset))
		cont.drawTextBox(90,370,200,40);

	if (isMouseInside(90,420,200,40,xOffset,yOffset))
		opt.drawTextBox(90,420,200,40);

	if (isMouseInside(90,590,200,40,xOffset,yOffset))
	{
		ext.drawTextBox(90,590,200,40);
		if (wasclicked_LB)
			inExitMenu = true;
	}
}

void menu::drawLoadMenu()
{

}

void menu::drawExitMenu()
{
	text exitM = text((const unsigned char*) "EXIT GAME?",
		orgWidth/2-100,orgHeight/2-30,0.2,0.2);
	text yes = text((const unsigned char*) "YES",
		orgWidth/2-150,orgHeight/2+30,0.2,0.2);
	text no = text((const unsigned char*) "NO",
		orgWidth/2+60,orgHeight/2+30,0.2,0.2);


	//Draw text for Exit Menu
	glColor4f(1.0,1.0,1.0,1.0);
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(2.0);
	exitM.drawText();
	yes.drawText();
	no.drawText();

	//Exit Yes textbox
	if (isMouseInside(orgWidth/2-170,orgHeight/2,100,40,xOffset,yOffset))
	{
		yes.drawTextBox(orgWidth/2-170,orgHeight/2,100,40);
		if (wasclicked_LB)
			exit(0);
	}

	// Exit No textbox
	if (isMouseInside(orgWidth/2+40,orgHeight/2,100,40,xOffset,yOffset))
	{
		no.drawTextBox(orgWidth/2+40,orgHeight/2,100,40);
		if (wasclicked_LB)
			inExitMenu = false;
	}
	
}

void menu::drawInGameMenu()
{
	text resume = text((const unsigned char*) "Resume",100,250,0.2,0.2);
	text save = text((const unsigned char*) "Save",100,300,0.2,0.2);
	text load = text((const unsigned char*) "Load",100,350,0.2,0.2);
	text opt = text((const unsigned char*) "Option",100,400,0.2,0.2);
	text ext = text((const unsigned char*) "Exit",100,600,0.2,0.2);

	glColor4f(1.0,1.0,1.0,1.0);
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(2.0);
	resume.drawText();
	save.drawText();
	load.drawText();
	opt.drawText();
	ext.drawText();

	if (isMouseInside(90,220,200,40,xOffset,yOffset))
	{
		resume.drawTextBox(90,220,200,40);
		if (wasclicked_LB)
		{
			ingame = true;
			inGameMenu = false;
		}
	}
	
	if (isMouseInside(90,270,200,40,xOffset,yOffset))
	{
		save.drawTextBox(90,270,200,40);
	}
	
	if (isMouseInside(90,320,200,40,xOffset,yOffset))
	{
		load.drawTextBox(90,320,200,40);
	}
	
	if (isMouseInside(90,370,200,40,xOffset,yOffset))
	{
		opt.drawTextBox(90,370,200,40);
	}
	
	if (isMouseInside(90,570,200,40,xOffset,yOffset))
	{
		ext.drawTextBox(90,570,200,40);
		if (wasclicked_LB)
			inExitMenu = true;
	}
	
}

bool menu::isMouseInside(int x, int y, int w, int h, float xOffset, float yOffset)
{
	float xCoor = (float) x * xOffset;
	float yCoor = (float) y * yOffset;
	float xFarCoor = (float) (x+w) * xOffset;
	float yFarCoor = (float) (y+h) * yOffset;

	if ((xCoor < mouseP.x) && (mouseP.x < xFarCoor) 
			&& (yCoor < mouseP.y) && (mouseP.y < yFarCoor))
		return true;
	else
		return false;
}

void menu::drawMenu()
{
	xOffset = (float) screenwidth/orgWidth;
	yOffset = (float) screenheight/orgHeight;

	glClear(GL_COLOR_BUFFER_BIT);

	glEnable( GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();
		glScalef(xOffset,yOffset,0);
		if(inMainMenu)
		{
			if (inExitMenu)
				drawExitMenu();
			else
				drawMainMenu();

		}
		else if (inGameMenu)
		{
			if (inExitMenu)
				drawExitMenu();
			else
				drawInGameMenu();	
		}
	glPopMatrix();

}