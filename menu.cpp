//menu.cpp
//class with static function to draw menu
//Author: Hao Vo


#include "gameinclude.h"

extern Point mouseP;	
extern bool wasclicked_LB, ingame;
extern int screenheight, screenwidth;

bool inMainMenu = true, inExitMenu, inLoadMenu, inOptionMenu;
int orgHeight = 720;
int orgWidth = 1280;




void drawMainMenu()
{
	int y = screenheight - mouseP.y;

	
//	int xOffset = w-720;
	glEnable( GL_TEXTURE_2D );
//	glEnable( GL_BLEND);
//	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	float xOffset = (float) screenwidth/orgWidth;
//	float yOffset = (float) screenheight/orgHeight;
	float xOffset = 1;
	float yOffset = 1;
	float hA = (float) screenheight/orgHeight;
	float wA = (float) screenwidth/orgWidth;


	
	text newGame = text((const unsigned char*) "Newgame",100,350,0.2,0.2);
	text cont = text((const unsigned char*) "Continue",100,300,0.2,0.2);
	text opt = text((const unsigned char*) "Option",100,250,0.2,0.2);
	text ext = text((const unsigned char*) "Exit",100,100,0.2,0.2);
/*
	text newGame = text((const unsigned char*) "Newgame",wWidth/16,wHeight*8/16,0.2,0.2);
	text cont = text((const unsigned char*) "Continue",wWidth/16,wHeight*7/16,0.2,0.2);
	text opt = text((const unsigned char*) "Option",wWidth/16,wHeight*6/16,0.2,0.2);
	text ext = text((const unsigned char*) "Exit",wWidth/16,wHeight*4/16,0.2,0.2);
*/
	glPushMatrix();
//		glScalef(1.2,1.066,0);
		glColor4f(1.0,1.0,1.0,1.0);
		glEnable(GL_LINE_SMOOTH);
		glLineWidth(2.0);
		newGame.drawText();
		cont.drawText();
		opt.drawText();
		ext.drawText();

	//	if ((90*xOffset*1.2 < menu::mouseP.x) && (menu::mouseP.x < 290*xOffset*1.2) && (340*yOffset*1.066 < menu::mouseP.y) && (menu::mouseP.y < 380*yOffset*1.066))
		if (isMouseInside(90,340,200,40,xOffset,yOffset))
		{
					newGame.setTextBoxColor(1,1,1,0.3);
					if (wasclicked_LB)
					{
						ingame = true;
						inMainMenu = false;
					}
		}
		newGame.drawTextBox(90,340,200,40);

		if (isMouseInside(90,290,200,40,xOffset,yOffset))
			cont.setTextBoxColor(1,1,1,0.3);
		cont.drawTextBox(90,290,200,40);

		if (isMouseInside(90,240,200,40,xOffset,yOffset))
			opt.setTextBoxColor(1,1,1,0.3);
		opt.drawTextBox(90,240,200,40);

		if (isMouseInside(90,90,200,40,xOffset,yOffset))
		{
			ext.setTextBoxColor(1,1,1,0.3);
			if (wasclicked_LB)
			{
				inExitMenu = true;
				inMainMenu = false;
				drawExitMenu();
			}
		}
		ext.drawTextBox(90,90,200,40);
	glPopMatrix();
}

void drawLoadMenu()
{

}

void drawExitMenu()
{
	float xOffset = 1;
	float yOffset = 1;
	int y = screenheight - mouseP.y;


	text exitM = text((const unsigned char*) "EXIT THE GAME?",
		screenwidth/3,screenheight/2,0.3,0.3);
	text yes = text((const unsigned char*) "YES",
		screenwidth/3,screenheight/2-100,0.3,0.3);
	text no = text((const unsigned char*) "NO",
		screenwidth/2,screenheight/2-100,0.3,0.3);
	glColor4f(1.0,1.0,1.0,1.0);
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(2.0);
	exitM.drawText();
	yes.drawText();
	no.drawText();

	if (isMouseInside(screenwidth/3-20,screenheight/2-120,200,60,xOffset,yOffset))
			yes.setTextBoxColor(1,1,1,0.3);
	yes.drawTextBox(screenwidth/3-20,screenheight/2-120,200,60);

	if (isMouseInside(screenwidth/2-20,screenheight/2-120,200,60,xOffset,yOffset))
	{
			no.setTextBoxColor(1,1,1,0.3);
			if (wasclicked_LB)
			{
				inMainMenu = true;
				inExitMenu = false;
			}
	}
		no.drawTextBox(screenwidth/2-20,screenheight/2-120,200,60);
	
}

bool isMouseInside(int x, int y, int w, int h, int xOffset, int yOffset)
{

	if ((x*xOffset < mouseP.x) && (mouseP.x < x+w*xOffset) 
			&& (y*yOffset < screenheight-mouseP.y) && (screenheight-mouseP.y < y+h*yOffset))
		return true;
	else
		return false;
}

void drawMenu()
{
//	glClearColor(0.0, 0.0, 0.0, 1.0);       // black background
	glClear( GL_COLOR_BUFFER_BIT);
	glTranslatef(0,screenheight,0);
	glScalef(1,-1,1);
	glEnable( GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	if(inMainMenu)
		drawMainMenu();
	if (inExitMenu)
			drawExitMenu();

}