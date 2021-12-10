#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <fstream>

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-500,500,-500,500,5,100);
}

void drawPolyLineFile(const char* fileName) {

	std::ifstream inStream;
	inStream.open(fileName);
	if (inStream.fail())
		return;
	GLint numpolys, numLines, x, y;
	inStream >> numpolys;
	for (int j = 0; j < numpolys; j++)
	{
		inStream >> numLines;
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < numLines; i++)
		{
			inStream >> x >> y;
			glVertex2i(x, y);
		}
		glEnd();
	}

	glFlush();
	inStream.close();
}

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	for (int i = 0; i < 12; i++)	//12마리가 30도씩 360도를 채움
	{
		glLoadIdentity();	//초기화
		glTranslatef(0, 0, -20);	//frustum안에 넣기위함
		glRotatef(i * 30, 0, 0, 1);
		glTranslatef(-300, 0, 0);
		glTranslatef(0, 600, 0);
		drawPolyLineFile("dino.dat");
	}

	glFlush();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("출력");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
