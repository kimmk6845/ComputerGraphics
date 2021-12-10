#include <GL/glut.h>
#include <math.h>
#define PI 3.141592

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5, 5, -5, 5,-5, 0);
}

void DrawHalfSpoke(void)
{
	glBegin(GL_LINE_STRIP);
	glVertex3f(0.2, 0.1, 1);
	glVertex3f(1.7, 0.1, 1);
	glVertex3f(1.7 + cos(PI / 3), 0.1 + sin(PI / 3), 1);
	glVertex3f(1.9 + cos(PI / 3) * 4 / 5, 0.1 + sin(PI / 3) * 4 / 5, 1);
	glVertex3f(1.9, 0.1, 1);
	glVertex3f(2.9, 0.1, 1);
	glVertex3f(2.9 + cos(PI / 3) * 4 / 5, 0.1 + sin(PI / 3) * 4 / 5, 1);
	glVertex3f(3.1 + cos(PI / 3) * 3 / 5, 0.1 + sin(PI / 3) * 3 / 5, 1);
	glVertex3f(3.1, 0.1, 1);
	glVertex3f(4.1, 0.1, 1);
	glVertex3f(4.2, 0, 1);

	glEnd();
	glFlush();
}

void DrawSpoke(void)	//1개 spoke
{
	DrawHalfSpoke();
	glScalef(1.0, -1.0, 1.0);
	DrawHalfSpoke();
}

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	
	for (int i = 0; i < 6; i++)	//rotate함수 6번 반복
	{
		glRotatef(60 * i, 0, 0, 1);	//z축 방향으로 60도씩 회전
		DrawSpoke();
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
