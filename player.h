//player.h

//this class is pretty done. 

//Author: Richard Ellena
#pragma once
#include "sprites.h"
#include <string>
#include "unit.h"
using namespace std;

class player : public unit
{
public:
	//constructors
	player();
	player(float,float,float,float,float,float,string,string,string,sprites);
	~player();//destr
	void loadSprites(sprites);//stores sprite
	sprites getSprites();//returns sprite

private:
	void deletePlayer();
	sprites sprite;
	string playerName;//name of player to be printed to screen for graphics
};
