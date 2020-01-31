// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// Filename: process.cpp
// Author:   Sharan Shanmugaratnam
// Date:     2018-09-10

#include <iostream>
#include "process.h"
#include "CString.h"

namespace w1 {
  void process(const char* string, std::ostream& os) {
    static int counter = 0;
    CString str2(string);
    os << counter++ << ": " << str2 << std::endl;
  }
}