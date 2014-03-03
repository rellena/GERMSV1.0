#include "gameinclude.h"

extern int screenwidth;
extern int screenheight;
extern player mainPlayer;
extern bool _move;
extern Point mouse;
extern unit *enemy;
extern bool *en_move;
extern int enemy_size;

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
	//movements handling
	playerMovement();//player collisons handled inside this function
	enemyMovement();

	//player drawing
	glPushAttrib(GL_CURRENT_BIT);//keeps players color from changing
	drawPlayer();
	glColor3f(0.0, 1.0, 0.0); 

	//enemy drawing
	for (int x=0; x<enemy_size; x++)
		drawEnemy(enemy[x].getPosition().x, enemy[x].getPosition().y,enemy[x].getRadius());

	glutSwapBuffers();//swap bufferes!!!! Important for animation
	glFlush();
}