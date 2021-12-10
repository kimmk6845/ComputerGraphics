#include <GL/glut.h>
void Init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-2.0, 2.0, -2.0, 2.0, 5.0, 10.0);
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);		//Face 1
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0, 0, 0);		//Vertex1
	glVertex3f(1, 0, 0);		//Vertex2
	glVertex3f(1, 1, 0);		//Vertex3
	glVertex3f(0.5, 1.5, 0.0);	//Vertex4
	glVertex3f(0, 1, 0);		//Vertex5
	glEnd();

	glBegin(GL_POLYGON);		//Face 2
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0, 0, 2);		//Vertex6
	glVertex3f(1, 0, 2);		//Vertex7
	glVertex3f(1, 1, 2);		//Vertex8
	glVertex3f(0.5, 1.5, 2.0);	//Vertex9
	glVertex3f(0, 1, 2);		//Vertex10
	glEnd();

	glBegin(GL_POLYGON);		//Face 3(¹Ø¸é)
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0, 0, 0);		//Vertex1
	glVertex3f(1, 0, 0);		//Vertex2
	glVertex3f(1, 0, 2);		//Vertex7
	glVertex3f(0, 0, 2);		//Vertex6
	glEnd();

	glBegin(GL_POLYGON);		//Face 4
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(1, 0, 0);		//Vertex2
	glVertex3f(1, 1, 0);		//Vertex3
	glVertex3f(1, 1, 2);		//Vertex8
	glVertex3f(1, 0, 2);		//Vertex7
	glEnd();

	glBegin(GL_POLYGON);		//Face 5
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0, 0, 0);		//Vertex1
	glVertex3f(0, 0, 2);		//Vertex6
	glVertex3f(0, 1, 2);		//Vertex10
	glVertex3f(0, 1, 0);		//Vertex5
	glEnd();

	glBegin(GL_POLYGON);		//Face 6(ÁöºØ)
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(1, 1, 0);		//Vertex3
	glVertex3f(0.5, 1.5, 0.0);	//Vertex4
	glVertex3f(0.5, 1.5, 2.0);	//Vertex9
	glVertex3f(1, 1, 2);		//Vertex8
	glEnd();

	glBegin(GL_POLYGON);		//Face 7(ÁöºØ)
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0, 1, 0);		//Vertex5
	glVertex3f(0.5, 1.5, 0.0);	//Vertex4
	glVertex3f(0.5, 1.5, 2.0);	//Vertex9
	glVertex3f(0, 1, 2);		//Vertex10
	glEnd();

	glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("1");
	Init();
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}