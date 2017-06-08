#include <string>
#include <iostream>
#include <sstream>

using namespace std;

// Class DateProfile prototype -----------------------
class DateProfile
{
private:
   char gender;
   char searchGender;
   int romance;
   int finance;
   string name;

public:
   static const char DEFAULT_GEND;
   static const char DEFAULT_SEARCH_GEND;
   static const string DEFAULT_NAME;
   static const char MALE_GEND;
   static const char FEMALE_GEND;
   static const int MIN_POINTS = 1;
   static const int MAX_POINTS = 10;
   static const int MIN_NAME_LEN = 0;
   static const int DEFAULT_POINTS = 0;
   static const int MIN_DIFFERENCE = 0;
   static const int NEGATIVE_CONST = -1;

   // default constructor
   DateProfile();

   // constructor with 5 parameters
   DateProfile(char gender, char searchGender, int romance, int finance,
               string name);

   // accessors and mutators
   char getGender() {return gender;}
   char getSearchGender() {return searchGender;}
   int getRomance() {return romance;}
   int getFinance() {return finance;}
   string getName() {return name;}

   bool setGender(char gender);
   bool setSearchGender(char searchGender);
   bool setRomance(int romance);
   bool setFinance(int finance);
   bool setName(string userName);

   // prototypes
   void setAll(char userGender, char searchGender,int romance, int finance,
               string userName);
   void setDefaults();
   double fitValue(DateProfile partner);

private:
   double determineGenderFit(DateProfile partner);
   double determineRomanceFit(DateProfile partner);
   double determineFinanceFit(DateProfile partner);
   bool validPoints(int testPoints);
   bool validChar(char testChar);
   bool validString(string testString);

};

// Static initializations that can't be done in-line
const char DateProfile::DEFAULT_GEND = 'F';
const char DateProfile::DEFAULT_SEARCH_GEND = 'F';
const char DateProfile::MALE_GEND = 'M';
const char DateProfile::FEMALE_GEND = 'F';
const string DateProfile::DEFAULT_NAME = "undefined";


// Global-Scope method----------------------------------------
static void displayTwoProfiles(DateProfile profile1, DateProfile profile2);

// Client Main() definition-----------------------------------
int main()
{
   // instantiate 4 objects
   DateProfile applicant1, applicant2, applicant3, applicant4;

   applicant1.setAll('M','F',3,7,"Diaz Agasatya");
   applicant2.setAll('F','M',6,9,"Keira Knightley");
   applicant3.setAll('F','M',3,8,"Gal Gadot");
   applicant4.setAll('M','F',5,2,"Kobe Bryant");

   displayTwoProfiles(applicant1, applicant1);
   displayTwoProfiles(applicant1, applicant2);
   displayTwoProfiles(applicant1, applicant3);
   displayTwoProfiles(applicant1, applicant4);

   cout << endl << endl;

   displayTwoProfiles(applicant2, applicant1);
   displayTwoProfiles(applicant2, applicant2);
   displayTwoProfiles(applicant2, applicant3);
   displayTwoProfiles(applicant2, applicant4);

   cout << endl << endl;

   displayTwoProfiles(applicant3, applicant1);
   displayTwoProfiles(applicant3, applicant2);
   displayTwoProfiles(applicant3, applicant3);
   displayTwoProfiles(applicant3, applicant4);

   cout << endl << endl;

   displayTwoProfiles(applicant4, applicant1);
   displayTwoProfiles(applicant4, applicant2);
   displayTwoProfiles(applicant4, applicant3);
   displayTwoProfiles(applicant4, applicant4);

   cout << endl << endl;

   // Mutator test - will print error message if return false
   bool testMutator;
   char testChar;
   testChar = 'Y';

   testMutator = applicant4.setGender(testChar);

   if (testMutator == false)
      cout << testChar << " rejected as gender" << endl << endl;
}

//Global-Scope method definition------------------------------
// prints the names of two object and show fit value
static void displayTwoProfiles(DateProfile profile1, DateProfile profile2)
{
   double fitValue;

   fitValue = profile1.fitValue(profile2);

   cout << "Fit between " << profile1.getName() << " and "
   << profile2.getName() << ":    " << fitValue << endl;

}

//DateProfile method definitions -----------------------------

// default constructor
DateProfile::DateProfile()
{
   setDefaults();
}

// constructor requires parameters
DateProfile::DateProfile(char gender, char searchGender,
                         int romance, int finance, string name)
{
   if (!setGender(gender))
      gender = DEFAULT_GEND;
   if (!setSearchGender(searchGender))
      searchGender = DEFAULT_SEARCH_GEND;
   if (!setRomance(romance))
      romance = DEFAULT_POINTS;
   if (!setFinance(finance))
      finance = DEFAULT_POINTS;
   if (!setName(name))
      name = DEFAULT_NAME;
}

// private helper for filtering validity of user inputs
bool DateProfile::validPoints(int testPoints)
{
   if (testPoints >= MIN_POINTS && testPoints <= MAX_POINTS)
      return true;
   return false;
}

