/********************************************************************************************************
@Author: Recodeo Rekod
Description: This class is a basic amortization tool that can calculate the minimum monthly payment
             based on the principle, rate, and number of months.
             You can use this code as in intro to how to create 
             function and classes in c++
*********************************************************************************************************/

#ifndef _AMORTIZATION_H
#define _AMORTIZATION_H

#include <string>
#include <iostream>
#include <cmath> 
#include <iomanip>   


class Loan{
    
      public:
      		Loan(const double& pPrinciple, const double& pRate, const int& pDuration, std::string pLoanLabel="user", const double& pExtraPayment=0);
          ~Loan();
          void setMinPayment(const double& pPrinciple, const double& pRate, const int& pDuration);
          double getMinPayment();
          void setExtraPayment(double pExtraPayment);
      		double monthCalculation();
          void printMonthPayment(int m);
          double getSaving();                                                                                                           
      		void display(); 

      private:
          std::string loanLabel; 
      		double minMonthPay;
      		double rate;
      		double principle;
      		int duration;
      		double remaining;
      		double totalInterestPaid;
      		double totalPaid; 
      		double extraPayment;
          double** data;   
      		int month; 
          bool allocatArray(int duration); 
};

#endif 