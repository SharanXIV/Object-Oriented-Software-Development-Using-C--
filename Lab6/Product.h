// Workshop 6 - STL Containers
// Filename: Product.h
// Author:   Sharan Shanmugaratnam
// Date:     2018-10-24

#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include "iProduct.h"
namespace w6 {

  class Product : public iProduct {
    size_t productCode;
    double price;
  public:
    Product() {
      productCode = 0;
      price = 0.0;
    }

    Product(size_t newPC, double newPrice) {
      productCode = newPC;
      price = newPrice;
    }

    double getPrice() const {
      return this->price;
    }

    void display(std::ostream& os) const {
      os << std::fixed << std::right << std::setw(10) << productCode << std::setprecision(2) << std::setw(10) << price;
    }

  };

}
#endif