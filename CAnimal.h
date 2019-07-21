#pragma once
#include <iostream>
using namespace std;
#include <Windows.h>
#pragma comment(lib, "winmm.lib")

class CAnimal
{
	
public:
	CAnimal();
	~CAnimal();
	virtual void move(int y, int speed) = 0;
	virtual void tell() = 0;

};

void gotoXY(int x, int y);
