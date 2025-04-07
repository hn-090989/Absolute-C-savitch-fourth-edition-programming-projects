#include <iostream>
using namespace std;

void playerO(char a[]);
void playerX(char a[]);
void displayBoard(char a[]);
bool win(char a[], char letter);


int main() {
	char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8','9'};
	int i = 0;
	while(true) {
		
		displayBoard(board);
		playerX(board);
		cout << endl;
		i++;
		if (win(board, 'X')) {
			system("cls");
			displayBoard(board);
			cout << "Player X wins !!!! " << endl;
			break;
		}
		if (i >= 9)break;
		system("cls");

		displayBoard(board);
		playerO(board);
		cout << endl;
		i++;
		if (win(board, 'O')) {
			system("cls");
			displayBoard(board);
			cout << "Player O wins !!!! " << endl;
			break;
		}
		if (i >= 9)break;

		system("cls");

	}
	if ((win(board, 'O') || win(board, 'X')) == false) {
		system("cls");
		displayBoard(board);
		cout << "Draw !!!!" << endl;
	}
	return 0;

}
void playerX(char a[]) {
	int position; 
	cout << "Player X \n>> ";
	cin >> position; 

	while (true) {
		if (a[position - 1] != 'X' && a[position - 1] != 'O' && (position == 1 || position == 2 || position == 3 || position == 4 || position == 5 || position == 6 || position == 7 || position == 8 || position == 9)) {
			break;
		}
		else {
			cout << "You cannot place your mark at there. Try again.";
			cin >> position;
		}
	}

	a[position - 1] = 'X';
}
void playerO(char a[]) {
	int position;
	cout << "Player O \n>> ";
	cin >> position;

	while (true) {
		if( a[position - 1] != 'X' && a[position - 1] != 'O' && (position == 1 || position == 2 || position == 3 || position == 4 || position == 5 || position == 6 || position == 7 || position == 8 || position == 9) ) {
			break;
		}
		else {
			cout << "You cannot place your mark at there. Try again" << endl << ">> ";
			cin >> position; 
		}
	}

	a[position-1] = 'O';
}
void displayBoard(char a[]) {
	int number = 0;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cout << a[number] << " ";
			number++;
		}
		cout << endl;
	}
}

bool win(char a[], char letter) {
	//horizontal win possibilities
	if (a[0] == letter && a[1] == letter && a[2] == letter) {
		return true; 
	}
	else if (a[3] == letter && a[4] == letter && a[5] == letter) {
		return true;
	}
	else if (a[6] == letter && a[7] == letter && a[8] == letter) {
		return true;
	}

	// vertical win probabilities
	else if (a[0] == letter && a[3] == letter && a[6] == letter) {
		return true;
	}
	else if (a[1] == letter && a[4] == letter && a[7] == letter) {
		return true;
	}
	else if (a[2] == letter && a[5] == letter && a[8] == letter) {
		return true;
	}

	 //  diagonal win possibilites
	else if (a[0] == letter && a[4] == letter && a[8] == letter) {
		 return true;
	}
	else if (a[2] == letter && a[4] == letter && a[6] == letter) {
		 return true;
	}
	else {
		return false; 
	}
}