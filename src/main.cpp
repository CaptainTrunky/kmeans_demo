#include "types.h"
#include <kmeans.h>

#include <iostream>

#include <boost/numeric/ublas/io.hpp>


int main () {
  Types::Point p1(5);

  for (size_t i = 0; i< 5; ++i) {
    p1(i) = static_cast<double>(i);
  }

  std::cout << p1 << '\n';

  return 0;
}
