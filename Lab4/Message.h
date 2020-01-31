// Workshop 4 - Containers
// Filename: Message.h
// Author:   Sharan Shanmugaratnam
// Date:     2018-10-03

#ifndef W4_MESSAGE_H
#define W4_MESSAGE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace w5 {
  class Message {
    string c_user;
    string c_reply;
    string c_tweet;

  public:
    // Default Constructor
    //
    Message();

    // Custom Constructor
    //
    Message(ifstream&, char);
    bool empty() const;
    
    // Display function
    //
    void display(ostream&) const;
  };
}
#endif