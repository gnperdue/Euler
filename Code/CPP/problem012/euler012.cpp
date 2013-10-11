#include <iostream>

#include "TriangularNumber.h"

int main(int argc, char * argv[]) 
{
  using std::cout;
  using std::endl;

	unsigned long maxfacts = 500L;

  TriangularNumber triangleCalc;
	unsigned long index = 2000000L;
  triangleCalc.set(index);
	std::vector<unsigned long> facts = triangleCalc.factors();
	unsigned long nfacts = facts.size();

	while (nfacts <= maxfacts) {
		triangleCalc.set(++index);
		facts = triangleCalc.factors();
		nfacts = facts.size();
	}
	cout << "The first trianglar number with more than " << maxfacts 
		<< " factors is " << triangleCalc.get() << endl;
	cout << "  The factors are: " << endl;
	for (auto x : facts) cout << " " << x;
	cout << endl;

  return 0;
}


