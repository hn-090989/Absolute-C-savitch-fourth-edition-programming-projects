#include <iostream>
using namespace std;

const int NUMBERS = 6;

void input(int result[]);
void display(const int result[]);

int main() {
	int result[NUMBERS] = { 0 };

	input(result);
	display(result);
	return 0;
}
void input(int result[]) {
	int grade =0, count =1; 
	cout << "Enter grades from 1 to 5 and append the list with a negative number" << endl;

	while (true) {
		cout << "Student " << count << ": ";
		cin >> grade; 
		if (grade < 0) {
			break;
		}
		if (grade >= 0 && grade <= 5) {
			result[grade]++;
		}
		count++;
	}
}
void display(const int result[]) {

	for (int i = 0; i < NUMBERS; i++) {
		cout << result[i] << " grade(s) of " << i;
		cout << endl;
	}
}
