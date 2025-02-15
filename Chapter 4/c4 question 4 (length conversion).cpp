#include <iostream>
#include <cmath>
using namespace std;

void input(int& feet, int& inches);
void computations(int feet, int inches, int& meters, int& centimeters);
void output(int meters, int centimeters);
bool repeat();

int main() {
	int feet, inches, centimeters, meters;
	do {
		cout << "Enter length in feet and inches to convert into meters and centimeters. " << endl;

		input(feet, inches);
		computations(feet, inches, meters, centimeters);
		output(meters, centimeters);

	} while (repeat());
	return 0;
}
void input(int& feet, int& inches) {
	cout << "Feet: ";
	cin >> feet;
	cout << "Inches: ";
	cin >> inches;
	cout << endl;
}
void computations(int feet, int inches, int& meters, int& centimeters) {
	inches = inches + (feet * 12);
	meters = static_cast<int>(inches * (0.3048 / 12));
	centimeters = round(((inches * (0.3048 / 12)) - meters)*100);
}
void output(int meters, int centimeters) {
	cout << meters << " meters " << centimeters << " centimeters "<<endl;
}
bool repeat() {
	char ans;
	cout << "Would you like to run the program again? (y/n) ";
	cin >> ans;
	cout << endl;
	return (ans == 'y' || ans == 'Y');
}