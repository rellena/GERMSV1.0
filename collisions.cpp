#include "gameinclude.h"

extern unit *enemy;
extern int enemy_size;
extern player mainPlayer;
extern bool _move;

int collide_with;

//collisons.cpp
//these are basic functions to check collisions, many overloaded funcs available

//CODES FOR COLLISION POINT MODIFIER(X && Y)
// -1 == move in left/down from P1 caused collision
// 1 == move in right/up from P1 cause collision
// 0 == no collision

//collide check function that is internal
bool theCollide(Point P1, Point P2, float r1, float r2)
{
	bool x,y;

	//check the x collision
	//Set x and y in the Point C to their flags
	if (P1.x > P2.x)
	{
		if ((P1.x - r1) < (P2.x + r2))
			x = true;
		else
			x = false;
	}
	else
	{
		if ((P1.x + r1) > (P2.x - r2))
			x = true;
		else
			x = false;
	}

	//check the y collision
	//set bool y true if the y's cross
	if (P1.y < P2.y)
	{
		if ((P1.y + r1) > (P2.y - r2))
			y = true;
		else
			y = false;
	}
	else
	{
		if ((P1.y - r1) < (P2.y + r2))
			y = true;
		else
			y = false;
	}

	if (x == true && y == true)
		return true;
	else
		return false;
}

//player to unit
bool checkCollidePU(player P, unit U)
{
	return (theCollide(P.getPosition(), U.getPosition(), P.getRadius(), U.getRadius()));
}

//player to player
bool checkCollidePP(player P1, player P2)
{
	return (theCollide(P1.getPosition(), P2.getPosition(), P1.getRadius(), P2.getRadius()));
}

//unit to unit
bool checkCollideUU(unit U1, unit U2)
{
	return (theCollide(U1.getPosition(), U2.getPosition(), U1.getRadius(), U2.getRadius()));
}

//player to hard code point
bool checkCollidePH(player P, float ox, float oy, float or)
{
	Point p;
	p.x = ox;
	p.y = oy;

	return theCollide(P.getPosition(), p, P.getRadius(), or);
}

//unit to hard codde point
bool checkCollideUH(unit U, float ox, float oy, float or)
{
	Point p;
	p.x = ox;
	p.y = oy;

	return theCollide(U.getPosition(), p, U.getRadius(), or);
}

bool checkCollisions()
{
	bool collide = false;
	float x, y;
	if (_move == true)
	{
		for (int x=0; x < enemy_size; x++)
		{
			collide = checkCollidePU(mainPlayer, enemy[x]);
			if (_move == true && collide == true)
			{
				collide_with = x;
				x = enemy_size;
			}
		}
	}

	return collide;
}
