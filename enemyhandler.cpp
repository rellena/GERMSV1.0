#include "gameinclude.h"

unit *enemy;
bool *en_move;
int enemy_size;

void initializeEnemies()
{
	enemy_size = 5;
	enemy = new unit[enemy_size];
	en_move = new bool[enemy_size];
	for (int n=0; n<enemy_size; n++)
		en_move = false;
}

void setEnemy(float x, float y, float r, int en)
{
	enemy[en].setPosition(x,y);
	enemy[en].setRadius(r);
}


void drawEnemy(float x, float y, float r)
{
		glColor3f(0.0, 1.0, 0.0);    // coloring rect
		glRectf(x-r, y-r, x+r, y+r);
		glFlush();
}

void enemyMovement()
{
}

