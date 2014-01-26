#include <iostream>
#include "DigitSums.h"


int main(int argc, const char *argv[])
{
  DigitSums digitSums;
  std::vector<unsigned> numbers;
  unsigned max = 5 * 9 * 9 * 9 * 9 * 9;
  for (unsigned i=2;i<max;++i) {
    digitSums.setNumber(i);
    if (i == digitSums.getDigitsToPowerSum(5) ) {
      numbers.push_back(i);
      std::cout << i << std::endl;
    }
  }
  unsigned sum = 0;
  for (auto i : numbers) {
    sum += i;
  }
  std::cout << "The final sum is " << sum << std::endl;

  return 0;
}


