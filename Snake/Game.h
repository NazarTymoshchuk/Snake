#pragma once

#include <ctime>
#include "Map.h"
#include "Snake.h"
#include "Level.h"
#include "File.h"

class Game
{
	Map map;
	Snake snake;
	Coord coin;
	int delay;
	int score;
	Direction currentDirection;
	File record;
public:
	void initialize();
	void moveSnake();
	bool isCoinHit();
	void prepareConsole();
	void run();
	void changeDirection();
	void chooseLevel();
	bool startGame();
	bool isGameOver();
	bool isWentBeyond();
	void generateCoin();
	void printCoin();
	void start();
	bool restart();
	void printScore();
	void printRecord();
};

