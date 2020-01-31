// Workshop 3 - Templates
// Filename: List.h
// Author:   Sharan Shanmugaratnam
// Date:     2018-09-26

#ifndef W3_LIST_H
#define W3_LIST_H

template <class T, int N>
class List {
  // Private members
  //
  T c_List[N];
  size_t counter;
public:
  // Default Constructor
  //
  List() : c_List{}, counter { 0 } {}

  // Returns the number of entries in the array.
  //
  size_t size() const {
    return this->counter;
  }

  // Overloaded operator that returns the element in the requested array index.
  //
  const T& operator[](int index) const {
    return this->c_List[index]; // Return requested element.
  }

  // Overloaded operator that adds an element to the array if space is available.
  //
  void operator+=(const T& element) {
    if (counter < N) {
      c_List[counter] = element;
      counter++;
    }
  }
};

#endif