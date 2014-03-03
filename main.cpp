//MAIN
//This main is very basic. Only prints a polygon to the screen.
//This was a test for opengl. Anyone feel free to edit this whole thing.
#include "gameinclude.h"

player mainPlayer;
extern bool ingame, wasclicked_LB, wasclicked_RB, wasclicked_MB, _move;
extern Point mouse;
extern bool en_move;
extern unit *enemy;
extern int enemy_size;

int _count = 0;
int screenwidth, screenheight;

int main(int argc, char* argv[])
{
	
	//set intial game variable
	initializeEnemies();
	getResolution();//set resolution to screen
	//setup player
	mainPlayer.setPosition(screenwidth/2,screenheight/2);//set mainplayer at a positon
	mainPlayer.setSpeed(3);//set player speed ~~~ADJUST THIS SPEED TO ADJUST MOVEMENT OF PLAYER SPRITE!!!!
	mainPlayer.setRadius(20);
	ingame = true;
	//setup enemies
	setEnemy(15,30,15,0);
	setEnemy(600,500,25,1);
	setEnemy(1000,80,20,2);
	setEnemy(20,555,16,3);
	setEnemy(700,200,18,4);


	//openGL HANDLES~~~~~~~~~~~~~~~~
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
	glutMainLoop();//start the glut loop

	return 0;
}
