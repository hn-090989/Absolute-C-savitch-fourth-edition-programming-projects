#include <iostream>
using namespace std;

double weight , height;//weight in pounds and height in inches.
int age;

double hatSize(double weight, double height);
double jacketSize(double height, double wieght, int age);
double waistSize(double weight, int age);

int main() 
{
	cout << "Welcome to the programme :) You can use it to find your ideal hat, jacket and waist size ";
	char ans;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

		do 
		{
			cout << "\nEnter your weight (in pounds): ";
			cin >> weight;
			cout << "\nEnter your height (in inches): ";
			cin >> height;
			cout << "\nEnter your age: ";
			cin >> age;

			cout << "\nHat size: "<< hatSize(weight, height);
			cout << "\nJacket size: " << jacketSize(height, weight, age);
			cout << "\nWaist size: " << waistSize(weight, age);
			cout << endl;
			
			cout << "Would you like to run the calculations for another set of values? (y/n): " ;
			cin >> ans;
			cout <<endl;

		} while (ans == 'y' || ans == 'Y');

	return 0;
}
double hatSize(double weight, double height)
{
	return (weight / height) * 2.9;
}

double jacketSize(double height, double wieght, int age)
{
	int numAdd;
	double jacketSize=(height * weight) / 228;
	numAdd = (age - 30) / 10;
	
	if (age > 30)

		for (int i = 1; i <= numAdd; i++)
			jacketSize += (1/8.0);
	
	return jacketSize;
} 
double waistSize(double weight, int age)
{
	int numAdd;
	double waistSize = weight / 5.7;
	numAdd = (age - 28) / 2;

	if (age > 28)
	for (int i = 1; i <= numAdd; i++)
		waistSize += (1/10.0);

	return waistSize;
}

