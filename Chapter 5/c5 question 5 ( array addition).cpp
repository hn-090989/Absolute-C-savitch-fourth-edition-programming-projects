#include <iostream>
#include <string>
using namespace std; 

const int DIGITS = 20;

void input(char number[], int& spacesUsed);
void convert(char number[], int num[], const int spacesUsed);
void reverse(int number[], int size);
void addition(int sum[], int number1[], int number2[], int larger);
void printArray(int arr[], int size); // Helper function to display results

int main() {
    char num1[DIGITS] = { 0 }, num2[DIGITS] = { 0 };
    int number1[DIGITS] = { 0 }, number2[DIGITS] = { 0 }, sum[DIGITS] = { 0 };
    int space1 = 0, space2 = 0;

    cout << "Enter 2 numbers, one digit at a time. Mark the end with '#'.\n";

    cout << "First number: ";
    input(num1, space1);
    convert(num1, number1, space1);
    reverse(number1, space1);

    cout << "Second number: ";
    input(num2, space2);
    convert(num2, number2, space2);
    reverse(number2, space2);

    int larger = (space1 > space2) ? space1 : space2; // Correct placement
    addition(sum, number1, number2, larger);

    cout << "Sum: ";
    printArray(sum, larger + 1); // Display the result
}
void input(char number[], int& spacesUsed) {
    int i = 0;
    char character;

    while (i < DIGITS) {  // Limit input to array size
        cin >> character;
        if (character == '#') break;

        number[i] = character;
        spacesUsed++;
        i++;
    }
}
void convert(char number[], int num[], const int spacesUsed) {
    for (int i = 0; i < spacesUsed; i++) {
        num[i] = number[i] - '0';  
    }
}
void reverse(int number[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = number[i];
        number[i] = number[size - 1 - i];
        number[size - 1 - i] = temp;
    }
}
void addition(int sum[], int number1[], int number2[], int larger) {
    int carry = 0;
    for (int i = 0; i < larger; i++) {
        int add = number1[i] + number2[i] + carry;
        sum[i] = add % 10;
        carry = add / 10;
    }

    if (carry > 0) { 
        sum[larger] = carry;
    }
}
void printArray(int arr[], int size) {
    bool leadingZero = true;
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] != 0) leadingZero = false; 
        if (!leadingZero) cout << arr[i];
    }
    cout << endl;
}

