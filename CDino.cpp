#include "CDino.h"



CDino::CDino()
{
}


CDino::~CDino()
{
}

void CDino::move(int y, int speed)
{
	int i = 0, j = y;
	gotoXY(i, j);

	while (i < 120)
	{
		
		draw(i, j);
		Sleep(speed);
		gotoXY(i, j);
		destroy(i,j);
		i += 3;
	}
}

void CDino::tell()
{
}

void CDino::draw(int x, int y)
{
	gotoXY(x, y);
	cout << dino1;
	gotoXY(x, y+1);
	cout << dino2;
}

void CDino::destroy(int x, int y)
{
	gotoXY(x, y);
	cout << blank;
	gotoXY(x, y + 1);
	cout << blank;
}
