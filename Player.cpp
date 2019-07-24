#include"Player.h"

People::People()
{
	p.x = 25;
	p.y = 15;
	Alive = 1;
};

void People::Draw() {
	gotoXY(p.x, p.y);
	std::cout << "Y";
}

void People::Destroy() {
	gotoXY(p.x, p.y);
	std::cout << " ";
}

//Move
void People::Up() {
	Destroy();
	p.y--;
	Draw();
}

void People::Down() {
	Destroy();
	p.y++;
	Draw();
}

void People::Left() {
	Destroy();
	p.x--;
	Draw();
}

void People::Right() {
	Destroy();
	p.x++;
	Draw();
}

//Impact
bool People::isImpact(Car *c) {
	for (int i = 0; i < 4; i++)
		if (c[i].Impact(p))
			return true;
	return false;
}

bool People::isImpact(Truck *t) {
	for (int i = 0; i < 4; i++)
		if (t[i].Impact(p))
			return true;
	return false;
}

bool People::isImpact(Bird *b)
{
	for (int i = 0; i < 4; i++)
		if (b[i].Impact(p))
			return true;
	return false;
}

bool People::isImpact(Dino* d)
{
	for (int i = 0; i < 4; i++)
		if (d[i].Impact(p))
			return true;
	return false;
}

//Status
bool People::isFinish()
{
	if (p.y == 1)
		return true;
	return false;
}
bool People::isDead()
{
	if (p.x == 1 || p.x == 49 || p.y == 16)
		Alive = false;
	return !Alive;
}

//Save
void People::savePos(int& a, int& b) {
	a = p.x;
	b = p.y;
}

void People::loadPos(int a, int b) {
	p.x = a;
	p.y = b;
}