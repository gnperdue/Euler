#include <iostream>
#include <cassert>

#include "TriangularNumber.h"
#include "DigitSums.h"

int main(int argc, char * argv[])
{
  using std::cout;
  using std::endl;

  {
    TriangularNumber triangleCalc;
    triangleCalc.set(7L);
    assert( triangleCalc.get() == 28L );
    std::vector<unsigned long> t7 {1,2,4,7,14,28};
    std::vector<unsigned long> t7p = triangleCalc.factors();
#if VERBOSE_PRINT
    for (auto x : t7p) cout << x << endl;
#endif
    assert( t7 == t7p );
    cout << "Passed Triangle Calc tests!" << endl;
  }

  {
    DigitSums digitSums;
    std::vector<unsigned> tests {1634,8208,9474};
    for (auto i : tests) {
      digitSums.setNumber(i);
      assert( i == digitSums.getDigitsToPowerSum(4) );
#if VERBOSE_PRINT
      for (auto x : digitSums.getDigits()) cout << x;
      cout << endl;
#endif
    }
    cout << "Passed Digit Powers tests!" << endl;
  }

  return 0;
}

