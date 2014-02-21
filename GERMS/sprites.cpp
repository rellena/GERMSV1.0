//sprites.cpp
//very simple, just an interface to store and load sprites
//need to include i file read and image reader into this class

//Author: Richard Ellena
#include "gameinclude.h"

//Sprites Constructors
sprites::sprites()
:spritecount(0)
{}
sprites::sprites(const sprites &other)
{
	copySprites(other);
}
sprites::~sprites()
{
	deleteSprites();
}

//Sprites Member Functions
int sprites::getSpriteCount()
{
	return spritecount;
}

void sprites::setSpriteCount(int count)
{
	spritecount = count;
}

//the getter, must return the sprites array
void sprites::getSprites()
{
}
//Sprites Operators
sprites& sprites::operator =(const sprites &other)
{
	copySprites(other);
	return *this;
}

//Sprites Private Functions
void sprites::copySprites(const sprites &other)
{
	spritecount = other.spritecount;
}

void sprites::deleteSprites()
{
}
