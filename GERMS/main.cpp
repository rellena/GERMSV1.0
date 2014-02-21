//MAIN
//This main is very basic. Only prints a polygon to the screen.
//This was a test for opengl. Anyone feel free to edit this whole thing.
#include "gameinclude.h"

player mainPlayer;
extern bool ingame, wasclicked_LB, wasclicked_RB, wasclicked_MB, move;
extern Point mouse;
int count = 0; //delay for the move function

void playerMovement (player &mainPlayer)
{
	//rotate player
	//needs to be added in, will come soon
	
	//move in direction of 
	if (move == true)
	{
		//move until player hits mouse click
		mainPlayer.move(mouse.x, mouse.y);
		if (mainPlayer.getPosition().x == mouse.x && mainPlayer.getPosition().y == mouse.y)
			move = false;
	}
}


void display(void)
{
	int x, y;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//this calls the function to update the player position
	//player moves once when count hits 60
	if (count == 60)
		playerMovement(mainPlayer);

	//get players position
	x = mainPlayer.getPosition().x;
	y = mainPlayer.getPosition().y;

	//draw our triangle
	glBegin(GL_TRIANGLES);
		glVertex3f(x,y + 20 ,0);
		glVertex3f(x -20, y-10,0);
		glVertex3f(x+20,y -10,0);
	glEnd();
	glutSwapBuffers();//swap bufferes!!!! Important for animation
	glFlush();

	//keeps count in line and resets it
	if (count == 90)
		count = 0;
	if (move == true)
		count++;
	if (move == false)
		count = 0;
}


int main(int argc, char* argv[])
{
	//variables for screen szie
	int screenwidth = 500, screenheight = 500;
	mainPlayer.setPosition(screenwidth/2,screenheight/2);//set mainplayer at a positon
	mainPlayer.setSpeed(3);//set player speed ~~~ADJUST THIS SPEED TO ADJUST MOVEMENT OF PLAYER SPRITE!!!!
	ingame = true;

	//initialize window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //disply mode with one buffer and colored
	glutInitWindowPosition(100,100);//windoww position from upper left corner
	glutInitWindowSize(screenwidth,screenheight);//set size of viewing window
	
	glutCreateWindow("GERMS");//create window
	//load mouse listening function
	glutMouseFunc(mouseButton);
	
	//funcs to adjust screen and scale to actual pixels of viewing window
	glLoadIdentity();//unsure what this does?
	glOrtho(0.0, screenwidth, 0.0, screenheight, 0, 200.0);//changes the view to the screen ~ IMPORTANT
	glScalef(1, -1, 1);//inverts the y axis
	glTranslatef(0, -screenheight, 0);//changes the xy scale, in opengl, 0,0 is bottom left, this makes it upper left
	glMatrixMode(GL_MODELVIEW);//sets the modeview, this is model view, unsure at the moment what differences are

	glutDisplayFunc(display);//calls display
	glutIdleFunc(display);
	glutMainLoop();//start the glut loop

	return 0;
}
