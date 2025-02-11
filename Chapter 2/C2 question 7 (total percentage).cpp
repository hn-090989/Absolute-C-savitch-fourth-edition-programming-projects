#include <iostream>
using namespace std;

int main()
{
	int N;
	double score, totalScoreRecieved = 0, totalScore = 0, marks = 0;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "How many exercises to input? ";
	cin >> N;
	cout << endl;

	     for (int i = 1; i <= N; ++i)
	     {
			 cout << "Score recieved for exersise " << i <<" ";
	         cin >> score;
	         totalScoreRecieved += score;

	         cout << " Total points possible for exersise " << i <<" ";
	         cin >> marks;
			 cout << endl;
	         totalScore += marks;
         }

    cout << "Your total is " << totalScoreRecieved << " out of " << totalScore;
    cout  << ", or " << (totalScoreRecieved / totalScore)*100 << "% \n";

	return 0
}