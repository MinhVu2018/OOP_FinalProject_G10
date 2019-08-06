#pragma once
#include "CAnimal.h"
class CBird :
	public CAnimal
{
	const char bird[4] = { (char)223, (char)254, (char)223,'\0' };
	const char blank[4] = { 32, 32, 32,'\0' };
public:
	CBird();
	~CBird();
	void move(int y, int speed);
	void tell();
	void draw();
	void destroy();

};

