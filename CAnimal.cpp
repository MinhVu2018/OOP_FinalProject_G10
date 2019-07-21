#include "CAnimal.h"



CAnimal::CAnimal()
{
}


CAnimal::~CAnimal()
{
}

void gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
