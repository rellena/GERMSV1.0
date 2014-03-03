#include "gameinclude.h"
extern player mainPlayer;
extern bool _move;

void keypressed(int key, int x, int y)
{
    switch (key){
        case GLUT_KEY_RIGHT:
            _move = true;
			mainPlayer.move((mainPlayer.getPosition().x)+mainPlayer.getSpeed(), mainPlayer.getPosition().y);
			_move = false;
            break;

        case GLUT_KEY_LEFT:
            _move = true;
			mainPlayer.move((mainPlayer.getPosition().x)-mainPlayer.getSpeed(), mainPlayer.getPosition().y);
			_move = false;
        break;

        case GLUT_KEY_UP:
            _move = true;
			mainPlayer.move((mainPlayer.getPosition().x), mainPlayer.getPosition().y-mainPlayer.getSpeed());
			_move = false;
            break;

        case GLUT_KEY_DOWN:
            _move = true;
			mainPlayer.move((mainPlayer.getPosition().x), mainPlayer.getPosition().y+mainPlayer.getSpeed());
			_move = false;
        break;

        default:
         break;
    }
    glutPostRedisplay();
}