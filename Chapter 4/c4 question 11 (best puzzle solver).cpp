#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void aaronShot(int& charlie,int& bob);
void bobShot(int& charlie,int& aaron);
void charlieShot(int& bob,int& aaron);
void round(int & chcount, int& aacount, int & bobcount);

int main() {
	srand(time(0));
	int chcount=0, aacount=0, bobcount=0;// initialize or it will assign a random value.

	for (int i = 1; i <= 10000; i++) {
		round(chcount, aacount, bobcount);
	}
	cout << "Aaron won " << aacount << "/10,000 duels or " << (aacount / 10000.0) * 100 << "%"<<endl;
	return 0;
}
void aaronShot(int &charlie, int &bob) {

	int hit = rand() % 3;
	if (charlie == 1 && hit == 2) {
		charlie--;
	}
	else if(bob==1 && hit == 2) {
		bob--;
	}
}
void bobShot(int& charlie, int& aaron) {
	
	int hit = rand() % 2;
	if (charlie == 1 && hit == 1) {
			charlie--;
	}
	else if (aaron == 1 && hit == 1) {
			aaron--;
	}
}
void charlieShot(int &bob, int &aaron) {
	
	if (bob == 1) {
		bob--;
	}
	else if (aaron == 1) {
		aaron--;
	}
}
void round(int& chcount, int& aacount, int& bobcount) {
	
	int aaron = 1, charlie = 1, bob = 1;
	int c = 0;
	while (true) {
		if (c > 0) {
			if (aaron == 1) {
				aaronShot(charlie, bob);
			}
		}
		if (bob == 1) {
			bobShot(charlie, aaron);
		}
		if (charlie == 1) {
			charlieShot(bob, aaron);
		}
		c++;
		

		if (charlie == 0 && bob ==0 ) {
			aacount++;
			break;
		}
		else if (aaron ==0 && bob ==0) {
			chcount++;
			break;
		}
		else if (charlie == 0 && aaron == 0) {
			bobcount++;
			break;
		}
	}
}
