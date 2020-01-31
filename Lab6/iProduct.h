// Workshop 6 - STL Containers
// Filename: iProduct.h
// Author:   Sharan Shanmugaratnam
// Date:     2018-10-24

#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

namespace w6 {

  class iProduct {
  public:
    virtual double getPrice() const = 0;
    virtual void display(std::ostream&) const = 0;
  };

  std::ostream& operator<<(std::ostream& os, const iProduct& src);
  iProduct* readProduct(std::ifstream& is);

}
#endif

