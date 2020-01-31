// Workshop 5 - Lambda Expressions
// Filename: Grades.h
// Author:   Sharan Shanmugaratnam
// Date:     2018-10-10

#ifndef SICT_GRADES_H
#define SICT_GRADES_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace sict {
  class Grades {
    unsigned int* studentNo;
    double* studentGrade;
    int size;
  public:
    Grades(const char*);

    Grades(const Grades &src) = delete;
    Grades& operator=(const Grades &src) = delete;
    Grades& operator=(Grades &&src) = delete;
    Grades(Grades &&src) = delete;

    ~Grades();

    template<class F>
    void displayGrades(std::ostream& os, F letterGrade) const {
      for (int i = 0; i < size; i++) {
        os << studentNo[i] << " " << studentGrade[i] << " " << letterGrade(studentGrade[i]) << endl;
      }
    }
  };
}

#endif