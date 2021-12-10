#include <windows.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/Glut.h>
#include <math.h>
#define PI 3.141592

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-20.0, 80.0, 20.0, 120.0);		//가시공간 가로 100/세로 100
}

void drdisc(float a, float b, float c)	//원
{
	//a : 반지름, b : 원 중심 x좌표, c : 원 중심 y좌표
	glBegin(GL_TRIANGLE_FAN);
	double t;
	int N = 10000;	//샘플링 10000개
	for (t = 0; t <= 2 * PI; t += (2 * PI) / N)
	{
		glVertex2f(b, c);
		glVertex2f(b + (a * cos(t)), c + (a * sin(t)));
		glVertex2f(b + (a * cos(t + PI/2)), c + (a * sin(t + PI/2)));		//직각 삼각형을 이용해 원을 그림
	}
	glEnd();
	glFlush();
}


void oval(float a, float b, float c)	//타원
{
	//매개변수는 원과 동일하게 a : 반지름, b : 원 중심 x좌표, c : 원 중심 y좌표
	//단축의 반지름이 원의 반지름과 동일하고 장축의 반지름이 1.5배의 비율을 가진다고 가정
	glBegin(GL_TRIANGLE_FAN);
	double t;
	int N = 10000;	//샘플링 10000개
	for (t = 0; t <= 2 * PI; t += (2 * PI) / N)
	{
		glVertex2f(b, c);
		glVertex2f(b + (1.5 * a * cos(t)), c + (a * sin(t)));
		glVertex2f(b + (1.5 * a * cos(t + PI / 2)), c + (a * sin(t + PI / 2)));
	}
	glEnd();
	glFlush();
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	int r = 20;	//원의 반지름 20
	for (int i = 0; i < 2; i++)
	{
		glColor3f(0.0, 0.0, 0.0);
		oval(r, 25.0, 75.0);
		glColor3f(1.0, 1.0, 1.0);
		drdisc(r, 25.0, 75.0);

		r = r * 2 / 3;	//원 안에 타원의 장축의 길이가 원의 지름이므로 원 안의 작은 원의 반지름은 2/3의 비율을 가짐
	}
}

void main(int argc, char** argv)
{
	glutInitWindowSize(400, 400);	//윈도우 크기
	glutInitWindowPosition(100, 100);
	glutCreateWindow("출력");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}