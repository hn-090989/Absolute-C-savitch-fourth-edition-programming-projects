#include <iostream>
#include <cmath>
using namespace std;

double height(double motherHeight, double fatherHeight, char gender);// computes the height of the child in inches and returns the value.

int main()
{
	int mfeet, minches, ffeet, finches, cfeet, cinches;
	double motherHeight, fatherHeight, childHeight;
	char gender;
	cout << "This program can be used to estimate the height of a child. \n";
	
	char ans;
	do {
		cout << "Enter the mothers' height in feet and inches \n";
		cout << "feet: ";
		cin >> mfeet;
		cout << "inches: ";
		cin >> minches;
		

		cout << "Enter the fathers' height in feet and inches \n";
		cout << "feet: ";
		cin >> ffeet;
		cout << "inches: ";
		cin >> finches;
		
		cout << "Whats your child's gender? ";
		cin >> gender; 

		motherHeight = mfeet * 12.0 + minches; 
		fatherHeight = ffeet * 12.0 + finches;
		/*childHeight = height(motherHeight, fatherHeight, gender);*/ 
		// cannot convert from void to double 

		childHeight = height(motherHeight, fatherHeight, gender);
		cfeet =  floor(childHeight / 12); 
		cinches = round(childHeight - cfeet* 12);
		cout << "The height of your child is estimated to be: "<< cfeet << " feet and "<< cinches << " inches." << endl;

		cout << "\nWould you like to run the computations again? (y/n) ";
		cin >> ans;

	} while (ans == 'y' || ans == 'Y');

	return 0;
}

double height(double motherHeight, double fatherHeight, char gender)
{
	if (gender == 'm' || gender == 'M')
		return (((motherHeight * 13) / 12.0) + fatherHeight) / 2.0;
	else 
		return(((fatherHeight * 12) / 13.0) + motherHeight) / 2.0;
}
