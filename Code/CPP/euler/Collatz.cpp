#include <sstream>
#include "Collatz.h"

Collatz::Collatz() : 
  initialValue(1L)
{
}

Collatz::Collatz(unsigned long init) : 
  initialValue(init)
{
  buildSequence();
}

void Collatz::buildSequence() 
{
  unsigned long value = initialValue;
  while (value != 1L) {
    collatzNums.push_back(value);
    if (value % 2 == 0) {
      value = value / 2L;
    } else {
      value = 3L * value + 1L;
    }
  }
  collatzNums.push_back(value);
}

unsigned int Collatz::size() const
{
  return collatzNums.size();
}

unsigned long Collatz::operator[](unsigned int i) const
{
  return collatzNums[i];
}

const std::vector<unsigned long>* Collatz::fullSequence() const
{
  return &collatzNums;
}

void Collatz::reset(unsigned long value) 
{
  initialValue = value;
  collatzNums.clear();
  buildSequence();
}

std::string Collatz::toString() const
{
  std::stringstream ss;
  const std::vector<unsigned long>* seq = this->fullSequence();
  unsigned index = 0;
  for (std::vector<unsigned long>::const_iterator p=seq->begin();
      p!=seq->end();
      ++p) {
    ss << "(" << index << "," << *p << ") ";
  }
  return ss.str();
}
