#include <GL/glut.h>

void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	int i;
	int NUM = 500;
	double u;
	double v;
	glBegin(GL_LINE_STRIP);
	for (i = 0; i < NUM; i++)	//(0,0),(5,-10),(23,-5),(25,5) --> 5의 곡선 아래 부분을 control point 4점을 이용한 3차 베지에 커브
	{
		u = double(i) / (NUM * 1.0);
		v = u + 1 / (NUM * 1.0);
		glVertex2f(-29 * u * u * u + 39 * u * u + 15 * u, -10 * u * u * u + 45 * u * u - 30 * u);
		glVertex2f(-29 * v * v * v + 39 * v * v + 15 * v, -10 * v * v * v + 45 * v * v - 30 * v);
	}

	glColor3f(0.0, 0.0, 1.0);
	for (i = 0; i < NUM; i++)	//(25,5),(25,15),(10,20),(5,17) --> 5의 곡선 윗 부분을 control point 4점을 이용한 3차 베지에 커브
	{
		u = double(i) / (NUM * 1.0);
		v = u + 1 / (NUM * 1.0);
		glVertex2f(25 * u * u * u - 45 * u * u + 25, -3 * u * u * u - 15 * u * u + 30 * u + 5);
		glVertex2f(25 * v * v * v - 45 * v * v + 25, -3 * v * v * v - 15 * v * v + 30 * v + 5);
	}

	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(5, 17);
	glVertex2f(8, 40);
	glVertex2f(25, 40);

	glEnd();

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 300);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("4");
	glutDisplayFunc(Display);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(-10, 50, -10, 50);
	glutMainLoop();
	return 0;
}