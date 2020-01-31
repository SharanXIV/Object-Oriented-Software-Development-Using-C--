// Workshop 6 - STL Containers
// w6.cpp

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "iProduct.h"

int main(int argc, char** argv) {

  std::ofstream ofs("Lab6Output.txt");

  std::cout << "\nCommand Line : ";
  for (int i = 0; i < argc; i++) {
    std::cout << argv[i] << ' ';
  }
  std::cout << std::endl;
  if (argc != 2) {
    std::cerr << "\n***Incorrect number of arguments***\n";
    return 1;
  }
  std::ifstream productList(argv[1]);
  if (!productList) {
    std::cerr << "\n***Failed to open file " << argv[1] << "***\n";
    return 2;
  }
  ofs << std::fixed << std::setprecision(2);

  //Add your code here
  try {
    std::vector<w6::iProduct*> vectorProduct;
    unsigned int count = 0;
    double total = 0.0;

    // Read vector elements.
    while (!productList.eof()) {
      vectorProduct.push_back(w6::readProduct(productList));
      count++;
    }

    ofs << std::fixed << std::left << std::setw(10) << "Product No" << std::setw(10) << std::right << "Price" << " Taxable \n";

    // Display vector elements.
    for (int i = 0; i < count; i++) {
      if (vectorProduct[i] != nullptr) {
        ofs << *(vectorProduct[i]);
        ofs << '\n';
        total += vectorProduct[i]->getPrice();
      }
    }

    ofs << std::fixed << std::right << std::setw(10) << "Total" << std::setw(10) << total;
  }
  catch (const char* error) {
    ofs << error;
    return 2;
  }

  std::cout << "Results are in Lab6Output.txt\nPress any key to continue ... ";
  std::cin.get();

  ofs.close();
}

