#include <iostream>
#include <fstream>
#include <string>
#include "Grades.h"

namespace sict {
  Grades::Grades(const char* fileName) {
    ifstream fs(fileName);
    size = 0;
    string lines;
    string temp;

    if (!fs.is_open()) { // If file fails to open set empty state.
      studentNo = nullptr;
      studentGrade = nullptr;
      throw "File not found.";
    }
    else {
      while (getline(fs, lines, '\n')) { // Extracts lines from file and stores them into 'lines'. Delimiter is newline.
        size++;
      }

      studentNo = new unsigned int[size];
      studentGrade = new double[size];

      fs.clear();
      fs.seekg(0);

      for (int i = 0; i < size; i++) {
        getline(fs, lines, '\n');
        temp = lines.substr(0, 7);
        studentNo[i] = stoul(temp, nullptr, 0);
        temp = lines.substr(8, 11);
        studentGrade[i] = stod(temp, nullptr);
      }
    }
  }

  Grades::~Grades() {
    delete[] studentNo;
    delete[] studentGrade;
  }
}