#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
   // Declare variables for transactions of frozen-yogurt
   int stamps, freeYogurt, yogurtInt, outOfRange;
   string userInputStr, yogurtStr, optionYogurt;
   const string INDENT = "   ";

   stamps = 0;
   freeYogurt = 7;
   outOfRange = 15; //maximum # yogurt each order

   // Main Loop for cash register
   while (!(userInputStr[0] == 's' || userInputStr[0] == 'S'))
   {
      // First main menu for command process
      cout << "Menu: " << endl;
      cout << INDENT << "P (process Purchase)" << endl;
      cout << INDENT << "S (Shut down)" << endl << endl;

      // Get first command for transaction
      cout << INDENT << "Your Choice: ";
      getline(cin,userInputStr); // user will input command P/S, s/p, words

      // Error testing if user input is not p/P or s/S
      if (!(userInputStr[0] == 'p' || userInputStr[0] == 'P')
          && (!(userInputStr[0] == 's' || userInputStr[0] == 'S')))
      {
         cout << endl << "*** Use P or S, please. ***" << endl << endl;
      }

      // If user wants to start process Purchase
      if (userInputStr[0] == 'p' || userInputStr [0] == 'P')
      {
         // Checks how many credits customer has.
         // Award Transaction : Customer qualify for free Yogurt
         if (stamps >= freeYogurt)
         {
            cout << endl << "You qualify for a free yogurt. Would you like to "
            << "use your credits? (Y or N) ";
            getline(cin,optionYogurt);

            // If function for customer use of credit (No)
            if (optionYogurt[0] == 'n' || optionYogurt[0] == 'N')
            {
               //jumps to Normal Transactions
            }
            // If function for customer use of credit (Yes)
            else if (optionYogurt[0] == 'y' || optionYogurt[0] == 'Y')
            {
               stamps -= freeYogurt;
               cout << endl << "You have just used 7 credits and have " << stamps
               << " left." << endl << "Enjoy your free yogurt." << endl << endl;
               continue;
            }
            // Error testing if user input is not y/Y or n/N
            else if (!(userInputStr[0] == 'y' || userInputStr[0] == 'Y')
                && (!(userInputStr[0] == 'n' || userInputStr[0] == 'N')))
            {
               cout << endl << "*** Use Y or N, please. ***" << endl << endl;
               continue;
            }
         }
         // Normal Transaction
         cout << endl << "How many yogurts would you like to buy? ";
         getline(cin,yogurtStr);
         istringstream(yogurtStr) >> yogurtInt;

         // If user input exceed maximum # yogurt
         if (yogurtInt > outOfRange)
         {
            cout << endl << "*** Out-of-Range # yogurts. ***" << endl << endl;
            continue;
         }
         // If user input zero or negative number
         if (yogurtInt < 1)
         {
            cout << endl << "*** Invalid # yogurts. ***" << endl << endl;
            continue;
         }
         // Number of yogurt purchased add to variable stamps
         if (yogurtInt >= 1)
         {
            stamps += yogurtInt;
            cout << endl << INDENT << "You just earned " << stamps << " stamps"
            << " and have a total of " << stamps << " to use" << endl << endl;
         }

      }
   }
   // If function is user want to exit/shut down the program
   if (userInputStr[0] == 's' || userInputStr [0] == 'S')
   {
      cout << endl;
      return 0;
   }
}

/*-------------------------------paste of run 1---------------------------------
Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: p

How many yogurts would you like to buy? 4

   You just earned 4 stamps and have a total of 4 to use

Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: purchase

How many yogurts would you like to buy? -3

*** Invalid # yogurts. ***

Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: 5

*** Use P or S, please. ***

Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: P

How many yogurts would you like to buy? 7

   You just earned 11 stamps and have a total of 11 to use

Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: Purchase

You qualify for a free yogurt. Would you like to use your credits? (Y or N) n

How many yogurts would you like to buy? 2

   You just earned 13 stamps and have a total of 13 to use

Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: process

You qualify for a free yogurt. Would you like to use your credits? (Y or N) y

You have just used 7 credits and have 6 left.
Enjoy your free yogurt.

Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: Process

How many yogurts would you like to buy? 0

*** Invalid # yogurts. ***

Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: PURCHASE

How many yogurts would you like to buy? 1

   You just earned 7 stamps and have a total of 7 to use

Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: PROCESS

You qualify for a free yogurt. Would you like to use your credits? (Y or N) Y

You have just used 7 credits and have 0 left.
Enjoy your free yogurt.

Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: T

*** Use P or S, please. ***

Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: panther

How many yogurts would you like to buy? 9

   You just earned 9 stamps and have a total of 9 to use

Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: PANTHER

You qualify for a free yogurt. Would you like to use your credits? (Y or N) N

How many yogurts would you like to buy? 5

   You just earned 14 stamps and have a total of 14 to use

Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: p

You qualify for a free yogurt. Would you like to use your credits? (Y or N) Y

You have just used 7 credits and have 7 left.
Enjoy your free yogurt.

Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: S

Program ended with exit code: 0
---------------------------------paste of run 2---------------------------------
Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: 12039

*** Use P or S, please. ***

Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: PARIS

How many yogurts would you like to buy? 15

   You just earned 15 stamps and have a total of 15 to use

Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: p

You qualify for a free yogurt. Would you like to use your credits? (Y or N) N

How many yogurts would you like to buy? 17

*** Out-of-Range # yogurts. ***

Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: process

You qualify for a free yogurt. Would you like to use your credits? (Y or N) YES

You have just used 7 credits and have 8 left.
Enjoy your free yogurt.

Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: p

You qualify for a free yogurt. Would you like to use your credits? (Y or N) NO

How many yogurts would you like to buy? -93

*** Invalid # yogurts. ***

Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: P

You qualify for a free yogurt. Would you like to use your credits? (Y or N) 739

*** Use Y or N, please. ***

Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: SHUT DOWN

Program ended with exit code: 0
------------------------------paste of run 3------------------------------------
Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: -5

*** Use P or S, please. ***

Menu: 
   P (process Purchase)
   S (Shut down)

   Your Choice: s

Program ended with exit code: 0
--------------------------------end of run------------------------------------*/

