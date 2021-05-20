#include<GL/glut.h>
#include<math.h>
#include<string.h>
int click_no=0;
void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 800, 0.0, 600);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if(click_no%2==0){
    glColor3f(0.0, 1.0, 0.0);
    }
    else{
    glColor3f(0.0, 0.0, 1.0);
    }
    glBegin(GL_TRIANGLES);
    glVertex2i(400, 550);
    glVertex2i(100, 200);
    glVertex2i(700, 200);
    glEnd();

glColor3f(1, 1, 1);
    char* st= "Parth Miglani 500067488";
    glRasterPos2i(450, 50);
    for( int i=0; i<strlen(st); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);
    }

    
    glFlush();
}

void mouse(int button, int state, int x, int y) 
	{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		click_no++;
		glutPostRedisplay();
			}			
	}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 550);
    glutCreateWindow("Experiment 2: Changing color of triangle");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
