#include <iostream>
using namespace std; 

int main()
{
    double farenheight=0, celsius; 
    celsius = 100;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    while (farenheight != celsius)
    {
        celsius--;
        farenheight = celsius * (9.0 / 5) + 32;
    } 
    cout << farenheight; 

    return 0;
}
