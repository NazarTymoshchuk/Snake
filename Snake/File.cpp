#include "File.h"

void File::writeRecord(int score)
{
	if (score > record) {
		ofstream ofs("Record.txt", ios_base::out);

		record = score;
		ofs << score;

		ofs.close();
	}
}

int File::readRecord()
{
	ifstream ifs("Record.txt", ios_base::in);

	ifs >> record;

	ifs.close();

	return record;
}
