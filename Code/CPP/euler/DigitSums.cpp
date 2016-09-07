#include "DigitSums.h"   // NOLINT(build/include)

DigitSums::DigitSums() :
  number(0) {
  digits.push_back(0);
}

DigitSums::DigitSums(uint64_t num) :
  number(num) {
  digits = calcDigitsForNumber(num);
}

std::vector<uint64_t> DigitSums::calcDigitsForNumber(uint64_t num) const {
  std::vector<uint64_t> v;
  if (0 == num) {
    v.push_back(0);
    return v;
  }
  while (num > 0) {
    auto it = v.begin();
    uint64_t dig = num % 10;
    v.insert(it, dig);
    num = num / 10;
  }
  return v;
}

void DigitSums::setNumber(uint64_t num) {
  number = num;
  digits = calcDigitsForNumber(num);
}

uint64_t DigitSums::getNumber() const {
  return number;
}

std::vector<uint64_t> DigitSums::getDigits() const {
  return digits;
}

uint64_t DigitSums::getDigitSum() const {
  return getDigitsToPowerSum(1);
}

uint64_t DigitSums::getDigitsToPowerSum(uint64_t power) const {
  uint64_t sum = 0;
  for (auto i : digits) {
    uint64_t term = 1;
    uint64_t p    = power;
    while (p > 0) {
      term *= i;
      --p;
    }
    sum += term;
  }
  return sum;
}
