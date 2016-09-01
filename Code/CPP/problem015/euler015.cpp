#include <iostream>  // NOLINT(readability/streams)
#include "Combinatorics.h"  // NOLINT(build/include)

int main(int argc, char * argv[]) {
  Combinatorics c;
  uint64_t k = 20;
  uint64_t n = k * 2;

  std::cout << "comb(" << n << "," <<  k << ") = "
    << c.combination(n, k) << std::endl;
  return 0;
}

