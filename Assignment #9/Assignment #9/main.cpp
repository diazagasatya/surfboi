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
   static string toString(string title, Student data[], int arraySize);
   static void arraySort(Student array[], int arraySize);
   static double getMedianDestructive(Student array[],  int arraySize);

private:
   static bool floatLargestToTop(Student data[], int top);
   static void mySwap(Student &a, Student &b);
};

// static initializations that can't be done in-line
const string Student::DEFAULT_NAME = "zz-error";

int main()
{

   Student  myClass[] =
   {
      Student("smith","fred",95),
      Student("bauer","jack",123),
      Student("jacobs","carrie",195),  Student("renquist","abe",148),
      Student("3ackson","trevor",108),  Student("perry","fred",225),
      Student("loceff","fred",44),  Student("stollings","pamela",452),
      Student("charters","rodney",295),  Student("cassar","john",321),
      Student("ishak","livia",730), Student("agasatya","diaz",800),
      Student("muhammad","rio",640), Student("harjo","anthony",680),
      Student("matahari","putri",530),Student("irena","angela",560),
   };

   Student myClassTwo[] =
   {
      Student("smith","fred",95),
      Student("bauer","jack",123),
      Student("jacobs","carrie",195),  Student("renquist","abe",148),
      Student("3ackson","trevor",108),  Student("perry","fred",225),
      Student("loceff","fred",44),  Student("stollings","pamela",452),
      Student("charters","rodney",295),  Student("cassar","john",321),
      Student("ishak","livia",730), Student("agasatya","diaz",800),
      Student("muhammad","rio",640), Student("harjo","anthony",680),
      Student("matahari","putri",530),
   };

   Student myClassThree[] =
   {
      Student("gadot","gal",930)
   };

   double median;
   int testSortKey;

   int arraySize = sizeof(myClass) / sizeof(myClass[0]);
   int arraySizeTwo = sizeof(myClassTwo) / sizeof(myClassTwo[0]);
   int arraySizeThree = sizeof(myClassThree) / sizeof(myClassThree[0]);

   // myClass[16] testing --------------------------------------------------
   // Display the array
   cout << StudentArrayUtilities::toString("Before:", myClass, arraySize)
   << endl;

   // Sort the array using default(lastName)
   StudentArrayUtilities::arraySort(myClass, arraySize);
   cout << "Sorting by default --------------------- \n";

   // Display the array after sorted
   cout << StudentArrayUtilities::toString("After:", myClass, arraySize)
   << endl;

   // Set sortKey to firstName
   Student::setSortKey(Student::SORT_BY_FIRST);

   // Sort the array using firstName
   StudentArrayUtilities::arraySort(myClass, arraySize);
   cout << "Sorting by first name ------------------- \n";

   // Display the array after sorted
   cout << StudentArrayUtilities::toString("After:", myClass, arraySize)
   << endl;

   // Set sortKey to totalPoints
   Student::setSortKey(Student::SORT_BY_POINTS);

   // Sort the array using totalPoints
   StudentArrayUtilities::arraySort(myClass, arraySize);
   cout << "Sorting by total points ------------------ \n";

   // Display the array after sorted
   cout << StudentArrayUtilities::toString("After:", myClass, arraySize)
   << endl;

   // Set sortKey to firstName & Get Median of array
   Student::setSortKey(Student::SORT_BY_FIRST);
   median = StudentArrayUtilities::getMedianDestructive(myClass, arraySize);
   cout << "Median of evenClass = " << fixed << setprecision(1) << median
   << endl;

   // Test if sortKey set back to default(lastName)
   testSortKey = Student::getSortKey();
   if (testSortKey == Student::SORT_BY_LAST)
      cout << "Successfully preserved sort key.\n";
   else
      cout << "Sort key is not preserved! Please debug the method.\n";

   // myClassTwo[15] testing ----------------------------------------------
   testSortKey = Student::getSortKey();
   median = StudentArrayUtilities::getMedianDestructive(myClassTwo,
                                                        arraySizeTwo);
   cout << "Median of oddClass = " << fixed << setprecision(1) << median
   << endl;

   // myClassThree[1] testing ---------------------------------------------
   testSortKey = Student::getSortKey();
   median = StudentArrayUtilities::getMedianDestructive(myClassThree,
                                                        arraySizeThree);
   cout << "Median of smallClass = " << fixed << setprecision(1) << median
   << endl;
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
   int totalPointsOne, totalPointsTwo, result = 0, resultTwo = 0;
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
   return result;
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

// Format the string inside the array and return it to main()
string StudentArrayUtilities::toString(string title, Student data[],
                                       int arraySize)
{
   string output = "";

   cout << title << endl;

   // build the output string from the individual Students:
   for (int k = 0; k < arraySize; k++)
      output += " " + data[k].Student::toString();

   return output;
}


double StudentArrayUtilities::getMedianDestructive(Student array[],
                                                   int arraySize)
{
   Student::setSortKey(Student::SORT_BY_POINTS); // Change sortKey to Points

   arraySort(array, arraySize); // Sort array from totalPoints

   int firstMiddleNumber, secondMiddleNumber ,middleNumber, middleTotalPoints,
   firstTotalPoints, secondTotalPoints,oneStudentTotalPoints,oneStudent;
   double average, result;

   //Calculations
   firstMiddleNumber = arraySize / 2;
   secondMiddleNumber = (arraySize / 2) - 1;
   middleNumber = ((arraySize - 1) / 2);
   oneStudent = 0;

   // Getters
   firstTotalPoints = array[firstMiddleNumber].Student::getTotalPoints();
   secondTotalPoints = array[secondMiddleNumber].Student::getTotalPoints();
   middleTotalPoints = array[middleNumber].Student::getTotalPoints();
   oneStudentTotalPoints = array[oneStudent].Student::getTotalPoints();

   average = ((double)firstTotalPoints + secondTotalPoints) / 2;

   // Determining result based on arraySize
   if (arraySize == 0)
      result = 0.0;
   else if (arraySize == 1)
      result = oneStudentTotalPoints;
   else if (arraySize % 2 == 0)
      result = average;
   else if (arraySize % 2 == 1)
      result = middleTotalPoints;

   Student::setSortKey(Student::SORT_BY_LAST); // Restore sortKey to Default;

   return result;
}

void StudentArrayUtilities::arraySort(Student array[], int arraySize)
{
   for (int k = 0; k < arraySize; k++)
      // compare with method def to see where inner loop stops
      if (!floatLargestToTop(array, arraySize-1-k))
         return;
}

// returns true if a modification was made to the array
bool StudentArrayUtilities::floatLargestToTop(Student data[], int top)
{
   bool changed = false;

   // compare with client call to see where the loop stops
   for (int k =0; k < top; k++)
      if (  Student::compareTwoStudents(data[k], data[k + 1]) > 0 )
      {
         mySwap(data[k], data[k + 1]);
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
  smith, fred points: 95
  bauer, jack points: 123
  jacobs, carrie points: 195
  renquist, abe points: 148
  zz-error, trevor points: 108
  perry, fred points: 225
  loceff, fred points: 44
  stollings, pamela points: 452
  charters, rodney points: 295
  cassar, john points: 321
  ishak, livia points: 730
  agasatya, diaz points: 800
  muhammad, rio points: 640
  harjo, anthony points: 680
  matahari, putri points: 530
  irena, angela points: 560

Sorting by default --------------------- 
After:
  agasatya, diaz points: 800
  bauer, jack points: 123
  cassar, john points: 321
  charters, rodney points: 295
  harjo, anthony points: 680
  irena, angela points: 560
  ishak, livia points: 730
  jacobs, carrie points: 195
  loceff, fred points: 44
  matahari, putri points: 530
  muhammad, rio points: 640
  perry, fred points: 225
  renquist, abe points: 148
  smith, fred points: 95
  stollings, pamela points: 452
  zz-error, trevor points: 108

Sorting by first name ------------------- 
After:
  renquist, abe points: 148
  irena, angela points: 560
  harjo, anthony points: 680
  jacobs, carrie points: 195
  agasatya, diaz points: 800
  loceff, fred points: 44
  perry, fred points: 225
  smith, fred points: 95
  bauer, jack points: 123
  cassar, john points: 321
  ishak, livia points: 730
  stollings, pamela points: 452
  matahari, putri points: 530
  muhammad, rio points: 640
  charters, rodney points: 295
  zz-error, trevor points: 108

Sorting by total points ------------------ 
After:
  loceff, fred points: 44
  smith, fred points: 95
  zz-error, trevor points: 108
  bauer, jack points: 123
  renquist, abe points: 148
  jacobs, carrie points: 195
  perry, fred points: 225
  charters, rodney points: 295
  cassar, john points: 321
  stollings, pamela points: 452
  matahari, putri points: 530
  irena, angela points: 560
  muhammad, rio points: 640
  harjo, anthony points: 680
  ishak, livia points: 730
  agasatya, diaz points: 800

Median of evenClass = 308.0
Successfully preserved sort key.
Median of oddClass = 295.0
Median of smallClass = 930.0
Program ended with exit code: 0
----------------------------------End of Run-------------------------------*/
