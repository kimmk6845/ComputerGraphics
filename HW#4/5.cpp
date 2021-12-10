#include <GL/glut.h>
static float t = 0.0;  // 타이머 변수
static float h = -0.2;  // X방향
static float v = -1.0;  // Y방향
static float g = 0.1;   // 중력 가속도

void DoTimer(int value)	//30ms마다 DoTimer함수 호출
{
	t += 1;
	glutPostRedisplay();
	glutTimerFunc(30, DoTimer, 1);

}
void init(void)
{
	GLfloat mat_specular[] = { 1, 1, 1, 1 };
	GLfloat mat_ambient[] = { 0.1, 0.1, 0.1, 1 };
	GLfloat mat_diffuse[] = { 1, 0, 0, 1 };
	GLfloat mat_shininess[] = { 25.0 };

	GLfloat light_ambient[] = { 1, 0, 0, 1 };
	GLfloat light_specular[] = { 1, 1, 1, 1 };
	GLfloat light_diffuse[] = { 1, 1, 0, 1 };
	GLfloat light_position[] = { 1, 3, -3, 0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0,0,-50);
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex3f(-10, 10, -5);
	glVertex3f(-20, -50, -5);
	glVertex3f(10, -50, -5);
	glVertex3f(20, 10, -5);
	glEnd();


	glPushMatrix();
	glTranslatef(h * t, v * (g / 2.0) * t * t, 0.0);
	glColor3f(0, 0, 1);
	glutSolidSphere(3.0, 10, 10);
	glPopMatrix();


	glutSwapBuffers();
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
}

int main()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("5");
	init();
	glutDisplayFunc(Display);
	glutReshapeFunc(resize);
	glutTimerFunc(30, DoTimer, 1);
	glutMainLoop();
	return 0;

}