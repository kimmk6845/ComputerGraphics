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
	gluOrtho2D(-1.0, 11.0, -1.0, 11.0);

}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	int N = 10000;	//샘플링 10000개
	int r = 10;		//반지름 10
	double t;

	for (t = 0; t <= 2 * PI; t += 2 * PI / N)
	{
		if (t >= 0 && t <= PI / 2)
		{
			glVertex2f(r * cos(t), r * sin(t));
		}
		else if (t > PI / 2 && t <= PI)
		{
			glVertex2f(r + r * cos(t), r * sin(t));
		}
		else if (t > PI && t <= ((3 * PI) / 2))
		{
			glVertex2f(r + r * cos(t), r + r * sin(t));
		}
		else
		{
			glVertex2f(r * cos(t), r + r * sin(t));
		}
	}
	glVertex2f(r, r);
	glVertex2f(r, 0);	
	//마지막 원의 중점이 (0, 10)인 원과 중점이 (0, 0)인 원의 일부에서 테두리가 이어지지 않으므로 이어주는 선분

	glEnd();
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
