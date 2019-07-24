#ifndef _Truck_h_
#define _Truck_h_
#include "Verhicle.h"
class Truck : public Verhicle
{
public:
	Truck():Verhicle()
	{
		
	}

	Truck(int x, int y):Verhicle(x, y)
	{
		
	}

	void Draw()
	{
		std::cout << truck;
	}

	void Destroy()
	{
		std::cout << blank;
	}

	
private:
	char truck[4] = { (char)220,(char)219,(char)219,'\0' };
	char blank[4] = { 32, 32, 32,'\0' };
};

#endif _Verhicle_h_