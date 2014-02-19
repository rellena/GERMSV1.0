	//mouselistener.cpp
	
	//This is the setup for mouse listener. Edit where necessary.
	
	//Author: Richard Ellena
	#include "gameinclude.h"
	
	//Mouse Listener Constructors
	MouseListener::MouseListener()
	{
		wasclicked_RB = false;
		wasclicked_LB = false;
		wasclicked_MB = false;
		ingame = false;
	}
	
	//Public Mouse Listener Functions
	void MouseListener::mouseButton(int button, int state, int x, int y)
	{
		mouseButtonp(button, state, x, y);
	}
	
	void MouseListener::mousePassive(int x, int y)
	{
		mousePassivep(x, y);
	}
	
	void MouseListener::mouseActive(int x, int y)
	{
		mouseActivep(x, y);
	}
	
	void MouseListener::setWasClicked(char button, bool set)
	{
		setWasClickedp(button, set);
	}
	
	void MouseListener::setInGame(bool set)
	{
		setInGamep(set);
	}
	Point MouseListener::getMouseXY()
	{
		return getMouseXYp();
	}
	
	
	//Private Mouse Listener Functions
	void MouseListener::mouseButtonp(int button, int state, int x, int y)
	{
		//choose state of mouse UP or Down
		if (state == GLUT_UP)
		{
			//which button was pressed
			switch (button)
			{
			case GLUT_LEFT_BUTTON:
				wasclicked_LB = false;
				break;
			case GLUT_RIGHT_BUTTON:
				break;
			case GLUT_MIDDLE_BUTTON:
				break;
			default:
				break;
			}
		}
		if (state == GLUT_DOWN)
		{
			switch (button)
			{
			case GLUT_LEFT_BUTTON:
				//update x and y point to be sent to player
				mouse.x = x;
				mouse.y = y;
				wasclicked_LB = true;
				break;
			case GLUT_RIGHT_BUTTON:
				break;
			case GLUT_MIDDLE_BUTTON:
				break;
			default:
				break;
			}
		}
	}
	
	void MouseListener::mouseActivep(int x, int y)
	{
		if (wasclicked_LB == true)		
		{
			//update to player while mouse is held
			mouse.x = x;
			mouse.y = y;
		}
	}
	void MouseListener::mousePassivep(int x, int y)
	{
	}
	
	void MouseListener::setWasClickedp(char button, bool set)
	{
		//switch for which button pressed
		switch (button)
		{
		case 'l':
			wasclicked_LB = set;
			break;
		case 'r':
			wasclicked_RB = set;
			break;
		case 'm':
			wasclicked_MB = set;
			break;
		}
	}
	
	void MouseListener::setInGamep(bool set)
	{
		ingame = set;
	}
	
	Point MouseListener::getMouseXYp()
	{
		return mouse;
	}
	
