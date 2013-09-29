#include "Fibonacci.h"

Fibonacci::Fibonacci(unsigned long int initialLength)
{
  for (unsigned long int index = 0; index < initialLength; ++index) {
    this->addFiboNumber();
  }
}

Fibonacci::Fibonacci(const Fibonacci& other)
{
  fiboNums = other.fiboNums;
}

void Fibonacci::addFiboNumber() 
{
  unsigned int initialLength = fiboNums.size();

  if (0 == initialLength) { 
    fiboNums.push_back(1L);
  } 
  else if (1 == initialLength) { 
    fiboNums.push_back(1L);
  }
  else {
    fiboNums.push_back( 
        fiboNums[initialLength - 1] + fiboNums[initialLength - 2] );
  }
}

unsigned int Fibonacci::size() const
{
  return fiboNums.size();
}

unsigned long int Fibonacci::operator[](unsigned int i) const
{
  return fiboNums[i];
}

