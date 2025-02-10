#include <iostream>
#include <cstdlib>
using namespace std;

double probabilityOfWinning(int seed);

int main()
{
	int houseSeed, homeSeed;
	
	homeSeed = 54;
	houseSeed = 16;
	cout <<"Your probablity of winning a game is: "<< probabilityOfWinning(homeSeed) <<endl;

	if (probabilityOfWinning(homeSeed) > probabilityOfWinning(houseSeed))
		cout << "You are more likely to win. " << endl;
	else
		cout << "The house is more likely to win." << endl;
	
	return 0;
}
double probabilityOfWinning(int seed)
{
	srand(seed);
	int comeOutRoll, thePoint, win=0,loss=0,x;

	for (int i = 1; i <= 10000; i++) {

		comeOutRoll = (rand()) % 13;
		if (comeOutRoll == 7 || comeOutRoll == 11){
			win += 1;
		}
		else{
			thePoint = comeOutRoll;
			while (true)
			{
				x = (rand() % 11)+2;
				if (x == thePoint) {
					win += 1;
					break; 
				}

				if (x == 7) {
					loss+=1;
					break;
				}

			}
		}
	}
	 return (static_cast<double>(win) / (win + loss));
	
}

