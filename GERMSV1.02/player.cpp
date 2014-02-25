//player.cpp
//cpp file for the player

//Author: Richard Ellena

//This class will handle the main player. Only one istance of this class will
//be created into an object in the main and then all other copies will be
//referenced to it

//Add to this class if needed but player is pretty much done

#include "gameinclude.h"

//player constructors
player::player()
:unit(), playerName(""), sprite(sprites())
{

}

player::player(float h, float a,float d,float s,float r,float e, string cn, string cc, string pn, sprites sprt)
{
	//see unit decl, for const details
	unit(h,a,d,s,r,e,cn,cc);
	playerName = pn;
	sprite = sprt;
}
player::player(const player &other)
{
	copyPlayer(other);
}
player::~player()
{
	deletePlayer();
}
//player member functions
void player::loadSprites(sprites sprt)
{
	
}
sprites player::getSprites()
{
	return sprite;
}
//player operators
player& player::operator =(const player &other)
{
	copyPlayer(other);
	return *this;
}
//player private functions
void player::copyPlayer(const player &other)
{
	playerName = other.playerName;
	sprite = other.sprite;
}

void player::deletePlayer()
{
}
