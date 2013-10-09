#include <iostream>
#include "Palindromic.h"

int main(int argc, char * argv[]) 
{
  Palindromic pp;

  int largestPalindrome = 0;
  for (int i = 900; i < 999; ++i) {
    for (int j = 900; j < 999; ++j) {
      int candidate = i * j;
      pp.setValue(candidate);
      if (pp.isPalindromic()) {
        if (candidate > largestPalindrome) 
          largestPalindrome = candidate;
      } 
    }
  }

  std::cout << "Largest Palindrome = " << largestPalindrome << std::endl;

  return 0;
}


