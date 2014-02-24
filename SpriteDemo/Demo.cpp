

#include <windows.h>							// Header File For Windows
#include <stdio.h>
#include <gl/GL.h>
#include <GL/glut.h>
#include <SOIL.h>
#include "sprites.h"

int Height;
int Width;

double L = 100.0;
double frame;
sprites a,b;

void display(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);       // red background
	glClear( GL_COLOR_BUFFER_BIT);



	glLoadIdentity(); 
	glEnable( GL_TEXTURE_2D );
	
	a.drawSprites(0,0,20,20);
	b.drawSprites(0,50,20,20);
	

	a.drawSprites(50,50,20,20);
	frame+=0.0005;
	if (frame > 1)
		b.drawSprites(50,50,20,20);
	if (frame > 2)
		frame = 0;

	glutSwapBuffers();

}

void reshape(int w, int h)
{
	Height = h;
	Width = w;
	GLfloat R = (GLfloat) w / (GLfloat) h;
	glViewport(0, 0, Width, Height);		
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();    
	if(w <= h)
		gluOrtho2D(0, 100, 0, 100);
	else
		gluOrtho2D(-L*R, L*R, -L, L);
	glMatrixMode (GL_MODELVIEW);
//	glutPostRedisplay(); 
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100,100);		
	glutInitWindowSize(500,500);			
	glutCreateWindow ("test");	

	a.loadTexture("Demo1.bmp");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	b.loadTexture("Demo2.bmp");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);


	glutDisplayFunc(display);
	glutIdleFunc (display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}
