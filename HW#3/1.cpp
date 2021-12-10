#include <iostream>
using namespace std;

void MidpointLine(int x1, int y1, int x2, int y2)
{
	int dx, dy, x, y;
	int incrE, incrNE;
	int D;
	int count = 0;

	dx = x2 - x1;
	dy = y2 - y1;
	D = 2 * dy - dx;	//결정변수
	incrE = 2 * dy;		//동쪽 선택
	incrNE = 2 * dy - 2 * dx;	//동북쪽 선택
	
	x = x1;
	y = y1;
	while (x < x2)
	{
		if (D <= 0) 
		{
			cout << "D = " << D << endl;
			D += incrE;
			x++;
		}
		else
		{
			cout << "D = " << D << endl;
			D += incrNE;
			x++;
			y++;
		}
		count++;
	}
	cout << "총 이용한 중점 수 = " << count << endl;
}

int main()
{
	int x1 = 0, y1 = 0, x2 = 9, y2 = 5;
	MidpointLine(x1, y1, x2, y2);
}