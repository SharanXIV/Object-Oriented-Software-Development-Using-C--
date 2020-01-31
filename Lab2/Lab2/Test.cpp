// Workshop 2 - Move and Copy Semantics
// Filename: Text.cpp
// Author:   Sharan Shanmugaratnam
// Date:     2018-09-19

#include "Text.h"

namespace w2 {

  // Default Constructor
  //
  Text::Text() { // Set to empty state.
    ArrStrPtr = nullptr;
    c_size = 0;
  }

  // Custom Constructor
  //
  Text::Text(const string filename) {
    fstream fs(filename);
    string lines;
    int lineCount = 0;

    if (fs.fail() == true) { // If file fails to open set empty state.
      this->c_size = 0;
      delete[] ArrStrPtr;
      return;
    }
    else {

      while (getline(fs, lines, '\n')) { // Extracts lines from file and stores them into 'lines'. Delimiter is newline.
        lineCount++;
      }
      
      fs.close(); // Close the file.
      ArrStrPtr = new string[lineCount]; // Allocate dynamic memory.

      fs.open(filename); //Re-open file.
      
      for (int i = 0; !fs.fail(); i++) { 
        getline(fs, ArrStrPtr[i], '\n'); // Copy into the string array. Delimiter is newline.
      }

      c_size = lineCount;

      fs.close(); // Close the file.
    }
  }

  // Copy Constructor
  //
  Text::Text(const Text &src) {
    ArrStrPtr = nullptr;
    c_size = 0;
    *this = src;
  }

  // Move Constructor
  //
  Text::Text(Text &&src) {
    *this = move(src);
  }

  // Copy Assignment Operator
  //
  Text& Text::operator=(const Text &src) {
    if (this != &src) { // Check for self-assignment.
      c_size = src.c_size;

      delete[] ArrStrPtr;
      ArrStrPtr = new string[c_size]; // Allocate dynamic memory.

      for (int i = 0; i < c_size; i++) { // Deep copy.
        ArrStrPtr[i] = src.ArrStrPtr[i];
      }
    }
    return *this;
  }

  // Move Assignment Operator
  //
  Text& Text::operator=(Text &&src) {
    if (this != &src) { // Check for self-assignment.
      c_size = src.c_size;
      ArrStrPtr = src.ArrStrPtr; // Pointer will now point to src's memory address.
      src.ArrStrPtr = nullptr; // Avoiding memory leak.
      src.c_size = 0;
    }
    return *this;
  }

  // Destructor
  //
  Text::~Text() {
    delete[] ArrStrPtr;
    ArrStrPtr = nullptr;
  }

  // Member function that returns number of records of text data
  //
  size_t Text::size() const {
    return c_size;
  }
}