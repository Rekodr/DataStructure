/*
Author: Recodeo Rekod
Description: this function determines the minimum monthly payment
             based on the principle, rate, and number of months.
             You can use this code as in intro to how to create 
             function and classes in cpp
*/

#include "Amortization.h"             

Amortization::Amortization(){
        minMonthPay = 0;
        rate = 0;
        principle = 0;
      	period = 0; 
}

Amortization::Amortization(const double pPrinciple, const double pPeriod, const double pRate)
       : principle{pPrinciple}, period{pPeriod}, rate{pRate} {

}

double Amortization::getMinPayment(){
	return 0; 
}
