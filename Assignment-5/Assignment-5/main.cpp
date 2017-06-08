#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//Method Prototype
char getKeyCharacter();
string getString();
string maskCharacter(string theString, char keyCharacter);
string removeCharacter(string theString, char keyCharacter);
int countKey(string theString, char keyCharacter);

// Variables used for different methods
int length;
bool validated;

int main()
{
   char keyCharacter;
   string theString, maskString, replaceCharacter;
   int numberOfKey;

   keyCharacter = getKeyCharacter();
   theString = getString();
   maskString = maskCharacter(theString, keyCharacter);
   cout << "\nString with key character, '" << keyCharacter << "' masked: \n"
   << maskString << endl << endl;
   replaceCharacter = removeCharacter(theString, keyCharacter);
   cout << "String with '" << keyCharacter << "' removed: \n" << replaceCharacter
   << endl << endl;
   numberOfKey = countKey(theString, keyCharacter);
   cout << "# of occurrences of key character, '" << keyCharacter << "': "
   << numberOfKey << endl;

}

// Request a single character from the user with certain validity
char getKeyCharacter()
{
   string userInput;
   char keyCharacter;

   validated = false;
   while (!(validated)) // while it's true
   {// Prompt user to enter a single character (symbol,character,number)
      cout << "Please enter a SINGLE character to act as key: ";
      getline(cin, userInput);

      length = userInput.length(); //object calling to userInput.length

      if (length == 1) // If length of character input is 1 = true, loop break
      {
         break;
      }
   }
   //Return string keyCharacter to a char value
   istringstream(userInput) >> keyCharacter;
   return keyCharacter;
}

// Request a string from the user
string getString()

{
   string theString;
   const int MINIMUM = 4;

   while(!(validated)) // While it's true
   {// Prompt user to enter string
      cout << "Please enter a phrase or sentence >= 4 <= 500 characters: ";
      getline(cin, theString);

      length = theString.length(); // Object calling to theString.length

      // If length is >=4 and <= 500 characters
      if (length >= MINIMUM && length <= 500)
      {
         break;
      }
   }
   //Return value targetString
   return theString;
}

// Take both string and key character as parameters and return a new string,
// replacing each key character input before by an asterisk (*).
string maskCharacter(string theString, char keyCharacter)
{
   char letter;
   string newString;
   newString = ""; // newString initialized as empty

   for (int number = 0; number <= length; number++) // Loop String per letter
   {
      letter = theString[number]; // Store in local variable so can be reuse
      if (!(letter == keyCharacter)) // If letter not equal to keyCharacter
      {
         newString = newString + letter; // Append the letter to newString
         continue;//
      }
      else // If letter the same as keyCharacter
      {
         newString = newString + "*"; //Replace keyCharacter with (*)
         continue;
      }
   }
   // Return value newString;
   return newString;
}


// Take both string and key character as parameters and return another new string,
// removing each key character
string removeCharacter(string theString, char keyCharacter)
{
   char letter;
   string replaceString;
   replaceString = ""; // RemoveString initialized as empty

   for (int number = 0; number <= length; number++) // Loop String per letter
   {
      letter = theString[number]; // Store in local variable so can be reuse
      if (!(letter == keyCharacter)) // If letter not equal to keyCharacter
      {
         replaceString = replaceString + letter; // Append the letter to removeString
         continue;//
      }
      else // If letter the same as keyCharacter
      {
         replaceString = replaceString + ""; // Replace keyCharacter with ( )
         continue;
      }
   }
   // Return value replaceString;
   return replaceString;
}

// Take both string and character as parameters and return the number of
// key characters that appear in the string (case sensitive)
int countKey(string theString, char keyCharacter)
{
   char letter;
   int countKey;
   countKey = 0; //initialize value of countkey

   for (int number = 0; number <= length; number++) //loop string per letter
   {
      letter = theString[number]; //store in local variable to be reuse
      if (letter == keyCharacter) //if letter is equal to key character
      {
         countKey = countKey + 1;
      }
   }
   // Return value of countKey
   return countKey;
}

/*------------------------------paste of run 1----------------------------------
Please enter a SINGLE character to act as key: asd
Please enter a SINGLE character to act as key: !@#
Please enter a SINGLE character to act as key: 
Please enter a SINGLE character to act as key: 123
Please enter a SINGLE character to act as key: a
Please enter a phrase or sentence >= 4 <= 500 characters: 
Please enter a phrase or sentence >= 4 <= 500 characters: ''
Please enter a phrase or sentence >= 4 <= 500 characters: at
Please enter a phrase or sentence >= 4 <= 500 characters: 213
Please enter a phrase or sentence >= 4 <= 500 characters: !@#
Please enter a phrase or sentence >= 4 <= 500 characters: asd ASD !@# 123aaa (a)

String with key character, 'a' masked: 
*sd ASD !@# 123*** (*)

String with 'a' removed: 
sd ASD !@# 123 ()

# of occurrences of key character, 'a': 5
Program ended with exit code: 0
-------------------------------paste of run 2-----------------------------------
Please enter a SINGLE character to act as key: 14903123
Please enter a SINGLE character to act as key: 
Please enter a SINGLE character to act as key: !#!@#()
Please enter a SINGLE character to act as key: A
Please enter a phrase or sentence >= 4 <= 500 characters: '12
Please enter a phrase or sentence >= 4 <= 500 characters: 
Please enter a phrase or sentence >= 4 <= 500 characters: 'wA
Please enter a phrase or sentence >= 4 <= 500 characters: As(0 AA13aa1 !!A30!aA

String with key character, 'A' masked: 
*s(0 **13aa1 !!*30!a*

String with 'A' removed: 
s(0 13aa1 !!30!a

# of occurrences of key character, 'A': 5
Program ended with exit code: 0
-------------------------------paste of run 3-----------------------------------
Please enter a SINGLE character to act as key: 103901001
Please enter a SINGLE character to act as key: !@()#
Please enter a SINGLE character to act as key: 6
Please enter a phrase or sentence >= 4 <= 500 characters: 666
Please enter a phrase or sentence >= 4 <= 500 characters: !!!
Please enter a phrase or sentence >= 4 <= 500 characters: .,
Please enter a phrase or sentence >= 4 <= 500 characters: 68403456 AsA^^66 ()136

String with key character, '6' masked: 
*840345* AsA^^** ()13*

String with '6' removed: 
840345 AsA^^ ()13

# of occurrences of key character, '6': 5
Program ended with exit code: 0
------------------------------paste of run 4------------------------------------
Please enter a SINGLE character to act as key: 4010
Please enter a SINGLE character to act as key: aAAAaa
Please enter a SINGLE character to act as key: &
Please enter a phrase or sentence >= 4 <= 500 characters: &13
Please enter a phrase or sentence >= 4 <= 500 characters: &aA
Please enter a phrase or sentence >= 4 <= 500 characters: a(3
Please enter a phrase or sentence >= 4 <= 500 characters: !&&
Please enter a phrase or sentence >= 4 <= 500 characters: &Asd& D&&&ds><! d!!&;'

String with key character, '&' masked: 
*Asd* D***ds><! d!!*;'

String with '&' removed: 
Asd Dds><! d!!;'

# of occurrences of key character, '&': 6
Program ended with exit code: 0
------------------------------end of run--------------------------------------*/

