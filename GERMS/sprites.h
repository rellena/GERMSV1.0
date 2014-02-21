//sprites.h
//very simple, just an interface to store and load sprites
//need to include i file read and image reader into this class

//this needs a sprite array which will be an array of stored images

//author: Richard Ellena
#pragma once
#include "gameinclude.h"

class sprites
{
public:
	sprites& operator= (const sprites&);
	//constructors
	sprites();
	sprites(const sprites&);//copy const
	~sprites();
	void setSpriteCount(int);//set the #ofimages
	int getSpriteCount();//get #images
	void getSprites();//get the image arry
	void setSprites();//place the array of images into the obj
private:
	void deleteSprites();
	void copySprites(const sprites&);
	int spritecount;
};
