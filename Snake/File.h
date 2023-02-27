#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class File
{
private:
	int record;
public:
	File() { record = 0; }
	void writeRecord(int score);
	int readRecord();
};

