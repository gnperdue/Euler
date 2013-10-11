#include <sstream>
#include "TriangularNumber.h"

TriangularNumber::TriangularNumber() : 
  initialValue(1L), triangularNumber(1L)
{
}

TriangularNumber::TriangularNumber(unsigned long init) : 
  initialValue(init), triangularNumber(1L)
{
  calcTriangle();
}

void TriangularNumber::calcTriangle() 
{
  unsigned long value = initialValue;
  triangularNumber = 0L;
  while (value != 0L) {
    triangularNumber += value;
    value--;
  }
}

void TriangularNumber::set(unsigned long index)
{
  initialValue = index;
  calcTriangle();
}

unsigned long TriangularNumber::get() const
{
  return triangularNumber;
}

std::vector<unsigned long> TriangularNumber::factors() const
{
  std::vector<unsigned long> factors {1L};
  unsigned long fact = 2L;
  while (fact <= triangularNumber) {
    if ( triangularNumber % fact == 0 ) 
      factors.push_back(fact);
    fact++;
  }
  return factors;
}


