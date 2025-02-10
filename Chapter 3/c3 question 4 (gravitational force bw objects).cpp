#include <iostream>
#include <cmath>
using namespace std; 

double G= 6.63e-8;// gravitational constant with units cm^3/(g.sec^2)

double force(double m1, double m2, double distance);
//preconditions: the formal parameters m1 and m2 are the masses of 2 bodies in grams.
//the formal parameter distance is the distance of the two masses from each other in centimeters .
//postconditions: the function force calculates the mass between the two bodies in dynes. 

int main()
{
	char ans;
	double mass1, mass2, distance;
	cout << "Welcome:) This programme will calculate the gravitational force between any two object in dynes.";
	do{
		cout << "\nMass of objest one (in grams): ";
		cin >> mass1;

		cout << "\nMass of objest two (in grams): ";
		cin >> mass2; 

		cout << "\nDistance between the two objects(in cm): ";
		cin >> distance; 
		cout << endl;

		cout << force(mass1, mass2, distance) << endl;

		cout << "\nWould you like to compute the force between another pair of objects? (y/n) ";
		cin >> ans;

	} while (ans == 'y' || ans == 'Y');
	cout << "End of programme. Have a good day! ";

	return 0;
}
double force(double m1, double m2, double distance)
{
	return (G * m1 * m2) / pow(distance, 2.0);
}