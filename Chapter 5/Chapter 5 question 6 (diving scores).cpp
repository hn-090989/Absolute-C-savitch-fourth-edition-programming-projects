#include <iostream>
using namespace std; 

const int NUMBER_OF_JUDGES = 7;
void judges(float scores[]);
void max(float score[], int NUMBER_OF_JUDGES);
void min(float score[], int NUMBER_OF_JUDGES);
float overallScore( float score[]);


int main() {

	float scores[NUMBER_OF_JUDGES];
	judges(scores);

	cout << "The total score is: " << overallScore(scores) << endl;

	return 0;
}
void judges(float scores[]) {
	int i = 1;
	float judgeScore; 

	while (i <= 7) {
		cout << "Judge "<<i << ": ";
		cin >> judgeScore;

		while (judgeScore < 0 || judgeScore > 10) {
			cout << "Invalid. Please enter a score between 1 and 10"<< endl << "Judge "<< i << ": ";
			cin >> judgeScore;
		}
		scores[i - 1] = judgeScore;
		i++;
	}
}
void max( float score[], int NUMBER_OF_JUDGES) {
	float max = score[0];
	for (int i = 1; i < NUMBER_OF_JUDGES; i++) {
		if (score[i] > max) {
			max = score[i];
		}
	}
	for (int x = 0; x < NUMBER_OF_JUDGES; x++) {
		if (score[x] == max) {
			score[x] = 0;
		}
	}
}
void min( float score[], int NUMBER_OF_JUDGES) {

	float min = score[0];
	for (int i = 1; i < NUMBER_OF_JUDGES; i++) {
		if (score[i] < min) {
			min = score[i];
		}
	}
	for (int x = 0; x < NUMBER_OF_JUDGES; x++) {
		if (score[x] == min) {
			score[x] = 0;
		}
	}
}
float overallScore( float score[]) {
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	float degree;

	cout << "Enter the degree of difficulty: ";
	cin >> degree;
	while (degree < 1.2 || degree > 3.8) {
		cout << "Degree of difficulty must be between 1.2 and 3.8: ";
		cin >> degree;
	}
	min(score, NUMBER_OF_JUDGES);
	max(score, NUMBER_OF_JUDGES);

	float sum = 0;
	for (int i = 0; i < NUMBER_OF_JUDGES; i++) {
		sum += score[i];
	}
	
	float total = sum * degree * 0.6;
	return total;
}
