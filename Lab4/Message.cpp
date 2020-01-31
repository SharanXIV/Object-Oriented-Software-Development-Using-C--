// Workshop 4 - Containers
// Filename: Message.cpp
// Author:   Sharan Shanmugaratnam
// Date:     2018-10-03

#include "Message.h"

using namespace std;

namespace w5 {

  // Default Constructor
  //
  Message::Message() {
    c_user = '\0';
    c_reply = '\0';
    c_tweet = '\0';
  }

  // Custom Constructor
  //
  Message::Message(ifstream& in, char c) {
    string t_user;
    string t_reply;
    string t_tweet;

    getline(in, t_tweet, c);
    int position = 0;
    position = t_tweet.find(' '); // Setting the position after the user's name.

    // Check if there is a message after username.
    if (position > 0) {
      t_user = t_tweet.substr(0, position);
      t_tweet = t_tweet.substr(position + 1, t_tweet.length());

      if (t_tweet[0] == '@') { // Checking if there is a user being replied to.
        position = t_tweet.find(' '); // Setting position to after reply username.
        t_reply = t_tweet.substr(1, position);
        t_tweet = t_tweet.substr(position + 1, t_tweet.length());
      }

      c_user = t_user;
      c_reply = t_reply;
      c_tweet = t_tweet;
    }
  }

  bool Message::empty() const {
    if ((c_user[0] == '\0') && (c_tweet[0] == '\0')) {
      return true;
    }
    else {
      return false;
    }
  }

  // Display function
  //
  void Message::display(ostream& os) const {
    os << "Message" << "\nUser  : " << c_user << endl;

    if (c_reply[0] != '\0') { // Checks for reply username.
      os << "Reply : " << c_reply << endl;
    }

    os << "Tweet : " << c_tweet << endl << "\n";
  }
}