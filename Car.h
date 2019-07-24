#ifndef _Car_h_
#define _Car_h_
#include "Verhicle.h"
class Car : public Verhicle
{
public:
	Car():Verhicle()
	{
		
	}

	Car(int x, int y):Verhicle(x, y)
	{
		
	}

	void Draw()
	{
		std::cout << car;
	}

	void Destroy()
	{
		std::cout << blank;
	}

	

private:
	char car[5] = { (char)220, (char)219, (char)219, (char)220,'\0' };
	char blank[5] = { 32, 32,32, 32,'\0' };
};

#endif _Car_h_