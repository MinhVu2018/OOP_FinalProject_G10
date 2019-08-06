#ifndef _Header_h_
#define _Header_h_

#include  <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <MMSystem.h>

using namespace std;
void setBackgroundColor(int color);
void SetConsoleColour(WORD* Attributes, DWORD Colour);
void FixConsoleWindow();
void gotoXY(int x, int y);
void setcursor(bool visible, DWORD size);
void frame();
void mainScreen();
void IntroScreen();
void Menu();
void EndGame();

void birdImpact();
void dinoImpact();
void carImpact();
void truckImpact();
void title();

struct Point
{
	int x, y;
};




#endif _Header_h_