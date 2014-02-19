	//mouselistener.h
	
	//This class needs work, very basic.
	//All these functions handle the mouse movements and
	//will update player x and y
	
	//Author: Richard Ellena
	#pragma once
	#include "gameinclude.h"
	
	class MouseListener
	{
	public:
		MouseListener();//constr
		void mouseButton(int,int,int,int);//opengl button press handler
		void mouseActive(int, int);//when mouse is held
		void mousePassive(int, int);//when mouse is not held
		void setWasClicked(char, bool);//sets which button was clicked(BOOLS)
		void setInGame(bool);//set if the game state is ingame
		Point getMouseXY();//get the mousexy to update to player
	private:
		//private update funcs
		void mouseButtonp(int, int, int, int);
		void mouseActivep(int, int);
		void mousePassivep(int, int);
		void setWasClickedp(char, bool);
		void setInGamep(bool);
		Point getMouseXYp();
	
		bool wasclicked_LB, wasclicked_RB, wasclicked_MB;
		bool ingame;
		Point mouse;
	};
