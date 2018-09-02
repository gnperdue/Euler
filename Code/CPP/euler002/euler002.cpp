#include <iostream>        // NOLINT(readability/streams)
#include "Fibonacci.h"     // NOLINT(build/include)

const uint64_t trialSize = 4000000L;

int main(int argc, char * argv[]) {
  Fibonacci fibonacci(1L);

  unsigned int index = 0;
  uint64_t val = fibonacci[index];
  while ( val < trialSize ) {
    fibonacci.addFiboNumber();
    index++;
    val = fibonacci[index];
  }

  std::vector<uint64_t> vals;   // NOLINT(build/include_what_you_use)
  uint64_t sum = 0L;
  for (auto i = 0; i < fibonacci.size(); ++i) {
    uint64_t val = fibonacci[i];
    if ( (0 == val % 2) && (val < trialSize) ) {
      vals.push_back(val);
      sum += val;
    }
  }
  std::cout << "Sum = " << sum << std::endl;

  return 0;
}

