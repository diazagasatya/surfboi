#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class TripleString
{
private:
   string string1, string2, string3;

public:
   // Static constants
   static const int MAX_LEN;
   static const int MIN_LEN;
   static const string DEFAULT_STRING;

   // Default constructor
   TripleString();

   // 3-parameter constructor
   TripleString(string string1, string string2, string string3);

   // Prototype
   bool setString1(string theString1);
   bool setString2(string theString2);
   bool setString3(string theString3);
   bool validString(string str); // method that determines string legality
   string getString1(), getString2(), getString3(), toString();
};

// Define static constants
const int TripleString::MAX_LEN = 50;
const int TripleString::MIN_LEN = 1;
const string TripleString::DEFAULT_STRING = "(undefined)";

// Client
int main()
{
   //Instantiate four objects
   TripleString stringOne, stringTwo, stringThree, stringFour;

   // Display all objects
   cout << "Display all objects default strings: " << endl;
   cout << "Str #1 string1: " << stringOne.getString1() << endl;
   cout << "Str #1 string2: " << stringOne.getString2() << endl;
   cout << "Str #1 string3: " << stringOne.getString3() << endl;
   cout << "Str #2 string1: " << stringTwo.getString1() << endl;
   cout << "Str #2 string2: " << stringTwo.getString2() << endl;
   cout << "Str #2 string3: " << stringTwo.getString3() << endl;
   cout << "Str #3 string1: " << stringThree.getString1() << endl;
   cout << "Str #3 string2: " << stringThree.getString2() << endl;
   cout << "Str #3 string3: " << stringThree.getString3() << endl;
   cout << "Str #4 string1: " << stringFour.getString1() << endl;
   cout << "Str #4 string2: " << stringFour.getString2() << endl;
   cout << "Str #4 string3: " << stringFour.getString3() << endl << endl;

   // Mutate one or more members of every object
   stringOne.setString1("My first name is Diaz");
   stringOne.setString2("My last name is Agasatya");
   stringTwo.setString3("I live in San Francisco");
   stringTwo.setString2("Specifically in sunset area");
   stringThree.setString1("I'm originally from Bali");
   stringThree.setString2("I moved to the states 5 years ago");
   stringFour.setString3("I love computer programming");
   stringFour.setString1("Can't wait to learn about AI");

   // Display all objects a second time
   cout << "Display all objects after mutating some members:" << endl;
   cout << "Str #1 string1: " << stringOne.getString1() << endl;
   cout << "Str #1 string2: " << stringOne.getString2() << endl;
   cout << "Str #1 string3: " << stringOne.getString3() << endl;
   cout << "Str #2 string1: " << stringTwo.getString1() << endl;
   cout << "Str #2 string2: " << stringTwo.getString2() << endl;
   cout << "Str #2 string3: " << stringTwo.getString3() << endl;
   cout << "Str #3 string1: " << stringThree.getString1() << endl;
   cout << "Str #3 string2: " << stringThree.getString2() << endl;
   cout << "Str #3 string3: " << stringThree.getString3() << endl;
   cout << "Str #4 string1: " << stringFour.getString1() << endl;
   cout << "Str #4 string2: " << stringFour.getString2() << endl;
   cout << "Str #4 string3: " << stringFour.getString3() << endl << endl;

   // Do two explicit mutator tests
   cout << "Two explicit mutator tests:" << endl;
   string testing1, testing2;
   testing1 = "Explicitly testing mutator valid string";
   testing2 = "Explicitly testing mutator valid string in object str2"
   " to make sure that the mutator can detect illegal input from user";

   if ( !stringOne.validString(testing1) ) // testing 1 (successful)
   {
      cout << "The Call fails!\n";
   }
   else
      cout << "The Call is successful!: String characters within range.\n";

   if ( !stringTwo.validString(testing2) ) // test2 (fails)
   {
      cout << "The Call fails: String exceeded 50 characters.\n\n";
   }
   else
      cout << "The Call is successful!\n";

   // Make two accesssor calls to demonstrate that they work
   cout << "Demonstration of calling two accessors:" << endl;
   cout << "Str #4 string 3: " << stringFour.getString3() << endl;
   cout << "Str #2 string 1: " << stringTwo.getString1() << endl << endl;

   // toString method call to demonstrate that it work
   cout << "Object 1 all strings:\n" << stringOne.toString() << endl;
   cout << "Object 2 all strings:\n" << stringTwo.toString() << endl;
   cout << "Object 3 all strings:\n" << stringThree.toString() << endl;
   cout << "Object 4 all strings:\n" << stringFour.toString() << endl;

}

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

// Mutators , Accessors and other class definitions
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

   allStrings = "String 1 = " + string1 + "\n" + "String 2 = "
   + string2 + "\n" + "String 3 = " + string3 + "\n";
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

/*-------------------------------paste of run-----------------------------------
Display all objects default strings: 
Str #1 string1: (undefined)
Str #1 string2: (undefined)
Str #1 string3: (undefined)
Str #2 string1: (undefined)
Str #2 string2: (undefined)
Str #2 string3: (undefined)
Str #3 string1: (undefined)
Str #3 string2: (undefined)
Str #3 string3: (undefined)
Str #4 string1: (undefined)
Str #4 string2: (undefined)
Str #4 string3: (undefined)

Display all objects after mutating some members:
Str #1 string1: My first name is Diaz
Str #1 string2: My last name is Agasatya
Str #1 string3: (undefined)
Str #2 string1: (undefined)
Str #2 string2: Specifically in sunset area
Str #2 string3: I live in San Francisco
Str #3 string1: I'm originally from Bali
Str #3 string2: I moved to the states 5 years ago
Str #3 string3: (undefined)
Str #4 string1: Can't wait to learn about AI
Str #4 string2: (undefined)
Str #4 string3: I love computer programming

Two explicit mutator tests:
The Call is successful!: String characters within range.
The Call fails: String exceeded 50 characters.

Demonstration of calling two accessors:
Str #4 string 3: I love computer programming
Str #2 string 1: (undefined)

Object 1 all strings:
String 1 = My first name is Diaz
String 2 = My last name is Agasatya
String 3 = (undefined)

Object 2 all strings:
String 1 = (undefined)
String 2 = Specifically in sunset area
String 3 = I live in San Francisco

Object 3 all strings:
String 1 = I'm originally from Bali
String 2 = I moved to the states 5 years ago
String 3 = (undefined)

Object 4 all strings:
String 1 = Can't wait to learn about AI
String 2 = (undefined)
String 3 = I love computer programming

Program ended with exit code: 0
---------------------------------end of run-----------------------------------*/