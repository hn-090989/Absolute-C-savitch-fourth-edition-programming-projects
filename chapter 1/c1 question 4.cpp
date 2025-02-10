#include <iostream>
using namespace std;

int main()
{
	int duration;
	double interestRate;
	double amountNeeded;
	double faceValue;

	cout << "Enter the amount you need: ";
	cin >> amountNeeded;

	cout << "Enter the interest rate: ";
	cin >> interestRate;

	cout << "Enter the duration of the installments in months: ";
	cin >> duration;

	faceValue = amountNeeded / (1 - (interestRate/100) * (duration/12.0));

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);


	cout << "The face value of the loan should be: " << faceValue << endl;
	cout << "You will have to pay "<< faceValue/duration <<" monthly /n";

	return 0;

}