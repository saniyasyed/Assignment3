#include <iostream>
#include "Delimeter.h"

using namespace std;

//constructor
Delimeter::Delimeter(char symbol, int lineCount)
{
  this->symbol = symbol;
  this->lineCount = lineCount;
  isMatch = false;
  checkMatchingDel();

}
//deconstructor
Delimeter::~Delimeter()
{
}

// void method that changes isMatch to true
// we call this when SyntaxCheck finds a delimeter match
void Delimeter::foundMatch()
{
  this->isMatch = true;
}

// void method that assigns matchingSymbol to the delimeter's matching delimeter
void Delimeter::checkMatchingDel()
{
  if(symbol == '(')
    matchingSymbol = ')';
  if(symbol == ')')
    matchingSymbol = '(';
  if(symbol == '[')
    matchingSymbol = ']';
  if(symbol == ']')
    matchingSymbol = '[';
  if(symbol == '{')
    matchingSymbol = '}';
  if(symbol == '}')
    matchingSymbol = '{';
}

// bool method that returns true if delimeter is a closing vector
bool Delimeter::isClosingDelimeter()
{
  if(symbol == ')')
    return true;
  else if(symbol == ']')
    return true;
  else if(symbol == '}')
    return true;
  else
    return false;
}
