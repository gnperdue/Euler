#include "Combinatorics.h"   // NOLINT(build/include)
#include <vector>

uint64_t Combinatorics::combination(uint64_t n, uint64_t k) {
  // n! / (k! (n - k)!) = (n * (n-1) * ... * (n-k+1))/k!
  if (n < 20) {  // seems to be about as big as 64 bit int goes
    uint64_t numerator = Combinatorics::factorial(n, n - k);
    uint64_t denominator = Combinatorics::factorial(k);
    return numerator / denominator;
  }
  std::vector<uint64_t> nums;
  std::vector<uint64_t> dems;
  for (uint64_t i = n; i > n - k; --i) {
    nums.push_back(i);
  }
  for (uint64_t i = k; i > 0; --i) {
    dems.push_back(i);
  }
  bool found_a_division = true;
  while (found_a_division) {
    found_a_division = false;
    for (auto &i : nums) {
      for (auto &j : dems) {
        if (i % j == 0 && j != 1) {
          i = i / j;
          j = 1;
          found_a_division = true;
        }
      }
    }
  }
  uint64_t numerator = 1;
  for (auto i : nums) {
    numerator *= i;
  }
  uint64_t denominator = 1;
  for (auto i : dems) {
    denominator *= i;
  }
  return numerator / denominator;
}

uint64_t Combinatorics::permutation(uint64_t n, uint64_t k) {
  // n! / (n - k)!
  return Combinatorics::factorial(n, n - k);
}

uint64_t Combinatorics::factorial(uint64_t n, uint64_t truncate) {
  uint64_t fact = 1;
  while (n > truncate) {
    fact *= n--;
  }
  return fact;
}

