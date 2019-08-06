#include "Truck.h"

Truck::Truck()
{
	p.x = p.y = 2;
}

void Truck::Draw()
{
	std::cout << truck;
}

void Truck::Destroy()
{
	std::cout << blank;
}

Point* Truck::inside()
{
	Point a[3];
	for (int i = 0; i < 3; i++)
		a[i] = { p.x + i, p.y };
	return a;
}

bool Truck::Impact(const Point& b)
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