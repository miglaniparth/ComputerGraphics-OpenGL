#include<GL/glut.h>
#include<math.h>
#include<string.h>
void init()
{
    glClearColor(0.529, 0.808, 0.922, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 800, 0.0, 600);
}
void DrawCircle(float cx, float cy, float radius, int seg,float r,float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < seg; i++)   {
        float theta = 2.0f * 3.1415926f * (i) / (seg);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //Roof     
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(400, 450);
    glVertex2i(700, 450);
    glVertex2i(750, 350);
    glVertex2i(450, 350);
    glEnd();

    // Hut triangle
    glColor3f(2.0, 0.5, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(400, 450);
    glVertex2i(450, 350);
    glVertex2i(350, 350);
    glEnd();

    // Door Wall
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(350, 350);
    glVertex2i(450, 350);
    glVertex2i(450, 150);
    glVertex2i(350, 150);
    glEnd();

    // Front Door
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(375, 300);
    glVertex2i(425, 300);
    glVertex2i(425, 150);
    glVertex2i(375, 150);
    glEnd();
    
    // Door Handle
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(7);
    glBegin(GL_POINTS);
    glVertex2i(415, 225);
    glEnd();

    // Wall
    glColor3f(0.5, 1.0, 0.5);
    glBegin(GL_POLYGON);
    glVertex2i(750, 350);
    glVertex2i(450, 350);
    glVertex2i(450, 150);
    glVertex2i(750, 150);
    glEnd();

    // Window
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(530, 300);
    glVertex2i(660, 300);
    glVertex2i(660, 200);
    glVertex2i(530, 200);
    glEnd();

    // Window Lines
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(595, 300);
    glVertex2i(595, 200);
    glVertex2i(530, 250);
    glVertex2i(660, 250);
    glEnd();
    
    // Grass
    glColor3f(0.0, 0.8, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(800, 0);
    glVertex2i(8000, 150);
    glVertex2i(0, 150);
    glEnd();
    
    // Path
    glColor3f(0.71, 0.396, 0.114);
    glBegin(GL_POLYGON);
    glVertex2i(425, 150);
    glVertex2i(375, 150);
    glVertex2i(200, 0);
    glVertex2i(300, 0);
    glEnd();
    
    //Tree Trunk    
    glColor3f(0.78, 0.53, 0.360);
    glBegin(GL_POLYGON);
    glVertex2i(95, 150);
    glVertex2i(125, 150);
    glVertex2i(125, 200);
    glVertex2i(95, 200);
    glEnd();
    
    //Tree leaves
    DrawCircle(112,237.5,50,300,0.0,0.7,0.0);
    DrawCircle(112,287.5,50,300,0.0,0.7,0.0);
    DrawCircle(112,337.5,50,300,0.0,0.7,0.0);
    
    //cloud 1
    DrawCircle(410,520,30,300,0.193,0.190,0.186);
    DrawCircle(450,520,30,300,0.193,0.190,0.186);
    DrawCircle(490,520,30,300,0.193,0.190,0.186);
    glColor3f(0.193,0.190,0.186);
    glBegin(GL_POLYGON);
    glVertex2i(410, 490);
    glVertex2i(490, 490);
    glVertex2i(490, 500);
    glVertex2i(410, 500);
    glEnd();
    
    ///cloud 2
    DrawCircle(610,520,30,300,0.193,0.190,0.186);
    DrawCircle(650,520,30,300,0.193,0.190,0.186);
    DrawCircle(690,520,30,300,0.193,0.190,0.186);
    glColor3f(0.193,0.190,0.186);
    glBegin(GL_POLYGON);
    glVertex2i(610, 490);
    glVertex2i(690, 490);
    glVertex2i(690, 500);
    glVertex2i(610, 500);
    glEnd();
    
    //SUN
    DrawCircle(250, 550, 50.0, 300, 1, 1, 0);
    
    //Circle in Triangle
    DrawCircle(400, 385, 20.0, 300, 0, 0, 1);
    
    //Text
    glColor3f(0, 0, 0);
    char* st= "Parth Miglani R110218103";
    glRasterPos2i(450, 50);
    for( int i=0; i<strlen(st); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);
    }

    glFlush();
}
int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 550);
    glutCreateWindow("Experiment 1: Scenery with Hut");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
