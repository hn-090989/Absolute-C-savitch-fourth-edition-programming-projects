#include <iostream>
#include <cmath>
using namespace std; 

int Cartesian(int reviews[4][7], int review1, int review2, int review3, int movie1,int movie2,int movie3);
void output(int reviews[4][7], int movie1, int movie2, int movie3, int reviewer);
inline void MovieInput(int &value);
inline void ReviewInput(int &value);

int main() {
	int reviews[4][6] = { {3,1,5,2,1,5},{4,2,1,4,2,4},{3,1,2,4,4,1},{ 5,1,4,2,4,2 } };

	int review1 = 0, review2 = 0, review3 = 0; 
	int movie1 = 0, movie2 = 0, movie3 = 0; 

	cout << "This program predicts your reviews for movies you havent watched based on your reviews for the ones you have watched"
		<< "Below is a list of a movie and the number assigned to it" << endl;
	cout << "How to train your dragon: 100" << endl
		<< "Shreak 2: 101" << endl
		<< "Puss in boots: 102" << endl
		<< "Spiderman Homecoming: 103" << endl
		<< "Kung fuu Panda: 104" << endl
		<< "Frozen: 105" << endl;
	cout << "You can enter the numbers associated with 3 movies and rate it from 1(terrible) to 5(excellent)\n" << endl;
	int reviewer = 0;
	MovieInput(movie1);
	ReviewInput(review1);


	MovieInput(movie2);
	ReviewInput(review2);

	MovieInput(movie3);
	ReviewInput(review3);

	reviewer = Cartesian(reviews, review1, review2, review3, movie1, movie2, movie3);
	output(reviews, movie1, movie2, movie3, reviewer);

}
inline void MovieInput(int &value) {
	static int number = 1;

	cout << "Movie " << number << " ";
	cin >> value;

	while (value < 100 || value > 105) {
		cout << "Please choose from the set movies.";
		cin >> value; 
	}
	number++;
}
inline void ReviewInput(int &value){ 
	cout << "Review: "; 
	cin >> value;
	while (value < 1 || value > 5) {
		cout << "Rating must be between 1 and 5:";
		cin >> value;
	}
	cout << endl;
}
int Cartesian(int reviews[4][7], int review1, int review2, int review3, int movie1, int movie2, int movie3) {
	movie1 = movie1 - 100; 
	movie2 = movie2 - 100;
	movie3 = movie3 - 100;

	int distance[4] = { 0 };
	for (int x = 0; x < 4; x++) {
		int diff1 = reviews[x][movie1] - review1;
		int diff2 = reviews[x][movie2] - review2;
		int diff3 = reviews[x][movie3] - review3;
		distance[x] = pow(diff1, 2) + pow(diff2, 2) + pow(diff3, 2);;
	}
	int reviewer = 0 ;
	int leastDistance  =  distance[0];
	for (int m = 1; m < 4 ; m++) {
		if (distance[m] < leastDistance) {
			leastDistance = distance[m];
			reviewer = m;
		}
	}
	return reviewer;
}
void output(int reviews[4][7], int movie1, int movie2, int movie3, int reviewer) {
	movie1 = movie1 - 100;
	movie2 = movie2 - 100;
	movie3 = movie3 - 100;

	for (int i = 0; i < 6; i++) {
		if (i == movie1 || i == movie2 || i == movie3) {
			continue;
		}
		cout <<"Movie "<< i+100 << " :" << reviews[reviewer][i] << endl;
	}
}
