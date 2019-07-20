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
	People() // constructor
	{
		p.x = 25;
		p.y = 15;
		Alive = 1;
	};

	void Draw()
	{
		gotoXY(p.x, p.y);
		std::cout << "Y";
	}

	void Destroy()
	{
		gotoXY(p.x, p.y);
		std::cout << " ";
	}

	//Movement
	void Up()
	{
		Destroy();
		p.y--;
		Draw();
	}

	void Down()
	{
		Destroy();
		p.y++;
		Draw();
	}

	void Left()
	{
		Destroy();
		p.x--;
		Draw();
	}

	void Right()
	{
		Destroy();
		p.x++;
		Draw();
	}

	//Impact
	bool isImpact(Car *c)
	{
		for (int i = 0; i < 4; i++)
			if (c[i].Impact(p))
				return true;
		return false;
	}

	bool isImpact(Truck *t)
	{
		for (int i = 0; i < 4; i++)
			if (t[i].Impact(p))
				return true;
		return false;
	}

	bool isImpact(Bird *b)
	{
		for (int i = 0; i < 4; i++)
			if (b[i].Impact(p))
				return true;
		return false;
	}

	bool isImpact(Dino* d)
	{
		for (int i = 0; i < 4; i++)
			if (d[i].Impact(p))
				return true;
		return false;
	}

	//Status
	bool isFinish()
	{
		if (p.y == 1)
			return true;
		return false;
	}
	bool isDead()
	{
		if (p.x == 1 || p.x == 49 || p.y == 16)
			Alive = false;
		return !Alive;
	}

	//Save
	void savePos(int& a, int& b) {
		a = p.x;
		b = p.y;
	}

	void loadPos(int a, int b) {
		p.x = a;
		p.y = b;
	}

private:
	Point p;
	bool Alive; // Alive or Dead
};

#endif _Player_h_