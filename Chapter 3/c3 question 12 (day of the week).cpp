#include <iostream>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <chrono>
#include <algorithm> 
using namespace std;

bool isLeapYear(int year);
int getCenturyValue(int year);
int getYearValue(int year);
int getMonthValue(string month, int year);
string DayOfTheWeek(string month, int year, int day);

int main() {
	int year;
	int day;
	string month;
	cout << "This program will tell you the day of the week associated with any day." << endl;
	cout << "\nMonth(eg: July): ";
	cin >> month;
    
	cout << "\nDay: ";
	cin >> day;
	cout << "\nYear (eg:2008): ";
	cin >> year;
	cout << endl;

	transform(month.begin(), month.end(), month.begin(), ::tolower);

	cout << "Day of the Week: " << DayOfTheWeek(month, year, day) << endl;

}

bool isLeapYear(int year) {
	return (year % 400 == 0 || (year % 4 == 0 && !(year % 100 == 0)));
}
int getCenturyValue(int year) {
	int remainder = (year / 100) % 4;
	return ((3 - remainder) * 2);
}
int getYearValue(int year) {
	int lastTwo = year % 100;
	int b = lastTwo / 4;
	return (b + lastTwo);
}
int getMonthValue(string month, int year){
	// switch only works with enum or integer types. 
	if (month == "january") {
		if (isLeapYear(year) == true){
			return 6;
		}
		else {
			return 0;
		}
	}
	else if (month == "february") {
		if (isLeapYear(year) == true) {
			return 2;
		}
		else {
			return 3;
		}
	}
	else if (month == "march") {
		return 3;
	}
	else if (month == "april") {
		return 6;
	}
	else if (month == "may") {
		return 1;
	}
	else if (month == "june") {
		return 4;
	}
	else if (month == "july") {
		return 6;
	}
	else if (month == "august") {
		return 2;
	}
	else if (month == "september") {
		return 5;
	}
	else if (month == "october") {
		return 0;
	}
	else if (month == "november") {
		return 3;
	}
	else if (month == "december") {
		return 5;
	}
	else {
		void rePrompt();
	}
}
string DayOfTheWeek(string month, int year, int day) {

	int sum = day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year);
	int weekDay = sum % 7;

	switch (weekDay) {
	case 0:
		return "Sunday";
		break;
	case 1:
		return "Monday";
		break;
	case 2:
		return "Tuesday";
		break;
	case 3:
		return "Wednesday";
		break;
	case 4:
		return "Thursday";
		break;
	case 5:
		return "Friday";
		break;
	case 6:
		return "Saturday";
		break;
	}
}
