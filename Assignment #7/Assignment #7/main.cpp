#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

//Class Prototype(s) TripleString--------------------------
class TripleString
{
   private:
   string string1, string2, string3;

   public:
   // static constants
   static const int MIN_SPACE;
   static const int MAX_SPACE;
   static const int MIN_SEVEN;
   static const int MAX_SEVEN;
   static const int MIN_BAR;
   static const int MAX_BAR;
   static const int MIN_CHERRIES;
   static const int MAX_CHERRIES;
   static const int MIN_BET;
   static const int MAX_BET;
   static const int MAX_LEN;
   static const int MIN_LEN;
   static const string DEFAULT_STRING;
   static const string PROB_ONE;
   static const string PROB_TWO;
   static const string PROB_THREE;
   static const string PROB_FOUR;

   // Default constructor
   TripleString();

   // 3-parameter constructor
   TripleString(string string1, string string2, string string3);

   // Class Prototypes
   bool setString1(string theString1);
   bool setString2(string theString2);
   bool setString3(string theString3);
   bool validString(string str); // string legality
   string getString1(), getString2(), getString3(), toString();
};

//Initialize static constants
static const int MIN_SPACE = 0;
static const int MAX_SPACE = 70;
static const int MIN_SEVEN = 71;
static const int MAX_SEVEN = 220;
static const int MIN_BAR = 221;
static const int MAX_BAR = 600;
static const int MIN_CHERRIES = 601;
static const int MAX_CHERRIES = 1000;
static const int MIN_BET = 0;
static const int MAX_BET = 50;
const int TripleString::MAX_LEN = 50;
const int TripleString::MIN_LEN = 1;
const string TripleString::DEFAULT_STRING = "(undefined)";
const string PROB_ONE = "space";
const string PROB_TWO = "7";
const string PROB_THREE = "BAR";
const string PROB_FOUR = "cherries";

//Global-Scope method protoypes------------------------------
int getBet();
string randString();
TripleString pull();
int getPayMultiplier (TripleString thePull);
void display(TripleString thePull, int winnings);


//Client Main() definition-----------------------------------
int main()
{
   TripleString thePull;

   int userBet, winnings;
   bool validated;

   validated = false;

   while(!validated) // Machine loop getBet() dependent
   {
      userBet = getBet();
      if (userBet != 0)
      {
         thePull = pull();
         winnings = (getPayMultiplier(thePull) * userBet);
         display(thePull, winnings);
      }
      else // this condition is bet == 0
      {
         cout << "Thank you for using Casino IdaBagus" << endl;
         return 1;
      }
   }
}

//Global-Scope method definition------------------------------
int getBet() // Get user bet -- make sure it's within range
{
   int userBet;

   do
   {
      cout << "How much would you like to bet (1 - 50) or 0 to quit? ";
      cin >> userBet;
   }
   while (userBet < MIN_BET || userBet > MAX_BET);

   return userBet;
}

TripleString pull()
{
   TripleString gameStart;

   gameStart.setString1(randString());
   gameStart.setString2(randString());
   gameStart.setString3(randString());

   return gameStart;
}

string randString()
{
   string result;
   int randomInteger;
   randomInteger = rand() % 1000 + 1; // generate 1 - 1000

   if (randomInteger > MIN_SPACE && randomInteger <= MAX_SPACE)
      result = PROB_ONE; // 7% of 1000
   else if (randomInteger >= MIN_SEVEN && randomInteger <= MAX_SEVEN)
      result = PROB_TWO;  // 15% of 1000
   else if (randomInteger >= MIN_BAR && randomInteger <= MAX_BAR)
      result = PROB_THREE; // 38% of 1000
   else if (randomInteger >= MIN_CHERRIES && randomInteger <= MAX_CHERRIES)
      result = PROB_FOUR; // 40% of 1000

   return result;
}

int getPayMultiplier(TripleString thePull)
{
   string string1, string2, string3;
   int multiplier;
   multiplier = 0;

   string1 = thePull.getString1();
   string2 = thePull.getString2();
   string3 = thePull.getString3();

   if (string1 == PROB_FOUR && string2 != PROB_FOUR)
      multiplier = 5;
   else if (string1 == PROB_FOUR && string2 == PROB_FOUR
            && string3 != PROB_FOUR)
      multiplier = 15;
   else if (string1 == PROB_FOUR && string2 == PROB_FOUR
            && string3 == PROB_FOUR)
      multiplier = 30;
   else if (string1 == PROB_THREE && string2 == PROB_THREE
            && string3 == PROB_THREE)
      multiplier = 50;
   else if (string1 == PROB_TWO && string2 == PROB_TWO
            && string3 == PROB_TWO )
      multiplier = 100;

   return multiplier;
}

