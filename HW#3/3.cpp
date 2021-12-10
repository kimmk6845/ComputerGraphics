#include <windows.h>
#include <GL/glut.h>

#include <iostream>
#include <fstream>
using namespace std;

float* VertexArr = new float[2132 * 3];
int* FaceInfo = new int[4272 * 4];

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20, 20, -20, 20, -20, 20);
}

void drawFile(const char* fileName) {
	ifstream inStream;
	inStream.open(fileName);
	if (inStream.fail())
		return;

	string fileformat;
	inStream >> fileformat;

	GLint numVertex, numFace, numEdge;
	GLfloat x, y, z;

	cout << "Fileformat: " << fileformat << endl;

	inStream >> numVertex;
	inStream >> numFace;
	inStream >> numEdge;
	cout << numVertex << " " << numFace << " " << numEdge << endl;

	int k1 = 0;
	for (int i = 0; i < numVertex; i++)	//vertex 정보 저장
	{
		inStream >> x >> y >> z;
		//cout << "Vertex " << i+1 << ": " << x << " " << y << " " << z << endl;
		VertexArr[k1++] = x;
		VertexArr[k1++] = y;
		VertexArr[k1++] = z;
	}
	cout << endl;

	GLint F_Vertex, F_VertexIdx1, F_VertexIdx2, F_VertexIdx3;
	int k2 = 0;
	for (int i = 0; i < numFace; i++)	//Face 정보 저장
	{
		inStream >> F_Vertex >> F_VertexIdx1 >> F_VertexIdx2 >> F_VertexIdx3;
		//cout << "Face " << i+1 << ": " << F_Vertex << " " << F_VertexIdx1 << " " << F_VertexIdx2 << " " << F_VertexIdx3 << endl;
		FaceInfo[k2++] = F_Vertex;	//삼각형으로 face 구성
		FaceInfo[k2++] = F_VertexIdx1;	//각 삼각형 꼭짓점의 vertexIndex
		FaceInfo[k2++] = F_VertexIdx2;
		FaceInfo[k2++] = F_VertexIdx3;

	}
	inStream.close();

	//glRotatef(90, 0, 0, 1);

	for (int i = 0; i < numFace; i++)
	{
		glBegin(GL_POLYGON);
		for (int j = 1; j < 4; j++)
		{
			int VertexIDX = FaceInfo[4 * i + j];

			glVertex3f(VertexArr[3 * VertexIDX], VertexArr[3 * VertexIDX + 1], VertexArr[3 * VertexIDX + 2]);
		}
		glEnd();
	}
	glFlush();
	delete[] FaceInfo;
	delete[] VertexArr;
}

void render() {

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	drawFile("block.off");
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("3");
	glutDisplayFunc(render);
	myInit();
	glutMainLoop();
}
