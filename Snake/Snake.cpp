#include "Snake.h"


Coord Snake::getHead()
{
	return body.front();
}

void Snake::pushHead(Coord coord)
{
	body.push_front(coord);
}

void Snake::pushTail(Coord coord)
{
	body.push_back(coord);
}

Coord Snake::getTail()
{
	return body.back();
}

void Snake::printHead()
{
	gotoxy(body.front().x, body.front().y);
	cout << HEAD;
}

void Snake::create(Coord start)
{
	pushHead(start);
	start.x++;
	pushHead(start);
}

void Snake::printBody()
{
	printHead();
	for (auto i = ++body.begin(); i != body.end(); i++)
	{
		gotoxy(i->x, i->y);
		cout << BODY;
	}
}

bool Snake::isBodyHit()
{
	Coord head = body.front();
	
	for (auto i = ++body.begin(); i != body.end(); i++)
	{
		if (head.x == i->x && head.y == i->y) {
			return true;
		}
	}

	return false;
}

void Snake::move() 
{
	gotoxy(body.front().x, body.front().y);
	cout << BODY;

	Coord nextHead = getHead();

	deleteTail();

	switch (dir)
	{
	case LEFT:
		nextHead.x--;
		break;
	case RIGHT:
		nextHead.x++;
		break;
	case UP:
		nextHead.y--;		
		break;
	case DOWN:
		nextHead.y++;
		break;
	}

	pushHead(nextHead);
}

void Snake::deleteTail()
{
	body.pop_back();
}

void Snake::clearTail()
{
	gotoxy(body.back().x, body.back().y);
	cout << " ";
}

void Snake::deleteSnake()
{
	body.clear();
}

bool Snake::isValidDir(Direction dir)
{
	switch (dir)
	{
	case LEFT:
		if (this->dir != RIGHT) { return true; }
		break;
	case RIGHT:
		if (this->dir != LEFT) { return true; }
		break;
	case UP:
		if (this->dir != DOWN) { return true; }
		break;
	case DOWN:
		if (this->dir != UP) { return true; }
		break;
	}
	return false;
}

void Snake::setDir(Direction dir)
{
	if (isValidDir(dir))
		this->dir = dir;
}
