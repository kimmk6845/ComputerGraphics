#include <windows.h>
#include <math.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/Glut.h>
#define PI 3.141592

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);      
	glColor3f(0.0f, 0.0f, 0.0f);           
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluOrtho2D(0.0, 4.0, -1.0, 1.0);	//���ð��� ����
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	double t;
	for (t = 0; t <= 4; t += 0.005)
	{
		glVertex2f(t, exp(-t) * cos(2 * PI * t));	//parametric form �̿�
	}
	glEnd();
	glFlush(); 
}
void main(int argc, char** argv)
{
	glutInitWindowSize(400, 200);   //window ũ�� ����
	glutInitWindowPosition(100, 150);
	glutCreateWindow("���"); 
	glutDisplayFunc(myDisplay);   
	myInit();
	glutMainLoop();    
}

