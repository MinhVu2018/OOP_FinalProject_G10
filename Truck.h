#ifndef _Truck_h_
#define _Truck_h_
#include "Vehicle.h"
class Truck : public Vehicle
{
public:
	Truck();

	Truck(int x, int y)
	{
		p.x = x;
		p.y = y; // 6
	}

	void Draw();

	void Destroy();

	Point* inside();

	bool Impact(const Point& );
	
private:
	char truck[4] = { (char)220,(char)219,(char)219,'\0' };
	char blank[4] = { 32, 32, 32,'\0' };
};

#endif