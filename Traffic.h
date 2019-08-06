#ifndef _Traffic_h_
#define _Traffic_h_

#include "Header.h"
#include <windows.h>
class TrafficLight
{
public:
	TrafficLight();

	void change();

	void display();

	void remove();

	int getColor();
private:
	int colour; // 4-red 2-green C-lightred A-light green
	char light = (char)219;
	char blank = (char)179;
};

#endif _Traffic_h