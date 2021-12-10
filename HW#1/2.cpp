#include <windows.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/Glut.h>

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5.0, 15.0, -5.0, 20.0);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(0.0, 13.0);
	glVertex2f(0.0, 15.0);
	glVertex2f(2.0, 13.0);	//clock
	
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(2.0, 13.0);
	glVertex2f(0.0, 15.0);
	glVertex2f(4.0, 15.0);	//clock

	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(2.0, 13.0);
	glVertex2f(4.0, 15.0);
	glVertex2f(2.0, 0.0);	//clock


	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(2.0, 0.0);
	glVertex2f(4.0, 15.0);
	glVertex2f(4.0, 2.0);	//clock

	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(2.0, 0.0);
	glVertex2f(4.0, 2.0);
	glVertex2f(7.0, 0.0);	//clock

	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(7.0, 0.0);
	glVertex2f(4.0, 2.0);
	glVertex2f(5.0, 2.0);	//clock

	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(7.0, 0.0);
	glVertex2f(5.0, 2.0);
	glVertex2f(5.0, 15.0);	//clock

	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(7.0, 0.0);
	glVertex2f(5.0, 15.0);
	glVertex2f(7.0, 13.0);	//clock

	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(7.0, 13.0);	
	glVertex2f(5.0, 15.0);
	glVertex2f(9.0, 15.0);	//clock
	
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(7.0, 13.0);
	glVertex2f(9.0, 15.0);
	glVertex2f(9.0, 13.0);	//clock
	//orientation�� �ð����
	//triangulation�� �������ȿ� �ٸ� vertex�� ���� �ﰢ������ �������� ������ ����
	//12�� vertex���

	glEnd();
	glFlush();
}

void main(int argc, char** argv)
{
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("���");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
