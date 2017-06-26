#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

// class Student prototype -----------------------
class Student
{
private:
   string lastName;
   string firstName;
   int totalPoints;
   static int sortKey;

public:
   static const string DEFAULT_NAME;
   static const int DEFAULT_POINTS = 0;
   static const int MAX_POINTS = 1000;
   static const int SORT_BY_FIRST = 88;
   static const int SORT_BY_LAST = 98;
   static const int SORT_BY_POINTS = 108;

public:
   Student( string lst = DEFAULT_NAME, string fst = DEFAULT_NAME,
           int pts = DEFAULT_POINTS);

   // accessors and mutators
   string getLastName() { return lastName; }
   string getFirstName() { return firstName; }
   int getTotalPoints() { return totalPoints; }
   static int getSortKey() {return sortKey;} // an accessor for sortKey

   bool setLastName(string last);
   bool setFirstName(string first);
   bool setPoints(int pts);
   static bool setSortKey(int key); // a mutator for member sortKey

   static int compareTwoStudents( Student firstStud, Student secondStud );
   string toString();

private:
   static bool validString( string testStr );
   static bool validPoints( int testPoints );

};  // end of class Student prototype --------------

// Static initializations that can't be done in-line
int Student::sortKey = SORT_BY_LAST;

// class StudentArrayUtilities prototype -----------------------
class StudentArrayUtilities
{
public:
   static const int MAX_STUDENTS = 20;

private:
   Student theArray[MAX_STUDENTS];
   int numStudents;

public:
   string toString(string title);
   void arraySort();
   double getMedianDestructive();
   bool addStudent( Student stud );
   Student removeStudent();

private:
   bool floatLargestToTop( int top );
   static void mySwap(Student &a, Student &b);
};

// static initializations that can't be done in-line
const string Student::DEFAULT_NAME = "zz-error";

int main()
{

   Student  myClass[] =
   {
      Student("smith","fred", 95),
      Student("bauer","jack",123),
      Student("jacobs","carrie", 195),  Student("renquist","abe",148),
      Student("3ackson","trevor", 108),  Student("perry","fred",225),
      Student("smith","fred", 44),  Student("stollings","pamela",452),
      Student("charters","rodney", 295),  Student("cassar","john",321)

   };

   Student student;
   int arraySize = sizeof(myClass) / sizeof(myClass[0]);
   int k;

   // instantiate an SAU object
   StudentArrayUtilities myStuds;

   // we can add stdunts manually and individually
   myStuds.addStudent( Student( "ishak", "livia", 750 ) );
   myStuds.addStudent( Student( "agasatya", "diaz", 365 ) );

   // if we happen to have an array available, we can add students in loop.
   for (k = 0; k < arraySize; k++ )
      myStuds.addStudent( myClass[k] );

   cout << myStuds.toString("Before: " );
   cout << endl;

   myStuds.arraySort();
   cout << myStuds.toString("After default sort: ");
   cout << endl;

   Student::setSortKey(Student::SORT_BY_FIRST);
   myStuds.arraySort();
   cout << myStuds.toString( "After sort by first: " );
   cout << endl;

   // test median
   cout << "Median of evenClass = "
   << myStuds.getMedianDestructive()
   << endl << endl;

   // various tests of removing and adding students in the array
   cout << "Testing removing students in the array: " << endl;
   for (k = 0; k < 100; k++)
   {
      student = myStuds.removeStudent();
      if ( Student::compareTwoStudents( student, Student() ) )
         cout << "   Removed " << student.toString();
      else
      {
         cout << "Empty after " << k << " removes." << endl;
         break;
      }
   }
   cout << endl;

   cout << "Testing adding students in the array: " << endl;
   for (k = 0; k < 100; k++)
   {
      if (!myStuds.addStudent(Student("first", "last", 22)))
      {
         cout << "Full after " << k << " adds." << endl;
         break;
      }
   }
}

// beginning of Student method definitions -------------

