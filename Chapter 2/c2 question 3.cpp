#include <iostream>
using namespace std; 

int main()
{
	int amount; 
	int noOfChocolates;
	int x;  
	int y;
	int coupons = 0;
	
	cout << "Amount $";
	cin >> amount;

	
    noOfChocolates = amount;
	coupons = amount;
	
	do   //a do-while loop is used so that coupons is not assigned 0 if the number is not enough to buy a chocolate.
	{
		x = coupons % 7; 
		y = coupons / 7;
		noOfChocolates += y;
		coupons = x + y; // coupons will take the value it gets at the last interation of the loop before it breaks. 
	} while (coupons >= 7);

	cout << "You can buy " << noOfChocolates << " chocolates \n";
	cout<< "and have " << coupons <<" coupons remaining. \n";

	return 0;
}
