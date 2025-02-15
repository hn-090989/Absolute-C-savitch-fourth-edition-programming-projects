#include <iostream>
using namespace std;

void inputs(int& hours, int& minutes);
void conversion(int& hours, char& time);
void output(int hours, int minutes, char time);

int main() {
	int hours, minutes;
	char notation;
	char ans;
	do {
		inputs(hours, minutes);
		conversion(hours, notation);
		output(hours, minutes, notation);

		cout << "Would you like to run the program again?(y/n) ";
		cin >> ans;

	} while (ans == 'Y' || ans == 'y');
	return 0;
}
void inputs(int& hours, int& minutes) {
	cout << "Enter the time in 24 hour notation: " << endl;
	
	cout << "Hours: ";
	cin >> hours;
	cout << "minutes: ";
	cin >> minutes;
}
void conversion(int& hours, char& time) {

	if (hours > 12){
		time = 'p';
		hours -= 12;
	}
	else if (hours==12){
		time = 'p';
	}
	else if (hours == 0) {
		time = 'a';
		hours = 12;
	}
	else { 
		time = 'a'; 
	}
}
void output(int hours, int minutes, char time) {
	
	cout << hours << ":" << (minutes < 10 ? "0" : "") << " ";
	if (time == 'p')
		cout << "P.M."<<endl;
	else
		cout << "A.M."<<endl;
}
