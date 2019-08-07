#include "Bird.h" 

Bird::Bird()
{
	p.x = p.y = 2;
}

void Bird::Draw()
{
	cout << bird;
}

void Bird::Destroy()
{
	cout << blank;
}

Point* Bird::inside()
{
	Point a[3];
	for (int i = 0; i < 3; i++)
		a[i] = { p.x + i, p.y };
	return a;
}

bool Bird::Impact(const Point& b)
{
	for (int i = 0; i < 4; i++)
		if (b.x == inside()[i].x && b.y == inside()[i].y)
		{
			for (int j = 0; j < 3; j++)
			{
				system("cls");
				gotoXY(p.x, p.y);
				Draw();
				cout << " OOPSS";
				Sleep(500);
				system("cls");
				gotoXY(b.x, b.y);
				cout << "0  "; cout << "OOPSS";
				Sleep(500);
			}
			return true;
		}
	return false;
}
