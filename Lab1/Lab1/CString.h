// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Filename: CString.h
// Author:   Sharan Shanmugaratnam
// Date:     2018-09-10

#include <iostream>

#ifndef W1_CSTRING_H
#define W1_CSTRING_H

namespace w1 {
  class CString {
    const int MAX;
    char c_string[10];
  public:
    CString(); 
    CString(const char* str);
    void display(std::ostream& os) const;
  };

  std::ostream& operator<<(std::ostream& os, CString& str);
}

#endif