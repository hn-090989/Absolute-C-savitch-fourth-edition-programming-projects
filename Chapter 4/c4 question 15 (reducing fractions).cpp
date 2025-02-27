#include <iostream>
using namespace std;

void convertToLowestTerms(int& numerator, int& denominator);
int main() {

	int numerator, denominator;
	char ans;
	do {
		cout << "Numerator: ";
		cin >> numerator;
		cout << "Denominator: ";
		cin >> denominator;

		convertToLowestTerms(numerator, denominator);
		cout << numerator << "\t" << denominator;

		cout << "\nWould you like to test the program again?";
		cin >> ans;
		cout << endl;
	} while (ans == 'y' || ans == 'Y');
	return 0;
}
void convertToLowestTerms(int& numerator, int& denominator) {

	int gcd = denominator;
	while (gcd>0) {
		if (denominator % gcd == 0 && numerator % gcd == 0) {
			denominator = denominator / gcd;
			numerator= numerator / gcd;
			break;	
		}
		else {
			gcd--;
			continue;
		}
	}
}
