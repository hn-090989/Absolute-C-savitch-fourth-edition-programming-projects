#include <iostream>
using namespace std;

int main()
{
	
	for (int T=0 ; T <= 9; T++) 
	{
		
		for ( int G=0; G <= 9; G++) // initialise inside loop or it wont reset 
		{
			for (int O=0; O<=9 ; O++)
			{
				for (int D=0; D<=9  ; D++)
				{
					if ((4 * T * O *O) == (G* O*O* D) && T != G && T != O && T != D && G != O && G != D && O != D) 
						cout << "T: " << T << " " << "O: " << O << " " << "G: " << G << " " << "D: " << D << endl;
				
					
				}
					

			}
			
		}
	}
	
	return 0;
}

