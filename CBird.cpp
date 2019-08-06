#include "CBird.h"

CBird::CBird()
{
}

CBird::~CBird()
{
}

void CBird::move(int y, int speed)
{
	int i = 0, j = y;
	gotoXY(i, j);
	while (i < 120)
	{
		draw();
		Sleep(1000-speed);
		gotoXY(i, j);
		destroy();
		i += 2;
	}
}

void CBird::tell()
{
	PlaySound("bird.wav", NULL, SND_ASYNC);
}



void CBird::draw()
{
	cout << bird;
}

void CBird::destroy()
{
	cout << blank;
}