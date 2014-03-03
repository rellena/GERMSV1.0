#pragma once
#include "Point.h"
#include "player.h"
#include "unit.h"
using namespace std;

//clide check function that is internal
bool theCollide(Point, Point, float, float);
//player to unit
bool checkCollidePU(player, unit);
//player to player
bool checkCollidePP(player, player);
//unit to unit
bool checkCollideUU(unit, unit);
//player to hard code point
bool checkCollidePH(player, float, float, float);
//unit to hard codde point
bool checkCollideUH(unit, float, float, float);
//check collisions formal function
bool checkCollisions();
