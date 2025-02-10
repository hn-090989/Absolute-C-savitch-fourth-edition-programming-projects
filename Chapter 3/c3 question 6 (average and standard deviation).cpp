#include <iostream>
#include <cmath>
using namespace std; 

void evaluation(double s1, double s2, double s3, double s4);
double sum(double s1, double s2, double s3, double s4);
double squareSum(double s1, double s2, double s3, double s4,double average);

int main ()
{
	double score1, score2, score3, score4;
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	char ans;
	do {
		cout << "Enter 4 acores to compute their average and standard deviation: \n";
		cin >> score1 >> score2 >> score3 >> score4;

		evaluation(score1, score2, score3, score4);

		cout << "Whould you like to run the program again? (y/n) ";
		cin >> ans;

	} while (ans == 'y' || ans == 'Y');

	return 0;
}

double sum(double s1, double s2, double s3, double s4)
{
	return(s1 + s2 + s3 + s4);
}

double squareSum(double s1, double s2, double s3, double s4, double average)
{
	double i;
	i = pow((s1 - average), 2) + pow((s2 - average), 2) + pow((s3 - average), 2) + pow((s4 - average), 2);
	return i;
}

void evaluation(double s1, double s2, double s3, double s4)
{
	double standardDeviation, average; 
	average = sum(s1, s2, s3, s4) / 4;
	standardDeviation = sqrt(squareSum(s1, s2, s3, s4, average) / 4);

	cout << "Average: " << average << endl;
	cout << "Standard Deviation: " << standardDeviation<<endl;

}
