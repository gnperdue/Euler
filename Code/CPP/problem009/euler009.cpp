#include <iostream>  // NOLINT(readability/streams)
#include "PythagoreanTriplet.h"  // NOLINT(build/include)

int main(int argc, char * argv[]) {
  PythagoreanTriplet pt;

  for (uint64_t i = 0; i < 1001; ++i) {
    for (uint64_t j = i + 1; j < 1001; ++j) {
      for (uint64_t k = j + 1; k < 1001; ++k) {
        if (i + j + k == 1000) {
          pt.setABC(i, j, k);
          if (pt.isPythagorean()) {
            std::cout << "i = " << i << "; "
              << "j = " << j << "; "
              << "k = " << k << " is Pythagorean. Product = "
              << (i * j * k) << std::endl;
          }
        }
      }
    }
  }

  return 0;
}

