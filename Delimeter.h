#include <iostream>

using namespace std;

class Delimeter
{
public:
  Delimeter(char symbol, int lineCount); // constructor
  ~Delimeter(); // destructor

  // Delimeter methods
  void foundMatch();
  void checkMatchingDel();
  bool isClosingDelimeter();
  
  // member variables
  char symbol; // delimeter character
  int lineCount; // line number of the symbol
  bool isMatch; // boolean variable that is true if the delimeter has a match
  char matchingSymbol; // variable that holds the delimeter's matching delimeter

};
