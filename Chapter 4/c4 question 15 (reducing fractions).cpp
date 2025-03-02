#include <iostream>
using namespace std;

int main() {

	char charBox[7];
	int i = 0;
	cout << "Enter up to 6 letters and follow with a dot. \n";
	
	while ((i < 7) && (x != '.')) {
	    cout << "Enter your letter: ";
		cin >> x;
		charBox[i] = x;
		i++;
	}
	int numberUsed = i;
	cout << "Here they are backwards: \n";
	for (i = numberUsed - 1; i >= 0; i--) {
		cout << charBox[i];
		cout << endl;
	}
	return 0;
}
