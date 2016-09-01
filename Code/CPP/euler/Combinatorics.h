#ifndef CODE_CPP_EULER_COMBINATORICS_H_
#define CODE_CPP_EULER_COMBINATORICS_H_

#include <cstdint>

class Combinatorics {

  private:  // NOLINT(whitespace/indent)
  public:   // NOLINT(whitespace/indent)
    Combinatorics() {}
    ~Combinatorics() {}
    Combinatorics& operator=(const Combinatorics&) = delete;
    Combinatorics(const Combinatorics&) = delete;

    uint64_t combination(uint64_t n, uint64_t k);
    uint64_t permutation(uint64_t n, uint64_t k);
    uint64_t factorial(uint64_t n, uint64_t truncate = 0);
};
# endif  // CODE_CPP_EULER_COMBINATORICS_H_
