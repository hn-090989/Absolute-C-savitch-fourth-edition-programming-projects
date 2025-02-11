# include <iostream>
using namespace std;

int main()
{
	double radius; 
	const double SPECIFIC_WEIGHT = 62.4; // pound per feet cubed
	double weight; 
    const double pi = 3.14159265358979323846;

	

	cout << "Weight of sphere (in pounds): ";
	cin >> weight;

	cout << "Radius of sphere(in feet): ";
	cin >> radius; 

	double volume = (4.0 / 3) * pi * (radius);
	double boyantForce = volume * SPECIFIC_WEIGHT;
	
	if (boyantForce >= weight)
		cout << "The object floats. \n";
	else
		cout << "The object sinks. ";


	return 0;

}