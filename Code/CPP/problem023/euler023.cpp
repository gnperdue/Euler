#include <iostream>  // NOLINT(readability/streams)
#include <unordered_set>
#include "ProperDivisors.h"  // NOLINT(build/include)

void check_abundance(uint64_t number) {
  ProperDivisors pd;
  std::cout << "checking " << number << std::endl;
  pd.set(number);
  for (auto i : pd.divisors()) {
    std::cout << i << std::endl;
  }
  std::cout << "sum of divisors = " << pd.sum_of_divisors() << std::endl;
}


int main(int argc, char * argv[]) {

  ProperDivisors pd;

  uint64_t smallest_abundant = 12;
  std::unordered_set<uint64_t> abundants = {smallest_abundant};

  // all numbers larger than this number may be written as the sum of two
  // abundant numbers - so, when looking for all abundant numbers we need
  // not look higher than this for this problem. add 1 for looping convenience
  uint64_t ubound = 28123 + 1;
  if (argc > 1) {
    ubound = (uint64_t)atoi(argv[1]);
    std::cout << "upper bound is " << ubound << std::endl;
  }

  for (uint64_t i = smallest_abundant; i < ubound; ++i) {
    pd.set(i);
    if (pd.sum_of_divisors() > i) {
      abundants.insert(i);
    }
  }

  // std::cout << "all abundants below " << ubound << std::endl;
  // for (auto i : abundants) {
  //   std::cout << i << std::endl;
  // }
  // std::cout << "n abundants below " << ubound << " = " <<
  //   abundants.size() << std::endl;

  uint64_t sum = 1;  // 1 is not the sum of two abundant numbers
  for (uint64_t i = 2; i < ubound; ++i) {
    bool is_the_sum_of_abundant_numbers = false;
    uint64_t max_sum_check = i / 2 + 1;
    // uint64_t max_sum_check = i;
    for (uint64_t j = 1; j < max_sum_check; ++j) {
      auto elem1 = abundants.find(j);
      bool abund1 = elem1 != abundants.end();
      if (abund1) {
        auto elem2 = abundants.find(i - j);
        bool abund2 = elem2 != abundants.end();
        if (abund2) {
          is_the_sum_of_abundant_numbers = true;
          break;
        }
      }
    }
    if (!is_the_sum_of_abundant_numbers) {
      sum += i;
    }
  }
  std::cout << sum << std::endl;

  return 0;
}
