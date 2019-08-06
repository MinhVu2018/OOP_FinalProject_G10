#ifndef _Line_h_
#define _Line_h_
#include "Header.h"

class Line1
{
public:
	void Draw()
	{
		for (int i = 0; i < 70; i++)
			std::cout << l;
	}
private:
	char l = (char)196;
};

class Line2
{
public:
	void Draw(int s, int e)
	{
		for (int i = s; i <= e; i++)
		{
			gotoXY(2, i);
			std::cout << l;
			gotoXY(71, i);
			std::cout << l;
		}
	}
private:
	char l = (char)179;
};

#endif _Line_h_