#include <iostream>

#include "SyntaxCheck.h"

using namespace std;

int main(int argc, char **argv)
{
  bool keepRunning = true; // used to keep while loop running
  string userFile;
  userFile = argv[1]; // setting the first command line argument to userFile

  while(keepRunning)
  {
    try
    {
      // creating a new SyntaxCheck object, which creates the delimeterStack and does all the methods to check the delimeters
      SyntaxCheck* sc = new SyntaxCheck(userFile);
    }
    catch(runtime_error e) // catching if there is unmatched delimeter
    {
      //printing out the runtime_error error from SyntaxCheck
      cout << e.what() << endl;
    }

    // asking if user wants to exit or input another file
    string userResponse;
    cout << "Would you like to check another file? (Enter: 'Yes' or 'No'): " << endl;
    cin >> userResponse;

    // if user wants to quit
    if(userResponse == "no" || userResponse == "No")
    {
      cout << "Goodbye." << endl;
      keepRunning = false; // ends the while loop
    }
    // if user wants to continue
    else if(userResponse == "yes" || userResponse == "Yes")
    {
      // asking user for the next file and setting it as userFile
      cout << "Enter the name of the file you would like to check: " << endl;
      cin >> userFile;
    }
    else
    {
      // exits program if user enters something other than yes or no
      throw runtime_error("You did not enter a valid choice. Goodbye.");
    }
  }


}
