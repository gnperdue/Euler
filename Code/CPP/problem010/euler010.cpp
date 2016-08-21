#include <iostream>           // NOLINT(readability/streams)
#include "PrimeNumbers.h"     // NOLINT(build/include)

int main(int argc, char * argv[]) {

  PrimeNumbers pn;
  uint64_t largestPrime = pn[ pn.size() - 1 ];
  uint64_t sum = largestPrime;
  while (largestPrime < 2000000) {
    pn.addPrimeNumber();
    largestPrime = pn[ pn.size() - 1 ];
    sum += largestPrime;
  }
  // don't keep the last one, and don't include 1 in the sum
  sum -= (largestPrime + 1);
  std::cout << sum << std::endl;

  return 0;
}

