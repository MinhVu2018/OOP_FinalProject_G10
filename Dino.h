#ifndef _Dino_h_
#define _Dino_h_
#include "Animal.h"

class Dino : public Animal
{
public:
	Dino();

	Dino(int x1, int y1)
	{
		p.x = x1;
		p.y = y1;
	}
	
	void Tell();

	void Draw();

	void Destroy();
	
	Point* inside();

	bool Impact(const Point& p);

private:
	char dino1[4] = { (char)255,(char)220,(char)219, '\0' };
	char dino2[3] = { (char)223, (char)223, '\0' };
	char blank[4] = { 32,32,32,'\0' };
};

#endif