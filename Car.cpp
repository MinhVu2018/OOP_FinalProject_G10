#include "Car.h"

Car::Car()
{
	p.x = 0;
	p.y = 0;
}

void Car::Draw()
{
	cout << car;
}

void Car::Destroy()
{
	cout << blank;
}

Point* Car::inside()
{
	Point a[4];
	for (int i = 0; i < 4; i++)
		a[i] = { p.x + i, p.y };
	return a;
}

bool Car::Impact(const Point& b)
{
	for (int i = 0; i < 4; i++)
		if (b.x == inside()[i].x && b.y == inside()[i].y)
		{
			for (int j = 0; j < 3; j++)
			{
				//crash();
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