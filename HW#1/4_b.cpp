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
	gluOrtho2D(-10.0, 50.0, -10.0, 50.0);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < 4; i++)	//세로
	{
		glBegin(GL_LINE_STRIP);
		for (int j = 0; j < 4; j++)	//가로
		{
			glViewport(i * 10, j * 10, 10, 10);
			int N = 10000;	//샘플링 10000개
			int r = 10;		//반지름 10
			double t;

			for (t = 0; t <= 2 * PI; t += 2 * PI / N)
			{
				if (t >= 0 && t <= PI / 2)
					glVertex2f((j * r) + (r * cos(t)), (i * r) + (r * sin(t)));
				else if (t > PI / 2 && t <= PI)
					glVertex2f((j * r) + (r + r * cos(t)), (i * r) + (r * sin(t)));
				else if (t > PI && t <= ((3 * PI) / 2))
					glVertex2f((j * r) + (r + r * cos(t)), (i * r) + (r + r * sin(t)));
				else
					glVertex2f((j * r) + (r * cos(t)), (i * r) + (r + r * sin(t)));

			}
			glVertex2f((j * r) + r, (i * r) + r);
			glVertex2f((j * r) + r, (i * r) + 0);
		}
		glEnd();
	}
	glFlush();
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