bool DateProfile::validString(string testString)
{
   if (testString.length() > MIN_NAME_LEN)
      return true;
   return false;
}

bool DateProfile::validChar(char testChar)
{
   if (testChar == MALE_GEND || testChar == FEMALE_GEND)
       return true;
   return false;
}

// Mutators
bool DateProfile::setGender(char gender)
{
   if ( !validChar(gender))
      return false;
   this->gender = gender;
   return true;
}

bool DateProfile::setSearchGender(char searchGender)
{
   if ( !validChar(searchGender))
      return false;
   this->searchGender = searchGender;
   return true;
}

bool DateProfile::setRomance(int romance)
{
   if ( !validPoints(romance))
      return false;
   this->romance = romance;
   return true;
}

bool DateProfile::setFinance(int finance)
{
   if ( !validPoints(finance))
      return false;
   this->finance = finance;
   return true;
}

bool DateProfile::setName(string userName)
{
   if ( !validString(userName))
      return false;
   name = userName;
   return true;

}

// takes all 5 perimeters and acts like a mutator
void DateProfile::setAll(char userGender, char searchGender,int
                         romance, int finance,string userName)
{
   setGender(userGender);
   setSearchGender(searchGender);
   setRomance(romance);
   setFinance(finance);
   setName(userName);
}

// sets all 5 private members to its default value
void DateProfile::setDefaults()
{
   gender = DEFAULT_GEND;
   searchGender = DEFAULT_SEARCH_GEND;
   romance = DEFAULT_POINTS;
   finance = DEFAULT_POINTS;
   name = DEFAULT_NAME;
}

// total comparison of fit value between calling object and passed parameter
// object
double DateProfile::fitValue(DateProfile partner)
{
   double average, romance, finance;

   if (determineGenderFit(partner) == MIN_DIFFERENCE)
      return 0.0;

   romance = determineRomanceFit(partner);
   finance = determineFinanceFit(partner);

   average = (romance + finance) / 2;

   return average;
}

//comparison gender fit of calling object and passed parameter object
double DateProfile::determineGenderFit(DateProfile partner)
{
   if (partner.gender == searchGender)
      return 1.0;
   return 0.0;
}

// comparison romance fit of calling object and passed parameter object
double DateProfile::determineRomanceFit(DateProfile partner)
{
   int difference;

   difference = partner.romance - romance;

   if (difference < MIN_DIFFERENCE)
      difference *= NEGATIVE_CONST;

   // calculate romance fit
   if (difference == 0)
      return 1.0;
   if (difference == 1)
      return 0.9;
   if (difference == 2)
      return 0.8;
   if (difference == 3)
      return 0.7;
   if (difference == 4)
      return 0.6;
   if (difference == 5)
      return 0.5;
   if (difference == 6)
      return 0.4;
   if (difference == 7)
      return 0.3;
   if (difference == 8)
      return 0.2;
   if (difference == 9)
      return 0.1;
   return 0.0;
}

// comparison finance fit of calling object and passed parameter object
double DateProfile::determineFinanceFit(DateProfile partner)
{
   int difference;

   difference = partner.finance - finance;

   if (difference < MIN_DIFFERENCE)
      difference *= NEGATIVE_CONST;

   // calculate romance fit
   if (difference == 0)
      return 1.0;
   if (difference == 1)
      return 0.9;
   if (difference == 2)
      return 0.8;
   if (difference == 3)
      return 0.7;
   if (difference == 4)
      return 0.6;
   if (difference == 5)
      return 0.5;
   if (difference == 6)
      return 0.4;
   if (difference == 7)
      return 0.3;
   if (difference == 8)
      return 0.2;
   if (difference == 9)
      return 0.1;
   return 0.0;
}

/*---------------------------paste of run-----------------------------------
Fit between Diaz Agasatya and Diaz Agasatya:    0
Fit between Diaz Agasatya and Keira Knightley:    0.75
Fit between Diaz Agasatya and Gal Gadot:    0.95
Fit between Diaz Agasatya and Kobe Bryant:    0


Fit between Keira Knightley and Diaz Agasatya:    0.75
Fit between Keira Knightley and Keira Knightley:    0
Fit between Keira Knightley and Gal Gadot:    0
Fit between Keira Knightley and Kobe Bryant:    0.6


Fit between Gal Gadot and Diaz Agasatya:    0.95
Fit between Gal Gadot and Keira Knightley:    0
Fit between Gal Gadot and Gal Gadot:    0
Fit between Gal Gadot and Kobe Bryant:    0.6


Fit between Kobe Bryant and Diaz Agasatya:    0
Fit between Kobe Bryant and Keira Knightley:    0.6
Fit between Kobe Bryant and Gal Gadot:    0.6
Fit between Kobe Bryant and Kobe Bryant:    0


Y rejected as gender

Program ended with exit code: 0
------------------------------end of run-----------------------------------*/