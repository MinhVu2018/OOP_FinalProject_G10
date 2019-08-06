#include "Traffic.h"

TrafficLight::TrafficLight()
{
	colour = 12;
}

void TrafficLight::change()
{
	if (colour == 12)
		colour = 10;
	else colour = 12;
}

void TrafficLight::display()
{
	for (int i = 0; i < 2; i++)
	{
		gotoXY(1, 9+3*i);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
		cout << light;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // white
	}
}

void TrafficLight::remove()
{
	gotoXY(1, 9);
	cout << blank;
	gotoXY(1, 12);
	cout << blank;
}

int TrafficLight::getColor()
{
	return colour;
}