#include "Barrier.h"

Barrier::Barrier()
{
	p.x = p.y = 2;
	speed = 1;
}

void Barrier::Move(int direction, int status)
{
	if (status == 0)
		return;		//Don't move
	gotoXY(p.x, p.y);
	Destroy();

	if (direction == 0)		//left
	{
		if (p.x == 49 - 4)
			p.x = 2;
		gotoXY(++p.x, p.y);
	}
	else                   //right
	{
		if (p.x == 2)
			p.x = 49 - 4;	
		gotoXY(--p.x, p.y);
	}

	Draw();
}

int Barrier::getSpeed()
{
	return speed;
}

void Barrier::savePos(int& a, int& b)
{
	a = p.x;
	b = p.y;
}

void Barrier::loadPos(int a, int b)
{
	p.x = a;
	p.y = b;
}