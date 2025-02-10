
#include <iostream>
#include <cmath>
#include<cstdlib>
using namespace std;

double chillFactor(double windSpeed, double temperature);

int main()
{
	double windSpeed, temp;

	cout << "Welcome! You can use this program to calculate the wind chill factor. "<<endl;

	cout << "Enter the wind speed in meters per second: ";
	cin >> windSpeed;

	char ans;
	while (true)
	{
		cout << endl << "Enter the temprature in celcius (must be less than 10 degree celcius): ";
		cin >> temp; 
		cout << endl;

		if (temp <= 10) 
		{
			break;
		}
		cout<<"The wind chill factor cannot be computed for this temperature. \n";
		cout <<"Would you like to try with another temperature? (y/n) ";
		cin >> ans;
			
		if (ans == 'n' || ans == 'N')
		{
			return 0;
		}

	}
	cout << endl;
	cout << "The wind chill factor is: " << chillFactor(windSpeed, temp);

}

double chillFactor(double windSpeed, double temperature)
{
	double i;
	i = (10 * sqrt(windSpeed) - windSpeed + 10.5) * (33 - temperature);
	return 33 - (i / 23.1);

}


