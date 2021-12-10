#include <cstdlib>
#include <iostream>
#include <fstream>
#include <GL/glut.h>

using namespace std;

static GLuint texName;
struct BitMapFile
{
	int sizeX;
	int sizeY;
	unsigned char* data;
};

BitMapFile* getBMPData(string filename)
{
	BitMapFile* bmp = new BitMapFile;
	unsigned int size, offset, headerSize;

	ifstream infile(filename.c_str(), ios::binary);

	infile.seekg(10);
	infile.read((char*)& offset, 4);

	infile.read((char*)& headerSize, 4);

	infile.seekg(18);
	infile.read((char*)& bmp->sizeX, 4);
	infile.read((char*)& bmp->sizeY, 4);

	size = bmp->sizeX * bmp->sizeY * 24;
	bmp->data = new unsigned char[size];

	infile.seekg(offset);
	infile.read((char*)bmp->data, size);

	int temp;
	for (int i = 0; i < size; i += 3)
	{
		temp = bmp->data[i];
		bmp->data[i] = bmp->data[i + 2];
		bmp->data[i + 2] = temp;
	}

	return bmp;
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-2.0, 2.0, -2.0, 2.0, 5.0, 10.0);

	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	BitMapFile* image[1];

	image[0] = getBMPData("Textures/canTop.bmp");
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[0]->sizeX, image[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image[0]->data);

}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
	glTexCoord2f(0.0, 1.0); glVertex3f(0, 1, 0);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(1, 0, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0); glVertex3f(0, 1, 0);
	glTexCoord2f(0.0, 1.0); glVertex3f(1, 1, 0);
	glTexCoord2f(0.5, 0.5); glVertex3f(0.5, 1.5, 0);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 2);
	glTexCoord2f(0.0, 1.0); glVertex3f(0, 1, 2);
	glTexCoord2f(1.0, 1.0); glVertex3f(1, 1, 2);
	glTexCoord2f(1.0, 0.0); glVertex3f(1, 0, 2);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0); glVertex3f(0, 1, 2);
	glTexCoord2f(0.0, 1.0); glVertex3f(1, 1, 2);
	glTexCoord2f(0.5, 0.5); glVertex3f(0.5, 1.5, 2);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 2);
	glTexCoord2f(0.0, 2.0); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 2.0); glVertex3f(1, 0, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(1, 0, 2);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(1, 0, 0);
	glTexCoord2f(0.0, 1.0); glVertex3f(1, 1, 0);
	glTexCoord2f(2.0, 1.0); glVertex3f(1, 1, 2);
	glTexCoord2f(2.0, 0.0); glVertex3f(1, 0, 2);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
	glTexCoord2f(0.0, 1.0); glVertex3f(0, 1, 0);
	glTexCoord2f(2.0, 1.0); glVertex3f(0, 1, 2);
	glTexCoord2f(2.0, 0.0); glVertex3f(0, 0, 2);
	glEnd();

	glBegin(GL_QUADS);	//ม๖บุ
	glTexCoord2f(0.0, 0.0); glVertex3f(1, 1, 0);
	glTexCoord2f(0.0, 0.707); glVertex3f(0.5, 1.5, 0);
	glTexCoord2f(2.0, 0.707); glVertex3f(0.5, 1.5, 2);
	glTexCoord2f(2.0, 0.0); glVertex3f(1, 1, 2);
	glEnd();

	glBegin(GL_QUADS);	//ม๖บุ
	glTexCoord2f(0.0, 0.0); glVertex3f(0, 1, 0);
	glTexCoord2f(0.0, 0.707); glVertex3f(0.5, 1.5, 0);
	glTexCoord2f(2.0, 0.707); glVertex3f(0.5, 1.5, 2);
	glTexCoord2f(2.0, 0.0); glVertex3f(0, 1, 2);
	glEnd();
	
	glFlush();


	glDisable(GL_TEXTURE_2D);
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("2");
	init();
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}