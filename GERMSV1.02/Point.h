//Point class, straightforward

//Author: Richard Ellena
#pragma once
#include "gameinclude.h"

class Point
{
public:
	//operator=
	Point& operator= (const Point&);
	//operator ==
	bool operator== (const Point&);
	//constructors
	Point();
	Point(float, float);
	Point(const Point&);//copy constructor
	float x,y;
private:
	void copyPoint(const Point&);
};
