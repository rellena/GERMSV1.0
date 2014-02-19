//Point class, straightforward

//Author: Richard Ellena
#pragma once
#include "gameinclude.h"

class Point
{
public:
	//operator=
	Point& operator= (const Point&);
	//constructors
	Point();
	Point(int, int);
	Point(const Point&);//copy constructor
	int x,y;
private:
	void copyPoint(const Point&);
};
