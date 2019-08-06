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

	//Movement
	void Up();
	void Down();
	void Right();
	void Left();

	//Impact
	bool isImpact(Car* c);

	bool isImpact(Truck* t);

	bool isImpact(Bird* b);

	bool isImpact(Dino* d);

	bool isImpact(Barrier** b);

	bool isImpactWall();
	//Status
	bool isFinish();
	int& getLives();

	// Again
	void Again();

	//save-load
	void savePos(int& a, int& b);

	void loadPos(int a, int b);

private:
	Point p;
	int lives;
};

#endif