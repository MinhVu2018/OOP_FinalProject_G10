#ifndef _Bird_h_
#define _Bird_h_
#include "Animal.h"

class Bird : public Animal
{
public:
	Bird();

	Bird(int x, int y)
	{
		p.x = x;
		p.y = y; //2
	}

	void Tell();

	void Draw();

	void Destroy();

	Point* inside();

	bool Impact(const Point& b);

private:
	char bird[4] = { (char)223, (char)254, (char)223,'\0' };
	char blank[4] = { 32, 32, 32,'\0' };
};

#endif