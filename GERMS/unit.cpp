//Unit.cpp

//Again this class is basically done. Edit here where necessary.

//Author: Richard Ellena
#include "gameinclude.h"

unit::unit()
:health(100),armor(50),damage(10),speed(5),range(5),energy(100), char_name(""), char_class("")
{
}
unit::unit(int h, int a, int d, int s, int r, int e, string cn, string cc)
{
	health = h;
	armor = a;
	damage = d;
	speed = s;
	range = r;
	energy = e;
	char_name = cn;
	char_class = cc;
}
int unit::getHealth()
{
	return health;
}
void unit::setHealth(int h)
{
	health = h;
}
int unit::getArmor()
{
	return armor;
}
void unit::setArmor(int a)
{
	armor = a;
}
int unit::getDamage()
{
	return damage;
}
void unit::setDamage(int d)
{
	damage = d;
}
int unit::getSpeed()
{
	return speed;
}
void unit::setSpeed(int s)
{
	speed = s;
}
int unit::getRange()
{
	return range;
}
void unit::setRange(int r)
{
	 range = r;
}
string unit::getCharName()
{
	return char_name;
}
void unit::setCharName(string cn)
{
	char_name = cn;
}
string unit::getCharClass()
{
	return char_class;
}
void unit::setCharClass(string cc)
{
	char_class = cc;
}
Point unit::getPosition()
{
	return position;
}
void unit::setPosition(int newx, int newy)
{
	position.x = newx;
	position.y = newy;
}

//Okay so this function is vital to the movement of units
//Right now the movement is fairly choppy, if we add in physics that are more realistic
//this will be the function to do it in
Point unit::move(int dirx, int diry)
{
	//dirx, is the direction to move in, it is actually the
	//point that the mouse click occured at, same for diry

	//the ifs just check if the clicked occured above or below the sprite
	//and then moves the sprite accordingly
	if (dirx > position.x)
	{
		if (position.x + speed <= dirx)
			position.x += speed;
		else
			position.x = dirx;
	}
	else if (dirx < position.x)
	{
		if (position.x - speed >= dirx)
			position.x -= speed;
		else
			position.x = dirx;
	}
	
	if (diry > position.y)
	{
		if (position.y + speed <= diry)
			position.y += speed;
		else
			position.y = diry;
	}
	else if (diry < position.y)
	{
		if (position.y - speed >= diry)
			position.y -= speed;
		else
			position.y = diry;
	}
	return position;
}	