#include "gameinclude.h"

extern player mainPlayer;
extern bool _move;
extern Point mouse;
extern int collide_with;
extern unit *enemy;

void playerMovement () 
{
	//rotate player
	//needs to be added in, will come soon
	//move in direction of 
	int col_flag;

	Point P1, P2;
	if (_move == true)
	{
		//move until player hits mouse click
		P1 = mainPlayer.getPosition();
		mainPlayer.move(mouse.x, mouse.y);
		P2 = mainPlayer.getPosition();

		if (checkCollisions() == true)
		{
			//left
			if ((mainPlayer.getPosition().x - mainPlayer.getRadius()) <= enemy[collide_with].getPosition().x + enemy[collide_with].getRadius() && (mainPlayer.getPosition().x - mainPlayer.getRadius()) + mainPlayer.getSpeed() + 1> enemy[collide_with].getPosition().x + enemy[collide_with].getRadius())
				col_flag = 1;
			//right
			else if ((mainPlayer.getPosition().x + mainPlayer.getRadius()) >= enemy[collide_with].getPosition().x - enemy[collide_with].getRadius() && (mainPlayer.getPosition().x + mainPlayer.getRadius()) - mainPlayer.getSpeed() - 1< enemy[collide_with].getPosition().x - enemy[collide_with].getRadius())
				col_flag = 2;
			//none
			else
				col_flag = 3;

			//top
			if ((mainPlayer.getPosition().y - mainPlayer.getRadius()) <= enemy[collide_with].getPosition().y + enemy[collide_with].getRadius() && (mainPlayer.getPosition().y - mainPlayer.getRadius()) + mainPlayer.getSpeed() + 1 > enemy[collide_with].getPosition().y + enemy[collide_with].getRadius())
				col_flag += 10;
			//bottom
			else if ((mainPlayer.getPosition().y + mainPlayer.getRadius()) >= enemy[collide_with].getPosition().y - enemy[collide_with].getRadius() && (mainPlayer.getPosition().y + mainPlayer.getRadius()) - mainPlayer.getSpeed() - 1 < enemy[collide_with].getPosition().y - enemy[collide_with].getRadius())
				col_flag += 20;
			//none
			else
				col_flag += 30;

			mainPlayer.setPosition(P1.x, P1.y);
			switch (col_flag)
			{
				//left top
				case 11:
					P1.x = enemy[collide_with].getPosition().x + enemy[collide_with].getRadius() + mainPlayer.getRadius();
					P1.y = enemy[collide_with].getPosition().y + enemy[collide_with].getRadius() + mainPlayer.getRadius();
					mainPlayer.move(P1.x,P1.y);
					break;
				//left bottom
				case 21:
					P1.x = enemy[collide_with].getPosition().x + enemy[collide_with].getRadius() + mainPlayer.getRadius();
					P1.y = enemy[collide_with].getPosition().y - enemy[collide_with].getRadius() - mainPlayer.getRadius();
					mainPlayer.move(P1.x,P1.y);
					break;
				//left none
				case 31:
					P1.x = enemy[collide_with].getPosition().x + enemy[collide_with].getRadius() + mainPlayer.getRadius();
					P1.y = mouse.y;
					mainPlayer.move(P1.x,P1.y);
					break;
				//right top
				case 12:
					P1.x = enemy[collide_with].getPosition().x - enemy[collide_with].getRadius() - mainPlayer.getRadius();
					P1.y = enemy[collide_with].getPosition().y + enemy[collide_with].getRadius() + mainPlayer.getRadius();
					mainPlayer.move(P1.x,P1.y);
					break;
				//right bottom
				case 22:
					P1.x = enemy[collide_with].getPosition().x - enemy[collide_with].getRadius() - mainPlayer.getRadius();
					P1.y = enemy[collide_with].getPosition().y - enemy[collide_with].getRadius() - mainPlayer.getRadius();
					mainPlayer.move(P1.x,P1.y);
					break;
				//right none
				case 32:
					P1.x = enemy[collide_with].getPosition().x - enemy[collide_with].getRadius() - mainPlayer.getRadius();
					P1.y = mouse.y;
					mainPlayer.move(P1.x,P1.y);
					break;
				//none top
				case 13:
					P1.x = mouse.x;
					P1.y = enemy[collide_with].getPosition().y + enemy[collide_with].getRadius() + mainPlayer.getRadius();
					mainPlayer.move(P1.x,P1.y);
					break;
				//none bottom
				case 23:
					P1.x = mouse.x;
					P1.y = enemy[collide_with].getPosition().y - enemy[collide_with].getRadius() - mainPlayer.getRadius();
					mainPlayer.move(P1.x,P1.y);
					break;
				//none none
				case 33:
					mainPlayer.move(mouse.x,mouse.y);
					break;
				default:
					mainPlayer.move(mouse.x,mouse.y);
					break;
			}
		}
			
		if (mainPlayer.getPosition().x == mouse.x && mainPlayer.getPosition().y == mouse.y)
			_move = false;

		Sleep(10);
	}
}

void drawPlayer()
{
	int x, y;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//get players position
	x = mainPlayer.getPosition().x;
	y = mainPlayer.getPosition().y;

	//draw our triangle
	glBegin(GL_TRIANGLES);
		glVertex3f(x,y + 20 ,0);
		glVertex3f(x -20, y-10,0);
		glVertex3f(x+20,y -10,0);
	glEnd();
	//glutSwapBuffers();//swap bufferes!!!! Important for animation
	glFlush();
}


