#include "PythagoreanTriplet.h"  // NOLINT(build/include)

PythagoreanTriplet::PythagoreanTriplet() :
  a(0), b(0), c(0), nsum(0)
{}


PythagoreanTriplet::PythagoreanTriplet(uint64_t a, uint64_t b, uint64_t c) :
  a(a), b(b), c(c), nsum(a+b+c)
{}


uint64_t PythagoreanTriplet::sum() const {
  return nsum;
}


bool PythagoreanTriplet::isPythagorean() const {
  return a * a + b * b == c * c;
}


void PythagoreanTriplet::setABC(uint64_t av, uint64_t bv, uint64_t cv) {
  a = av;
  b = bv;
  c = cv;
  nsum = a + b + c;
}
