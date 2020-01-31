// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include <fstream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {

  std::ofstream ofs("Lab5Output.txt");

  std::cout << "Command Line : ";
  for (int i = 0; i < argc; i++) {
    std::cout << argv[i] << ' ';
  }
  std::cout << std::endl;

  if (argc == 1) {
    std::cerr << "\n*** Insufficient number of arguments ***\n";
    std::cerr << "Usage: " << argv[0] << " fileName \n";
    return 1;
  }
  else if (argc != 2) {
    std::cerr << "\n*** Too many arguments ***\n";
    std::cerr << "Usage: " << argv[0] << " fileName \n";
    return 2;
  }

  //Update the main functions as per the specifications here
  auto letter = [](double tempGrade) {
    string letterGrade;

    if (tempGrade >= 90) {
      return convertLetter(Letter::aPlus);
    }
    else if (tempGrade >= 80) {
      return convertLetter(Letter::a);
    }
    else if (tempGrade >= 75) {
      return convertLetter(Letter::bPlus);
    }
    else if (tempGrade >= 70) {
      return convertLetter(Letter::b);
    }
    else if (tempGrade >= 65) {
      return convertLetter(Letter::cPlus);
    }
    else if (tempGrade >= 60) {
      return convertLetter(Letter::c);
    }
    else if (tempGrade >= 55) {
      return convertLetter(Letter::dPlus);
    }
    else if (tempGrade >= 50) {
      return convertLetter(Letter::d);
    }
    else if (tempGrade < 50) {
      return convertLetter(Letter::f);
    }
    else {
      throw "Not a valid grade.";
    }
  };

  try {
    Grades grades(argv[1]);
    grades.displayGrades(ofs, letter);
  }
  catch (const char* error) {
    throw error;
  }


  ofs.close();
}