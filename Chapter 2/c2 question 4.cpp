#include <iostream>
using namespace std;

int main()
{
    int dcount = 0;
    for (int i = 3; i <= 100; i++)
    {
        int dcount = 0;

        for (int x = 2; x <= i-1; x++)
        {
            if (i % x == 0)
            {
                dcount++;
                break;
            }
        }

        if (dcount == 0)
            cout << i << " ";
    }
    cout << endl;

    return 0;
}

