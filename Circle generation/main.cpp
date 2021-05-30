#include <GL/glut.h>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>


int clicks = 0,x0,y,cenX,cenY;


void PolarCircle(float cx, float cy, float radius, int seg,float r,float g, float b) {
glColor3f(r, g, b);
glBegin(GL_TRIANGLE_FAN);
for (int i = 0; i < seg; i++)
{
float theta = 2.0f * 3.1415926f * (i) / (seg);
float x = radius * cosf(theta);
float y = radius * sinf(theta);
glVertex2f(x + cx, y + cy);
}
glEnd();
}


void plot(int p, int q){
    glBegin(GL_POINTS);
    glVertex2f(p,q);
    glEnd();
}
void mouse1(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_UP)
    {
        clicks++;
        x0 = mousex;
        y = 480-mousey;
        cenX = mousex;
        cenY = 480-mousey;
        plot(x0, y);
        glColor3f(0,0,0);
    }
    glutPostRedisplay();
}
void mouse2(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_UP)
    {
        clicks++;
        x0 = mousex;
        y = 480-mousey;
        cenX = mousex;
        cenY = 480-mousey;
        plot(x0, y);
        glColor3f(0,0,0);
    }

    glutPostRedisplay();
}
void midPointCircle(int x0, int y0) {
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2.0);
    float r = 80;
    float x = 0, y = r;
    float p = 1 - r;
    glBegin(GL_POINTS);
    while (x != y)
    {
        x++;
        if (p < 0) {
            p += 2 * (x + 1) + 1;
        }
        else {
            y--;
            p += 2 * (x + 1) + 1 - 2 * (y - 1);
        }
        glVertex2i(x+x0, y+y0);
        glVertex2i(-x+x0, y+y0);
        glVertex2i(x+x0, -y+y0);
        glVertex2i(-x+x0, -y+y0);

        glVertex2i(y+x0, x+y0);
        glVertex2i(-y+x0, x+y0);
        glVertex2i(y+x0, -x+y0);
        glVertex2i(-y+x0, -x+y0);

    }
    glEnd();
    glFlush();
}
void display1()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1,1, 1);
    char* st1= "Mid-point";
 glRasterPos2i(250, 450);
 for( int i=0; i<strlen(st1); i++)
 {
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st1[i]);
 }
 char* st= "Parth Miglani 500067488";
 glRasterPos2i(175, 425);
 for( int i=0; i<strlen(st); i++)
 {
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);
 }

 char* st3= "Center of circle = ";
 glRasterPos2i(250, 50);
 for( int i=0; i<strlen(st3); i++)
 {
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st3[i]);
 }

char buffer[10]={"\0"};
 sprintf(buffer,"%d",cenX);
 char buffer1[10]={"\0"};
 sprintf(buffer1,"%d",cenY-2*cenY);
 glRasterPos2i(450, 50);
 for( int i=0; i<strlen(buffer); i++)
 {
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buffer[i]);
 }
 for( int i=0; i<strlen(buffer1); i++)
 {
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buffer1[i]);
 }

 if(clicks)
    midPointCircle(x0,y);


    glFlush();
}

void display2()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glClearColor(1, 1, 1.0, 0);
    if(clicks)
    PolarCircle(x0, y, 80, 50,0,0,0);
    glColor3f(0, 0, 0);
    char* st1= "Polar";
 glRasterPos2i(250, 450);
 for( int i=0; i<strlen(st1); i++)
 {
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st1[i]);
 }
 char* st= "Parth Miglani 500067488";
 glRasterPos2i(150, 425);
 for( int i=0; i<strlen(st); i++)
 {
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);
 }
char* st3= "Center of circle = ";
 glRasterPos2i(250, 50);
 for( int i=0; i<strlen(st3); i++)
 {
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st3[i]);
 }

char buffer[10]={"\0"};
 sprintf(buffer,"%d",cenX);
 char buffer1[10]={"\0"};
 sprintf(buffer1,"%d",cenY-2*cenY);
 glRasterPos2i(450, 50);
 for( int i=0; i<strlen(buffer); i++)
 {
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buffer[i]);
 }
 for( int i=0; i<strlen(buffer1); i++)
 {
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buffer1[i]);
 }

    glColor3f(1.0, 1.0, 1.0);
    glFlush();
}
void displayMain(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
    glFlush();
}
void keyboard(unsigned char key, int mousex, int mousey){
    if(key==27){
        exit(0);
    }
    glutPostRedisplay();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(1290,500);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    int mw = glutCreateWindow("Viva 1");
    glutDisplayFunc(displayMain);

    int sw1 = glutCreateSubWindow(mw, 0, 10, 640, 480);
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutDisplayFunc(display1);

    glutMouseFunc(mouse1);

    int sw2 = glutCreateSubWindow(mw, 640 + 10, 10, 640, 480);
   gluOrtho2D(0.0, 640.0, 0.0, 480.0);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc(display2);


    glutMouseFunc(mouse2);

    glutMainLoop();
}
