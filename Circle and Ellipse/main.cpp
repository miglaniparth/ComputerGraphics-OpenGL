#include <GL/glut.h>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
int clicks = 0,x0,y,cenX,cenY,a=40,b=80;

void DrawEllipse(int x0, int y0){
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);
    float p1 = b*b+a*a/4-a*a*b;
    float dx, dy;
    float x = 0;
    float y = b;
    float p2 = ((b * b) * ((x + 0.5) * (x + 0.5))) + ((a * a) * ((y - 1) * (y - 1))) - (a * a * b * b);
    dx = 2*b*b*x;
    dy = 2*a*a*y;
    glBegin(GL_POINTS);
    while (b*b*x < a*a*y)
    {
         x++;
        if (p1 < 0)
        {
            dx = dx + (2 * b * b);
            p1 = p1 + dx + (b * b);
        }
        else
        {
            y--;
            dx = dx + (2 * b * b);
            dy = dy - (2 * a * a);
            p1 = p1 + dx - dy + (b * b);
        }
        glVertex2i(x + x0, y + y0);
        glVertex2i(-x + x0, y + y0);
        glVertex2i(x + x0, -y + y0);
        glVertex2i(-x + x0, -y + y0);
    }
    glEnd();
    glBegin(GL_POINTS);
    while (1)
    {
        y--;
        if (p2 > 0)
        {
            dy = dy - (2 * a * a);
            p2 = p2 + (a * a) - dy;
        }
        else
        {
            x++;
            dx = dx + (2 * b * b);
            dy = dy - (2 * a * a);
            p2 = p2 + dx - dy + (a * a);
        }
        glVertex2i(x + x0, y + y0);
        glVertex2i(-x + x0, y + y0);
        glVertex2i(x + x0, -y + y0);
        glVertex2i(-x + x0, -y + y0);
        if(y<0)
            break;
    }
    glEnd();
    glFlush();
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
 char* st1= "Circle ";
 glRasterPos2i(260, 450);
for( int i=0; i<strlen(st1); i++)
 {
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st1[i]);
 }
char* st= "Parth Miglani 500067488";
 glRasterPos2i(165, 425);
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
 DrawEllipse(x0,y);
 glColor3f(0, 0, 0);
 char* st1= "Ellipse";
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
char* st3= "Center of ellipse = ";
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
}
int main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitWindowSize(1290,500);
 glutInitWindowPosition(0,0);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 int mw = glutCreateWindow("Lab 5 : Circle and Ellipse");
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
 glutKeyboardFunc(keyboard);
 glutMainLoop();
}
