#ifndef _Game_h_
#define _Game_h_

#include "Header.h"
#include "Truck.h"
#include "Bird.h"
#include "Car.h"
#include "Dino.h"
#include "Player.h"
#include "Traffic.h"

class Game
{
	Truck* t;
	Car* c;
	Bird* b;
	Dino *d;
	People p;
	TrafficLight tr;
public:
	Game();
	~Game();

	People getPlayer();
	Bird* getBird();
	Truck* getTruck();
	Car* getCar();
	Dino* getDino();
	TrafficLight getLight();

	void drawGame();

	void exitGame();
	void resumeGame();
	void pauseGame();
	void startGame();
	void saveGame();
	void loadGame();

	void UpdatePosPeople(char move);

	void UpdatePosBird();
	void UpdatePosTruck();
	void UpdatePosCar();
	void UpdatePosDino();
	void flashoff();

};

#endif _Game_h_