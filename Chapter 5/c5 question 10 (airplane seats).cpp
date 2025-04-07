#include <iostream>
using namespace std; 

void seats(char b[]);
int	index();
void convert(char& column, bool & retry);
void display(char a[]);
void booking(char a[]);
void fillCheck(char a[],bool& check);

int main() {
	char seat[28];
	seats(seat);
	bool check = true;
	char ans;

	do {
		fillCheck(seat, check);
		if (check == false) {
			cout << "All seats are full.";
			break;
		}
		display(seat);
		booking(seat);
		cout << "Would you like to book another seat?(y/n) ";
		cin >> ans;
		cout << endl;
	} while (ans == 'Y' || ans == 'y');
}
void seats(char b[]) {
	int i = 0;
	for (int x = 0; x < 7; x++) {
		for (char alpha = 'A'; alpha <= 'D';alpha++) {
			b[i] = alpha;
			i++;
		}
	}
}
int	index(){
	char column;
	int number; 

	do {
		cout << "Enter the row number: ";
		cin >> number;
	} while (number < 1 || number >7);

	cout << "Enter the column letter: ";
    do{	
		bool retry = true;
		cin >> column;
		convert(column, retry);
	} while (!retry);

	return (number - 1) * 4 + (column - 1);
}
void convert(char& column, bool& retry) {
	switch (static_cast<int>(column)) {
	case 'A':
		column = 1;
		break;
	case 'B':
		column = 2;
		break;
	case 'C':
		column = 3;
		break;
	case 'D':
		column = 4;
		break;
	case 'a':
		column = 1;
	    break;
	case 'b':
		column = 2;
		break;
	case 'c':
		column = 3;
		break;
	case 'd':	
		column = 4;
		break;
	default:
		cout << "Please enter a valid column from A-B: ";
		retry = false;
		break;
	}
}
void display(char a[]) {
	int x = 0;

	for (int i = 1; i <= 7; i++) {
		cout << i << "     ";
		int m = 1;

		while (m <= 4) {
			cout << a[x]<< " ";
			if (m == 2) {
				cout << " ";
			}
			x++;
			m++;
		}
		cout << endl;	
	}
}
void booking(char a[]) {
	int bookingseat = index();
	
	if (a[bookingseat] == 'X') {
		cout<< "Please pick another seat"<< endl;
		bookingseat=index();
	}
	else {
		a[bookingseat] = 'X';
		cout << "Your seat has been booked" << endl;
	}
}
void fillCheck(char a[], bool& check) {
	for (int i = 0; i < 28; i++) {
		if (a[i] != 'X') {
			return; 
		}
	}
	check = false; 
}



