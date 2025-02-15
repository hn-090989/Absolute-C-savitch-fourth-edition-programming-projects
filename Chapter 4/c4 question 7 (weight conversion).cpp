#include <iostream>
#include <cmath>
using namespace std;

void input(int& pounds, int& ounces); 
void conversion(pounds, ounces, int& kilograms, int& grams);  
void output(int kilograms, int grams); 
bool repeat();

int main() {
	cout << "Enter the weight in pounds and ounces to convert it to kilograms and grams. ";
	cout << endl;

	int pounds, ounces, kilograms, grams;
	do {
		input(pounds, ounces);
		conversion(pounds, ounces, kilograms, grams);
		output(kilograms, grams);

	} while (repeat());

	return 0;
}
void input(int& pounds, int& ounces) {
	
	cout << "Pounds: ";
	cin >> pounds;
	cout << "Ounces: ";
	cin >> ounces;
}
void conversion(int pounds, int ounces, int& kilograms, int& grams) {

	double totalOunces = pounds * 16 + ounces;
	double totalkilograms = totalOunces / (2.2046 * 16);

	kilograms = static_cast<int>(totalkilograms);
	grams = round((totalkilograms - kilograms) * 1000);
}
void output(int kilograms, int grams) {

	cout << kilograms << " kilograms " << grams << " grams ";

}
bool repeat() {
	char ans;
	cout << "\nWould you like to rerun the program?(y/n) ";
	cin >> ans;
	cout << endl;
	return (ans == 'y' || ans == 'Y');
}