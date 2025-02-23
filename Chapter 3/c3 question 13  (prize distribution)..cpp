#include <iostream>
#include <chrono>
#include <thread>
using namespace std;


int main() {
	srand(time(0));// for random values at every run of the program

	cout << "And the winners are ";
	this_thread::sleep_for(chrono::seconds(1));
	cout << '.';
	this_thread::sleep_for(chrono::seconds(1));
	cout << '.';
	this_thread::sleep_for(chrono::seconds(1));
	cout << '.';
	this_thread::sleep_for(chrono::seconds(1));	
	cout << '.';
	this_thread::sleep_for(chrono::seconds(1));
	cout << endl;
	int first, second, third, fourth;


	first = rand() % 25 + 1;
	do {
		second = rand() % 25 + 1;
	} while (second == first);
	
	do {
		third = rand() % 25 + 1;
	} while (third == first || third == second);
	
	do {
		fourth = rand() % 25 + 1;
	} while (fourth == first || fourth == second || third == fourth);

	cout << "Consestent " << first << endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Consestent " << second << endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Consestent " << third << endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Consestent " << fourth << endl;
	this_thread::sleep_for(chrono::seconds(2));
}