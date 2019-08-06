#include "windows.h"
#include <Windows.h>
#include "Player.h"
#include "Barrier.h"
#include "Line.h"
#include <conio.h>
#include <thread>
#include "Traffic.h"

using namespace std;

void SetConsoleColour(WORD* Attributes, DWORD Colour)
{
	CONSOLE_SCREEN_BUFFER_INFO Info;
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdout, &Info);
	*Attributes = Info.wAttributes;
	SetConsoleTextAttribute(hStdout, Colour);
}	// reset colour

void setBackgroundColor(int color)
{
	// lấy vị trí hiện tại của dấu nháy 
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screen_buffer_info);
	COORD currentPos = { screen_buffer_info.dwCursorPosition.X,screen_buffer_info.dwCursorPosition.Y };

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 80; j++)
			std::cout << " ";
	// thiết lập lại vị trí của dấu nháy
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), currentPos);
}

void FixConsoleWindow()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_WINDOWED_MODE, 0);
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);

	MoveWindow(consoleWindow, 200, 200, 550, 500, TRUE);
	SetWindowLong(consoleWindow, GWL_STYLE, style);

	ShowScrollBar(consoleWindow, SB_BOTH, FALSE);
}

void setcursor(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
	HWND consoleWindow = GetConsoleWindow();
	if (size == 0)
		size = 20;
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(consoleWindow, &lpCursor);
}

void gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//  <Impact>
void dinoImpact()
{
	char** a = new char* [12];

	a[0] = new char[101];
	char temp[38] = "                       _. - ~ ~ ~ - .";
	a[0] = temp;

	a[1] = new char[101];
	char temp1[41] = "   ..       __.    .-~               ~-.";
	a[1] = temp1;

	a[2] = new char[101];
	char temp2[43] = "   ((\\     /   `}.~                     `.";
	a[2] = temp2;

	a[3] = new char[101];
	char temp3[45] = "    \\\\\\   {     }               /     \    \\ ";
	a[3] = temp3;

	a[4] = new char[101];
	char temp4[46] = "(\\   \\\\~~^      }              |       }   \\ ";
	a[4] = temp4;

	a[5] = new char[101];
	char temp5[47] = " \\`.-~ -@~      }  ,-.         |       )    \\ ";
	a[5] = temp5;

	a[6] = new char[101];
	char temp6[49] = " (___     ) _}   (    :        |    / /      `. ";
	a[6] = temp6;

	a[7] = new char[101];
	char temp7[51] = "  `----._-~.     _\\ \\ |_       \\   / /- _      `. ";
	a[7] = temp7;

	a[8] = new char[101];
	char temp8[56] = "         ~~----~~  \\ \\| ~~--~~~(  + /     ~-.     ~- _ ";
	a[8] = temp8;

	a[9] = new char[101];
	char temp9[61] = "                   /  /         \\  \\          ~- . _ _~_-_. ";
	a[9] = temp9;

	a[10] = new char[101];
	char temp10[39] = "                __/  /          _\\  ) ";
	a[10] = temp10;

	a[11] = new char[101];
	char temp11[38] = "              .<___.'         .<___/ ";
	a[11] = temp11;

	for (int j = 20; j >= 0; j--)
	{
		gotoXY(j, 1);
		for (int i = 0; i < 12; i++)
		{
			cout << a[i];
			gotoXY(j, i + 2);
		}
		Sleep(100);
		system("cls");
	}
	delete[] a;
}

void carImpact()
{
	char** a = new char* [6];
	a[0] = new char[18];
	char temp[18] = "       _______";
	a[0] = temp;

	a[1] = new char[18];
	char temp1[18] = "      //  ||\\ \\";
	a[1] = temp1;

	a[2] = new char[21];
	char temp2[21] = "_____//___||_\\ \\___";
	a[2] = temp2;

	a[3] = new char[22];
	char temp3[22] = ")  _          _    \\";
	a[3] = temp3;

	a[4] = new char[22];
	char temp4[22] = "|_/ \\________/ \\___ |";
	a[4] = temp4;

	a[5] = new char[19];
	char temp5[19] = "  \\_/        \\_/";
	a[5] = temp5;
	for (int j = 0; j < 20; j++)
	{
		gotoXY(j, 1);
		for (int i = 0; i < 6; i++)
		{
			cout << a[i];
			gotoXY(j, i + 2);
		}
		Sleep(100);
		system("cls");
	}
	delete[] a;
}

void truckImpact()
{
	char** a = new char* [7];

	a[0] = new char[25];
	char temp[25] = " ======================\\";
	a[0] = temp;

	a[1] = new char[32];
	char temp1[32] = " |---------------||@   \\\\   ___";
	a[1] = temp1;

	a[2] = new char[34];
	char temp2[34] = " |____|__________|||_ /_\\\\_|___|_";
	a[2] = temp2;

	a[3] = new char[35];
	char temp3[35] = "<|  ___\\         ||      | ____  |";
	a[3] = temp3;

	a[4] = new char[35];
	char temp4[35] = "<| /    |________||______|/    | |";
	a[4] = temp4;

	a[5] = new char[36];
	char temp5[36] = "||/  O  |________________/  O  |_||";
	a[5] = temp5;

	a[6] = new char[36];
	char temp6[36] = "   \\___/                  \\___/";
	a[6] = temp6;

	for (int j = 0; j < 20; j++)
	{
		gotoXY(j, 1);
		for (int i = 0; i < 7; i++)
		{
			cout << a[i];
			gotoXY(j, i + 2);
		}
		Sleep(100);
		system("cls");
	}
	delete[]a;
}

