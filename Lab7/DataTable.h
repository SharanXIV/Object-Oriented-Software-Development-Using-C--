// Workshop 7 - STL Algorithms
// Filename: Product.h
// Author:   Sharan Shanmugaratnam
// Date:     2018-10-30

#ifndef _DATATABLE_H_
#define _DATATABLE_H_

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

namespace w7 {
  template <class T>
  class DataTable {
    std::vector<T> x, y;
    int fieldWidth, decimals;

  public:
    DataTable(std::ifstream& is, int width, int dec) {
      fieldWidth = width;
      decimals = dec;
      T fx, fy;

      while (is.good()) {
        is >> fx >> fy;
        x.push_back(fx);
        y.push_back(fy);
      }
    }

    ~DataTable() {
      //Do you have to empty vectors?
    }

    T mean() const {
      int n = x.size();
      T avg = std::accumulate(y.begin(), y.end(), (T)0) / n;
      return avg;
    }

    T sigma() const {
      int n = x.size();
      T y_m = mean();
      return std::sqrt(std::accumulate(y.begin(), y.end(), (T)0,
        [=](T ss, T yy) {return ss + (yy - y_m)*(yy - y_m); }
      ) / (n - 1));
    }

    T median() const {
      int n = x.size();
      std::vector<T> temp(y.size());
      std::copy(y.begin(), y.end(), temp.begin());
      int i;

      std::sort(temp.begin(), temp.end());

      if (n % 2 == 0) {
        i = temp.size() / 2;
      }
      else {
        i = (temp.size() + 1) / 2;
      }

      return temp[i];
    }

    void regression(T& slope, T& y_intercept) const {
      int n = x.size();
      T x_s = std::accumulate(x.begin(), x.end(), (T)0);
      T y_s = std::accumulate(y.begin(), y.end(), (T)0);
      T x_x = std::inner_product(x.begin(), x.end(), x.begin(), (T)0);
      T x_y = std::inner_product(x.begin(), x.end(), y.begin(), (T)0);

      slope = (n * x_y - x_s * y_s) / (n * x_x - x_s * x_s);
      y_intercept = (y_s - slope * x_s) / n;
    }

    void display(std::ostream& os) const {
      os << std::setw(fieldWidth) << "x";
      os << std::setw(fieldWidth) << "y";
      os << std::endl;
      os << std::fixed << std::setprecision(decimals);

      for (auto i = 0; i < x.size(); i++) {
        os << std::setw(fieldWidth) << x[i];
        os << std::setw(fieldWidth) << y[i];
        os << std::endl;
      }
    };

  };

  template <class T>
  std::ostream& operator<<(std::ostream& fs, const DataTable<T>& data) {
    data.display(fs);
    return fs;
  }
}
#endif