//player.h

//this class is pretty done. 

//Author: Richard Ellena

#pragma once
#include "gameinclude.h"

class player : public unit
{
public:
	player& operator= (const player&);
	//constructors
	player();
	player(float,float,float,float,float,float,string,string,string,sprites);
	player(const player&);//copy const
	~player();//destr
	void loadSprites(sprites);//stores sprite
	sprites getSprites();//returns sprite

private:
	void copyPlayer(const player&);
	void deletePlayer();
	sprites sprite;
	string playerName;//name of player to be printed to screen for graphics
};
