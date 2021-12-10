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

	//����(0,0)
	glVertex3f(0 + 10, 0, 1);
	glVertex3f(0 + 10 * cos(PI / 3), 0 + 10 * sin(PI / 3), 1);
	glVertex3f(0 + 10 * cos(PI / 3) - 10, 0 + 10 * sin(PI / 3), 1);
	glVertex3f(0 - 10, 0, 1);
	glVertex3f(0 + 10 * cos(PI / 3) - 10, 0 - 10 * sin(PI / 3), 1);
	glVertex3f(0 + 10 * cos(PI / 3), 0 - 10 * sin(PI / 3), 1);
	glVertex3f(0 + 10, 0, 1);	//������ Line_Strip�� �̾��ֱ� ���� vertex

	glEnd();
	glFlush();
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//�߾� hexagon
	draw_hexagon();

	//�߾ӿ� �������ִ� hexagons
	glColor3f(1, 0, 0);
	for (int i = 0; i < 6; i++)
	{
		glLoadIdentity();
		glRotatef(60 * i, 0, 0, 1);
		glTranslatef(15, 10 * sin(PI / 3), 0);
		draw_hexagon();
	}

	//���� �ٱ��� hexagons (1)
	glColor3f(0, 1, 0);
	for (int i = 0; i < 6; i++)
	{
		glLoadIdentity();
		glRotatef(60 * i, 0, 0, 1);
		glTranslatef(30, 0, 0);
		draw_hexagon();
	}

	//���� �ٱ��� (2)
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
	glutCreateWindow("���");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
