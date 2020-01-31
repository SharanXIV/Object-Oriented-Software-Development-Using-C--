// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Filename: CString.cpp
// Author:   Sharan Shanmugaratnam
// Date:     2018-09-10

#include <cstring>
#include <iostream>
#include "CString.h"

// Had to suppress warning 4996 for strncpy error or else it would not compile.

int STORED = 3;

namespace w1 {

  // Default constructor
  //
  CString::CString() : MAX{ 0 }, c_string{ '\0' } {  } // Set empty state.

  CString::CString(const char* str) : MAX{ STORED } {
    if (str == nullptr) { // Set empty state.
      c_string[0] = '\0';
    }
    else {
      strncpy(c_string, str, MAX);
      c_string[MAX] = '\0';
    }
  }

  void CString::display(std::ostream& os) const {
    os << c_string;
  }

  std::ostream& operator<<(std::ostream& os, CString& str) {
    str.display(os);
    return os;
  }
}