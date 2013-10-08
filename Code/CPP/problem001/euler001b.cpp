#include <iostream>

int main(int argc, char * argv[])
{
  unsigned sum = 0;
  for (std::size_t i = 2; i < 1000; ++i) {
    if ( (0 == i % 3) || (0 == i % 5) ) 
      sum += i;
  }
  std::cout << "Sum = " << sum << std::endl;

  return 0;
}

