#ifndef _Barrier_h_
#define _Barrier_h_

#include "Header.h"

class Barrier
{
public:
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
		if (p.x == 49-4)
			p.x = 1;
		//Sleep(500 + speed*1000); //speed
		gotoXY(++p.x, p.y);
		Draw();
	}
	void savePos(int &a, int &b) {
		a = p.x;
		b = p.y;
	}
	void loadPos(int a , int b) {
		p.x = a;
		p.y = b;
	}
protected:
	Point p;
	int speed = 0;
};

#endif Barrier_h_