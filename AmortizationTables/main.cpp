/*
Author: Recodeo Rekod
Description: this is the main: note that cpp requires a main function
*/

#include "Amortization.h"
#include <iostream> 

#define _DEGUB_ 0

using namespace std; 


/****************************************************************************************** 
  The main function here is used to create a Loan object and perfome basic operations on it
******************************************************************************************/  
int main(){

    double principle{0}; 
    double rate{0};
    int period{0};
    double extraPayment{0}; 
    string label; 
    cout << endl; 
    
    /*getting the user input*/
    cout << "Enter a label for your loan: ";
    cin >> label; 
    cout << "Please enter a principle, annual interest rate(Ex: 0.06 for 6%%) the duration(in month)" << endl; 
    cin >> principle >> rate >> period ;
    
    cout << "If you will make ExtraPayment please input your ExtraPayment: " ; 
    cin >> extraPayment;

    /* the creation of the load object in done here. */ 
    Loan loan(principle, rate, period, label, extraPayment);
    loan.display(); 
    cout << endl; 

    /*if the user have input extra payement this will show how much was saved. */
    if(extraPayment > 0){
        cout << "Using an ExtraPayment of: " << extraPayment << ", you have saved: " << loan.getSaving() << endl; 
    }

    //The cause below is for testing purpose
    #if _DEGUB_
    cout << "Testing the monthly payment function." << endl;
    cout << "Test 1: P=150000 r=0.04 n=360" << endl; 
    Loan test1(150000, 0.04, 360); 
    cout << test1.getMinPayment() << endl ; 
     cout << "Test 2: P=50000 r=0.03 n=120" << endl; 
    Loan test2(15000, 0.03, 120); 
    cout << test2.getMinPayment() << endl ; 

    Loan test3(15000, 0.06, 36);  
    test3.display(); 

    cout << endl; 
    cout << test3.getSaving() << endl;
    #endif

    
	return 0; 
}