void display (TripleString thePull, int winnings)
{
   string string1, string2, string3;

   string1 = thePull.getString1();
   string2 = thePull.getString2();
   string3 = thePull.getString3();

   cout << "whhhhhrrrrr... and your pull is..." << endl;
   cout << thePull.toString() << endl;

   if (winnings == 0)
      cout << "Sorry, you lose." << endl << endl;
   else
      cout << "Congratulations, you win: $" << winnings << endl <<endl;
}

//Class Method Definitions-----------------------------------

// TripleString Class Methods
// Default constructor
TripleString::TripleString()
{
   string1 = DEFAULT_STRING;
   string2 = DEFAULT_STRING;
   string3 = DEFAULT_STRING;

}

// 3-parameters constructor
TripleString::TripleString(string string1, string string2, string string3)
{
   if ( !setString1(string1) )
   string1 = DEFAULT_STRING;
   if ( !setString2(string2) )
   string2 = DEFAULT_STRING;
   if ( !setString3(string3) )
   string3 = DEFAULT_STRING;
}

// Private helper method validString() for string legality
bool TripleString::validString(string str)
{
   if (str.length() < MIN_LEN || str.length() > MAX_LEN)
   return false;
   // else

   str = str;
   return true;
}

// Mutators "set" methods
bool TripleString::setString1(string theString1)
{
   if ( !validString(theString1) )
   return false;
   // else
   string1 = theString1;
   return true;

}

bool TripleString::setString2(string theString2)
{
   if ( !validString(theString2) )
   return false;
   // else
   string2 = theString2;
   return true;

}

bool TripleString::setString3(string theString3)
{
   if ( !validString(theString3) )
   return false;
   // else
   string3 = theString3;
   return true;

}

// Returns a string which contains all the information (3 strings)
// of the TripleString object.
string TripleString::toString()
{
   string allStrings;

   allStrings = " " + string1 + " " + string2 + " " + string3;
   return allStrings;

}

// Accessor "get" methods
string TripleString::getString1()
{
   return string1;
}
string TripleString::getString2()
{
   return string2;
}
string TripleString::getString3()
{
   return string3;
}



