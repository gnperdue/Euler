#include <iostream>   // NOLINT(readability/streams)

#include "TriangularNumber.h"   // NOLINT(build/include)

int main(int argc, char * argv[]) {
  using std::cout;
  using std::endl;

  uint64_t maxfacts = 500L;
  uint64_t currentMax = 0L;

  TriangularNumber triangleCalc;
	uint64_t index = 1L;
  triangleCalc.set(index);
	std::vector<uint64_t> facts = triangleCalc.factors();
	uint64_t nfacts = facts.size();

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
