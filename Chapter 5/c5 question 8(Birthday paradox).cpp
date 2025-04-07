#include <iostream>
#include <ctime>
using namespace std;

const int MAX = 50; 

int birthday();
double probability(int number);

int main() {
	srand(time(0));
	for (int numberOfPeople =2; numberOfPeople <= 50; numberOfPeople++) {
		cout << "For " << numberOfPeople << " people, the probabilty of two birthdays is about " << probability(numberOfPeople)<< endl;
	}

	return 0; 
}
int birthday() {
	return rand() % 365 + 1;
}
double probability(int number) {
	int a[MAX];
	int count = 0;

	for (int y = 1; y <= 10000; y++) {
		bool found = false;

		for (int i = 0; i < number; i++) {
			int x = birthday();
			a[i] = x;

			for (int m = 0; m < i; m++) {
				if (a[i] == a[m]) {
					count++;
					found = true;
					break;
				}
			}
			if (found) { break; }
		}
	}
	return count / 10000.0;

}
