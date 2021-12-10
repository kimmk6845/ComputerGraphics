#include <iostream>
using namespace std;

void MidpointLine(int x1, int y1, int x2, int y2)
{
	int dx, dy, x, y;
	int incrN, incrNE;
	int D;
	int count = 0;

	dx = x2 - x1;
	dy = y2 - y1;
	D = -2 * dx + dy;	//��������
	incrN = -2 * dx;		//���� ����
	incrNE = 2 * dy - 2 * dx;	//������ ����

	x = x1;
	y = y1;
	while (y < y2)		//y�� 1�� �þ�Ƿ�
	{
		if (D <= 0)
		{
			cout << "D = " << D << endl;
			D += incrNE;
			x++;
			y++;
		}
		else
		{
			cout << "D = " << D << endl;
			D += incrN;
			y++;
		}
		count++;
	}
	cout << "�� �̿��� ���� �� = " << count << endl;
}

int main()
{
	int x1 = 0, y1 = 0, x2 = 5, y2 = 9;
	MidpointLine(x1, y1, x2, y2);
}