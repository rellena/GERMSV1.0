//MAIN
//This main is very basic. Only prints a polygon to the screen.
//This was a test for opengl. Anyone feel free to edit this whole thing.
#include "gameinclude.h"

player mainPlayer;
extern bool ingame, wasclicked_LB, wasclicked_RB, wasclicked_MB, move;
extern Point mouse;
int count = 0, scale  = 0; //delay for the move function
int screenwidth, screenheight;

//scale function to adjust the screen
void setScale()
{
	double factor;
	factor = ((double)(screenheight + screenwidth) / ((double)(screenheight * screenwidth)));
	
	factor = factor * 1000;
	factor = (3.95*(factor*factor)) + (factor * 3.45);
	
	factor = factor - 5;

	scale = factor;
}

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

//draws the "enemy" units
void drawRect(int x, int y)
{
		glColor3f(0.0, 1.0, 0.0);    // coloring rect
		glRectf(x, y, x+30, y+30);
		glFlush();
}

void resize(int width, int height)
{
	glLoadIdentity();//unsure what this does?
	gluOrtho2D(0.0, width, 0, height);//changes the view to the screen ~ IMPORTANT
	glScalef(1, -1, 1);//inverts the y axis
	glTranslatef(0, -height, 0);//changes the xy scale, in opengl, 0,0 is bottom left, this makes it upper left
	glViewport(0, 0, width, height);
	glMatrixMode(GL_MODELVIEW);
	
	screenwidth = width;
	screenheight = height;
	setScale();
}

void getResolution()
{
   RECT desktop;
   // Get a handle to the desktop window
   const HWND hDesktop = GetDesktopWindow();
   // Get the size of screen to the variable desktop
   GetWindowRect(hDesktop, &desktop);
   // The top left corner will have coordinates (0,0)
   // and the bottom right corner will have coordinates
   // (horizontal, vertical)
   screenwidth = desktop.right;
   screenheight = desktop.bottom;
}

void display(void)
{
	if (count == scale)
	{
		playerMovement(mainPlayer);
		cout<<"Moved"<<" "<<scale;
		count = 0;
	}

	if (move == true)
		count++;
	glPushAttrib(GL_CURRENT_BIT);//keeps players color from changing
	drawPlayer();
	glColor3f(0.0, 1.0, 0.0); 
	drawRect(150,55);
	drawRect(250, 357);
	drawRect(369,109);
	glutSwapBuffers();//swap bufferes!!!! Important for animation
	glFlush();
}

int main(int argc, char* argv[])
{
	//variables for screen szie
	getResolution();
	mainPlayer.setPosition(screenwidth/2,screenheight/2);//set mainplayer at a positon
	mainPlayer.setSpeed(3);//set player speed ~~~ADJUST THIS SPEED TO ADJUST MOVEMENT OF PLAYER SPRITE!!!!
	ingame = true;

	//initialize window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //disply mode with one buffer and colored
	glutInitWindowPosition(0,0);//windoww position from upper left corner
	glutInitWindowSize(screenwidth,screenheight);//set size of viewing window
	
	glutCreateWindow("GERMS");//create window
	//load mouse listening function
	glutMouseFunc(mouseButton);
	glutSpecialFunc(keypressed);//allows use of special keys such as arrow keys
	
	//funcs to adjust screen and scale to actual pixels of viewing window
	glLoadIdentity();//unsure what this does?
	gluOrtho2D(0.0, screenwidth, 0.0, screenheight);//changes the view to the screen ~ IMPORTANT
	glScalef(1, -1, 1);//inverts the y axis
	glTranslatef(0, -screenheight, 0);//changes the xy scale, in opengl, 0,0 is bottom left, this makes it upper left
	glMatrixMode(GL_MODELVIEW);

	glutDisplayFunc(display);//calls display
	glutIdleFunc(display);//when glut is idle
	glutReshapeFunc(resize);//resize
	setScale();
	glutMainLoop();//start the glut loop

	return 0;
}
