#pragma once

#include <List>
#include "Coord.h"
#include "Direction.h"
#include "Utilities.h"
#include "Symbol.h"

using namespace std;

class Snake
{
private:
	list<Coord> body;
	Direction dir;
public:
	Snake() { dir = RIGHT; }
	Coord getHead();
	Coord getTail();
	void pushHead(Coord coord);
	void pushTail(Coord coord);
	void create(Coord start);
	void printBody();
	void deleteTail();
	void clearTail();
	void printHead();
	bool isBodyHit();
	void setDir(Direction dir);
	bool isValidDir(Direction dir);
	void move();
	void deleteSnake();
};

