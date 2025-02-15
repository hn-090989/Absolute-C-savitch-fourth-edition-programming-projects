# include <iostream>
#include <cmath>
using namespace std;

void weight();

void KgToPounds();
void KTPinput(int& kilograms, int& grams);
void KTP(int kilograms, int grams, int& pounds, int& ounces);
void KTPoutput(int pounds, int ounces);

void PoundsToKg();
void PTKinput(int& pounds, int& ounces);
void PTK(int pounds, int ounces, int& kilograms, int& grams);
void PTKoutput(int kilograms, int grams);


void length();

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
	do {
		cout << "For length conversions, enter 1. For weight conversions, enter 2."<< endl;
		cin >> ans;
		if (ans == 1) {
			length();
		}
		else if (ans==2){
			weight();
		}
	} while (repeat());
	cout << "Have a good day!!!";
	return 0;
}
void weight() {
	int ans;
	cout << "To convert from kilograms to pounds, enter 1.\nTo convert from pounds to kilograms, enter 2. " << endl;
	cin >> ans;

	if (ans == 1) {
		KgToPounds();
	}
	else if (ans==2) {
		PoundsToKg();
	}
}
void KgToPounds() {

	int kilograms, grams, pounds, ounces;
	KTPinput(kilograms, grams);
	KTP(kilograms, grams, pounds, ounces);
	KTPoutput(pounds, ounces);
}
void KTPinput(int& kilograms, int& grams) {

	cout << "kilograms: ";
	cin >> kilograms;
	cout << "grams: ";
	cin >> grams;
}
void KTP(int kilograms, int grams, int& pounds, int& ounces) {
	double totalgrams = kilograms * 1000 + grams;
	double totalPounds = totalgrams * (2.2046 / 1000);

	pounds = static_cast<int>(totalPounds);
	ounces = round((totalPounds - pounds) * 16);

	pounds += ounces / 16;
	ounces = ounces % 16;
}
void KTPoutput(int pounds, int ounces) {

	cout << pounds << " pounds " << ounces << " ounces ";

}

void PoundsToKg() {

	int kilograms, grams, pounds, ounces;
	PTKinput(pounds, ounces);
	PTK(pounds, ounces, kilograms, grams);
	PTKoutput(kilograms, grams);
}
void PTKinput(int& pounds, int& ounces) {

	cout << "Pounds: ";
	cin >> pounds;
	cout << "Ounces: ";
	cin >> ounces;
}
void PTK(int pounds, int ounces, int& kilograms, int& grams) {

	double totalOunces = pounds * 16 + ounces;
	double totalkilograms = totalOunces / (2.2046 * 16);

	kilograms = static_cast<int>(totalkilograms);
	grams = round((totalkilograms - kilograms) * 1000);

}
void PTKoutput(int kilograms, int grams) {

	cout << kilograms << " kilograms " << grams << " grams ";

}


void length() {
	int ans;
	cout << "To convert from meters to feet, press 1.\nTo convert from feet to meters, press 2. " << endl;
	cin >> ans;
	if (ans == 1) {
		metersToFeet();
	}
	else if (ans == 2) {
		feetToMeters();
	}
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
	cout << "Would you like to run the program again? (y/n) " << endl;
	cin >> ans;
	cout << endl;
	return (ans == 'y' || ans == 'Y');
}
