#include "Game.h"


void Game::initialize()
{
	map.printFrame();
	snake.create(map.getCenter());
	snake.printBody();
}

bool Game::isCoinHit()
{
	Coord head = snake.getHead();
	return head.x == coin.x && head.y == coin.y;
}

void Game::moveSnake()
{
	snake.clearTail();
	snake.move();
	snake.printHead();
}

void Game::run()
{

	if (startGame()) {

		initialize();
		prepareConsole();
		printCoin();

		printRecord();
		score = 0;

		currentDirection = RIGHT;
		auto start = clock();

		printScore();

		do
		{
			
			if (isCoinHit())
			{
				snake.pushTail(snake.getTail());
				printCoin();

				score++;
				printScore();
			}

			changeDirection();

			if (clock() - start > delay)
			{
				snake.setDir(currentDirection);
				moveSnake();
				start = clock();
			}
		} while (!isGameOver());

		record.writeRecord(score);

	}
}

void Game::changeDirection()
{
	if (_kbhit())
	{
		if (_getch() == 224) 
		{
			switch (_getch())
			{
			case 72:
				currentDirection = UP; break;
			case 75:
				currentDirection = LEFT; break;
			case 77:
				currentDirection = RIGHT; break;
			case 80:
				currentDirection = DOWN; break;
			}
		}
	}
}

void Game::chooseLevel()
{
	cout << "Choose level\n\n[1] - Easy\n[2] - Midle\n[3] - Hard\n\nEnter - ";

	int choose;
	cin >> choose;

	cout << endl << endl;

	if (choose == 1)
	{
		delay = EASY;
	}
	else if (choose == 2)
	{
		delay = MIDLE;
	}
	else if (choose == 3)
	{
		delay = HARD;
	}
}

bool Game::startGame()
{
	chooseLevel();

	cout << "Press 'Y' if you want to play" << endl;
	cout << "Press 'N' if you want to get out" << endl;

	char s;
	cin >> s;

	if (s == 'Y' || s == 'y') 
		return true;
	
	
	return false;
}

void Game::prepareConsole()
{
	setConsoleSize(720, 760);
	ShowConsoleCursor(false);
}

bool Game::isGameOver()
{
	if (isWentBeyond()) {

		gotoxy(map.getCenter().x - 5, map.getCenter().y);
		cout << "GAME OVER!!!" << endl;

		return true;
	}

	if (snake.isBodyHit()) {

		gotoxy(map.getCenter().x - 5, map.getCenter().y);
		cout << "GAME OVER!!!" << endl;

		return true;
	}

	
	return false;
}

bool Game::isWentBeyond()
{
	if (snake.getHead().x > map.getWidth() || snake.getHead().x < 1 || snake.getHead().y > map.getHeigth() || snake.getHead().y < 1)
		return true;

	return false;
}

void Game::generateCoin()
{
	srand(unsigned(time(NULL)));

	coin.x = 1 + rand() % map.getWidth();
	coin.y = 1 + rand() % map.getHeigth();
}

void Game::printCoin()
{
	generateCoin();

	gotoxy(coin.x, coin.y);
	cout << COIN;
}

void Game::start()
{
	do
	{
		system("cls");

		snake.deleteSnake();

		run();

	} while (restart());
}

bool Game::restart()
{
	gotoxy(10, 18);
	cout << "If you want to continue press 'Y'";
	gotoxy(10, 19);
	cout << "If you want to leave press 'N'";
	gotoxy(10, 20);
	cout << "Enter - ";

	char s;
	cin >> s;

	if (s == 'y' || s == 'Y')
		return true;

	return false;
}

void Game::printScore()
{
	gotoxy(map.getWidth() + 5, 4);
	cout << "Score: " << score;
}

void Game::printRecord()
{
	gotoxy(map.getWidth() + 5, 2);
	cout << "Record: " << record.readRecord();
}

