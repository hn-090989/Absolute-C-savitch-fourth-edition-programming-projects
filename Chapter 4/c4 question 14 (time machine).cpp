#include <iostream>
using namespace std;

int difference(int startTime, int endTime);

int main() {

	int start;
	int end;

	cout << "Start time (HHMM): ";
	cin >> start;
	cout << "End time (HHMM): ";
	cin >> end;

	cout << "Difference: ";
	cout << difference(start, end) << endl;

	return 0;
}
int difference(int startTime, int endTime) {

	int difference;
	int h1 = startTime / 100, m1 = startTime % 100;
	int h2 = endTime / 100, m2 = endTime % 100;

	difference = (h2 * 60 + m2)- (h1 * 60 + m1)  ;
	return  difference;
}
