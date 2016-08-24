#include <sstream>
#include "TriangularNumber.h"   // NOLINT(build/include)

TriangularNumber::TriangularNumber() :
  initialValue(1L), triangularNumber(1L) {}

TriangularNumber::TriangularNumber(uint64_t init) :
  initialValue(init), triangularNumber(1L) {
  calcTriangle();
}

void TriangularNumber::calcTriangle() {
  uint64_t value = initialValue;
  triangularNumber = 0L;
  while (value != 0L) {
    triangularNumber += value;
    value--;
  }
}

void TriangularNumber::set(uint64_t index) {
  initialValue = index;
  calcTriangle();
}

uint64_t TriangularNumber::get() const {
  return triangularNumber;
}

std::vector<uint64_t> TriangularNumber::factors() const {
  std::vector<uint64_t> factors {1L};  // NOLINT(build/include_what_you_use)
  uint64_t fact = 2L;
  while (fact <= triangularNumber) {
    if (triangularNumber % fact == 0)
      factors.push_back(fact);
    fact++;
  }
  return factors;
}


