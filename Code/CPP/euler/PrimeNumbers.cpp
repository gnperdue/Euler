#include "PrimeNumbers.h"    // NOLINT(build/include)

//----------------
// add the next occuring prime to storage
void PrimeNumbers::addPrimeNumber() {
  if (!primeNumbers.size()) {
    primeNumbers.push_back(1L);
  } else {
    uint64_t endp = primeNumbers[ primeNumbers.size() - 1 ];
    uint64_t newp = nextPrime(endp);
    primeNumbers.push_back(newp);
  }
}


//----------------
// brute force, inelegant prime number checker
bool PrimeNumbers::isPrime(uint64_t num) const {
  if (1L == num) return true;
  if (2L == num) return true;
  if (3L == num) return true;

  uint64_t m = num - 1L;
  while (m > 1L) {
    if (0L == num % m) return false;
    --m;
  }

  return true;
}


//----------------
// compute the next prime number that occurs after the given value
uint64_t PrimeNumbers::nextPrime(uint64_t val) const {
  uint64_t next = val + 1L;
  while ( !isPrime(next) ) ++next;
  return next;
}


//----------------
// get the number of stored computed primes
unsigned PrimeNumbers::size() const {
  return primeNumbers.size();
}


//----------------
// get a prime from storage by index
uint64_t PrimeNumbers::operator[](uint64_t i) const {
  return primeNumbers[i];
}

