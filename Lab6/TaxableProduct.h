// Workshop 6 - STL Containers
// Filename: TaxableProduct.h
// Author:   Sharan Shanmugaratnam
// Date:     2018-10-24

#ifndef _TAXABLE_PRODUCT_H_
#define _TAXABLE_PRODUCT_H_

#include "iProduct.h"
namespace w6 {

  class TaxableProduct : public Product {
    std::string taxType;
    double taxrate[2] = { 1.13, 1.08 };
  public:
    TaxableProduct() : Product() {

    }

    TaxableProduct(size_t newPC, double newPrice, std::string newTax) : Product(newPC, newPrice) {
      taxType = newTax;
    }

    double getPrice() const {
      if (taxType[0] == 'H') {
        return Product::getPrice() * taxrate[0];
      }
      else {
        return Product::getPrice() * taxrate[1];
      }
    }

    void display(std::ostream& os) const {
      Product::display(os);
      if (taxType[0] == 'H') {
        os << " HST";
      }
      else {
        os << " PST";
      }
    }

  };

}
#endif