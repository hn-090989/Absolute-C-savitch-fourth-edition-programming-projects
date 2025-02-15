#include <iostream>
#include <cmath>
using namespace std;

void feetToMeters();
void inputFTM(int& feet, int& inches);
void FTM(int feet, int inches, int& meters, int& centimeters);
void outputFTM(int meters, int centimeters);


void metersToFeet();
void inputMTF(int& meters, int& centimeters);
void MTF(int meters, int centimeters, int& feet, int& inches);
void outputMTF(int feet, int inches);

bool repeat();

int main() {
	
	int ans;
	cout << "Welcome to the program!"<<endl;

	do {
		cout << "Press 1 to convert from meters and centimeters to feet and inches and press 2 to convert from feet and inches to meters and centimeters.";
		cin >> ans;

		if (ans == 1)
			metersToFeet();
		else if (ans == 2)
			feetToMeters();

	} while (repeat());
	cout << "Byee!!! "<<endl;

	return 0;
}
void metersToFeet() {
	
	int feet, meters, inches, centimeters;
	inputMTF(meters, centimeters);
	MTF(meters, centimeters, feet, inches);
	outputMTF(feet, inches);
}
void inputMTF(int& meters, int& centimeters) {

	cout << "Meters: ";
	cin >> meters;
	cout << "Centimeters: ";
	cin >> centimeters;
	cout << endl;
}
void MTF(int meters, int centimeters, int& feet, int& inches) {

	double totalMeters = meters + (centimeters / 100.0);
	double totalFeet = totalMeters / 0.3048;
	feet = static_cast<int>(totalFeet);
	inches = round((totalFeet - feet) * 12);
}
void outputMTF(int feet, int inches) {

	cout << feet << " feet " << inches << " inches " << endl;
}


void feetToMeters() {

	int feet, meters, inches, centimeters;

	inputFTM(feet, inches);
	FTM(feet, inches, meters, centimeters);
	outputFTM(meters, centimeters);
}
void inputFTM(int& feet, int& inches) {

	cout << "Feet: ";
	cin >> feet;
	cout << "Inches: ";
	cin >> inches;
	cout << endl;
}
void FTM(int feet, int inches, int& meters, int& centimeters) {

	inches = inches + (feet * 12);
	meters = static_cast<int>(inches * (0.3048 / 12));
	centimeters = round(((inches * (0.3048 / 12)) - meters) * 100);
}
void outputFTM(int meters, int centimeters) {

	cout << meters << " meters " << centimeters << " centimeters " << endl;
}


bool repeat() {
	char ans;
	cout << "Would you like to run the program again? (y/n) ";
	cin >> ans;
	cout << endl;
	return (ans == 'y' || ans == 'Y');
}