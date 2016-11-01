#include "ProperDivisors.h"   // NOLINT(build/include)
#include <cmath>
#include <cstdlib>

//-----------------------------------------------------------------------------
ProperDivisors::ProperDivisors() : value(0) {}

//-----------------------------------------------------------------------------
ProperDivisors::ProperDivisors(uint64_t val) : value(val) {}

//-----------------------------------------------------------------------------
void ProperDivisors::set(uint64_t val) {
  value = val;
}

//-----------------------------------------------------------------------------
std::vector<uint64_t> ProperDivisors::divisors() const {
  std::vector<uint64_t> divs; // NOLINT(build/include_what_you_use)
  std::set<uint64_t> divs_set = divisors_set();
  for (auto i : divs_set) {
    divs.push_back(i);
  }
  return divs;
}

//-----------------------------------------------------------------------------
std::set<uint64_t> ProperDivisors::divisors_set() const { // NOLINT(build/include_what_you_use)
  std::set<uint64_t> divs = {1};  // NOLINT(build/include_what_you_use)
  uint64_t ubound = ceil(sqrt(value));
  for (uint64_t x = 2; x <= ubound; ++x) {
    // get quotient and remainder in one step - actually optimized?
    std::lldiv_t result = lldiv(value, x);
    if (result.rem == 0) {
      divs.insert(x);
      divs.insert(result.quot);
    }
  }
  return divs;
}

//-----------------------------------------------------------------------------
uint64_t ProperDivisors::sum_of_divisors() const {
  std::set<uint64_t> divs = divisors_set(); // NOLINT(build/include_what_you_use)
  uint64_t sum = 0;
  for (auto i : divs) {
    sum += i;
  }
  return sum;
}