// constructor requires parameters - no default supplied
Student::Student( string last, string first, int points)
{
   if ( !setLastName(last) )
      lastName = DEFAULT_NAME;
   if ( !setFirstName(first) )
      firstName = DEFAULT_NAME;
   if ( !setPoints(points) )
      totalPoints = DEFAULT_POINTS;
}

bool Student::setLastName(string last)
{
   if ( !validString(last) )
      return false;
   lastName = last;
   return true;
}

bool Student::setFirstName(string first)
{
   if ( !validString(first) )
      return false;
   firstName = first;
   return true;
}

bool Student::setPoints(int pts)
{
   if ( !validPoints(pts) )
      return false;
   totalPoints = pts;
   return true;
}

// Client want to set a new sort key, filter out bad data
bool Student::setSortKey(int key)
{
   if ( !validPoints(key) )
      return false;
   sortKey = key;
   return true;
}

// could be an instance method and, if so, would take one parameter
int Student::compareTwoStudents( Student firstStud, Student secondStud )
{
   int totalPointsOne, totalPointsTwo, result = 0, resultTwo = 0,
   resultOne = 0;
   totalPointsOne = firstStud.getTotalPoints();
   totalPointsTwo = secondStud.getTotalPoints();

   if (totalPointsOne > totalPointsTwo)
      resultTwo = 1;
   else if (totalPointsOne < totalPointsTwo )
      resultTwo = -1;
   else if (totalPointsOne == totalPointsTwo)
      resultTwo = 0;

   switch (sortKey) {
      case SORT_BY_FIRST: result = firstStud.firstName.compare
         (secondStud.firstName);
         break;
      case SORT_BY_LAST: result = firstStud.lastName.compare
         (secondStud.lastName);
         break;
      case SORT_BY_POINTS: result = resultTwo;
         break;
   }

   // Limit variable result from 1 to -1
   if (result > 0)
      resultOne = 1;
   else if (result < 0)
      resultOne = -1;
   else
      resultOne = 0;

   return resultOne;
}

string Student::toString()
{
   string resultString;
   ostringstream cnvrtFirst, cnvrtLast, cnvrtPoints;

   cnvrtFirst << firstName;
   cnvrtLast << lastName;
   cnvrtPoints << totalPoints;

   resultString = " " + cnvrtLast.str()
   + ", " + cnvrtFirst.str()
   + " points: " + cnvrtPoints.str()
   + "\n";
   return resultString;
}

bool Student::validString( string testStr )
{
   if (testStr.length() > 0 && isalpha(testStr[0]))
      return true;
   return false;
}

bool Student::validPoints( int testPoints )
{
   if (testPoints >= 0 && testPoints <= MAX_POINTS)
      return true;
   return false;
}
// end of Student method definitions  --------------

// beginning of StudentArrayUtilities method definitions -------------

bool StudentArrayUtilities::addStudent(Student stud)
{
   bool condition;

   if (numStudents < MAX_STUDENTS) {
      theArray[numStudents] = stud;
      numStudents++;
      condition = true;
   }
   else {
      cout << "Array is full! Can't add anymore students.\n";
      condition = false;
   }

      return condition;
}

Student StudentArrayUtilities::removeStudent()
{
   Student removeStudent, deletedStudent;
   removeStudent = Student();
   int highestStudent;
   highestStudent = numStudents;

   if (! (numStudents == 0)) {
      deletedStudent = theArray[highestStudent];
      theArray[highestStudent] = removeStudent;
      numStudents--;
   }
   else {
      deletedStudent = Student();
   }

   return deletedStudent;
}

// Format the string inside the array and return it to main()
string StudentArrayUtilities::toString(string title)
{
   string output = "";

   cout << title << endl;

   // build the output string from the individual Students:
   for (int k = 0; k < numStudents; k++)
      output += " " + theArray[k].Student::toString();

   return output;
}


