#include <GL/glut.h>

using namespace std;

void Init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5, 5, -5, 5, -5, 10);
}

void Display(void)
{
	glEnable(GL_DEPTH_TEST);
	//glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBegin(GL_POLYGON);
	glColor4f(0.0, 0.0, 1.0, 0.5);	//BLUE
	glVertex3f(-4, -3, 0);
	glVertex3f(-4, -4, 0);
	glVertex3f(4, -4, 0);
	glVertex3f(4, -3, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor4f(1.0, 0.0, 0.0, 0.5);	//RED
	glVertex3f(2, 3.5, 0);
	glVertex3f(2, -4.5, 0);
	glVertex3f(3, -4.5, 0);
	glVertex3f(3, 3.5, 0);
	glEnd();


	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	//DEPTH Ãß°¡
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("4");
	Init();
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}
