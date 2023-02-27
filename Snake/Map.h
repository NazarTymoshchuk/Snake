#pragma once

#include <conio.h>
#include "Coord.h"
#include "Utilities.h"
#include "Symbol.h"

using namespace std;

class Map
{
private:
	const int heigth = 30;
	const int width = 50;
public:
	Coord getCenter();
	int getHeigth();
	int getWidth();
	void printFrame();
};

