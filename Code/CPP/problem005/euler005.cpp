#include <iostream>    // NOLINT(readability/streams)
#include <vector>

bool evenDivisByAll(int num, const std::vector<int> &divs);

int main(int argc, char * argv[]) {
  int evenlyDivisible{1};
  std::vector<int> xs{7, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

  for (;;) {
    if (evenDivisByAll(evenlyDivisible, xs)) {
      std::cout << evenlyDivisible <<
        " is evenly divisible by all the numbers.\n";
      break;
    }
    evenlyDivisible++;
  }

  return 0;
}

bool evenDivisByAll(int num, const std::vector<int> &divs) {
  bool isEvenDivisByAll = true;
  for (const auto x : divs) {
    if (0 != num % x) {
      isEvenDivisByAll = false;
      break;
    }
  }
  return isEvenDivisByAll;
}

