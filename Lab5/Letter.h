// Workshop 5 - Lambda Expressions
// Filename: Letter.h
// Author:   Sharan Shanmugaratnam
// Date:     2018-10-10

#ifndef SICT_LETTER_H
#define SICT_LETTER_H

namespace sict {

  enum Letter {
    aPlus, a, bPlus, b, cPlus, c, dPlus, d, f
  };

  template <class T>
  const char* convertLetter(const T& letter) {
    if (letter == Letter::aPlus) {
      return "A+";
    }
    else if (letter == Letter::a) {
      return "A";
    }
    else if (letter == Letter::bPlus) {
      return "B+";
    }
    else if (letter == Letter::b) {
      return "B";
    }
    else if (letter == Letter::cPlus) {
      return "C+";
    }
    else if (letter == Letter::c) {
      return "C";
    }
    else if (letter == Letter::dPlus) {
      return "D+";
    }
    else if (letter == Letter::d) {
      return "D";
    }
    else if (letter == Letter::f) {
      return "F";
    }
  }
}
#endif