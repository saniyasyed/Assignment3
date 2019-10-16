#include <iostream>
#include "GenStack.h"
#include "Delimeter.h"

using namespace std;

class SyntaxCheck
{
public:
  SyntaxCheck(string userFile); // constructor
  ~SyntaxCheck(); //deconstructor

  // SyntaxCheck methods
  void ReadFile(string userFile);
  void CheckDelimeters();
  void finalResults();

  // declaring the delimeterStack, full of Delimeter objects
  GenStack<Delimeter*> delimeterStack;

  // member variables
  int lineCount;
  string userFile;



};
