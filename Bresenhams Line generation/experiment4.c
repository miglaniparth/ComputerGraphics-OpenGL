#include<GL/glut.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
int click_no=0;
float points[2][2];
float slope;
void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 800, 0.0, 600);
}

void drawline(){
    glPointSize(5);
    glColor3f(1,1,1);

    int dx, dy, p;
    dx = points[1][0]-points[0][0];
    dy = points[1][1]-points[0][1];
    
    int temp; 
    
    if(dx<0){
    temp=points[0][0];
    points[0][0]=points[1][0];
    points[1][0]=temp;
    
    temp=points[0][1];
    points[0][1]=points[1][1];
    points[1][1]=temp;
    
    dx=-dx;
    dy=-dy;
    }
    if (slope<0 && slope>=-1){
    p=2*dy-dx;
    while(points[1][0]!=points[0][0] && points[1][1]!=points[0][1]){
    if(p>0){
    points[0][0]++;
    points[0][1]--;
    glBegin(GL_POINTS);
    glVertex2f(points[0][0],points[0][1]);
    glEnd();
    p=p-2*dy-2*dx;
    }
    else{
    points[0][0]++;
    glBegin(GL_POINTS);
    glVertex2f(points[0][0],points[0][1]);
    glEnd();
    p=p-2*dy;
  }
  }
    }
    if (slope<-1){
    glColor3f(0,0,1);
    p=2*dx+dy;
    while(points[1][0]!=points[0][0] && points[1][1]!=points[0][1]){
    if(p>0){
    points[0][1]--;
    points[0][0]++;
    glBegin(GL_POINTS);
    glVertex2f(points[0][0],points[0][1]);
    glEnd();
    p=p+2*dx+2*dy;
    }
    else{
    points[0][1]--;
    glBegin(GL_POINTS);
    glVertex2f(points[0][0],points[0][1]);
    glEnd();
    p=p+2*dx;
    }
    }}
    else if(slope<=1 && slope>=0){
    glColor3f(0,1,1);
    p=2*dy-dx;
    while(points[1][0]!=points[0][0] && points[1][1]!=points[0][1]){
    if(p>0){
    points[0][0]++;
    points[0][1]++;
    glBegin(GL_POINTS);
    glVertex2f(points[0][0],points[0][1]);
    glEnd();
    p=p+2*dy-2*dx;
    }
    else{
    points[0][0]++;
    glBegin(GL_POINTS);
    glVertex2f(points[0][0],points[0][1]);
    glEnd();
    p=p+2*dy;
  }
  }}
  else if (slope>=1){
  glColor3f(1,0,1);
    p=2*dx-dy;
    while(points[1][0]!=points[0][0] && points[1][1]!=points[0][1]){
    if(p>0){
    points[0][1]++;
    points[0][0]++;
    glBegin(GL_POINTS);
    glVertex2f(points[0][0],points[0][1]);
    glEnd();
    p=p+2*dx-2*dy;
    }
    else{
    points[0][1]++;
    glBegin(GL_POINTS);
    glVertex2f(points[0][0],points[0][1]);
    glEnd();
    p=p+2*dx;
  }
}
}
}
void display()
{
    
    glColor3f(1, 1, 1);
    char* st= "Parth Miglani 500067488";
    glRasterPos2i(450, 50);
    for( int i=0; i<strlen(st); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);
    }
    char* s= "Slope of last line = ";
    glRasterPos2i(450, 550);
    for( int i=0; i<strlen(s); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
    }
    char* s1= "No. of lines = ";
    glRasterPos2i(50, 50);
    for( int i=0; i<strlen(s1); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s1[i]);
    }
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(650,570);
    glVertex2i(770,570);
    glVertex2i(770,540);
    glVertex2i(650,540);
    glEnd();
    glColor3f(1, 1, 1);
    glRasterPos2i(650, 550);
    char buffer[10]={"\0"};
    sprintf(buffer,"%f",slope);
    for( int i=0; i<strlen(buffer); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buffer[i]);
    }
    if (click_no%2==0){
        drawline();
    }
    glColor3f(0,0,0);
    glPointSize(60);
    glBegin(GL_POINTS);
    glVertex2i(250,50);
    glEnd();
    
    glColor3f(1,1,1);
    glRasterPos2i(250, 50);
    char buffer1[10]={"\0"};
    sprintf(buffer1,"%d",click_no/2);
     for( int i=0; i<strlen(buffer1); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, buffer1[i]);
    }
    
    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        click_no++;
        if (click_no%2!=0){
            points[0][0]=x;
            points[0][1]=600-y;
        }
        else{
            points[1][0]=x;
            points[1][1]=600-y;
            slope=(float)(points[1][1]-points[0][1])/(points[1][0]-points[0][0]);
            glutPostRedisplay();
        }
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        
    }
}
void keyboard(unsigned char key, int x, int y){
    if(key==27){
        exit(0);
    }
    
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Experiment 4: Bresenham's Line Drawing Algo");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
