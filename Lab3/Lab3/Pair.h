// Workshop 3 - Templates
// Filename: Pair.h
// Author:   Sharan Shanmugaratnam
// Date:     2018-09-26

#ifndef W3_PAIR_H
#define W3_PAIR_H

template <class A, class B>
class Pair {
  // Private members
  //
  A c_a;
  B c_b;
public:
  // Default Constructor
  //
  Pair() : c_a{}, c_b{} {}

  // Custom Constructor
  //
  Pair(const A& a, const B& b) : c_a{ a }, c_b{ b } {} 

  // Returns a read-only version of stored 'a' information.
  //
  const A& getKey() const {
    return c_a;
  }

  // Returns a read-only version of stored 'b' information.
  //
  const B& getValue() const {
    return c_b;
  }
};

#endif