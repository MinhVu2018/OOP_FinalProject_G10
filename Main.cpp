#include <iostream>
#include <conio.h>
#include <thread>
#include <stdio.h>
#include <cstdlib> // system is ambigious
#include "windows.h"
#include <Windows.h>
#include "Barrier.h"
#include "Player.h"
#include "Truck.h"
#include "Car.h"
#include "Bird.h"
#include "Dino.h"
#include "Line.h"
#include "Game.h"
#include "Traffic.h"
#include <mmsystem.h>
#include <MMSystem.h>

using namespace std;

char MOVING;
Game g;
bool IS_PAUSE = false;
bool IS_RUNNING = true;

void frame()
{
	for (int i = 2; i < 16; i++)
	{
		gotoXY(1, i);
		cout << (char)179;
		gotoXY(49, i);
		cout << (char)179;
	}

	for (int i = 1; i < 50; i++)
	{
		gotoXY(i, 1);
		cout << (char)196;
		gotoXY(i, 16);
		cout << (char)196;
	}
	gotoXY(1, 1);
	cout << (char)218;
	gotoXY(1, 16);
	cout << (char)192;
	gotoXY(49, 1);
	cout << (char)191;
	gotoXY(49, 16);
	cout << (char)217;

	gotoXY(0, 17);
	for (int i = 1; i <= g.getPlayer().getLives(); i++)
		cout << '\3' << " ";
	gotoXY(0, 18);
	cout << "Press P to pause game";
	gotoXY(0, 19);
	cout << "Press S to save game";
}

void AnimalThread()
{
	while (IS_RUNNING || g.getPlayer().getLives() == 0)
	{
		while (IS_PAUSE)
		{
			this_thread::sleep_for(0.1s);
		}
		//Sleep(1000 - g.getLevel()*300);

		for (int i = 1; i <= 20; i++)
		{
			if (g.getPlayer().getLives() == 0)
				return;
			if (IS_PAUSE)
				break;
			Sleep(100 - g.getLevel() * 30);
			if (g.getBird()->getSpeed() * i % 2 == 0)
				g.UpdatePosBird();
			if (g.getDino()->getSpeed() * i % 3 == 0)
				g.UpdatePosDino();
			if (g.getCar()->getSpeed() * i % 4 == 0)
				g.UpdatePosCar();
			if (g.getTruck()->getSpeed() * i % 5 == 0)
				g.UpdatePosTruck();

			g.UpdatePosPeople('temp');
			if (i==1)
				g.flashoff();

			if (g.getPlayer().isImpact(g.getBird()))
			{
				g.updateLives();
				system("cls");
				//PlaySound(TEXT("D:\\bird.wav"), NULL, SND_SYNC);
				birdImpact();
				Sleep(100);
				g.resetGame();
			}
			else if (g.getPlayer().isImpact(g.getCar()))
			{
				g.updateLives();
				system("cls");
				carImpact();
				Sleep(100);
				g.resetGame();
			}
			else if (g.getPlayer().isImpact(g.getTruck()))
			{
				g.updateLives();
				system("cls");
				truckImpact();
				Sleep(100);
				g.resetGame();
			}
			else if (g.getPlayer().isImpact(g.getDino()))
			{
				g.updateLives();
				system("cls");
				dinoImpact();
				Sleep(100);
				g.resetGame();
			}
			else if (g.getPlayer().isFinish())
			{
				system("cls");
				frame();
				cout << "Finish";
				Sleep(1000);
				g.levelUp();
				g.resetGame();
			}
			else if (g.getPlayer().isImpactWall())
			{
				g.updateLives();
				system("cls");
				cout << "You can not go through wall !!!" << endl;
				Sleep(1000); 
				system("cls");
				g.resetGame();
			}
		}
	}
}

int main()
{
	FixConsoleWindow();
	//setBackgroundColor(BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
	g.startGame();
	char temp;
	thread t1(&AnimalThread);
	g.getPlayer().Draw();
	while (g.getPlayer().getLives() != 0)
	{
		temp = _getch();
		if (temp == 'p')
		{
			IS_PAUSE = true;
		}
		else if (temp == 'r')
		{
			IS_PAUSE = false;
		}
		else if (temp == 's')
		{
			IS_PAUSE = true;
			g.saveGame();
			IS_PAUSE = false;
			g.drawGame();
		}
		else if (temp == (char)27)
		{
			IS_RUNNING = false;
			t1.join();
			g.exitGame();
			system("pause");
			return 0;
		}
		else g.UpdatePosPeople(temp);
	}
	t1.join();
	g.exitGame();
	system("pause");
	return 0;
}