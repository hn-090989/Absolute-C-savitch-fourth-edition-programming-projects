#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <thread>
using namespace std;

int humanTurn(int humanTotalScore);
int computerTurn(int computerTotalScore);

int main()

{
	int humanTotalScore = 0, computerTotalScore = 0;
	char ans;
	
	cout << "Welcome!! In this programe you will play a game of Pig against a computer.\n";
	this_thread::sleep_for(chrono::seconds(3));
	
	cout << "The rules of the game are simple: \n";
	this_thread::sleep_for(chrono::seconds(2));

	cout << "You will roll a random number from 1 to 6.\nIf you roll a 1, your turn ends and you get 0 points that round.\n"
		"If you roll any other number, you can choose to either HOLD or roll again.\n"
		"When you HOLD, your turn ends.\n"
		"You can keep rolling however many times you want and all your rolls will be added to make the total score for that round\n"
		"BUT beware. as soon as you roll a 1 your total score for that round will become o and your turn ends.\n"
		"To win the game get 100 points before the computer does."<< endl;
	
	cout << "\nWould you like to proceed? (y/n)";
	cin >> ans;

	if (ans == 'n' || ans == 'N') {
		cout << "\nThank you for your time.";
		exit(0);
	}else {
		cout << "\nEnjoy!!!!!" << endl;
		this_thread::sleep_for(chrono::seconds(2));

	}


	int i = 1;

	while (true) {
		
		cout << "\nRound "<< i <<" Fight!!!"<<endl;
		this_thread::sleep_for(chrono::seconds(2));

		humanTotalScore += humanTurn(humanTotalScore);

		cout << "\nComputers Turn! " << endl;
		computerTotalScore += computerTurn(computerTotalScore);

		
		cout << "\nYour total score is: " << humanTotalScore<<endl;
		cout << "The computer's total score is: " << computerTotalScore<<endl;
		this_thread::sleep_for(chrono::seconds(3));


		i++;
	}
	return 0;
}
int humanTurn(int humanTotalScore)
{
	int turnScore=0; 
	char ans;
	

	if (humanTotalScore > 100) {
		return 0;
	}

	int humanRoll;
	do {
		humanRoll= (rand() % 5) + 1;

		if (humanRoll < 2) {
			cout << "You rolled a 1. Your score this round is 0. \n";
			turnScore = 0; 
			this_thread::sleep_for(chrono::seconds(2));
			break; 
		}

		cout << "\nRoll: ";
		this_thread::sleep_for(chrono::seconds(2));
		cout<< humanRoll << endl;
		turnScore += humanRoll;

		cout << "Your score this round is " << turnScore<< endl;
		cout << "Would you like to roll again? (y/n) ";
		cin >> ans;
		cout << endl;

	} while (ans == 'y' || ans == 'Y');
	cout << "\nYour score this round is: " << turnScore << endl;
	this_thread::sleep_for(chrono::seconds(2));


	return turnScore; 
}

int computerTurn(int computerTotalScore)
{
	int turnScore=0, computerRoll;

	if (computerTotalScore > 100) {
		return 0;
	}

	while (turnScore < 20) {
		this_thread::sleep_for(chrono::seconds(1));
		computerRoll = (rand() % 6) + 1;

		cout << "\nRoll: ";
		this_thread::sleep_for(chrono::seconds(2));
		cout << computerRoll;

		if (computerRoll < 2) {
			turnScore = 0;
			cout << "\nThe computer rolled a 1.";
			break;
		}else{
			turnScore += computerRoll;
		}
		
	}
	this_thread::sleep_for(chrono::seconds(2));

	if (turnScore >= 20) {
		cout << "\nHOLD.";
		this_thread::sleep_for(chrono::seconds(2));
	}

	cout << "\nThe computers total score this round was: " << turnScore<<endl; 
	this_thread::sleep_for(chrono::seconds(2));
	

	return turnScore;

}
