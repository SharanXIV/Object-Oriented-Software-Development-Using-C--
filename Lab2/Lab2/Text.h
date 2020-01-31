// Workshop 2 - Move and Copy Semantics
// Filename: Text.h
// Author:   Sharan Shanmugaratnam
// Date:     2018-09-19

#ifndef W2_TEXT_H
#define W2_TEXT_H

#include <string>
#include <fstream>

using namespace std;

namespace w2 {
  class Text {
    string* ArrStrPtr;
    int c_size;

  public:
    // Default Constructor
    //
    Text();
    
    // Custom Constructor
    //
    Text(const string filename);
    
    // Copy Constructor
    //
    Text(const Text &src);
    
    // Move Constructor (passing through rvalue)
    //
    Text(Text &&src);

    // Copy Assignment Operator
    //
    Text& operator=(const Text &src);

    // Move Assignment Operator
    //
    Text& operator=(Text &&src);        
    
    // Destructor
    //
    ~Text();                            
    
    // Member function that returns number of records of text data
    //
    size_t size() const;
  };
}

#endif