#ifndef _Barrier_h_
#define _Barrier_h_

#include "Header.h"

class Barrier
{
public:
	Barrier();

	virtual void Draw() = 0;

	virtual void Destroy() = 0;

	virtual void Move(int, int);	// left-right, stop-move

	int getSpeed();

	virtual Point* inside() = 0;

	virtual bool Impact(const Point&) = 0;

	void savePos(int& , int& );
	
	void loadPos(int, int);

protected:
	Point p;
	int speed;
};

#endif