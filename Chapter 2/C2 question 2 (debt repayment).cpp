
#include <iostream>
using namespace std;

int main()
{
    const double  PRICE = 1000;
    const double INTEREST = 0.015; // Interest rate
    const double MONTHLY_PAYMENT = 50; 
    double debt;
   
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    double monthlyInterest= 0;
    int totalMonths = 0; // To measure the total number of months it will take to repay the debt
    double totalInterest = 0;
    debt = PRICE;
    int n = 1;
   while (debt > 0)
   {
       cout << " >> Month " << n << endl;
       n++; 

       monthlyInterest = debt * INTEREST;
       cout << "The interest payed this month is: $" << monthlyInterest << endl;

       totalInterest += monthlyInterest;

       debt = debt - (50 - monthlyInterest);

       if (debt < 0)
           cout << "The remaining debt is $0. You have $" << -debt << " remaining \n";
       else 
            cout << "The remaining debt is: $" << debt << endl;
       
       totalMonths++;
 
   } 
        
     cout << "\n It will take " << totalMonths << " months " << "to repay the loan. \n";
     cout << "You will have payed $"<< totalInterest << " in interest throught this period. \n";

     return 0;
    
}
