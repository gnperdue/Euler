#include <iostream>
#include "Fibonacci.h"

const unsigned long int trialSize = 4000000L;

int main(int argc, char * argv[])
{
  Fibonacci fibonacci(1L);

  unsigned int index = 0;
  unsigned long int val = fibonacci[index];
  while ( val < trialSize ) {
    fibonacci.addFiboNumber();
    index++;
    val = fibonacci[index];
  } 

  std::vector<unsigned long int> vals;
  unsigned long int sum = 0L;
  for (unsigned int i = 0; i < fibonacci.size(); ++i) {
    unsigned long int val = fibonacci[i];
    if ( (0 == val % 2) && (val < trialSize) ) {
      vals.push_back( val );
      sum += val;
    }
  }
  std::cout << "Sum = " << sum << std::endl;

  return 0;
}

