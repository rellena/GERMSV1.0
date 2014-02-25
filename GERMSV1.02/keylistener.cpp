#include "gameinclude.h"
extern player mainPlayer;
extern bool move;

void keypressed(int key, int x, int y)
{
    switch (key){
        case GLUT_KEY_RIGHT:
            move = true;
			mainPlayer.move((mainPlayer.getPosition().x)+mainPlayer.getSpeed(), mainPlayer.getPosition().y);
			move = false;
            break;

        case GLUT_KEY_LEFT:
            move = true;
			mainPlayer.move((mainPlayer.getPosition().x)-mainPlayer.getSpeed(), mainPlayer.getPosition().y);
			move = false;
        break;

        case GLUT_KEY_UP:
            move = true;
			mainPlayer.move((mainPlayer.getPosition().x), mainPlayer.getPosition().y-mainPlayer.getSpeed());
			move = false;
            break;

        case GLUT_KEY_DOWN:
            move = true;
			mainPlayer.move((mainPlayer.getPosition().x), mainPlayer.getPosition().y+mainPlayer.getSpeed());
			move = false;
        break;

        default:
         break;
    }
    glutPostRedisplay();
}