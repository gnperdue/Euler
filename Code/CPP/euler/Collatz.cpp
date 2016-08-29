#include <sstream>
#include "Collatz.h"  // NOLINT(build/include)

Collatz::Collatz() :
  initialValue(1L) {}

Collatz::Collatz(uint64_t init) :
  initialValue(init) {
  buildSequence();
}

void Collatz::buildSequence() {
  uint64_t value = initialValue;
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

unsigned int Collatz::size() const {
  return collatzNums.size();
}

uint64_t Collatz::operator[](unsigned int i) const {
  return collatzNums[i];
}

const std::vector<uint64_t>* Collatz::fullSequence() const {
  return &collatzNums;
}

void Collatz::reset(uint64_t value) {
  initialValue = value;
  collatzNums.clear();
  buildSequence();
}

std::string Collatz::toString() const {
  std::stringstream ss;
  const std::vector<uint64_t>* seq = this->fullSequence();
  unsigned index = 0;
  for (std::vector<uint64_t>::const_iterator p = seq->begin();
      p != seq->end();
      ++p) {
    ss << "(" << index << "," << *p << ") ";
  }
  return ss.str();
}
