// Workshop 4 - Containers
// Filename: Notifications.h
// Author:   Sharan Shanmugaratnam
// Date:     2018-10-03

#ifndef W4_NOTIFICATIONS_H
#define W4_NOTIFICATIONS_H

#include "Message.h"

using namespace std;

namespace w5 {
  class Notifications {
    Message* pMessage[10];
    size_t c_size = 10;
    size_t count = 0;
  
  public:
    // Default Constructor
    //
    Notifications();
    
    // Copy Constructor
    //
    Notifications(const Notifications&);
    
    // Copy Assignment Operator
    //
    Notifications& operator=(const Notifications&);
    
    // Move Constructor
    //
    Notifications(Notifications&&);
    
    // Move Assignment Operator
    //
    Notifications& operator=(Notifications&&);
    
    // Destructor
    //
    ~Notifications();

    // Overloaded operator
    //
    void operator+=(const Message& msg);
    
    // Display function
    //
    void display(std::ostream& os) const;
  };
}

#endif