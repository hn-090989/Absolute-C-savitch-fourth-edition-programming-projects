#include <iostream>
using namespace std;

void deleteRepeats(char a[], int size);
int main() {
	char a[10];
	a[0] = 'b';
	a[1] = 'm';
	a[2] = 'b';
	a[3] = 'c';
	a[4] = 'm';
	a[5] = 'b';
	int size = 6;

	deleteRepeats(a, size);
	for (int i=0; i < size  ; i++)
		cout << a[i];
	return 0;
}
void deleteRepeats(char a[], int size) {
	for (int i = 0; i < size; i++) {
		for (int x = i + 1; x < size ;x++) {
			if (a[i] == a[x]) {
				a[x] = 0;
			}
	
		}
	}
	for (int y = 0; y < size; y++) {
		if (a[y] == 0) {
			a[y] = a[y + 1];
			
			a[y + 1] = 0;
			size--;
		}
	}

}
