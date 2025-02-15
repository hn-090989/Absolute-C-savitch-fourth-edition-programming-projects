#include <iostream>
#include <cmath>
using namespace std;

void triangle(double a, double b, double c, double& area, double& perimeter);

int main() {
	double a, b, c;
	double area = 0, perimeter = 0;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	do {
		cout << "First side of the triange (in cm): ";
		cin >> a;
		cout << "Second side of the triange (in cm): ";
		cin >> b;
		cout << "Third side of the triange (in cm): ";
		cin >> c;
		
		triangle(a, b, c, area, perimeter);
		if (!(area == 0)) {
			cout << "Area: " << area << endl << "Perimeter: " << perimeter << endl;
			break;
		}
	} while (area == 0);
}
void triangle(double a, double b, double c, double& area, double& perimeter) {
	
	if (a < 0 || b < 0 || c < 0) {
		cout << "Values cannot be negative or 0. Please try again. " << endl;
		return;
	}
	if (!((a + b > c) && (a + c > b) && (b + c > a))) {
		cout << "Not a valid triangle. Please try again. "<<endl;
		return;
	}
	
	double s = (a + b + c) / 2;//semiperimeter
	area = sqrt(s * (s - a) * (s - b) * (s - c));
	perimeter = a + b + c;
}
