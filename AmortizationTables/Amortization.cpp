/********************************************************************************************************
@Author: Recodeo Rekod
Description: This class is a basic amortization tool that can calculate the minimum monthly payment
             based on the principle, rate, and number of months.
             You can use this code as in intro to how to create 
             function and classes in cpp
*********************************************************************************************************/

#include "Amortization.h"
         


/**********************************************************************************************************
  This is the loan class constructor. 
  @param: pPrinciple(principle), pRate(rate), pDuration(duration), pExtraPayment(extraPayment)
**********************************************************************************************************/  
Loan::Loan(const double& pPrinciple, const double& pRate, const int& pDuration, std::string pLoanLabel, const double& pExtraPayment)
       : loanLabel(pLoanLabel), extraPayment(pExtraPayment) {     
  setMinPayment(pPrinciple, pRate, pDuration);  
  this->allocatArray(pDuration); 
 	remaining = principle; 
  totalInterestPaid = 0; 
 	totalPaid = 0; 
  month = 0 ;  
}
/******************************************************************************************************* 
    This load destructor(function called when the object load is destroyed)
    @param: none
*******************************************************************************************************/  
Loan::~Loan(){
  //make sure to delete the pointer(array data) in order to avoid mem leaking. 
  this->data = NULL; 
  delete this->data; 
}


/********************************************************************************************************
  This function determines the minimum monthly payment based on the principle, rate, and number of months.
  @param: pPrincipe(principle), pRate(rate per month), pDuration(duration)
  @return: void 
********************************************************************************************************/  
void Loan::setMinPayment(const double& pPrinciple, const double& pRate, const int& pDuration){

  this->rate = pRate/12.0;
  this->principle = pPrinciple;
  this->duration = pDuration; 
  this->minMonthPay = (rate * principle * pow((1 + rate), duration)) / (-1 + pow((1+ rate), duration));  
}

double Loan::getMinPayment (){
  return minMonthPay; 
}

/*******************************************************************************************************
  This function set the extram payement per month.
  @param: pExtraPayment(extraPayment)
  @return: void
********************************************************************************************************/  

void Loan::setExtraPayment(double pExtraPayment){
  this->extraPayment = pExtraPayment; 
}


/*******************************************************************************************************
  This function calculate the amortization information and stores it into the data array
  The varabiable month is increamented in order to keep track on the period.
  @param: none
  @return: totalPaid
*******************************************************************************************************/  
double Loan::monthCalculation(){

     /* 
        the purpose of this loop is repeat the calculation untill the remaining balance(remaining) is zero
     */
  while(this->remaining > 0){
    month++; 
    double principalPaid{0}, interestPaid{0}, paid{0}, totalPrinciplePaid{0};
    this->data[month-1][0] = this->month;  

    interestPaid = this->remaining * this->rate;
    this->data[month-1][1] = interestPaid;

    this->totalInterestPaid += interestPaid;
    this->data[month-1][2] = this->totalInterestPaid; 
          
    /* 
    This check if the remaining balance is less than the monthly payment
    This is possible when extraPayment is not zero.
    If yes, the user only pais the remaining balance and the interest on
    that balance
    */
    if(this->remaining >= (minMonthPay+extraPayment)){
      paid = this->minMonthPay + this->extraPayment;
      this->data[month-1][3] = paid; 
    } 
    else{
      paid = this->remaining + interestPaid; 
      this->data[month-1][3] = paid; 
    }   
     
    this->totalPaid += paid;
    this->data[month-1][4] = this->totalPaid;

    principalPaid = paid - interestPaid;
    this->data[month-1][5] = principalPaid;

    this->remaining -= principalPaid;
    this->data[month-1][6] = this->remaining;

    totalPrinciplePaid = this->principle - this->remaining; 
    this->data[month-1][7] = totalPrinciplePaid; 
  }
 return this->totalPaid; 
}

/******************************************************************************************************* 
    This function print all the amortization payments information for the entire loan period
    @param: none
    @return: void
*******************************************************************************************************/      
void Loan::display(){
  std::cout << std::endl; 
  std::cout << "Loan label: " << this->loanLabel << std::endl;
  std::cout << "Principle: " << this->principle << std::endl;
  std::cout << "Rate(per year): " << this->rate * 12 << std::endl;
  std::cout << "Extrapayment: " << this->extraPayment << std::endl; 
  std::cout << std::endl; 

  std::cout << std::setw(5) << "Month"  << std::setw(20) << "Paid" << std::setw(20)  << "Interest"  
  << std::setw(20) << "Principle" << std::setw(20)  << "Paid Balance"  << std::setw(20) << "Ending Balance" 
  << std::setw(20) << "Total Interest" << std::setw(20)  << "Total" << std::endl;  
  
  this->monthCalculation(); 

  for(int i=0;i < this->month; i++){
    this->printMonthPayment(i);
  }
}

/******************************************************************************************************* 
    This function print all the amortization payments information for only one month
    @param: m(month)
    @return: void
*******************************************************************************************************/  
void Loan::printMonthPayment(int m){

   /* formatting output and printing on the screen*/
  std::cout  << std::setprecision(0)<< std::fixed << std::setw(5) << this->data[m][0] << std::setprecision(2) 
  << std::setw(20)<< this->data[m][3] << std::setw(20) << this->data[m][1] << std::setw(20) << this->data[m][5] 
  << std::setw(20) << this->data[m][7] << std::setw(20) << this->data[m][6] << std::setw(20) << this->data[m][2] 
  << std::setw(20) << this->data[m][4] << std::endl ; 
}

/******************************************************************************************************* 
    This function allocate the internal data array to the needed size
    @param: duration(array size)
    @return: bool
*******************************************************************************************************/  
bool Loan::allocatArray(int duration){
  this->data = new double * [duration];
  for( int i=0; i<duration; i++) this->data[i] = new double [8] ; 
  return true; 
}

/******************************************************************************************************
	This function calculate how much the user has save on the entire loan.
	@param: none
	@return: saving
******************************************************************************************************/	
double Loan::getSaving(){
  double I = duration*this->minMonthPay - this->principle; 
  double saving = (principle + I) - this->totalPaid;
  return saving;
}