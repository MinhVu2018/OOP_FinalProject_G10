#ifndef _Car_h_
#define _Car_h_

#include "Vehicle.h"
class Car : public Vehicle
{
public:
	Car();

	Car(int x, int y)
	{
		p.x = x;
		p.y = y;
	}

	void Draw();

	void Destroy();

	Point* inside();

	bool Impact(const Point& p);

private:
	char car[5] = { (char)220, (char)219, (char)219, (char)220,'\0' };
	char blank[5] = { 32, 32,32, 32,'\0' };
};

#endif