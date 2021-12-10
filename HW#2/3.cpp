#include <GL/glut.h>
#include <math.h>
#define PI 3.141592

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100, 100, -100, 100,-5, 0);
}

void draw_hexagon(void)
{
	glBegin(GL_LINE_STRIP);

	//중점(0,0)
	glVertex3f(0 + 10, 0, 1);
	glVertex3f(0 + 10 * cos(PI / 3), 0 + 10 * sin(PI / 3), 1);
	glVertex3f(0 + 10 * cos(PI / 3) - 10, 0 + 10 * sin(PI / 3), 1);
	glVertex3f(0 - 10, 0, 1);
	glVertex3f(0 + 10 * cos(PI / 3) - 10, 0 - 10 * sin(PI / 3), 1);
	glVertex3f(0 + 10 * cos(PI / 3), 0 - 10 * sin(PI / 3), 1);
	glVertex3f(0 + 10, 0, 1);	//마지막 Line_Strip을 이어주기 위한 vertex

	glEnd();
	glFlush();
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//중앙 hexagon
	draw_hexagon();

	//중앙에 인접해있는 hexagons
	glColor3f(1, 0, 0);
	for (int i = 0; i < 6; i++)
	{
		glLoadIdentity();
		glRotatef(60 * i, 0, 0, 1);
		glTranslatef(15, 10 * sin(PI / 3), 0);
		draw_hexagon();
	}

	//가장 바깥쪽 hexagons (1)
	glColor3f(0, 1, 0);
	for (int i = 0; i < 6; i++)
	{
		glLoadIdentity();
		glRotatef(60 * i, 0, 0, 1);
		glTranslatef(30, 0, 0);
		draw_hexagon();
	}

	//가장 바깥쪽 (2)
	glColor3f(0, 0, 1);
	for (int i = 0; i < 6; i++)
	{
		glLoadIdentity();
		glRotatef(60 * i, 0, 0, 1);
		glTranslatef(30, 20 * sin(PI / 3), 0);
		draw_hexagon();
	}
}

void main(int argc, char** argv)
{
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("출력");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
