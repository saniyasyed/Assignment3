#include <iostream>

using namespace std;

template <class T>
class GenStack
{
public:
  // constructor
  GenStack()
  {
    //initialization of default values
    myArray = new T[128];
    size = 50;
    top = -1;
  }
  // overloaded constructor
  GenStack(int maxSize)
  {
    myArray = new T[maxSize]; //allocating array dynamically -- "new" -- on the heap
    size = maxSize;
    top = -1;
  }
  // destructor
  ~GenStack()
  {
    //build character
    // deleting myArray
    // delete myArray;
  }

  void push(T d)
  {
    //need to check error/boundary check
    if(!isFull())
    {
      myArray[++top] = d;
    }
    else
    {
      cout << "Array has reached capacity. Resizing array." << endl;
      resizeArray();
      // myArray[++top] = d;
      push(d);
    }
  }

  T pop()
  {
    //error checking, make sure it is not isEmpty
    if(isEmpty())
    {
    throw runtime_error("Your stack is empty. Cannot pop.");
    }
    return myArray[top--];
  }

  T peek()//AKA top()
  {
    //check if empty
    if(isEmpty())
    {
    throw runtime_error("Your stack is empty. Cannot peek.");
    }
    else
    {
      return myArray[top];
    }
  }

  bool isFull()
  {
    return (top == size - 1);
  }

  bool isEmpty()
  {
    return (top == -1);
  }


  int size;
  int top;

  T *myArray; // pointer: memory address;

private:
  //method used for resizing the array when it gets full
  void resizeArray()
  {
    T* tempArray = new T[size * 2];
    //copying everything from the original array into the tempArray
    for(int i = 0; i < size; ++i)
    {
      tempArray[i] = myArray[i];
    }
    delete[] myArray;
    myArray = tempArray;
    size = size * 2; //updating size to match the new resized array
  }
};