/*-----------------------------paste of run----------------------------
How much would you like to bet (1 - 50) or 0 to quit? 2
whhhhhrrrrr... and your pull is...
 cherries BAR 7
Congratulations, you win: $10

How much would you like to bet (1 - 50) or 0 to quit? 124
How much would you like to bet (1 - 50) or 0 to quit? 1000
How much would you like to bet (1 - 50) or 0 to quit? 12038912
How much would you like to bet (1 - 50) or 0 to quit? 20
whhhhhrrrrr... and your pull is...
 cherries cherries BAR
Congratulations, you win: $300

How much would you like to bet (1 - 50) or 0 to quit? 3
whhhhhrrrrr... and your pull is...
 BAR cherries cherries
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 7
whhhhhrrrrr... and your pull is...
 cherries BAR 7
Congratulations, you win: $35

How much would you like to bet (1 - 50) or 0 to quit? 8
whhhhhrrrrr... and your pull is...
 BAR space cherries
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 3
whhhhhrrrrr... and your pull is...
 BAR BAR cherries
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 9
whhhhhrrrrr... and your pull is...
 cherries cherries BAR
Congratulations, you win: $135

How much would you like to bet (1 - 50) or 0 to quit? 10
whhhhhrrrrr... and your pull is...
 7 cherries 7
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 11
whhhhhrrrrr... and your pull is...
 BAR cherries 7
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 32
whhhhhrrrrr... and your pull is...
 BAR cherries BAR
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 23
whhhhhrrrrr... and your pull is...
 7 cherries BAR
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 94
How much would you like to bet (1 - 50) or 0 to quit? 2
whhhhhrrrrr... and your pull is...
 BAR cherries cherries
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 1
whhhhhrrrrr... and your pull is...
 cherries 7 BAR
Congratulations, you win: $5

How much would you like to bet (1 - 50) or 0 to quit? 4
whhhhhrrrrr... and your pull is...
 cherries cherries cherries
Congratulations, you win: $120

How much would you like to bet (1 - 50) or 0 to quit? 20
whhhhhrrrrr... and your pull is...
 BAR BAR BAR
Congratulations, you win: $1000

How much would you like to bet (1 - 50) or 0 to quit? 30
whhhhhrrrrr... and your pull is...
 cherries BAR 7
Congratulations, you win: $150

How much would you like to bet (1 - 50) or 0 to quit? 12
whhhhhrrrrr... and your pull is...
 7 BAR space
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 8
whhhhhrrrrr... and your pull is...
 7 cherries cherries
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 30
whhhhhrrrrr... and your pull is...
 cherries BAR 7
Congratulations, you win: $150

How much would you like to bet (1 - 50) or 0 to quit? 37
whhhhhrrrrr... and your pull is...
 7 BAR cherries
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 50
whhhhhrrrrr... and your pull is...
 cherries cherries BAR
Congratulations, you win: $750

How much would you like to bet (1 - 50) or 0 to quit? 3
whhhhhrrrrr... and your pull is...
 space cherries cherries
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 2
whhhhhrrrrr... and your pull is...
 cherries BAR BAR
Congratulations, you win: $10

How much would you like to bet (1 - 50) or 0 to quit? 7
whhhhhrrrrr... and your pull is...
 cherries BAR cherries
Congratulations, you win: $35

How much would you like to bet (1 - 50) or 0 to quit? 85
How much would you like to bet (1 - 50) or 0 to quit? 4
whhhhhrrrrr... and your pull is...
 cherries space cherries
Congratulations, you win: $20

How much would you like to bet (1 - 50) or 0 to quit? 3
whhhhhrrrrr... and your pull is...
 cherries space BAR
Congratulations, you win: $15

How much would you like to bet (1 - 50) or 0 to quit? 24
whhhhhrrrrr... and your pull is...
 BAR cherries 7
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 31
whhhhhrrrrr... and your pull is...
 7 cherries BAR
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 39
whhhhhrrrrr... and your pull is...
 BAR 7 7
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 44
whhhhhrrrrr... and your pull is...
 BAR BAR BAR
Congratulations, you win: $2200

How much would you like to bet (1 - 50) or 0 to quit? 43
whhhhhrrrrr... and your pull is...
 7 7 BAR
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 41
whhhhhrrrrr... and your pull is...
 cherries cherries BAR
Congratulations, you win: $615

How much would you like to bet (1 - 50) or 0 to quit? 46
whhhhhrrrrr... and your pull is...
 cherries BAR BAR
Congratulations, you win: $230

How much would you like to bet (1 - 50) or 0 to quit? 27
whhhhhrrrrr... and your pull is...
 7 BAR cherries
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 37
whhhhhrrrrr... and your pull is...
 cherries cherries 7
Congratulations, you win: $555

How much would you like to bet (1 - 50) or 0 to quit? 41
whhhhhrrrrr... and your pull is...
 BAR 7 BAR
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 37
whhhhhrrrrr... and your pull is...
 BAR cherries cherries
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 49
whhhhhrrrrr... and your pull is...
 BAR cherries 7
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 3
whhhhhrrrrr... and your pull is...
 cherries BAR 7
Congratulations, you win: $15

How much would you like to bet (1 - 50) or 0 to quit? 5
whhhhhrrrrr... and your pull is...
 BAR cherries BAR
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 6
whhhhhrrrrr... and your pull is...
 BAR BAR BAR
Congratulations, you win: $300

How much would you like to bet (1 - 50) or 0 to quit? 3
whhhhhrrrrr... and your pull is...
 space BAR cherries
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 8
whhhhhrrrrr... and your pull is...
 7 BAR space
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 13
whhhhhrrrrr... and your pull is...
 cherries cherries BAR
Congratulations, you win: $195

How much would you like to bet (1 - 50) or 0 to quit? 14
whhhhhrrrrr... and your pull is...
 7 cherries cherries
Sorry, you lose.

How much would you like to bet (1 - 50) or 0 to quit? 19
whhhhhrrrrr... and your pull is...
 cherries cherries cherries
Congratulations, you win: $570

How much would you like to bet (1 - 50) or 0 to quit? 27
whhhhhrrrrr... and your pull is...
 cherries cherries BAR
Congratulations, you win: $405

How much would you like to bet (1 - 50) or 0 to quit? 0
Thank you for using Casino IdaBagus
Program ended with exit code: 1
---------------------------------end of run--------------------------*/
