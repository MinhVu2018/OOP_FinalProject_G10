#pragma once
#include "CAnimal.h"
class CDino :
	public CAnimal
{
	const char dino1[4] = { (char)255,(char)220,(char)219, '\0' };
	const char dino2[3] = { (char)223, (char)223, '\0' };
	const char blank[4] = { 32,32,32,'\0' };
public:
	CDino();
	~CDino();
	void move(int y, int speed);
	void tell();
	void draw(int x, int y);
	void destroy(int x, int y);
};

