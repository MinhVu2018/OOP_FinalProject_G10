#include "Dino.h"

Dino::Dino()
{
	p.x = p.y = 2;
}

void Dino::Draw()
{
	std::cout << dino1;
	gotoXY(p.x, p.y + 1);
	std::cout << dino2;
}

void Dino::Destroy()
{
	std::cout << blank;
	gotoXY(p.x, p.y + 1);
	std::cout << blank;
}

Point* Dino::inside()
{
	Point a[6];
	for (int i = 0; i < 3; i++)
		a[i] = { p.x + i, p.y };
	for (int i = 0; i < 3; i++)
		a[i] = { p.x + i, p.y+1 };
	return a;
}

bool Dino::Impact(const Point& b)
{
	for (int i = 0; i < 4; i++)
		if (b.x == inside()[i].x && p.y == inside()[i].y)
		{
			for (int j = 0; j < 3; j++)
			{
				//PlaySound(TEXT("D:\\dino.wav"), NULL, SND_SYNC);
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