#include <iostream>
#include <cmath>
#include <memory>
#include "PrimeNumbers.h"

const unsigned long number = 600851475143L;

int main(int argc, char * argv[]) 
{
  /* constexpr unsigned long sqrtnum = ceil( sqrt( number ) ); */

  std::shared_ptr<PrimeNumbers> calculator(new PrimeNumbers());
  unsigned long startingPoint = ceil( sqrt(number) );
  startingPoint = calculator->nextPrime( startingPoint );
  std::cout << "Investigating : " << number << std::endl;
  std::cout << "Starting Point: " << startingPoint << std::endl;

  unsigned long value = startingPoint;

  while (value > 0) {
    if ( calculator->isPrime(value) && (0 == number % value) ) {
      std::cout << "Largest Prime Factor: " << value << std::endl;
      break;
    }
    --value;
  }

  return 0;
}

