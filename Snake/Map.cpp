#include "Map.h"


void Map::printFrame()
{
	system("cls");

	cout << TOPLEFTBORDER;
	for (size_t i = 0; i < width; i++)
	{
		cout << HORIZONTALBORDER;	
	}
	cout << TOPRIGHTBORDER << endl;


	for (size_t i = 0; i < heigth; i++)
	{
		cout << VERTICALBORDER << endl;
	}

	for (size_t i = 0; i < heigth; i++)
	{
		gotoxy(width + 1, i + 1);
		cout << VERTICALBORDER << endl;
	}


	cout << BOTTOMLEFTBORDER;
	for (size_t i = 0; i < width; i++)
	{
		cout << HORIZONTALBORDER;
	}
	cout << BOTTOMRIGHTBORDER << endl;
}

Coord Map::getCenter()
{
	return {width/2, heigth/2};
}

int Map::getHeigth()
{
	return heigth;
}

int Map::getWidth()
{
	return width;
}
