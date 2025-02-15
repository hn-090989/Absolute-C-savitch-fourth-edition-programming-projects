#include <iostream>
#include <cmath>
using namespace std;

void input(int& kilograms, int& grams);
void conversion(int kilograms, int grams, int& pounds, int& ounces);
void output(int pounds, int ounces);
bool repeat();

int main() {
	cout << "Enter the weight in kilograms and grams to convert it to pounds and ounces. ";
	cout << endl;

	int kilograms, grams, pounds, ounces;
	do {
		input(kilograms, grams);
		conversion(kilograms, grams, pounds, ounces);
		output(pounds, ounces);

	} while (repeat());

	return 0;
}
void input(int& kilograms, int& grams) {

	cout << "kilograms: ";
	cin >> kilograms;
	cout << "grams: ";
	cin >> grams;
}
void conversion(int kilograms, int grams, int& pounds, int& ounces) {
	double totalgrams = kilograms * 1000 + grams;
	double totalPounds = totalgrams*(2.2046/1000);
	
	pounds = static_cast<int>(totalPounds);
	ounces = round((totalPounds  - pounds)*16);
	
}
void output(int pounds, int ounces) {

	cout << pounds << " pounds " << ounces << " ounces ";

}
bool repeat() {
	char ans;
	cout << "\nWould you like to rerun the program?(y/n) ";
	cin >> ans;
	cout << endl;
	return (ans == 'y' || ans == 'Y');
}