#ifndef _Verhicle_h_
#define _Verhicle_h_

#include "Barrier.h"
class Verhicle 
{
public:
	Verhicle()
	{
		p.x = 0;
		p.y = 0;
	}
	Verhicle(int a, int b)
	{
		p.x = a;
		p.y = b;
	}
	virtual void Draw()
	{
		gotoXY(p.x, p.y);
	}

	virtual void Destroy()
	{
		gotoXY(p.x++, p.y);
	}

	virtual void Move(int, int)
	{
		gotoXY(p.x, p.y);
		Destroy();
		if (p.x == 49 - 4)
			p.x = 1;
		//Sleep(500 + speed*1000); //speed
		gotoXY(++p.x, p.y);
		Draw();
	}
	Point* inside()
	{
		Point a[3];
		for (int i = 0; i < 3; i++)
			a[i] = { p.x + i, p.y };
		return a;
	}

	bool Impact(const Point& p)
	{
		for (int i = 0; i < 4; i++)
			if (p.x == inside()[i].x && p.y == inside()[i].y)
				return true;
		return false;
	}
protected:
	Point p;
	int speed = 0;
};

#endif _Verhicle_h_