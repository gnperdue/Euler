#include "DigitSums.h"

DigitSums::DigitSums() :
  number(0)
{
  digits.push_back(0);
}

DigitSums::DigitSums(unsigned num) :
  number(num)
{
  digits = calcDigitsForNumber(num);
}

std::vector<unsigned> DigitSums::calcDigitsForNumber(unsigned num) const
{
  std::vector<unsigned> v;
  if (0 == num) {
    v.push_back(0);
    return v;
  }
  while (num > 0) {
    auto it = v.begin();
    unsigned dig = num % 10;
    v.insert(it,dig);
    num = num / 10;
  }
  return v;
}

void DigitSums::setNumber(unsigned num) 
{
  number = num;
  digits = calcDigitsForNumber(num);
}

unsigned DigitSums::getNumber() const
{
  return number;
}

std::vector<unsigned> DigitSums::getDigits() const
{
  return digits;
}

unsigned DigitSums::getDigitSum() const
{
  return getDigitsToPowerSum(1);
}

unsigned DigitSums::getDigitsToPowerSum(unsigned power) const
{
  unsigned sum = 0;
  for (auto i : digits) {
    unsigned term = 1;
    unsigned p    = power;
    while (p > 0) {
      term *= i;
      --p;
    }
    sum += term;
  }
  return sum;

}



