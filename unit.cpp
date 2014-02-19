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
void unit::getPosition(int &rx, int &ry)
{
	rx = x;
	ry = y;
}
void unit::setPosition(int newx, int newy)
{
	x = newx;
	y = newy;
}
void unit::move(int dirx, int diry)
{
	//if the x to move is greater, then x must go up same for y
	if (dirx > x)
		x += speed;		
	else
		x -= speed;
	
	if (diry > y)
		y += y + speed;
	else
		y -= y - speed;
}
