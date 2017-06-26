#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// method prototypes
void statePurpose();
void getInputComputAndShowPayment();
void sayGoodbye();

int main()
{
   statePurpose();
   getInputComputAndShowPayment();
   sayGoodbye();
}

// gives an overview to user
void statePurpose()
{
   string instructions;

   instructions =
   "\nThe following program will calculate the \n"
   "monthly payment  required for a loan of D dollars \n"
   "over a period of Y years at an annual \n"
   "interest rate of R%.\n";
   cout << instructions;
}

// does all the work - gets input, computes and reports answer
void getInputComputAndShowPayment()
{
   string prompt;
   double dblPrincipal, dblRate, dblYears, dblMoRt, dblMonths;
   double dblTemp, dblPmt;

   // get principal
   prompt = "\nEnter amount of the loan. (only use numbers, \n"
   "please, no commas or characters like '$')\n"
   "Your loan amount: ";
   cout << prompt;
   cin >> dblPrincipal;

   // get interest
   prompt = "\nNow enter the interest rate (If the quoted rate is 6.5%, \n"
   "for example, enter 6.5 without the %.)\n"
   "Your annual interest rate: ";
   cout << prompt;
   cin >> dblRate;

   // get length of loan
   prompt = "\nEnter term of the loan in years: ";
   cout << prompt;
   cin >> dblYears;

   // convert years to months
   dblMonths = dblYears * 12;

   // convert rate to decimal and months
   dblMoRt = dblRate / (100 * 12);

   // use formula to get result
   dblTemp = pow(1 + dblMoRt, dblMonths);
   dblPmt = dblPrincipal * dblMoRt * dblTemp
   / ( dblTemp - 1 );

   cout.setf(ios::fixed);
   cout.precision(2);
   cout <<  "\nYour Monthly Payment: " << dblPmt << endl;
}

// sign off
void sayGoodbye()
{
   string signoff;
   signoff =
   "\nThanks for using the Foothill Mortgage Calculator. \n"
   "We hope you'll come back and see us again, soon.\n\n";
   cout << signoff;
}