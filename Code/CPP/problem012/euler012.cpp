#include <iostream>

#include "TriangularNumber.h"

int main(int argc, char * argv[]) 
{
  using std::cout;
  using std::endl;

	unsigned long maxfacts = 500L;
  unsigned long currentMax = 0L;

  TriangularNumber triangleCalc;
	unsigned long index = 1L;
  triangleCalc.set(index);
	std::vector<unsigned long> facts = triangleCalc.factors();
	unsigned long nfacts = facts.size();

	while (nfacts <= maxfacts) {
		triangleCalc.set(++index);
		facts = triangleCalc.factors();
		nfacts = facts.size();
    if (nfacts > currentMax) {
      currentMax = nfacts;
      cout << "The first trianglar number with more than " << currentMax 
        << " factors is " << triangleCalc.get() << endl;
    }
  }
  cout << "The first trianglar number with more than " << maxfacts 
    << " factors is " << triangleCalc.get() << endl;
  cout << "  The factors are: " << endl;
  for (auto x : facts) cout << " " << x;
  cout << endl;

  return 0;
}


