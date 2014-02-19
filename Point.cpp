//point.cpp
//the cpp for the point header, straightforward
#include "gameinclude.h"

//Constructors
Point::Point()
:x(0),y(0)
{}
Point::Point(int otherx, int othery)
{
	x = otherx;
	y = othery;
}
Point::Point(const Point &other)
{
	copyPoint(other);
}

//Operators
Point& Point::operator= (const Point &other)
{
	copyPoint(other);
	return *this;
}

//Private functions
void Point::copyPoint(const Point &other)
{
	x = other.x;
	y = other.y;
}
