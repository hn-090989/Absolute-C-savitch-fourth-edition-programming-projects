#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

const int COLUMNS = 190;
const int ROWS = 50;

void initialCondition(char world[ROWS][COLUMNS]);
void generation(char world[ROWS][COLUMNS]);
void display(char world[ROWS][COLUMNS]);

int main() {
	char world[ROWS][COLUMNS];

	initialCondition(world);
	for (int i = 1; i <= 100; i++) {
		generation(world);
		display(world);
		this_thread::sleep_for(chrono::seconds(2));this_thread::sleep_for(chrono::seconds(2));

		system("cls");
	}
	
}

void initialCondition(char world[ROWS][COLUMNS]) {
	srand(time(0));

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			world[i][j] = (rand() % 100 < 10) ? '*' : ' ';
		}
	}
}

void generation(char world[ROWS][COLUMNS]) {

	char temp[ROWS][COLUMNS];

	for (int row = 0; row < ROWS; row++) {
		for (int column = 0; column < COLUMNS; column++) {
			temp[row][column] = world[row][column];
		}
	}

	for (int j = 1; j < COLUMNS - 1; j++) {
		for (int i = 1; i < ROWS - 1; i++) {
			int neighbours = 0;

			if (temp[i - 1][j - 1] == '*') { neighbours++; }
			if (temp[i - 1][j] == '*') { neighbours++; }
			if (temp[i - 1][j + 1] == '*') { neighbours++; }
			if (temp[i][j - 1] == '*') { neighbours++; }
			if (temp[i][j + 1] == '*') { neighbours++; }
			if (temp[i + 1][j - 1] == '*') { neighbours++; }
			if (temp[i + 1][j] == '*') { neighbours++; }
			if (temp[i + 1][j + 1] == '*') { neighbours++; }// logic can be improved 

			if (world[i][j] == '*') {
				if (neighbours <= 1 || neighbours > 3) {world[i][j] = ' ';}
			}else if (world[i][j] == ' ' && neighbours == 3) {world[i][j] = '*';	}
		}
	}

	// top edge
	for (int m = 1; m < COLUMNS - 1; m++) {
		int neighbours = 0;

		if (temp[0][m - 1] == '*') { neighbours++; }
		if (temp[0][m + 1] == '*') { neighbours++; }
		if (temp[1][m - 1] == '*') { neighbours++; }
		if (temp[1][m] == '*') { neighbours++; }
		if (temp[1][m + 1] == '*') { neighbours++; }

		if (world[0][m] == '*') {
			if (neighbours <= 1 || neighbours > 3) {world[0][m] = ' ';}
		}else if (world[0][m] == ' ' && neighbours == 3) {world[0][m] = '*';}
	}

	// bottom edge
	for (int b = 1; b < COLUMNS - 1; b++) {
		int neighbours = 0;

		if (temp[ROWS-2][b-1] == '*') { neighbours++; }
		if (temp[ROWS - 2][b] == '*') { neighbours++; }
		if (temp[ROWS - 2][b + 1] == '*') { neighbours++; }
		if (temp[ROWS - 1][b - 1] == '*') { neighbours++; }
		if (temp[ROWS - 1][b + 1] == '*') { neighbours++; }

		if (world[ROWS-1][b] == '*') {
			if (neighbours <= 1 || neighbours > 3) {world[ROWS-1][b] = ' ';}
		}else if (world[ROWS-1][b] == ' ' && neighbours == 3) {world[ROWS-1][b] = '*';}
	}

	// left edge
	for (int c = 1; c < ROWS - 1; c++) {
		int neighbours = 0;
		if (temp[c - 1][0] == '*') { neighbours++; }
		if (temp[c + 1][0] == '*') { neighbours++; }
		if (temp[c - 1][1] == '*') { neighbours++; }
		if (temp[c][1] == '*') { neighbours++; }
		if (temp[c + 1][1] == '*') { neighbours++; }

		if (world[c][0] == '*') {
			if (neighbours <= 1 || neighbours > 3) {world[c][0] = ' ';}
		}else if (world[c][0] == ' ' && neighbours == 3) {world[c][0] = '*';}
	}

	// right edge
	for (int h = 1; h < ROWS - 1; h++) {
		int neighbours = 0;
		if (temp[h - 1][COLUMNS - 1] == '*') { neighbours++; }
		if (temp[h + 1][COLUMNS - 1] == '*') { neighbours++; }
		if (temp[h - 1][COLUMNS - 2] == '*') { neighbours++; }
		if (temp[h][COLUMNS - 2] == '*') { neighbours++; }
		if (temp[h + 1][COLUMNS - 2] == '*') { neighbours++; }

		if (world[h][COLUMNS - 1] == '*') {
			if (neighbours <= 1 || neighbours > 3) {world[h][COLUMNS - 1] = ' ';}
		}else if (world[h][COLUMNS - 1] == ' ' && neighbours == 3) {world[h][COLUMNS - 1] = '*';}
	}

	// corners
	int neighbours = 0;
	if (temp[0][1] == '*') { neighbours++; }
	if (temp[1][0] == '*') { neighbours++; }
	if (world[0][0] == '*') {
		if (neighbours <= 1) {world[0][0] = ' ';}
	}else if (neighbours == 3) { world[0][0] = '*'; }


	neighbours = 0;
	if (temp[0][COLUMNS - 2] == '*') { neighbours++; }
	if (temp[1][COLUMNS - 1] == '*') { neighbours++; }
	if (world[0][COLUMNS - 1] == '*') {
		if (neighbours <= 1) {world[0][COLUMNS - 1] = ' ';}
	}else if (neighbours == 3) { world[0][COLUMNS - 1] = '*'; }

	neighbours = 0;
	if (temp[ROWS - 2][0] == '*') { neighbours++; }
	if (temp[ROWS - 1][1] == '*') { neighbours++; }
	if (world[ROWS - 1][0] == '*') {
		if (neighbours <= 1) {world[ROWS - 1][0] = ' ';}
	}else if (neighbours == 3) { world[ROWS - 1][0] = '*'; }

	neighbours = 0;
	if (temp[ROWS - 1][COLUMNS - 2] == '*') { neighbours++; }
	if (temp[ROWS - 2][COLUMNS - 1] == '*') { neighbours++; }
	if (world[ROWS - 1][COLUMNS - 1] == '*') {
		if (neighbours <= 1) {world[ROWS - 1][COLUMNS - 1] = ' ';}
	}else if (neighbours == 3) { world[ROWS-1][COLUMNS - 1] = '*'; }
}

void display(char world[ROWS][COLUMNS]) {

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			cout << world[i][j];
		}
		cout << endl;
	}
}
