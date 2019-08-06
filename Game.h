#ifndef _Game_h_
#define _Game_h_
#include "Header.h"
#include "Truck.h"
#include "Bird.h"
#include "Car.h"
#include "Dino.h"
#include "Player.h"
#include "Traffic.h"
#include <stdlib.h>  // exit func
#include <conio.h>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
extern bool IS_RUNNING;
class Game
{
	Truck* t;
	Car* c;
	Bird* b;
	Dino* d;
	People p;
	TrafficLight tr;
	int level = 0;
	int n;		//number of animals in a line
public:
	Game()
	{
		n = 5;
		t = new Truck[n];
		c = new Car[n];
		b = new Bird[n];
		d = new Dino[n];
		for (int i = 0; i < n; i++)
		{
			Bird temp2(2 + 9 * i, 2);
			b[i] = temp2;
			Dino temp3(2 + 9 * i, 5);
			d[i] = temp3;
			Car temp1(2 + 9 * i, 9);
			c[i] = temp1;
			Truck temp(2 + 9 * i, 12);
			t[i] = temp;
		}
	}
	~Game()
	{
		delete[]t;
		delete[]c;
		delete[]b;
		delete[]d;
	}

	int getLevel()
	{
		return level;
	}
	void levelUp()
	{
		if (level < 3)
			level++;
	}
	void updateLives()
	{
		p.getLives() -= 1;
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

	Animal** getAnimal()
	{
		Animal** a = new Animal * [n * 2];
		for (int i = 0; i < n; i++)
		{
			Animal* tempBird = &b[i];
			a[i] = tempBird;
		}
		for (int i = 0; i < n; i++)
		{
			Animal* tempDino = &d[i];
			a[i + n] = tempDino;
		}
		return a;
	}

	Vehicle** getVehicle()
	{
		Vehicle** a = new Vehicle * [n * 2];
		for (int i = 0; i < n; i++)
		{
			Vehicle* tempCar = &c[i];
			a[i] = tempCar;
		}
		for (int i = 0; i < n; i++)
		{
			Vehicle* tempTruck = &t[i];
			a[i + n] = tempTruck;
		}
		return a;
	}

	void drawGame()
	{
		system("cls");
		p.Draw();
		cout << "   ---> You are here";
		Sleep(2000);
		system("cls");
		frame();
	}
	void SettingGame()
	{
		system("cls");
		cout << "<SETTINGS>" << endl;
		cout << "Lives: "; cin >> p.getLives();
		cout << "How many barrier in a line: "; cin >> n;
		cout << "Level[0-4]:"; cin >> level;
		drawGame();
	}
	void exitGame()
	{
		IS_RUNNING = false;
		system("cls");
		EndGame();
	}
	void resumeGame()
	{
		for (int i = 3; i >= 0; i--)
		{
			std::cout << i;
			Sleep(300);
			cout << "haha";
			std::cout << '\b';
		}
	}
	void startGame()
	{
		//title();
		Menu();
		int choice;
		std::cout << " Enter your choice[1/2/3]: "; std::cin >> choice;
		if (choice == 1)
			drawGame();
		else if (choice == 2)
			loadGame();
		else if (choice == 3)
			SettingGame();
		else if (choice == 4)
			exit(EXIT_FAILURE);
	}
	void saveGame()
	{
		system("cls");
		system("cls");
		string name, dir;
		cin.ignore();
		cout << "File name: ";
		getline(cin, name);

		cout << "Directory: ";
		getline(cin, dir);

		string path;
		path.append(dir);
		path.append("\\");
		path.append(name);
		ofstream fout(path, ios::binary);
		int a, f;
		t->savePos(a, f);
		//fout << a << " " << f << endl;
		fout.write((char*)& a, sizeof(int));
		fout.write((char*)& f, sizeof(int));
		c->savePos(a, f);
		//fout << a << " " << f << endl;
		fout.write((char*)& a, sizeof(int));
		fout.write((char*)& f, sizeof(int));
		b->savePos(a, f);
		//fout << a << " " << f << endl;
		fout.write((char*)& a, sizeof(int));
		fout.write((char*)& f, sizeof(int));
		d->savePos(a, f);
		//fout << a << " " << f << endl;
		fout.write((char*)& a, sizeof(int));
		fout.write((char*)& f, sizeof(int));
		p.savePos(a, f);
		//fout << a << " " << f << endl;
		fout.write((char*)& a, sizeof(int));
		fout.write((char*)& f, sizeof(int));
		fout.close();
		cout << "\n Game saved.";
		Sleep(1000);
	}
	void loadGame()
	{
		system("cls");
		cin.ignore();
		string path;
		cout << "Path: ";
		getline(cin, path);
		ifstream fin(path, ios::binary);
		if (!fin.is_open())
			cout << "Cannot load data." << endl;
		int a, f;
		//fin >> a >> f;
		fin.read((char*)& a, sizeof(int));
		fin.read((char*)& f, sizeof(int));
		t->loadPos(a, f);
		//fin >> a >> f;
		fin.read((char*)& a, sizeof(int));
		fin.read((char*)& f, sizeof(int));
		c->loadPos(a, f);
		//fin >> a >> f;
		fin.read((char*)& a, sizeof(int));
		fin.read((char*)& f, sizeof(int));
		b->loadPos(a, f);
		//fin >> a >> f;
		fin.read((char*)& a, sizeof(int));
		fin.read((char*)& f, sizeof(int));
		d->loadPos(a, f);
		//fin >> a >> f;
		fin.read((char*)& a, sizeof(int));
		fin.read((char*)& f, sizeof(int));
		p.loadPos(a, f);
		fin.close();
		system("cls");
		frame();
		t->Draw();
		c->Draw();
		b->Draw();
		d->Draw();
		p.Draw();
	}
	void resetGame()
	{
		if (p.getLives() != 0)
		{
			p.Again();
			drawGame();
		}
		else cout << "You don't have enough lives to countinue.\nPlease press 0 to exit.";
	}

	void UpdatePosPeople(char move)
	{
		int v = int(move);
		if (v == 72)
		{
			p.Up();
		}
		else if (v == 80)
		{
			p.Down();
		}
		else if (v == 75)
		{
			p.Left();
		}
		else if (v == 77)
		{
			p.Right();
		}
		else p.Draw();
	}
	void UpdatePosBird()
	{
		for (int i = 0; i < n; i++)
		{
			b[i].Move(1, 1);
		}
	}	
	void UpdatePosTruck()
	{
		for (int i = 0; i < n; i++)	
		{
			if (tr.getColor() == 10)
				t[i].Move(0, 1);
			else t[i].Move(0, 0);
		}	
	}
	void UpdatePosCar()
	{
		for (int i = 0; i < n; i++)	
		{
			if (tr.getColor() == 10)
				c[i].Move(1, 1);
			else c[i].Move(1, 0);
		}
	}
	void UpdatePosDino()
	{
		for (int i = 0; i < n; i++)	
		{
			d[i].Move(0, 1);
		}
	}

	void flashoff()
	{
		tr.remove();
		tr.change();
		tr.display();
	}
};

#endif _Game_h_