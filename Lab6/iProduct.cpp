// Workshop 6 - STL Containers
// Filename: iProduct.cpp
// Author:   Sharan Shanmugaratnam
// Date:     2018-10-24

#include "iProduct.h"
#include "Product.h"
#include "TaxableProduct.h"

namespace w6 {
  std::ostream& operator<<(std::ostream& os, const iProduct& src) {
    src.display(os);
    return os;
  }

  iProduct* readProduct(std::ifstream& is) {
    std::string line;
    std::string tempCode;
    std::string tempPrice;
    std::string taxType;
    iProduct* ptr = nullptr;

    getline(is, line, '\n');

    if (line == "") {
      return ptr;
    }

    tempCode = line.substr(0, 5);
    tempPrice = line.substr(6, 11);

    if (line.length() < 12) {
      ptr = new Product(std::stoul(tempCode), std::stod(tempPrice));
    }
    else {
      if (line.at(12) == 'H' || line.at(12) == 'P') {
        taxType = line.substr(12);
        ptr = new TaxableProduct(std::stoul(tempCode), std::stod(tempPrice), taxType);
      }
      else {
        throw "Tax code is invalid! \n";
      }
    }

    return ptr;
  }
}