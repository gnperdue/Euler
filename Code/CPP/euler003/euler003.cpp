#include <iostream>           // NOLINT(readability/streams)
#include <cmath>
#include "PrimeNumbers.h"     // NOLINT(build/include)

const uint64_t number = 600851475143L;

int main(int argc, char * argv[]) {
  uint64_t startingPoint = ceil(sqrt(number));

  PrimeNumbers calculator;
  startingPoint = calculator.nextPrime(startingPoint);
  std::cout << "Investigating : " << number << std::endl;
  std::cout << "Starting Point: " << startingPoint << std::endl;

  uint64_t value = startingPoint;

  while (value > 0) {
    if ( calculator.isPrime(value) && (0 == number % value) ) {
      std::cout << "Largest Prime Factor: " << value << std::endl;
      break;
    }
    --value;
  }

  return 0;
}

