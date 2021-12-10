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
	gluOrtho2D(-20.0, 80.0, 20.0, 120.0);		//���ð��� ���� 100/���� 100
}

void drdisc(float a, float b, float c)	//��
{
	//a : ������, b : �� �߽� x��ǥ, c : �� �߽� y��ǥ
	glBegin(GL_TRIANGLE_FAN);
	double t;
	int N = 10000;	//���ø� 10000��
	for (t = 0; t <= 2 * PI; t += (2 * PI) / N)
	{
		glVertex2f(b, c);
		glVertex2f(b + (a * cos(t)), c + (a * sin(t)));
		glVertex2f(b + (a * cos(t + PI/2)), c + (a * sin(t + PI/2)));		//���� �ﰢ���� �̿��� ���� �׸�
	}
	glEnd();
	glFlush();
}


void oval(float a, float b, float c)	//Ÿ��
{
	//�Ű������� ���� �����ϰ� a : ������, b : �� �߽� x��ǥ, c : �� �߽� y��ǥ
	//������ �������� ���� �������� �����ϰ� ������ �������� 1.5���� ������ �����ٰ� ����
	glBegin(GL_TRIANGLE_FAN);
	double t;
	int N = 10000;	//���ø� 10000��
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

	int r = 20;	//���� ������ 20
	for (int i = 0; i < 2; i++)
	{
		glColor3f(0.0, 0.0, 0.0);
		oval(r, 25.0, 75.0);
		glColor3f(1.0, 1.0, 1.0);
		drdisc(r, 25.0, 75.0);

		r = r * 2 / 3;	//�� �ȿ� Ÿ���� ������ ���̰� ���� �����̹Ƿ� �� ���� ���� ���� �������� 2/3�� ������ ����
	}
}

void main(int argc, char** argv)
{
	glutInitWindowSize(400, 400);	//������ ũ��
	glutInitWindowPosition(100, 100);
	glutCreateWindow("���");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}