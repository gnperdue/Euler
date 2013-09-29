#include "PrimeNumbers.h"

//----------------
void PrimeNumbers::addPrimeNumber()
{
  if (!primeNumbers.size()) {
    primeNumbers.push_back(1L);
  }
  else {
    unsigned long endp = primeNumbers[ primeNumbers.size() - 1 ];
    unsigned long newp = nextPrime( endp );
    primeNumbers.push_back( newp );
  }
}


//----------------
bool PrimeNumbers::isPrime(unsigned long num) const
{
  if (1L == num) return true;
  if (2L == num) return true;
  if (3L == num) return true;

  unsigned long m = num - 1L;
  while (m > 1L) {
    if (0L == num % m) return false;
    --m;
  }

  return true;
}


//----------------
unsigned long PrimeNumbers::nextPrime(unsigned long val) const
{
  unsigned long next = val + 1L;
  while ( !isPrime(next) ) ++next;
  return next;
}


//----------------
unsigned PrimeNumbers::size() const 
{
  return primeNumbers.size();
}


//----------------
unsigned long PrimeNumbers::operator[](unsigned i) const 
{
  return primeNumbers[i];
}

