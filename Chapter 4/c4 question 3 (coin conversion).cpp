#include <iostream>
using namespace std;

void computeCoin(int coinValue, int& number, int& amountLeft);
bool repeat();

int main(){
    const int QUARTERS= 25, DIMES=10, PENNIES=1;
    int number=0, amountLeft, quarters, dimes, pennies;
    char ans;   
    do {
        cout << "Enter the number of pennies: ";
        cin >> amountLeft;

        computeCoin(QUARTERS, number, amountLeft);
        quarters = number;
        computeCoin(DIMES, number, amountLeft);
        dimes = number;
        computeCoin(PENNIES, number, amountLeft);
        pennies = number;

        cout << quarters << " quarters(s) " << dimes << " dime(s) " << pennies << " penny(pennies)" << endl;

    } while (repeat());
    cout << "Bye!!" << endl;

    return 0;
}
void computeCoin(int coinValue, int& number, int& amountLeft) {
    number = amountLeft/coinValue;
    amountLeft %= coinValue;
}
bool repeat() {
    char ans; 
    cout << "Would you like to run the program again? (y/n) ";
    cin >> ans;
    cout << endl;
    return (ans == 'y' || ans == 'Y');
}

