#include <iostream>
#include <cmath>
using namespace std;

void input(int& meters, int& centimeters);
void computations(int meters, int centimeters, int& feet, int& inches);
void output(int feet, int inches);
bool repeat();

int main() {
	int feet, inches, centimeters, meters;
	do {
		cout << "Enter length in meters and feet to convert into feet and inches. " << endl;

		input(meters, centimeters);
		computations(meters, centimeters, feet, inches);
		output(feet, inches);

	} while (repeat());
	return 0;
}
void input(int& meters, int& centimeters){
	cout << "Meters: ";
	cin >> meters;
	cout << "Centimeters: ";
	cin >> centimeters;
	cout << endl;
}
void computations(int meters, int centimeters, int& feet, int& inches) {
	double totalMeters = meters + (centimeters / 100.0);  
	double totalFeet = totalMeters / 0.3048;  
	feet = static_cast<int>(totalFeet);  
	inches = round((totalFeet - feet) * 12);
}
void output(int feet, int inches){
	cout << feet << " feet " << inches << " inches " << endl;
}
bool repeat() {
	char ans;
	cout << "Would you like to run the program again? (y/n) ";
	cin >> ans;
	cout << endl;
	return (ans == 'y' || ans == 'Y');
}