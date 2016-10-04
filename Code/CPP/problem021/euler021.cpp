#include <iostream>  // NOLINT(readability/streams)
#include <iomanip>
#include <map>

#include "ProperDivisors.h"  // NOLINT(build/include)

int main(int argc, char * argv[]) {

  ProperDivisors pd;
  std::map<uint64_t, uint64_t> nums_and_sums;
  for (uint64_t n = 9999; n > 1; --n) {
    pd.set(n);
    nums_and_sums[n] = pd.sum_of_divisors();
  }
  // for (auto x = nums_and_sums.begin(); x != nums_and_sums.end(); ++x) {
  //   std::cout << std::setfill(' ') << std::setw(4) << x->first << " : ";
  //   std::cout << x->second << std::endl;
  // }

  std::map<uint64_t, uint64_t> amicable_pairs;
  for (auto x = nums_and_sums.begin(); x != nums_and_sums.end(); ++x) {
    uint64_t k1 = x->first;
    uint64_t v1 = x->second;
    auto k = nums_and_sums.find(v1);
    if (k != nums_and_sums.end()) {
      uint64_t v2 = k->second;
      if (v2 == k1) {
        if (v1 > v2) {
          amicable_pairs[v1] = v2;
        } else if (v2 > v1) {
          amicable_pairs[v2] = v1;
        }
      }
    }
  }

  uint64_t amicable_sum = 0;
  for (auto x = amicable_pairs.begin(); x != amicable_pairs.end(); ++x) {
    amicable_sum += (x->first + x->second);
  }
  std::cout << "  amicable_sum = " << amicable_sum << std::endl;

  return 0;
}

