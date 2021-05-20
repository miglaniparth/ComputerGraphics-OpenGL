#include<GL/glut.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
int click_no=0;
float r,g,b;
int p,q;
int arr[1000][2];
int is_clicked=0;
void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 800, 0.0, 600);
}
void pentagon(int x,int y){
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2i(x,y+50);
    glVertex2i(x-50,y);
    glVertex2i(x-50,y-50);
    glVertex2i(x+50,y-50);
    glVertex2i(x+50,y);
    glEnd();
    }
void display()
{
    if(is_clicked){
    pentagon(p,q);
    }
    glColor3f(1, 1, 1);
    char* st= "Parth Miglani 500067488";
    glRasterPos2i(450, 50);
    for( int i=0; i<strlen(st); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);
    }
    char* s= "No. of pentagons = ";
    glRasterPos2i(50, 50);
    for( int i=0; i<strlen(s); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
    }
    glColor3f(0,0,0);
    glPointSize(40);
    glBegin(GL_POINTS);
    glVertex2i(250,50);
    glEnd();
    glColor3f(1, 1, 1);
    glRasterPos2i(250, 50);
    char buffer[10]={"\0"};
    sprintf(buffer,"%d",click_no);
     for( int i=0; i<strlen(buffer); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buffer[i]);
    }
    
    glFlush();
}

void mouse(int button, int state, int x, int y) 
	{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		is_clicked=1;
		p=x;
		arr[click_no][0]=x;
		arr[click_no][1]=y;
		q=600-y;
		r=1;
		g=1;
		b=1;
		click_no++;
		glutPostRedisplay();
		}		
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
		is_clicked=1;
		r=(float)rand()/RAND_MAX;
		g=(float)rand()/RAND_MAX;
		b=(float)rand()/RAND_MAX;
		glutPostRedisplay();
		}		
	}
void keyboard(unsigned char key, int x, int y){
	if(key==27){
	exit(0);
	}
	if(key==32){
	if(click_no>0){
	p=arr[click_no-1][0];
	q=600-arr[click_no-1][1];
	click_no--;
	r=0;
	g=0;
	b=0;
	glutPostRedisplay();}
	}
}
int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 550);
    glutCreateWindow("Experiment 2: Event Handling");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
