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
	Game()
	{
		t = new Truck[5];
		c = new Car[5];
		b = new Bird[5];
		d = new Dino[5];
		for (int i = 0; i < 5; i++)
		{
			Bird temp2(2 + 8 * i, 2);
			b[i] = temp2;
			Truck temp(2 + 8 * i, 9);
			t[i] = temp;
			Car temp1(2 + 8 * i, 12);
			c[i] = temp1;
			Dino temp3(2 + 8 * i, 5);
			d[i] = temp3;
		}
	}
	~Game()
	{
		delete[]t;
		delete[]c;
		delete[]b;
		delete[]d;
	}

	People getPlayer()
	{
		return p;
	}
	Bird* getBird()
	{
		return b;
	}
	Truck* getTruck()
	{
		return t;
	}
	Car* getCar()
	{
		return c;
	}
	Dino* getDino()
	{
		return d;
	}
	TrafficLight getLight()
	{
		return tr;
	}

	void drawGame()
	{
		system("cls");
		p.Draw();
		std::cout << "   ---> You are here";
		Sleep(2000);
		system("cls");
		frame();
		//Draw();
		//p.Draw();
	}

	void exitGame()
	{
		system("cls");
		EndGame();
	}
	void resumeGame()
	{
		for (int i = 3; i >= 0; i--)
		{
			std::cout << i;
			Sleep(300);
			std::cout << '\b';
		}
	}
	void pauseGame()
	{
		system("pause");
	}
	void startGame()
	{
		Menu();
		int choice;
		std::cout << " Enter your choice[1/2/3]: "; std::cin >> choice;
		if (choice == 1)
			drawGame();
		else if (choice == 2) {
			system("cls");
			loadGame();
		}
		else if (choice == 4)
			exitGame();
	}
	void saveGame() {
		//t c b d p
		ofstream fout("gamesave.bin",ios::binary);
		int a, f;
		t->savePos(a, f);
		//fout << a << " " << f << endl;
		fout.write((char*)&a, sizeof(int));
		fout.write((char*)&f, sizeof(int));
		c->savePos(a, f);
		//fout << a << " " << f << endl;
		fout.write((char*)&a, sizeof(int));
		fout.write((char*)&f, sizeof(int));
		b->savePos(a, f);
		//fout << a << " " << f << endl;
		fout.write((char*)&a, sizeof(int));
		fout.write((char*)&f, sizeof(int));
		d->savePos(a, f);
		//fout << a << " " << f << endl;
		fout.write((char*)&a, sizeof(int));
		fout.write((char*)&f, sizeof(int));
		p.savePos(a, f);
		//fout << a << " " << f << endl;
		fout.write((char*)&a, sizeof(int));
		fout.write((char*)&f, sizeof(int));
		fout.close();
		gotoXY(50, 20);
		cout << "Game saved.";
		Sleep(1000);
		gotoXY(50, 20);
		cout << "           ";
	}
	void loadGame() {
		ifstream fin("gamesave.bin",ios::binary);
		if (!fin.is_open())
			cout << "Cannot load data." << endl;
		int a, f;
		//fin >> a >> f;
		fin.read((char*)&a, sizeof(int));
		fin.read((char*)&f, sizeof(int));
		t->loadPos(a, f);
		//fin >> a >> f;
		fin.read((char*)&a, sizeof(int));
		fin.read((char*)&f, sizeof(int));
		c->loadPos(a, f);
		//fin >> a >> f;
		fin.read((char*)&a, sizeof(int));
		fin.read((char*)&f, sizeof(int));
		b->loadPos(a, f);
		//fin >> a >> f;
		fin.read((char*)&a, sizeof(int));
		fin.read((char*)&f, sizeof(int));
		d->loadPos(a, f);
		//fin >> a >> f;
		fin.read((char*)&a, sizeof(int));
		fin.read((char*)&f, sizeof(int));
		p.loadPos(a, f);
		fin.close();

		frame();
		t->Draw();
		c->Draw();
		b->Draw();
		d->Draw();
		p.Draw();

	}

	void UpdatePosPeople(char move)
	{
		p.Draw();
		int v = move;
		if (v == 119)
		{
			p.Up();
		}
		else if (v == 115)
		{
			p.Down();
		}
		else if (v == 97)
		{
			p.Left();
		}
		else if (v == 100)
		{
			p.Right();
		}
		else p.Draw();
	}

	void UpdatePosBird()
	{
		for (int i=0; i<5; i++)
			b[i].Move(1,1);
	}	
	void UpdatePosTruck()
	{
		for (int i = 0; i < 5; i++)
			t[i].Move(1, 1);
	}
	void UpdatePosCar()
	{
		for (int i = 0; i < 5; i++)
			c[i].Move(1, 1);
	}
	void UpdatePosDino()
	{
		for (int i = 0; i < 5; i++)
			d[i].Move(1, 1);
	}
	void flashoff()
	{
		tr.remove();
		tr.change();
		tr.display();
	}

};

#endif _Game_h_