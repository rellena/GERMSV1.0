//Unit.h

//This class is almost completely done. All units of the game
//will inherit from this class. Add what is necessary if there
//is anything needed.

//Author: Richard Ellena
#pragma once
#include "gameinclude.h"

class unit
{
public:
	//const
	unit();
	unit(int,int,int,int,int,int,string,string);
	//getters and setters
	int getHealth();
	void setHealth(int);
	int getArmor();
	void setArmor(int);
	int getDamage();
	void setDamage(int);
	int getSpeed();
	void setSpeed(int);
	int getRange();
	void setRange(int);
	string getCharName();
	void setCharName(string);
	string getCharClass();
	void setCharClass(string);
	Point getPosition();//units postion gets and sets
	void setPosition(int, int);
	Point move(int, int);//function to move the unit in direction
private:
	int health, armor, damage, speed, range, energy;
	string char_name, char_class;
	Point position, moveto;
};