void birdImpact()
{
	char** a = new char* [17];

	a[0] = new char[26];
	char temp[26] = "                 /|_";
	a[0] = temp;

	a[1] = new char[25];
	char temp1[25] = "                /   |_";
	a[1] = temp1;

	a[2] = new char[24];
	char temp2[24] = "               /     /";
	a[2] = temp2;

	a[3] = new char[24];
	char temp3[24] = "              (      >";
	a[3] = temp3;

	a[4] = new char[22];
	char temp4[22] = "             /      /";
	a[4] = temp4;

	a[5] = new char[21];
	char temp5[21] = "            /     /";
	a[5] = temp5;

	a[6] = new char[26];
	char temp6[26] = "           /      /";
	a[6] = temp6;

	a[7] = new char[25];
	char temp7[25] = "      ____/      \\_____";
	a[7] = temp7;

	a[8] = new char[24];
	char temp8[24] = "     /_'_  Bird       |";
	a[8] = temp8;

	a[9] = new char[24];
	char temp9[24] = "        /      /-\\   /";
	a[9] = temp9;

	a[10] = new char[22];
	char temp10[22] = "       /     /    \\-/";
	a[10] = temp10;

	a[11] = new char[15];
	char temp11[15] = "      /      /";
	a[11] = temp11;

	a[12] = new char[14];
	char temp12[14] = "     /     /";
	a[12] = temp12;

	a[13] = new char[13];
	char temp13[13] = "    (     >";
	a[13] = temp13;

	a[14] = new char[12];
	char temp14[12] = "   /    _|";
	a[14] = temp14;

	a[15] = new char[12];
	char temp15[12] = "  /  __/";
	a[15] = temp15;

	a[16] = new char[12];
	char temp16[12] = " /_/";
	a[16] = temp16;

	for (int j = 20; j >= 0; j--)
	{
		gotoXY(j, 1);
		for (int i = 0; i < 17; i++)
		{
			cout << a[i];
			gotoXY(j, i + 2);
		}
		Sleep(100);
		system("cls");
	}

	delete[] a;
}
//  </Impact>
void title()
{
	char** a = new char* [15];

	a[0] = new char[12];
	char temp[12] = "    _____";
	a[0] = temp;

	a[1] = new char[36];
	char temp1[36] = "   / ___ |  __ _  ____ ___    ____";
	a[1] = temp1;

	a[2] = new char[36];
	char temp2[36] = "  | |   _  / _' || '_ ` _ \\  / __ \\";
	a[2] = temp2;

	a[3] = new char[36];
	char temp3[36] = "  | |__| || (_| || | | | | ||  ___/";
	a[3] = temp3;

	a[4] = new char[36];
	char temp4[36] = "   \\_____| \\__,_||_| |_| |_| \\____|";
	a[4] = temp4;

	a[5] = new char[8];
	char temp5[8] = "  _____";
	a[5] = temp5;

	a[6] = new char[39];
	char temp6[39] = " / ___ | _ __  ___   ___  ___  __  __ ";
	a[6] = temp6;

	a[7] = new char[39];
	char temp7[39] = "| |     | '__|/ _ \\ / __|/ __||  ||  |";
	a[7] = temp7;

	a[8] = new char[38];
	char temp8[38] = "| |____ | |  | |_| |\\__ \\\\__ \\ \\ \\/ /";
	a[8] = temp8;

	a[9] = new char[38];
	char temp9[38] = " \\_____||_|   \\___/ |__ /|__ /  |__| ";
	a[9] = temp9;

	a[10] = new char[34];
	char temp10[34] = "       _____                   _";
	a[10] = temp10;

	a[11] = new char[34];
	char temp11[34] = "      | __  \\ ___    __ _   __| |";
	a[11] = temp11;

	a[12] = new char[34];
	char temp12[34] = "      |     // _ \\  / _' | / _' |";
	a[12] = temp12;

	a[13] = new char[34];
	char temp13[34] = "      | |\\ \\| |_| || (_| || (_| |";
	a[13] = temp13;

	a[14] = new char[34];
	char temp14[34] = "      |_| \\_\\\\___/  \\__,_| \\__,_|";
	a[14] = temp14;

	for (int j = 0; j < 10; j++)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), j);
		for (int i = 0; i < 15; i++)
		{
			gotoXY(8, i + 1);
			cout << a[i];
		}
		Sleep(200);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	Sleep(2000);

	delete[] a;
}

void IntroScreen()
{
	gotoXY(0, 2);
	cout << "  Project Oject-Oriented-Programming" << endl;
	cout << "---------------------------------------" << endl;
	cout << "|	  18CLC2 - Group 10:	      |" << endl;
	cout << "| 18127155 - Vu Cong Minh - Leader    |" << endl;
	cout << "| 18127042 - Le Phuong Dao - Secretary|" << endl;
	cout << "| 18127056 - Pham Xuan Tu - Member    |" << endl;
	cout << "| 18127260 - Tu Kien Hoa - Member     |" << endl;
	cout << "---------------------------------------" << endl;
}

void Menu()
{
	system("cls");
	gotoXY(10, 2);
	cout << "Game Crossy Road" << endl;

	cout << "  Menu: " << endl;
	cout << "  1.New game " << endl;
	cout << "  2.Load game " << endl;
	cout << "  3.Settings" << endl;
	cout << "  4.Exit" << endl;
}

void EndGame()
{
	cout << "  Thank you for playing game" << endl;
	IntroScreen();
}