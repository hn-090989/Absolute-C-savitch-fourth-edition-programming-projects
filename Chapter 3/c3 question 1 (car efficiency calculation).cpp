#include <iostream>
using namespace std;

double liter = 0.264179; // number of liters per gallon.

double delivered(double gasolineConsumed, double distance);
//preconditions: the formal parameter gasolineConsumed is the amount comsumed in liters 
//the formal parameter distance is the number of miles travelled

int main ()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	double consumed; 
	double distance; 

	cout << "How much gasoline was consumed (in liters)? ";
	cin >> consumed;
	cout << endl;
	cout << "How much distace was covered?(in miles)? ";
	cin >> distance;
	cout << endl;

	cout << "The efficiency of your car is: " << delivered(consumed, distance) << " miles per gallon." << endl;


}

double delivered(double gasolineConsumed, double distance)
{
	return (distance/(gasolineConsumed * liter));
}