double StudentArrayUtilities::getMedianDestructive()
{
   Student::setSortKey(Student::SORT_BY_POINTS); // Change sortKey to Points

   arraySort(); // Sort array from totalPoints

   int firstMiddleNumber, secondMiddleNumber ,middleNumber, middleTotalPoints,
   firstTotalPoints, secondTotalPoints,oneStudentTotalPoints,oneStudent;
   double average, result;

   //Calculations
   firstMiddleNumber = numStudents / 2;
   secondMiddleNumber = (numStudents / 2) - 1;
   middleNumber = ((numStudents - 1) / 2);
   oneStudent = 0;

   // Getters
   firstTotalPoints = theArray[firstMiddleNumber].Student::getTotalPoints();
   secondTotalPoints = theArray[secondMiddleNumber].Student::getTotalPoints();
   middleTotalPoints = theArray[middleNumber].Student::getTotalPoints();
   oneStudentTotalPoints = theArray[oneStudent].Student::getTotalPoints();

   average = ((double)firstTotalPoints + secondTotalPoints) / 2;

   // Determining result based on arraySize
   if (numStudents == 0)
      result = 0.0;
   else if (numStudents == 1)
      result = oneStudentTotalPoints;
   else if (numStudents % 2 == 0)
      result = average;
   else if (numStudents % 2 == 1)
      result = middleTotalPoints;

   Student::setSortKey(Student::SORT_BY_LAST); // Restore sortKey to Default;

   return result;
}

void StudentArrayUtilities::arraySort()
{
   for (int k = 0; k < numStudents; k++)
      // compare with method def to see where inner loop stops
      if (!floatLargestToTop(numStudents))
         return;
}

// returns true if a modification was made to the array
bool StudentArrayUtilities::floatLargestToTop(int top)
{
   bool changed = false;

   // compare with client call to see where the loop stops
   for (int k =0; k < top; k++)
      if (  Student::compareTwoStudents(theArray[k], theArray[k + 1]) > 0 )
      {
         mySwap(theArray[k], theArray[k + 1]);
         changed = true;
      }
   return changed;
}

void StudentArrayUtilities::mySwap(Student &a, Student &b)
{
   Student temp("", "", 0);

   temp = a;
   a = b;
   b = temp;
}

// end of StudentArrayUtilities method definitions  --------------

/*------------------------------Paste of Run---------------------------------
Before: 
  ishak, livia points: 750
  agasatya, diaz points: 365
  smith, fred points: 95
  bauer, jack points: 123
  jacobs, carrie points: 195
  renquist, abe points: 148
  zz-error, trevor points: 108
  perry, fred points: 225
  smith, fred points: 44
  stollings, pamela points: 452
  charters, rodney points: 295
  cassar, john points: 321

After default sort: 
  agasatya, diaz points: 365
  bauer, jack points: 123
  cassar, john points: 321
  charters, rodney points: 295
  ishak, livia points: 750
  jacobs, carrie points: 195
  perry, fred points: 225
  renquist, abe points: 148
  smith, fred points: 95
  smith, fred points: 44
  stollings, pamela points: 452
  zz-error, trevor points: 108

After sort by first: 
  renquist, abe points: 148
  jacobs, carrie points: 195
  agasatya, diaz points: 365
  perry, fred points: 225
  smith, fred points: 95
  smith, fred points: 44
  bauer, jack points: 123
  cassar, john points: 321
  ishak, livia points: 750
  stollings, pamela points: 452
  charters, rodney points: 295
  zz-error, trevor points: 108

Median of evenClass = 171.5

Testing removing students in the array: 
   Removed  ishak, livia points: 750
   Removed  stollings, pamela points: 452
   Removed  agasatya, diaz points: 365
   Removed  cassar, john points: 321
   Removed  charters, rodney points: 295
   Removed  perry, fred points: 225
   Removed  jacobs, carrie points: 195
   Removed  renquist, abe points: 148
   Removed  bauer, jack points: 123
Empty after 9 removes.

Testing adding students in the array: 
Array is full! Can't add anymore students.
Full after 18 adds.
Program ended with exit code: 0
 ----------------------------------End of Run-------------------------------*/
