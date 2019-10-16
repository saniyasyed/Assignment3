#include <iostream>
#include "SyntaxCheck.h"
#include <fstream>

using namespace std;
  //constructor
  SyntaxCheck::SyntaxCheck(string userFile)
  {
    this->userFile = userFile;
    lineCount = 0;
    delimeterStack = GenStack<Delimeter*>();
    ReadFile(userFile);
    CheckDelimeters();
    finalResults();

  }

  //destructor
  SyntaxCheck::~SyntaxCheck()
  {

  }

  //void method that takes in userFile, reads it, and adds each valid delimeter to the delimeterStack
  void SyntaxCheck::ReadFile(string userFile)
  {
    ifstream fileStreamer; //declaring ifstream object
    fileStreamer.open(userFile); //opening userFile
    string line;

    //checking if the file exists
    if(!fileStreamer)
    {
      throw runtime_error("The file could not be opened");
    }

    char symbol; // variable to store delimeter that is read from the file, and used to fill the delimeterStack
    while(getline(fileStreamer,line)) // iterating through the userFile, line by line
    {
        lineCount++; // incrementing lineCount for every line
        //used to disregard delimeters in quotes
        int openQuoteIndex = -1;
        int closeQuoteIndex = -1;

        // iterating through each char of the line to check for quotes
        for(int i = 0; i < line.length(); ++i)
        {
          //checking for a quote
          if(line[i] == '\"' || line[i] == '\'')
          {
            openQuoteIndex = i; // setting the index of the first quote to openQuoteIndex

            //iterating through the rest of the line, after the first quote to find the second quote
            for(int j = i + 1; j < line.length(); ++j)
            {
              //checking for the second quote
              if(line[j] == '\"' || line[j] == '\'')
              {
                closeQuoteIndex = j; //setting index of second quote to closeQuoteIndex
              }
            }
          }
          // checking if i is in the range of openQuoteIndex and closeQuoteIndex
          if(i >= openQuoteIndex && i <= closeQuoteIndex)
          {
            continue; // skipping this iteration because we don't count delimeters in quotes
          }
          //checking if a line starts with a comment, so we can ignore the rest of the line
          else if(line[i] == '/' && line[i+1] == '/')
          {
            break;
          }
          //after checking all cases with quotes and comments, we can check if we have a delimeter and add them to the delimeterStack
          else
          {
            if(line[i] == '(')
            {
              symbol = '(';
              Delimeter* d =  new Delimeter(symbol, lineCount); //creating a new Delimeter object filling it with the delimeter and its lineCount
              delimeterStack.push(d); // pushing the new Delimeter object to the delimeterStack

            }
            if(line[i] == ')')
            {
              symbol = ')';
              Delimeter* d = new Delimeter(symbol, lineCount); //creating a new Delimeter object filling it with the delimeter and its lineCount
              delimeterStack.push(d); // pushing the new Delimeter object to the delimeterStack

            }
            if(line[i] == '[')
            {
              symbol = '[';
              Delimeter* d = new Delimeter(symbol, lineCount); //creating a new Delimeter object filling it with the delimeter and its lineCount
              delimeterStack.push(d); // pushing the new Delimeter object to the delimeterStack

            }
            if(line[i] == ']')
            {
              symbol = ']';
              Delimeter* d = new Delimeter(symbol, lineCount); //creating a new Delimeter object filling it with the delimeter and its lineCount
              delimeterStack.push(d); // pushing the new Delimeter object to the delimeterStack

            }
            if(line[i] == '{')
            {
              symbol = '{';
              Delimeter* d = new Delimeter(symbol, lineCount); //creating a new Delimeter object filling it with the delimeter and its lineCount
              delimeterStack.push(d); // pushing the new Delimeter object to the delimeterStack

            }
            if(line[i] == '}')
            {
              symbol = '}';
              Delimeter* d = new Delimeter(symbol, lineCount); //creating a new Delimeter object filling it with the delimeter and its lineCount
              delimeterStack.push(d); // pushing the new Delimeter object to the delimeterStack
            }
          }

        }
      }
      fileStreamer.close(); // closing fileStreamer after reading the file
    }

    // void method that checks all the delimeter objects in the delimeterStack
    void SyntaxCheck::CheckDelimeters()
    {
      // iterating through the delimeterStack
      for(int i = 0; i <= delimeterStack.top; ++i)
      {
        Delimeter* currDeli = delimeterStack.myArray[i]; // creating a new delimeter object to hold the current delimeter of the stack

          // if the currDeli already has a valid delimeter match, skip this iteration
          if(currDeli->isMatch == true)
          {
            continue;
          }
          // if the delimeter is a closing delimeter that does not already have a match
          // it must be false, because an opening delimeter would have checked it already and changed it to a match
          else if(currDeli -> isClosingDelimeter())
          {
            continue; // skipping this iteration, keeping it's isMatch to its default false value
          }
          else
          {
            // iterating through every delimeter after the current delimeter to check for a match
            for(int j = i; j <= delimeterStack.top; ++j)
            {
              Delimeter* checkDeli = delimeterStack.myArray[j]; // creating new delimeter object to check

              //checks if the current delimeter matches with the checkDeli's delimeter
              if(checkDeli->symbol == currDeli->matchingSymbol)
              {
                //sets both opening and closing parameters to true
                currDeli->foundMatch();
                checkDeli->foundMatch();
                break; // breaking because their can only be one match for every delimeter
              }
            }
          }
        }
      }
  // void method that goes through the delimeterStack to check for the first unmatched delimeter
  void SyntaxCheck::finalResults()
  {
    //iterating through the delimeterStack
    for(int i = 0; i <= delimeterStack.top; ++i)
    {
      // if an object's isMatch is false, there is an unmatched delimeter
      //throws error and exits
      if(delimeterStack.myArray[i] -> isMatch == false)
      {
        string message = "LINE " + to_string(delimeterStack.myArray[i]->lineCount) + ": UNMATCHED ' " + string(1, delimeterStack.myArray[i]->symbol) + " '";
        throw runtime_error(message);
      }
    }
    // if all delimeters are matched
    cout << "Reached end of file. No unmatched delimeters found." << endl;
  }
