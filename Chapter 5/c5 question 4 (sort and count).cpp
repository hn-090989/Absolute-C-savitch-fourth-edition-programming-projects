#include <iostream>
#include <iomanip>
using namespace std;

void sort(int a[], int numberUsed);
void input ()

int main() {

	int a[50] = { -12, 3, -12, 4, 1, 1, -12, 1, -1, 1, 2, 3, 4, 2, 3, -12 };
	int valuesUsed = 16;

	sort(a, valuesUsed);
	cout << "N\tCount" << endl;
	int count = 0; 
	for (int i = 0; i < valuesUsed; i++) {
		count++;
		if (a[i] != a[i + 1]) {
			cout << a[i] << "\t" << count << endl;
			count = 0;
		}

	}
}

int indexOfLargest(const int a[], int startIndex, int numberUsed) {
	int max = a[startIndex];
	int indexOfMax = startIndex;
	for (int index = startIndex + 1; index < numberUsed; index++) {
		if (a[index] > max) {
			max = a[index];
			indexOfMax = index;
		}
	}
	return indexOfMax;
}
void swap(int& v1, int& v2) {
	int temp=v1;
	v1 = v2;
	v2 = temp;
}
void sort(int a[], int numberUsed) {
	int Largest;
	for (int index = 0; index < numberUsed - 1; index++) {
		Largest = indexOfLargest(a, index, numberUsed);
		swap(a[index], a[Largest]);
	}
}

