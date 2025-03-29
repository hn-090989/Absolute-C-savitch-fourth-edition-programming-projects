#include <iostream>
#include <cmath>
using namespace std;

double standardDeviation(double a[], int count);
int main()
{
    double a[10] = {55.7, 4, 56, 23, 7.6, 4.8};
    cout << "The standard Deviation is: "<< standardDeviation(a, 6);

    return 0;
}
double standardDeviation(double a[], int count) {
    double sum = 0; 

    for (int i = 0; i < count; i++) {
       
        sum  = sum + a[i];
    }

    double average = sum / count;

    double squareSum = 0;

    for (int i = 0; i < count; i++) {

        squareSum = squareSum + pow(a[i] - average, 2);
    }
    double deviation = squareSum / count; 
    deviation = sqrt(deviation);S

    return deviation; 
}

