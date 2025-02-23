#include <iostream>
#include <cstdlib>  
#include <ctime>
using namespace std;

int doorSelection();
int prizeDoor();
int Sswitch (int revealedDoor, bool& change, int doorSelection);
void WinOrLoss (bool& win, bool&change);
int revealedDoor(int prizeDoor, int doorSelection);

int main() {
	srand(time(0));
	int withSwitchW = 0, withoutSwitchW = 0, withoutSwitchL=0, withSwitchL=0;

	for (int i = 1; i <= 10000; i++) {
		bool win, change;
		WinOrLoss(win, change);

		if (win == true && change == false)
			withoutSwitchW ++;
		else if (win == true && change == true)
			withSwitchW ++;
		else if (win == false && change == false)
			withoutSwitchL ++;
		else if (win == false && change == true)
			withSwitchL++;
	}
	cout << "Switching: "<<endl;
	cout << "Matches won: " << withSwitchW <<endl;
	cout << "Mathces lost: " << withSwitchL << endl;
	cout << "Staying: " <<endl;
	cout << "Matches won: " << withoutSwitchW << endl;
	cout << "Mathces lost: " << withoutSwitchL << endl;
	cout << endl;
	
	if (withoutSwitchW > withSwitchW) {
		cout << "You are more likely to win without switching";
	}
	if (withoutSwitchW < withSwitchW) {
		cout << "You are more likely to win if you switch";

	}
	cout << endl;
	return 0;
}


int doorSelection () {

	return rand() % 3 + 1;
}
int prizeDoor (){

	return rand() % 3 + 1;
}
int revealedDoor(int prizeDoor, int doorSelection) {
	int x;
	do {
		x= rand() % 3 + 1;
	} while (x == prizeDoor || x == doorSelection);
	return x;
}
int Sswitch(int revealedDoor, bool& change, int doorSelection) {
	int x; 
	do {
		x = rand() % 3 + 1;
	} while (x == revealedDoor);

	if (doorSelection == x)
		change = false;
	else
		change = true; 
	
	return x;
}
void WinOrLoss(bool &win, bool& change) {
	
	int prize , door , revealed;

	door = doorSelection();
	prize = prizeDoor();
	revealed = revealedDoor(prize, door);
	door = Sswitch(revealed, change, door);

	if (door == prize)
		win = true;
	else
		win = false;
}
