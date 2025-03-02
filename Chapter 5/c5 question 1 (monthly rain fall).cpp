#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

void userInput(double actualRainfall[],  int size, string month, int year, const string months[]);
void deviation(const double actualRainfall[], const double averageRainfall[], double deviation[], int size);
void table(const double actualRainfall[], const double deviation[], int size, string month, int year, const string months[]);
void barChart(const double actualRainfall[], const double averageRainfall[], int size, string month, int year, const string months[]);

int main() {
	const int SIZE = 12;
	double averageRainfall[SIZE] = { 35 , 15 , 18, 5, 0.3, 0.2, 2.3, 
		0.6, 0.3, 1, 11, 24 };
	double actualRainfall[SIZE], deviationFromAverage[SIZE];

	string months[SIZE] = { "january", "feburary", "march", "april", "may", "june", "july", "august", "september",
	 "october", "november", "december" };

	string month;
	int year;

	cout << "Hello! This program can be used to display the deviation between the average rainfall for a month and the actual rainfall. \n";

	cout << "Enter the current month: ";
	while (true) {
		cin >> month;

		if (month == "january" || month == "feburary" || month == "march" || month == "april" || month == "may" || month == "june" || month == "july" || month == "august" || month == "september" || month == "october"
			|| month == "november" || month == "december") {
			break;
		}
		cout << "Please enter a valid input.";
	}

	cout << "Enter the current year: ";
	while (true) {
		cin >> year;
		
		if (year / 1000 != 0 && year > 0) {
			break;
		}
		cout << "Please enter a valid year: ";
	}
	userInput(actualRainfall, SIZE, month, year, months);
	deviation(actualRainfall, averageRainfall, deviationFromAverage, SIZE);

	char ans = 'y';
	int option;
	do {
		while (true) {
			cout << "Enter 1 to have your result printed as a table. Enter 2 to have your result printed as a barchart. ";
			cin >> option;
			cout << endl;
			if (option == 1) {
				table(actualRainfall, deviationFromAverage, SIZE, month, year, months);
				break;
			}
			else if (option == 2) {
				barChart(actualRainfall, averageRainfall, SIZE, month, year, months);
				break;
			}	
		}
		cout << endl;

		cout << "Do you want to try another display? (y/n)";
		cin >> ans;
	} while (ans == 'Y' || ans == 'y');
	return 0;
}

void userInput(double actualRainfall[], int size, string month, int year, const string months[]) {

	int mon = 1;
	for (int i = 0; i < size; i++) {
		if (months[i] == month) {
			mon = i;
		}
	}
	for (int x = 0; x < size; x++) {

		cout << months[mon] << " " << year << ": ";
		cin >> actualRainfall[mon];
		mon--;

		if (mon < 0) {
			mon = 11;
			year--;
		}
	}
}
void deviation(const double actualRainfall[], const double averageRainfall[], double deviation[], int size) {
		
	  
		for (int i = 0; i < size; i++) {
			deviation[i] = averageRainfall[i]- actualRainfall[i];
		}
}
void table(const double actualRainfall[], const double deviation[], int size, string month, int year, const string months[]) {


	cout << "\n--------------------------------------------------------------" << endl;
	cout << "|   Month    |   Year   |  Monthly Rainfall  |  Deviation    |" << endl;
	cout << "--------------------------------------------------------------" << endl;
	int mon = 1;
	for (int i = 0; i < size; i++) {
		if (months[i] == month) {
			mon = i;
		}
	}
	for (int x = size - 1; x >= 0; x--) {

		cout << "| " << setw(10) << left << months[mon] << " | "
			<< setw(8) << year << " | "
			<< setw(18) << actualRainfall[mon] << " | "
			<< setw(13) << deviation[mon] << " |" << endl;

		mon--;
		if (mon < 0) {
			mon = 11;
			year--;
		}
		cout << "--------------------------------------------------------------"<< endl;
	}
}
void barChart(const double actualRainfall[], const double averageRainfall[], int size, string month, int year, const string months[]) {

	int mon = 1;
	for (int i = 0; i < size; i++) {
		if (months[i] == month) {
			mon = i;
			break;
		}
	}
	for (int x = 0; x < size; x++) {
		cout << months[mon] << " " << year << ": ";

		if (mon < 0) {
			mon = 11;
			year--;
		}
		cout << endl;

		int stars = 0;
		stars += static_cast<int>(actualRainfall[mon]);
		
		int astars = 0;
		astars += static_cast<int>(averageRainfall[mon]);
		
		cout << "Actual Rainfall \t";
		for (int x = 1; x <= stars;x++) {
			cout << "*";
		}
		cout << endl;
		cout << "Average Rainfall \t";
		for (int y = 1; y <= astars;y++) {
			cout << "*";
		}
		mon--;
		cout << endl << endl;	
	}
}
	





