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
		Sleep(1000-speed);
		gotoXY(i, j);
		destroy(i,j);
		i += 2;
	}
}

void CDino::tell()
{
	PlaySound("dino.wav", NULL, SND_ASYNC);
	
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
