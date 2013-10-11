#include <iostream>
#include <cassert>

#include "TriangularNumber.h"


int main(int argc, char * argv[])
{
  using std::cout;
  using std::endl;

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

  return 0;
}

