#ifndef _Player_h_
#define _Player_h_
#include "Header.h"
#include "Truck.h"
#include "Car.h"
#include "Bird.h"
#include "Dino.h"

class People
{
public:
	People();
	void Draw();
	void Destroy();

	//Move
	void Up();
	void Down();
	void Left();
	void Right();

	//Impact
	bool isImpact(Car *c);
	bool isImpact(Truck *t);
	bool isImpact(Bird *b);
	bool isImpact(Dino* d);

	//Status
	bool isFinish();
	bool isDead();

	//Save
	void savePos(int& a, int& b);
	void loadPos(int a, int b);

private:
	Point p;
	bool Alive; // Alive or Dead
};

#endif _Player_h_