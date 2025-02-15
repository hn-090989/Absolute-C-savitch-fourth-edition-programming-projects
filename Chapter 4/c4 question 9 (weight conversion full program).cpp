#include <iostream>
#include <cmath>
using namespace std;

void KgToPounds();
void KTPinput(int& kilograms, int& grams);
void KTP(int kilograms, int grams, int& pounds, int& ounces);
void KTPoutput(int pounds, int ounces);

void PoundsToKg();
void PTKinput(int& pounds, int& ounces);
void PTK(int pounds, int ounces, int& kilograms, int& grams);
void PTKoutput(int kilograms, int grams);

bool repeat();
int main() {
	int ans;
	do {
		cout << "To convert from kilograms and grams to pounds and ounces, enter 1.\nTo convert from pounds and ounces to kilograms and grams, enter 2. ";
		cin >> ans;

		if (ans == 1)
			KgToPounds();
		else if (ans == 2)
			PoundsToKg();

	} while (repeat());
	return 0;
}
void KgToPounds() {

	int kilograms, grams, pounds, ounces;
	KTPinput(kilograms, grams);
	KTP( kilograms,  grams,  pounds,  ounces);
	KTPoutput( pounds, ounces);
}
void KTPinput(int& kilograms, int& grams) {

	cout << "kilograms: ";
	cin >> kilograms;
	cout << "grams: ";
	cin >> grams;
}
void KTP(int kilograms, int grams, int& pounds, int& ounces) {
	double totalgrams = kilograms * 1000 + grams;
	double totalPounds = totalgrams *(2.2046/1000);

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
bool repeat() {
	char ans;
	cout << "\nWould you like to rerun the program?(y/n) ";
	cin >> ans;
	cout << endl;
	return (ans == 'y' || ans == 'Y');
}