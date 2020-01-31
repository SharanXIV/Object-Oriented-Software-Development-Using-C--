// Workshop 4 - Containers
// Filename: Notifications.cpp
// Author:   Sharan Shanmugaratnam
// Date:     2018-10-03

#include <utility>
#include "Notifications.h"

using namespace std;

namespace w5 {

  // Default Constructor
  //
  Notifications::Notifications() {
    for (int i = 0; i < c_size; i++) {
      pMessage[i] = nullptr;
    }
  }

  // Copy Constructor
  //
  Notifications::Notifications(const Notifications& src) {
    c_size = src.c_size;

    for (int i = 0; i < c_size; i++) {
      pMessage[i] = new Message;
    }

    for (int i = 0; i < c_size; i++) {
      pMessage[i] = src.pMessage[i];
    }
  }

  // Copy Assignment Operator
  //
  Notifications& Notifications::operator=(const Notifications& src) {
    if (this != &src) { // Check for self-assignment.
      //c_size = src.c_size;
      for (int i = 0; i < c_size; i++) {
        delete pMessage[i];
        pMessage[i] = new Message;
        *this->pMessage[i] = *src.pMessage[i];
      }
    }

    return *this;
  }

  // Move Constructor
  //
  Notifications::Notifications(Notifications&& src) {
    for (int i = 0; i < c_size; i++) {
      pMessage[i] = nullptr;
    }
    *this = move(src);
  }

  // Move Assignment Operator
  //
  Notifications& Notifications::operator=(Notifications&& src) {
    if (this != &src) { // Check for self-assignment.
      c_size = src.c_size;

      for (int i = 0; i < c_size; i++) {
        delete pMessage[i];
        pMessage[i] = src.pMessage[i];
        src.pMessage[i] = nullptr;
      }
    }

    return *this;
  }

  // Destructor
  //
  Notifications::~Notifications() {
    for (int i = 0; i < c_size; i++) { // De-allocate dynamic memory.
      delete pMessage[i];
      pMessage[i] = nullptr;
    }
    c_size = 0;
  }

  // Overloaded operator
  //
  void Notifications::operator+=(const Message& msg) {
    //if (c_size < 10) {
      //this->pMessage[c_size++] = new Message(msg);
      pMessage[count] = new Message;
      *this->pMessage[count] = msg;
      count++;
    //}
  }

  // Display function
  //
  void Notifications::display(std::ostream& os) const {
    for (int i = 0; i < c_size; i++) {
      if (pMessage[i] != nullptr) {
        pMessage[i]->display(os);
      }
    }
  }

}