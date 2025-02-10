#include <iostream>
#include <cstdlib>
using namespace std;

double inflationRate(double yearAgo, double today);
//preconditions: yearAgo is the value of an item a year ago.
//today is the price of the item today.
//postconditions: the inflation rate is calculated.

void prediction(int time, double rate, double priceToday);
//preconditons: time is the number of years from today.
// rate is the inflation rate that was computed by the inflationRate function.
//post condition: the price of the item time years from today is estimated using the inflationRate

int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	double rate, today, yearago;
	int yearsFromNow; 

	cout << "What was the price of a hotdog a year ago? ";
	cin >> yearago;
	cout << "\n What is the price of a hot dog now? ";
	cin >> today;

	rate = inflationRate(yearago, today);
	rate = inflationRate(yearago, today);
	cout << "\nThe inflation rate is: " << rate << "%";

	char j;

	cout << "\nDo you want an estimate of what the price will be in a few years?(y/n) ";
	cin >> j;

	if (j == 'n' || j == 'N')
		exit(0);
	cout << "\nEnter the number of years from now: \n";
	cin >> yearsFromNow;

	prediction(yearsFromNow, rate, today);


}
double inflationRate(double yearAgo, double today)
{
	return (((today-yearAgo)/yearAgo)*100);
}
void prediction(int time, double rate, double priceToday)
{
	double price = priceToday;
	for (int i = 1; i <= time; i++)
		price += price * (rate/100);
	
	cout <<"$" << price;
}