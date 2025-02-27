#include <iostream>
using namespace std;

double convertToMPH(int minuites, int seconds);
double convertToMPH(double kph);

int main() {

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	double kph;
	int minuites, seconds;
	int ans;
	cout << "To convert your speed from minuites and seconds taken per mile to miles per hour, press 1. \nTo convert your speed from kilometers per hours to miles per hour, press 2.";
	cin >> ans;
	cout << endl;

	if (ans == 1){

		cout << "Minuites: ";
		cin >> minuites;
		cout << "Seconds: ";
		cin >> seconds;
		cout << convertToMPH(minuites, seconds) << " miles per hour.";
	}
	else {
		cout << "Speed in kilometers per hour: ";
		cin >> kph;
		cout << convertToMPH(kph) << " miles per hour";
	}
	return 0;
}
double convertToMPH(int minuites, int seconds) {

	return 1 / (minuites / 60.0 + seconds / 3600.0);

}
double convertToMPH(double kph) {

	return kph * 0.62137119;
}
