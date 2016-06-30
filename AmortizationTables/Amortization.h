/*
Author: Recodeo Rekod
Description: this function determines the minimum monthly payment
             based on the principle, rate, and number of months.
             You can use this code as in intro to how to create 
             function and classes in cpp
*/


#ifndef _AMORTIZATION_H
#define _AMORTIZATION_H

class Amortization{
      
      public:
      		Amortization(); 
      		Amortization(const double pPrinciple =0, const double pPeriod=0, const double pRate=0 );
      		double getMinPayment();
      private:
      		double minMonthPay;
      		double rate;
      		double principle;
      		double period;     
};

#endif 