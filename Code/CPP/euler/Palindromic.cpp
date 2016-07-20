#include "Palindromic.h"    // NOLINT(build/include)

Palindromic::Palindromic() : value(0) {}

Palindromic::Palindromic(int theValue) : value(theValue) {}

bool Palindromic::isPalindromic() const {
  std::vector<int> digits = digitize(value);
  return isPalindromic(digits);
}

bool Palindromic::isPalindromic(const std::vector<int>& digits) const {
  std::vector<int>::const_iterator p=digits.begin();
  std::vector<int>::const_iterator q=digits.end()-1;
  while (std::distance(p, q) > 0) {
    if ( (*p) != (*q) ) return false;
    ++p;
    --q;
  }
  return true;
}

std::vector<int> Palindromic::digitize() const {
  return digitize(value);
}

std::vector<int> Palindromic::digitize(int value) const {
  std::vector<int> digits;
  value = value < 0 ? -value : value;
  while (value) {
    int rem = value % 10;
    value /= 10;
    digits.push_back(rem);
  }
  return digits;
}

int Palindromic::getValue() const {
  return value;
}

void Palindromic::setValue(int theValue) {
  value = theValue;
}
